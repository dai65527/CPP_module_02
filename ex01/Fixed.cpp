/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:05:15 by dnakano           #+#    #+#             */
/*   Updated: 2021/01/14 07:46:53 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cmath>
#include <iostream>

static void *ft_memcpy(void *dst, const void *src, size_t n) {
  size_t i;
  char *dst_c;
  char *src_c;

  if (!dst && !src) return (NULL);
  dst_c = (char *)dst;
  src_c = (char *)src;
  i = 0;
  while (i < n) {
    dst_c[i] = src_c[i];
    i++;
  }
  return (dst);
}

Fixed::Fixed(void) {
  std::cout << "Default constructor called" << std::endl;
  raw_ = 0;
}

Fixed::Fixed(const Fixed &fixed) {
  std::cout << "Copy constructor called" << std::endl;
  *this = fixed;
}

Fixed::Fixed(const int int_to_initialize) {
  std::cout << "Int constructor called" << std::endl;
  if (int_to_initialize > (int)FIXED8_MAX) {
    raw_ = 0x7FFFFFFF;
    return;
  } else if (int_to_initialize < (int)FIXED8_MIN) {
    raw_ = -0x80000000;
    return;
  }
  raw_ = int_to_initialize < 0 ? -int_to_initialize : int_to_initialize;
  raw_ = raw_ << fractional_bits_;
  if (int_to_initialize < 0) {
    raw_ = -raw_ & 0xFFFFFF00;
  }
}

static bool ft_isnan_f(const float nb) {
  uint32_t bit;

  ft_memcpy(&bit, &nb, sizeof(uint32_t));
  return (((bit & (0xFF << 23)) == (0xFF << 23)) && (bit & 0x7FFFFF));
}

bool Fixed::check_float(const float float_to_initialize) {
  if (ft_isnan_f(float_to_initialize) ||
      abs(float_to_initialize) < FIXED8_ABSMIN) {
    raw_ = 0;
    return (true);
  } else if (float_to_initialize > FIXED8_MAX) {
    raw_ = 0x7FFFFFFF;
    return (true);
  } else if (float_to_initialize < FIXED8_MIN) {
    raw_ = -0x80000000;
    return (true);
  }
  return (false);
}

Fixed::Fixed(const float float_to_initialize) {
  uint8_t exp;
  uint32_t bit;
  uint32_t frac;
  int offset;

  std::cout << "Float constructor called" << std::endl;

  if (check_float(float_to_initialize)) return;
  ft_memcpy(&bit, &float_to_initialize, sizeof(bit));
  exp = bit >> 23;
  frac = (bit & 0x7FFFFF) | (1 << 23);
  offset = (23 - fractional_bits_ - (exp - 127));
  if (offset > 0) {
    raw_ = frac >> offset;
    if (offset < 31 && (frac | (1 << (offset - 1))) &&
        frac << (32 - offset - 1)) {
      raw_++;
    }
  } else {
    raw_ = frac << -offset;
  }
  if (float_to_initialize < 0) {
    raw_ = -raw_;
  }
}

Fixed &Fixed::operator=(const Fixed &fixed) {
  std::cout << "Assignation operator called" << std::endl;
  raw_ = fixed.getRawBits();
  return (*this);
}

Fixed::~Fixed(void) { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const { return (raw_); }

void Fixed::setRawBits(int const raw) { raw_ = raw; }

int Fixed::toInt(void) const { return (roundf(toFloat())); }

float Fixed::toFloat(void) const {
  int i;
  int raw;
  float base;
  float fractional_part;

  raw = (raw_ >= 0) ? raw_ : -raw_;
  base = 1.0;
  fractional_part = 0.0;
  for (i = 0; i < 8; i++) {
    base /= 2.0;
    if (raw & (1 << (7 - i))) {
      fractional_part += base;
    }
  }
  if (raw_ >= 0) {
    return ((raw_ >> 8) + fractional_part);
  } else {
    return (-(-raw_ >> 8) - fractional_part);
  }
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
  out << fixed.toFloat();
  return (out);
}

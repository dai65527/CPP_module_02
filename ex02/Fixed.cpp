/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:05:15 by dnakano           #+#    #+#             */
/*   Updated: 2021/01/13 22:59:45 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cmath>

Fixed::Fixed(void) { raw_ = 0; }

Fixed::Fixed(const Fixed &fixed) { *this = fixed; }

Fixed::Fixed(const int int_to_initialize) {
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

  memcpy(&bit, &nb, sizeof(uint32_t));
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

  if (check_float(float_to_initialize)) return;
  memcpy(&bit, &float_to_initialize, sizeof(bit));
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
    raw_ = (raw_ & 0xFF) | (((~raw_) & 0xFFFFFF00) + (1 << 8));
  }
}

Fixed::~Fixed(void) {}

Fixed &Fixed::operator=(const Fixed &fixed) {
  raw_ = fixed.getRawBits();
  return (*this);
}

bool Fixed::operator>(const Fixed &fixed) const { return (raw_ > fixed.raw_); }

bool Fixed::operator<(const Fixed &fixed) const { return (raw_ < fixed.raw_); }

bool Fixed::operator>=(const Fixed &fixed) const {
  return (raw_ >= fixed.raw_);
}

bool Fixed::operator<=(const Fixed &fixed) const {
  return (raw_ <= fixed.raw_);
}

bool Fixed::operator==(const Fixed &fixed) const {
  return (raw_ == fixed.raw_);
}

bool Fixed::operator!=(const Fixed &fixed) const {
  return (raw_ != fixed.raw_);
}

int Fixed::sumPosAndNeg(int raw_pos, int raw_neg) {
  int raw_res;

  if ((raw_pos & 0xFFFFFF00) >= -(raw_neg & 0xFFFFFF00)) {
    if ((raw_pos & 0xFF) >= (raw_neg & 0xFF)) {
      raw_res = (raw_pos & 0xFF) - (raw_neg & 0xFF);
      raw_res |= (raw_pos & 0xFFFFFF00) + (raw_neg & 0xFFFFFF00);
    } else {
      raw_res = (raw_pos & 0xFF) + 0x100 - (raw_neg & 0xFF);
      raw_res |= (raw_pos & 0xFFFFFF00) - 0x100 + (raw_neg & 0xFFFFFF00);
    }
  } else {
    if ((raw_pos & 0xFF) >= (raw_neg & 0xFF)) {
      raw_res = (raw_neg & 0xFF) + 0x100 - (raw_pos & 0xFF);
      raw_res |= (raw_pos & 0xFFFFFF00) + 0x100 + (raw_neg & 0xFFFFFF00);
    } else {
      raw_res = (raw_neg & 0xFF) - (raw_pos & 0xFF);
      raw_res |= (raw_pos & 0xFFFFFF00) + (raw_neg & 0xFFFFFF00);
    }
  }
  return (raw_res);
}

Fixed Fixed::operator+(const Fixed &fixed) const {
  Fixed result;

  if ((raw_ <= 0 && fixed.raw_ <= 0) || (raw_ >= 0 && fixed.raw_ >= 0)) {
    result.raw_ = raw_ + fixed.raw_;
  } else if (raw_ > fixed.raw_) {
    result.raw_ = sumPosAndNeg(raw_, fixed.raw_);
  } else {  // raw_ < fixed.raw_
    result.raw_ = sumPosAndNeg(fixed.raw_, raw_);
  }
  return (result);
}

Fixed Fixed::operator-(const Fixed &fixed) const {
  Fixed reversed;

  reversed.setRawBits((fixed.raw_ & 0xFF) |
                      (((~fixed.raw_) & 0xFFFFFF00) + (1 << 8)));
  return (*this + reversed);
}

int Fixed::getRawBits(void) const { return (raw_); }

void Fixed::setRawBits(int const raw) { raw_ = raw; }

int Fixed::toInt(void) const { return (raw_ >> 8); }

float Fixed::toFloat(void) const {
  int i;
  float base;
  float fractional_part;

  base = 1.0;
  fractional_part = 0.0;
  for (i = 0; i < 8; i++) {
    base /= 2.0;
    if (raw_ & (1 << (7 - i))) {
      fractional_part += base;
    }
  }
  if (raw_ >= 0) {
    return ((float)(raw_ >> 8) + fractional_part);
  } else {
    return ((float)(raw_ >> 8) - fractional_part);
  }
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
  out << fixed.toFloat();
  return (out);
}

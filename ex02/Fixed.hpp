/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:05:28 by dnakano           #+#    #+#             */
/*   Updated: 2021/01/14 08:32:08 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

#define FIXED8_MAX 8388607.99609375
#define FIXED8_MIN -8388608.0
#define FIXED8_ABSMIN 0.00390625

class Fixed {
 private:
  int raw_;
  static const int fractional_bits_ = 8;

  bool check_float(const float float_to_initialize);

  static int sumPosAndNeg(int raw_pos, int raw_neg);

 public:
  Fixed(void);
  Fixed(const int int_to_initialize);
  Fixed(const float float_to_initialize);
  Fixed(const Fixed &fixed);
  ~Fixed(void);

  Fixed &operator=(const Fixed &fixed);
  bool operator>(const Fixed &fixed) const;
  bool operator<(const Fixed &fixed) const;
  bool operator>=(const Fixed &fixed) const;
  bool operator<=(const Fixed &fixed) const;
  bool operator==(const Fixed &fixed) const;
  bool operator!=(const Fixed &fixed) const;
  Fixed operator+(const Fixed &fixed) const;
  Fixed operator+(void) const;
  Fixed operator-(const Fixed &fixed) const;
  Fixed operator-(void) const;
  Fixed operator*(const Fixed &fixed) const;
  Fixed operator/(const Fixed &fixed) const;
  Fixed &operator++(void);
  Fixed operator++(int zero);
  Fixed &operator--(void);
  Fixed operator--(int zero);

  int getRawBits(void) const;
  void setRawBits(int const raw);

  int toInt(void) const;
  float toFloat(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif /* FIXED_HPP */

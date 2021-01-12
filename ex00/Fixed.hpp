/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:05:28 by dnakano           #+#    #+#             */
/*   Updated: 2021/01/12 10:34:31 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
 private:
  int raw_;
  static const int fractional_bits_ = 8;

 public:
  Fixed(void);
  Fixed(const Fixed &fixed);
  Fixed &operator=(const Fixed &fixed);
  ~Fixed(void);

  int getRawBits(void) const;
  void setRawBits(int const raw);
};

#endif /* FIXED_HPP */

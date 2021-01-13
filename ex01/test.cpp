/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:02:25 by dnakano           #+#    #+#             */
/*   Updated: 2021/01/13 23:59:58 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp"

int main(void)
{
  Fixed fixed;

  fixed = Fixed((float)FIXED8_MAX);
  std::cout << "fixed: " << fixed << std::endl;
  fixed = Fixed((float)FIXED8_MIN);
  std::cout << "fixed: " << fixed << std::endl;
  fixed = Fixed((float)FIXED8_ABSMIN);
  std::cout << "fixed: " << fixed << std::endl;
  fixed = Fixed((float)(-FIXED8_ABSMIN));
  std::cout << "fixed: " << fixed << std::endl;
  fixed = Fixed((float)(FIXED8_ABSMIN - 0.00000001));
  std::cout << "fixed: " << fixed << std::endl;
  fixed = Fixed(0.0f);
  std::cout << "fixed: " << fixed << std::endl;
  fixed = Fixed(0.42f);
  std::cout << "fixed: " << fixed << std::endl;
  fixed = Fixed(-0.42f);
  std::cout << "fixed: " << fixed << std::endl;
  fixed = Fixed(4.2f);
  std::cout << "fixed: " << fixed << std::endl;
  fixed = Fixed(-4.2f);
  std::cout << "fixed: " << fixed << std::endl;
  fixed = Fixed(4242424.242f);
  std::cout << "fixed: " << fixed << std::endl;
  fixed = Fixed(-4242424.242f);
  std::cout << "fixed: " << fixed << std::endl;
}

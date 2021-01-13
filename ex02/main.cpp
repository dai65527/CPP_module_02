/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:41:22 by dnakano           #+#    #+#             */
/*   Updated: 2021/01/13 18:58:32 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void) {
  Fixed a(42.42f);
  Fixed b(21.21f);
  Fixed c(42.42f);

  std::cout << a << " == " << b << " is " << (a == b) << std::endl;
  std::cout << a << " == " << c << " is " << (a == c) << std::endl;
  // std::cout << a << " * " << b << " = " << c << std::endl;
  return 0;
}

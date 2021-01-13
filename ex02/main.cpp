/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:41:22 by dnakano           #+#    #+#             */
/*   Updated: 2021/01/13 19:39:56 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void) {
  Fixed a(42.42f);
  Fixed b(21.21f);
  Fixed c(42.42f);
  Fixed d(-42.42f);
  Fixed res;

  std::cout << "\033[1mOperator \"<\" test \033[0m" << std::endl;
  std::cout << a << " < " << b << " is " << (a < b) << std::endl;
  std::cout << b << " < " << a << " is " << (b < a) << std::endl;
  std::cout << a << " < " << c << " is " << (a < c) << std::endl;

  std::cout << std::endl;

  std::cout << "\033[1mOperator \">\" test \033[0m" << std::endl;
  std::cout << a << " > " << b << " is " << (a > b) << std::endl;
  std::cout << b << " > " << a << " is " << (b > a) << std::endl;
  std::cout << a << " > " << c << " is " << (a > c) << std::endl;

  std::cout << std::endl;

  std::cout << "\033[1mOperator \"<=\" test \033[0m" << std::endl;
  std::cout << a << " <= " << b << " is " << (a <= b) << std::endl;
  std::cout << b << " <= " << a << " is " << (b <= a) << std::endl;
  std::cout << a << " <= " << c << " is " << (a <= c) << std::endl;

  std::cout << std::endl;

  std::cout << "\033[1mOperator \">=\" test \033[0m" << std::endl;
  std::cout << a << " >= " << b << " is " << (a >= b) << std::endl;
  std::cout << b << " >= " << a << " is " << (b >= a) << std::endl;
  std::cout << a << " >= " << c << " is " << (a >= c) << std::endl;

  std::cout << std::endl;

  std::cout << "\033[1mOperator \"==\" test \033[0m" << std::endl;
  std::cout << a << " == " << b << " is " << (a == b) << std::endl;
  std::cout << a << " == " << c << " is " << (a == c) << std::endl;

  std::cout << std::endl;

  std::cout << "\033[1mOperator \"!=\" test \033[0m" << std::endl;
  std::cout << a << " != " << b << " is " << (a != b) << std::endl;
  std::cout << a << " != " << c << " is " << (a != c) << std::endl;

  std::cout << std::endl;

  std::cout << "\033[1mOperator \"+\" test \033[0m" << std::endl;
  res = a + b;
  std::cout << a << " + " << b << " = " << res << std::endl;
  res = a + c;
  std::cout << a << " + " << c << " = " << res << std::endl;
  res = b + d;
  std::cout << b << " + " << d << " = " << res << std::endl;

  std::cout << std::endl;

  std::cout << "\033[1mOperator \"-\" test \033[0m" << std::endl;
  res = a - b;
  std::cout << a << " - " << b << " = " << res << std::endl;
  res = b - a;
  std::cout << b << " - " << a << " = " << res << std::endl;
  res = a - c;
  std::cout << a << " - " << c << " = " << res << std::endl;
  res = b - d;
  std::cout << b << " - " << d << " = " << res << std::endl;

  std::cout << std::endl;

  return (0);
}

#!/bin/bash
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/12 11:43:56 by dnakano           #+#    #+#              #
#    Updated: 2021/01/12 11:43:56 by dnakano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

clang++ -Wall -Wextra -Werror main.cpp Fixed.cpp -o test_fixed.out
./test_fixed.out > output_mine.txt
diff output_mine.txt output_subj.txt
rm test_fixed.out output_mine.txt

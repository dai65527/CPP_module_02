#!/bin/bash
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/13 17:53:07 by dnakano           #+#    #+#              #
#    Updated: 2021/01/13 17:53:07 by dnakano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

clang++ -Wall -Wextra -Werror main.cpp Fixed.cpp -o fixed_test
./fixed_test > result_mine.txt
diff result_mine.txt result_subj.txt
rm result_mine.txt fixed_test

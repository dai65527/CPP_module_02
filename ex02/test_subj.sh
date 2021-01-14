#!/bin/bash
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_subj.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 09:15:40 by dnakano           #+#    #+#              #
#    Updated: 2021/01/14 09:15:40 by dnakano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

clang++ -Wall -Wextra -Werror main_subj.cpp Fixed.cpp -o test_subj
./test_subj > res_mine.txt
diff res_mine.txt res_subj.txt
rm res_mine.txt test_subj

cc evaluate.c -o evaluate

cd ex00
cc -c -Wall -Wextra -Werror -o ex00.o ft_putchar.c
norminette -R CheckForbiddenSourceHeader ft_putchar.c
rm -rf ex00.o
cd ..

cd ex01
cc -c -Wall -Wextra -Werror -o ex01.o ft_print_alphabet.c
norminette -R CheckForbiddenSourceHeader ft_print_alphabet.c
rm -rf ex01.o
cd ..

cd ex02
cc -c -Wall -Wextra -Werror -o ex02.o ft_print_reverse_alphabet.c
norminette -R CheckForbiddenSourceHeader ft_print_reverse_alphabet.c
rm -rf ex02.o
cd ..

cd ex03
cc -c -Wall -Wextra -Werror -o ex03.o ft_print_numbers.c
norminette -R CheckForbiddenSourceHeader ft_print_numbers.c
rm -rf ex03.o
cd ..

cd ex04
cc -c -Wall -Wextra -Werror -o ex04.o ft_is_negative.c
norminette -R CheckForbiddenSourceHeader ft_is_negative.c
rm -rf ex04.o
cd ..

cd ex05
cc -c -Wall -Wextra -Werror -o ex05.o ft_print_comb.c 
norminette -R CheckForbiddenSourceHeader ft_print_comb.c
rm -rf ex05.o
cd ..

cd ex06
cc -c -Wall -Wextra -Werror -o ex06.o ft_print_comb2.c
norminette -R CheckForbiddenSourceHeader ft_print_comb2.c
rm -rf ex06.o
cd ..

cd ex07
cc -c -Wall -Wextra -Werror -o ex07.o ft_putnbr.c
norminette -R CheckForbiddenSourceHeader ft_putnbr.c
rm -rf ex07.o
cd ..

cd ex08
cc -c -Wall -Wextra -Werror -o ex08.o ft_print_combn.c
norminette -R CheckForbiddenSourceHeader ft_print_combn.c
rm -rf ex08.o
cd ..

./evaluate

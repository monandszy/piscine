rm -rf evaluate
cc evaluate.c -o evaluate

cd ex00
cc -c -Wall -Wextra -Werror ft_iterative_factorial.c -o ex00.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex00.o
cd ..

cd ex01
cc -c -Wall -Wextra -Werror ft_recursive_factorial.c -o ex01.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex01.o
cd ..

cd ex02
cc -c -Wall -Wextra -Werror ft_iterative_power.c -o ex02.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex02.o
cd ..

cd ex03
cc -c -Wall -Wextra -Werror ft_recursive_power.c -o ex03.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex03.o
cd ..

cd ex04
cc -c -Wall -Wextra -Werror ft_fibonacci.c -o ex04.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex04.o
cd ..

cd ex05
cc -c -Wall -Wextra -Werror ft_sqrt.c -o ex05.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex05.o
cd ..

cd ex06
cc -c -Wall -Wextra -Werror ft_is_prime.c -o ex06.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex06.o
cd ..

cd ex07
cc -c -Wall -Wextra -Werror ft_find_next_prime.c -o ex07.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex07.o
cd ..

cd ex08
cc -c -Wall -Wextra -Werror ft_ten_queens_puzzle.c -o ex08.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex08.o
cd ..

./evaluate
rm -rf evaluate

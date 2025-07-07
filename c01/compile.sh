rm -rf evaluate
cc evaluate.c -o evaluate

cd ex00
cc -c -Wall -Wextra -Werror ft_ft.c -o ex00.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex00.o
cd ..

cd ex01
cc -c -Wall -Wextra -Werror ft_ultimate_ft.c -o ex01.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex01.o
cd ..

cd ex02
cc -c -Wall -Wextra -Werror ft_swap.c -o ex02.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex02.o
cd ..

cd ex03
cc -c -Wall -Wextra -Werror ft_div_mod.c -o ex03.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex03.o
cd ..

cd ex04
cc -c -Wall -Wextra -Werror ft_ultimate_div_mod.c -o ex04.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex04.o
cd ..

 cd ex05
cc -c -Wall -Wextra -Werror ft_putstr.c -o ex05.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex05.o
cd ..

cd ex06
cc -c -Wall -Wextra -Werror ft_strlen.c -o ex06.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex06.o
cd ..

cd ex07
cc -c -Wall -Wextra -Werror ft_rev_int_tab.c -o ex07.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex07.o
cd ..

cd ex08
cc -c -Wall -Wextra -Werror ft_sort_int_tab.c -o ex08.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex08.o
cd ..

./evaluate
rm -rf evaluate

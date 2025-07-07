cd ex00
cc -Wall -Wextra -Werror ft_print_program_name.c -o ex00.o
norminette -R CheckForbiddenSourceHeader
chmod 777 ex00.o
./ex00.o | cat -e
rm -rf ex00.o
cd ..

cd ex01
cc -Wall -Wextra -Werror ft_print_params.c -o ex01.o
norminette -R CheckForbiddenSourceHeader
chmod 777 ex01.o
./ex01.o test1 test2 test3 | cat -e
rm -rf ex01.o
cd ..

cd ex02
cc -Wall -Wextra -Werror ft_rev_params.c -o ex02.o
norminette -R CheckForbiddenSourceHeader
chmod 777 ex02.o
./ex02.o test1 test2 test3 | cat -e
rm -rf ex02.o
cd ..

cd ex03
cc -Wall -Wextra -Werror ft_sort_params.c -o ex03.o
norminette -R CheckForbiddenSourceHeader
chmod 777 ex03.o
./ex03.o 1 00 9 3 4 5 2
./ex03.o "avc" "wda" "avd" "avce" "avc"
rm -rf ex03.o
cd ..

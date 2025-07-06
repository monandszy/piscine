rm -rf evaluate
cc evaluate.c -o evaluate

cd ex00
cc -c -Wall -Wextra -Werror ft_strcpy.c -o ex00.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex00.o
cd ..

cd ex01
cc -c -Wall -Wextra -Werror ft_strncpy.c -o ex01.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex01.o
cd ..

cd ex02
cc -c -Wall -Wextra -Werror ft_str_is_alpha.c -o ex02.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex02.o
cd ..

cd ex03
cc -c -Wall -Wextra -Werror ft_str_is_numeric.c -o ex03.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex03.o
cd ..

cd ex04
cc -c -Wall -Wextra -Werror ft_str_is_lowercase.c -o ex04.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex04.o
cd ..

cd ex05
cc -c -Wall -Wextra -Werror ft_str_is_uppercase.c -o ex05.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex05.o
cd ..

cd ex06
cc -c -Wall -Wextra -Werror ft_str_is_printable.c -o ex06.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex06.o
cd ..

cd ex07
cc -c -Wall -Wextra -Werror ft_strupcase.c -o ex07.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex07.o
cd ..

cd ex08
cc -c -Wall -Wextra -Werror ft_strlowcase.c -o ex08.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex08.o
cd ..

cd ex09
cc -c -Wall -Wextra -Werror ft_strcapitalize.c -o ex09.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex09.o
cd ..

cd ex10
cc -c -Wall -Wextra -Werror ft_strlcpy.c -o ex10.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex10.o
cd ..

cd ex11
cc -c -Wall -Wextra -Werror ft_putstr_non_printable.c -o ex11.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex11.o
cd ..

cd ex12
cc -c -Wall -Wextra -Werror ft_print_memory.c -o ex12.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex12.o
cd ..

./evaluate

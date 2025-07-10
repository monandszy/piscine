rm -rf evaluate
cc evaluate.c -o evaluate

cd ex00
cc -c -Wall -Wextra -Werror ft_strdup.c -o ex00.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex00.o
cd ..

cd ex01
cc -c -Wall -Wextra -Werror ft_range.c -o ex01.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex01.o
cd ..

cd ex02
cc -c -Wall -Wextra -Werror ft_ultimate_range.c -o ex02.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex02.o
cd ..

cd ex03
cc -c -Wall -Wextra -Werror ft_strjoin.c -o ex03.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex03.o
cd ..

cd ex04
cc -c -Wall -Wextra -Werror ft_convert_base.c ft_convert_base2.c -o ex04.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex04.o
cd ..
cc 4main.c ex04/ft_convert_base.c ex04/ft_convert_base2.c -o 4main.o
./4main.o
rm -rf 4main.o

cd ex05
cc -c -Wall -Wextra -Werror ft_split.c -o ex05.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex05.o
cd ..

./evaluate
rm -rf evaluate

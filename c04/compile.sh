cc evaluate.c -o evaluate

cp ../c01/ex06/* ./ex00/
cp ../c01/ex05/* ./ex01/
cp ../c00/ex07/* ./ex02/

cd ex00
cc -c -Wall -Wextra -Werror ft_strlen.c -o ex00.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex00.o
cd ..

cd ex01
cc -c -Wall -Wextra -Werror ft_putstr.c -o ex01.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex01.o
cd ..

cd ex02
cc -c -Wall -Wextra -Werror ft_putnbr.c -o ex02.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex02.o
cd ..

cd ex03
cc -c -Wall -Wextra -Werror ft_atoi.c -o ex03.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex03.o
cd ..

cd ex04
cc -c -Wall -Wextra -Werror ft_putnbr_base.c -o ex04.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex04.o
cd ..

cd ex05
cc -c -Wall -Wextra -Werror ft_atoi_base.c -o ex05.o
norminette -R CheckForbiddenSourceHeader
rm -rf ex05.o
cd ..

./evaluate

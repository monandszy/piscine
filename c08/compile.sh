norminette ./ex00/ft.h.gch -R CheckForbiddenSourceHeader -R CheckDefine
rm -rf ./ex00/ft_.h.gch
norminette ./ex01/ft_boolean.h -R CheckForbiddenSourceHeader -R CheckDefine
rm -rf ./ex01/ft_booleans.h.gch
norminette ./ex02/ft_abs.h -R CheckForbiddenSourceHeader -R CheckDefine
rm -rf ./ex02/ft_abs.h.gch
norminette ./ex03/ft_point.h -R CheckForbiddenSourceHeader -R CheckDefine
rm -rf ./ex03/ft_point.h.gch

cc -Wall -Wextra -Werror ./ex01/ft_boolean.h ./ex02/ft_abs.h ./ex03/ft_point.h ./main.c
./a.out E
./a.out O O
rm -rf a.out


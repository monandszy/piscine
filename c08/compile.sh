norminette ./ex00/ft.h.gch -R CheckForbiddenSourceHeader -R CheckDefine
norminette ./ex01/ft_boolean.h -R CheckForbiddenSourceHeader -R CheckDefine
norminette ./ex02/ft_abs.h -R CheckForbiddenSourceHeader -R CheckDefine
norminette ./ex03/ft_point.h -R CheckForbiddenSourceHeader -R CheckDefine

cc -Wall -Wextra -Werror ./ex01/ft_boolean.h ./ex02/ft_abs.h ./ex03/ft_point.h ./main.c
./a.out E
./a.out O O
rm -rf a.out
rm -rf ./ex00/ft_.h.gch
rm -rf ./ex01/ft_booleans.h.gch
rm -rf ./ex02/ft_abs.h.gch
rm -rf ./ex03/ft_point.h.gch


norminette ./ex04/ft_strs_to_tab.c -R CheckForbiddenSourceHeader -R CheckDefine
norminette ./ex05/ft_show_tab.c -R CheckForbiddenSourceHeader -R CheckDefine
cc ./ex04/ft_strs_to_tab.c ./ex05/ft_show_tab.c ft_stock_str.h	
./a.out
rm -rf a.out

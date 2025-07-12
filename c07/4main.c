
#include <stdio.h>

char *ft_convert_base(char *nbr, char *base_from, char *base_to);

int main()
{
	printf("\n---testing ex04---\n");
	char *hex = "0123456789abcdef";
	char *dec = "0123456789";

	printf("%s\n", ft_convert_base("aaa", "ba", "0123456789"));
	printf("%s\n", ft_convert_base("10", dec, hex));
	printf("%s\n", ft_convert_base("-0a", hex, dec));
	printf("%s\n", ft_convert_base("0", hex, dec));
	printf("%s\n", ft_convert_base("0a", hex, dec));
	printf("%s\n", ft_convert_base("0a", "invalid", dec));
	printf("%s\n", ft_convert_base("0a", "invalid", "invalid"));
	printf("%s\n", ft_convert_base("-----dawdaaaa0", dec, dec));
//	ft_convert_bas
//	printf("\n");
	printf("---END---\n");
}

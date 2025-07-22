#include <stdio.h>

int	main(int ac, char **av)
{
	char	*str;

	printf("Salut ! Comment t'appelles tu ?\n");

	scanf("%s", str);

	printf("bonjour %s\n", str);

	int	age;
	printf("Quelle age a-tu ?\n");
	scanf("%d", &age);

	printf("ok %s, tu as %d ans.\n", str, age);
	return (0);
}

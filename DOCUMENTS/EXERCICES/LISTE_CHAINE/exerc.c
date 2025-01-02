#include <stdio.h>
#include <string.h>

struct	personne
{
	char	nom[50];
	int	age;
};

int main()
{
	struct	personne p1;
	struct	personne p2;

	strcpy(p1.nom, "anthony");
	strcpy(p2.nom, "gabriela");
	p1.age = 31;
	p2.age = 4;

	printf("nom p1 = %s\n", p2.nom);
	printf("age p1 = %d", p2.age);
	return 0;
}

"	STRUCTURE	"

p1.age		=	acces struct non-pointee;
ptr->age	=	acces struct pointee;
(*ptr).age	=	equivalent, mais moin pratique;

// STRUCTURE BASIC
struct	personne
{
	char	nom[50];
	char	prenom[50];
	int	age;
	int	taille;
}

// STRUCTURE POINTEUR

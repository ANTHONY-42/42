// dans le .h

typedef struct liste{
	int value;
	struct	liste	*next;
	struct	liste	*previous;
} struct list; // Pas sur

// Dans programme
//
int	main()
{
	struct liste	a; // Plus pratique avec des pointeurs
	struct liste	b;

	a.value = 1;
	a.next = &b;
	b.value = 2;
	b.next = NULL;

	a.next

	
}	

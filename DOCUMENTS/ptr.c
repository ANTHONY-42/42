RAM  = MEMOIRE VOLATIL
STACK = PILE = INT A, CHAR C, ...
STACK OVERFLOW =  MEMORE MAX 
HEAP = TAS = MALLOC, POINTEUR 


int a; int = 4 bytes, donc ton CPU alloue 4 bytes sur la stack
char c; char = 1 byte donc ton CPU alloue 1 byte sur la stack

int *a; le pointeur de type int qui peut donc pointer vers des variables de type int;
char *c; le pointeur de type char qui peut pointer vers des variables de type char;


int *a = malloc(sizeof(int) * 10);

 arythmetique des ptr;
[[  8] [ 53 ]  [42 ]                                                        ZONE MEMOIRE DANS LA STACK DE 40 BYTES                                                                      ]
 ^
 |
 |
 pointeur 

a[0] == *(a + 0)
a[1] == *(a + 1)
a[2] == *(a + 2) = (a + 2 * sizeof(int))

char *S = malloc(8)

[ 'H' 'E' 'L' 'L' 'O'                8 BYTES        ]
^
|
|

S[0] = *(S + 12)
S[1] = *(S + 1) (S + 1 * sizeof(char))

free(S);

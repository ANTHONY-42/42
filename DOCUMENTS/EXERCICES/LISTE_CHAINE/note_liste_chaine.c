"	LISTE CHAINEE"
ex:	[5 | *] -> [10 | *] -> [20 | *] -> [30 | NULL]

1 noeud = [valeur | pointeur]
- valeur 	a droit
- pointeur	a gauche
- ->		*] -> [valeur
- NULL		dernier noeud



"	LISTE DOUBLEMENT CHAINE" 
ex:	NULL <- [10 | * | *] <-> [20 | * | *] <-> [30 | * | NULL]

1 noeud double = [valeur | * precendent | * suivant]

"	LISTE CHAINE BOUCLE"
ex:	[10 | *] -> [20 | *] -> [30 | *] -+
	      ^----------------------------+

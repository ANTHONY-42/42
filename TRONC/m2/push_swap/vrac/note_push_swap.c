
PILE A	|PILE B
	|
	|

--------------------------------------------------------------------
"--------------------------------------------------------------------
//--------------------------------------------------------------------
	SWAP:	v^
//--------------------------------------------------------------------
sa: (swap a) = Echange les 2 premiers element de la pile A.
^|
|v		= A
--------------------------------------------------------------------
sb: (swap b) = Echange les 2 premiers element de la pile A.
|^
v|		= B
--------------------------------------------------------------------
ss: effectue sa et sb en meme temps.
^| | ^|	
|v | |v		= A + B
--------------------------------------------------------------------
"--------------------------------------------------------------------
//--------------------------------------------------------------------
	PUSH: -><-
//--------------------------------------------------------------------
pa: (push a) = deplace le 1 premiers element de la pile b vers la pile a.
A	<-	B
--------------------------------------------------------------------
pb: (push b) = deplace le premier element de la pile a vers la pile b.
B	->	A
--------------------------------------------------------------------
"--------------------------------------------------------------------
//--------------------------------------------------------------------
	ROTATE_HAUT:	^^
//--------------------------------------------------------------------
ra: (rotate a) = Decaler tous les element vers le haut.
^ ^
| |		= A
--------------------------------------------------------------------
rb: (rotate B) = decale tous les element de la pile b vers le haut.
^ ^
| |		= B
--------------------------------------------------------------------
rr: effectue ra et rb en meme temps.
^ ^  ^ ^
| |  | |	= A + B
--------------------------------------------------------------------
"--------------------------------------------------------------------
//--------------------------------------------------------------------
	ROTATE_BAS:	vv
//--------------------------------------------------------------------

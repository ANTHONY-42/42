sed	=	STREAM EDITOR (editeur de flux);
s 	=	substitution;
d	=	delete;

s/texte/replacement/g
Substitute = remplace le texte cherché par un autre
echo "hello world" | sed 's/world/universe/'
hello universe
d
/motif/d
Delete = supprime les lignes contenant le motif
echo -e "a\nb\nc" | sed '/b/d'
ac
p
/motif/p
Print = affiche seulement les lignes qui correspondent
echo -e "a\nb\nc" | sed -n '/b/p'
b
i
/motif/i texte
Insert = insère une ligne avant le motif
echo -e "a\nb" | sed '/b/i INSERT'
aINSERTb
a
/motif/a texte
Append = ajoute une ligne après le motif
echo -e "a\nb" | sed '/a/a AFTER'
aAFTERb
c
/motif/c texte
Change = remplace la ligne entière contenant le motif
echo -e "a\nb" | sed '/b/c CHANGED'
aCHANGED
y
y/abc/ABC/
Transliterate = transforme les caractères un par un
echo "abc" | sed 'y/abc/ABC/'
ABC
=
=
Affiche le numéro de ligne
echo -e "a\nb\nc" | sed '='
1a2b3c
q
q
Quit = arrête l’exécution (souvent après une condition)
echo -e "a\nb\nc" | sed '2q'
ab


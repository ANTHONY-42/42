  ////////////////////////
 ////"PARSER UNE MAP"////
////////////////////////

Qu'est-ce que parser une carte ?

Parser une carte signifie lire un fichier contenant la représentation de la carte du jeu et transformer ces données en une structure exploitable par le programme. Cette étape implique plusieurs tâches :

1. Lire le contenu du fichier : Charger le fichier .ber ligne par ligne.
2. Stocker les données : Organiser ces lignes dans une structure de données (par exemple, un tableau de chaînes).
3. Vérifier la validité de la carte : Contrôler que le fichier respecte des règles spécifiques
(forme rectangulaire, murs, éléments obligatoires, etc.).

Pourquoi est-ce important dans so_long ?

Le jeu utilise cette carte pour afficher le monde du joueur. Chaque caractère de la carte représente un élément du jeu :

    1 : Mur.
    0 : Espace vide.
    C : Collectible (objet à ramasser).
    E : Sortie.
    P : Position de départ du joueur.

Ces informations sont essentielles pour construire la logique du jeu (affichage, déplacements, interactions).


📦 Syntaxe de open() :	int open(const char *pathname, int flags, mode_t mode);


📊 Tableau des principaux flags open()

"	Flag		  | Nom complet		| Effet								| Exemple d’utilisation
//-----------------------------------------------------------------------------------------------------------------------------------------------
/*	O_RDONLY	*/| Read only		| Ouvre le fichier en "lecture seule"				| open("file.txt", O_RDONLY);	|
//-----------------------------------------------------------------------------------------------------------------------------------------------
/*	O_WRONLY	*/| Write only		| Ouvre le fichier en "écriture seule"				| open("file.txt", O_WRONLY);	|
//-----------------------------------------------------------------------------------------------------------------------------------------------
/*	O_RDWR		*/| Read & write	| Ouvre le fichier en "lecture et écriture"			| open("file.txt", O_RDWR);	|
//-----------------------------------------------------------------------------------------------------------------------------------------------
/*	O_CREAT		*/| Create		| "Crée" le fichier s’il n’existe pas (nécessite aussi un mode)	| open(“new.txt”, O_CREAT	|
//-----------------------------------------------------------------------------------------------------------------------------------------------
/*	O_TRUNC		*/| Truncate		| "Vide" le fichier existant dès l’ouverture			| open(“file.txt”, O_WRONLY	|
//-----------------------------------------------------------------------------------------------------------------------------------------------
/*	O_APPEND	*/| Append		| Ajoute à la fin du fichier au lieu d’écraser			| open(“log.txt”, O_WRONLY	|
//-----------------------------------------------------------------------------------------------------------------------------------------------
/*	O_EXCL		*/| Exclusive		| Échoue si le fichier existe déjà (avec O_CREAT)		| open(“file.txt”, O_CREAT	|
//-----------------------------------------------------------------------------------------------------------------------------------------------
/*	O_SYNC		*/| Synchronised write	| Écrit directement sur le disque (lent, mais sûr)		| open(“data.txt”, O_WRONLY	|
//-----------------------------------------------------------------------------------------------------------------------------------------------


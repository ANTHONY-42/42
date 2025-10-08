//==============================================================================================//
//threads
Le threads partage la memoire.
Tous les threads accedent au meme variable.

"pthread_create"	= Lance une fonction thread qui s'execute en parallele.
"pthread_join"		= Attend qu'un thread se termine avant de continuer.
"pthread_detach"	= Laisse un thread s'executer seul sans qu'on lattende.

//==============================================================================================//
//mutex
Le mutex protege une source :
Il empeche plusieur threads de toucher a la meme chose en meme temps.

Deadlock : Quand deux threads attendent chacun un verrou que l autre ne rend pas.

"pthread_mutex_init"	= Prepare un verrou (mutex) qu'on pourra utiliser.
"pthread_mutex_lock"	= Prend le verrou (si quelqu un d'autre la, il attend).
"pthread_mutex_unlock"	= Libre le verrou pour que d autre threads puissent l utilise.
"pthread_mutex_destroy"	= Libere les ressources utilisees par le mutex.

//==============================================================================================//
//temps
Calcul de temps : On fai la difference entre deux temps pour savoir combien de ms sont passee.
Detection de mort : Si trop de temps est passe depuis le dernier repas, le philosophe est mort.

"gettimeofday"		= Donne l'heure exacte a al microseconde pres.
"usleep"		= Met un thread en pause pendant un temps donne.
surveillance : Un thread surveille tous les philosophes ou chaque philosophe se surveille lui-meme.

//==============================================================================================//
//Race condition
definition : Deux threads modifient une variable en meme temps sans protection (bug aleatoire)
Solution :   Toujours utiliser un mutex pour les variable partagees.
surveillance : Un thread surveille tous les philosophes ou chaque philosophe se surveille lui-meme.

//==============================================================================================//
//surveillance de la mort
verification : On verifie souvent si un philosophe est reste trop longtemps sans manger.
surveillance : Un thread surveille tous les philosophes ou chaque philosophe se surveille lui-meme.

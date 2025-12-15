"┌─────────────────────────────────────────────────────┐"
"│                      FD TABLE                       │"
"│	                    &                          │"
"│                     REDIRECTION                     │"
"└─────────────────────────────────────────────────────┘"

/* [ "CHAQUE PROCESSUS RECOIT UN FD TABLE DE BASE" ] */

//─────────────────────────────────────────────────────
//	FD TABLE DE BASE :
//─────────────────────────────────────────────────────
┌────────┬──────────┬────────────────────────────┐
│  FD    │   NOM    │     SOURCE                 │
├────────┼──────────┼────────────────────────────┤
│  0     │ STDIN    │ entrée standard (clavier)  │
│  1     │ STDOUT   │ sortie standard (terminal) │
│  2     │ STDERR   │ sortie d'erreur (terminal) │
└────────┴──────────┴────────────────────────────┘



//─────────────────────────────────────────────────────
//	APRES PLUSIEURS OPEN()
//─────────────────────────────────────────────────────
int fd_1 = open("in.txt", O_RDONLY);
int fd_2 = open("out.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
int fd_3 = open("log.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

┌────────┬──────────┬────────────────────────────┐
│  FD    │   NOM    │     SOURCE                 │
├────────┼──────────┼────────────────────────────┤
│  0     │ STDIN    │ entrée standard (clavier)  │
│  1     │ STDOUT   │ sortie standard (terminal) │
│  2     │ STDERR   │ sortie standard (terminal) │
│  3     │ fd_1     │ in.txt (lecture)           │
│  4     │ fd_2     │ out.txt (écriture)         │
│  5     │ fd_3     │ log.txt (append)           │
└────────┴──────────┴────────────────────────────┘



//─────────────────────────────────────────────────────
//	APRES REDIRECTION
//─────────────────────────────────────────────────────
dup2(fd_1, STDIN);
dup2(fd_2, STDOUT);

close(fd_1);
close(fd_2);
┌────────┬──────────┬────────────────────────────┐
│  FD    │   NOM    │     SOURCE                 │
├────────┼──────────┼────────────────────────────┤
│  0     │ STDIN    │ in.txt (lecture)           │
│  1     │ STDOUT   │ out.txt (écriture)         │
│  2     │ STDERR   │ sortie d'erreur (terminal) │
│  5     │ fd_3     │ log.txt (append)           │
└────────┴──────────┴────────────────────────────┘
//─────────────────────────────────────────────────────

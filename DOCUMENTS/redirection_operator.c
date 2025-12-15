FD TABLE

Processus après open :

 fd_1	= open("input.txt", W_WONLY);
 fd_	= open("output.txt", )
 ┌──────────────┬────────────────────────┐
 │ FD (int)     │ Cible (open file)      │
 ├──────────────┼────────────────────────┤
 │ 0 (STDIN)    │ terminal (entrée)      │
 │ 1 (STDOUT)   │ terminal (sortie)      │
 │ 2 (STDERR)   │ terminal (erreurs)     │
 │ 3            │ fichier out.txt (écrit)│
 └──────────────┴────────────────────────┘

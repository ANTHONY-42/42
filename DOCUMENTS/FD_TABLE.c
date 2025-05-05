// FD_TABLE

╔════╦════════════╦═════════════════════════════╗
║ FD ║ Nom        ║ Connecté à                  ║
╠════╬════════════╬═════════════════════════════╣
║ 0  ║ STDIN      ║ le terminal (entrée clavier)║
║ 1  ║ STDOUT     ║ le terminal (sortie écran)  ║
║ 2  ║ STDERR     ║ le terminal (erreurs)       ║
║ 3  ║ infile     ║ ton fichier d'entrée        ║
║ 4  ║ outfile    ║ ton fichier de sortie       ║
║ 5  ║ pipefd[0]  ║ extrémité LECTURE du pipe   ║
║ 6  ║ pipefd[1]  ║ extrémité ÉCRITURE du pipe  ║
╚════╩════════════╩═════════════════════════════╝

infile  (fichier disque)
   │
   ▼
stdin (0) —[cmd1]→ stdout (1)
                         │
                         ▼
                  pipefd[1] —──┐
                               │ zone mémoire tampon (pipe)
                  pipefd[0] ◀──┘
                         │
                         ▼
stdin (0) —[cmd2]→ stdout (1)
   │
   ▼
outfile (fichier disque)

//	BORN2BEROOT

"	1. PARTIE INSTALLATION	"

- aff info vm	: hostnamectl
//-------------------------------------------------------------------------------
//	HOSTNAME (nom de la machine)
	Permet de donner un nom à ta machine;

command :
- verifie l'hostname			: hostname
- modification hostname temporairement	: sudo hostname new_name
- modification hostname permanent 	: sudo hostnamectl set-hostname new_name
//-------------------------------------------------------------------------------
//	DOMAINE
	Adresse complete d'un reseaux;
//-------------------------------------------------------------------------------
//	FULLNAME (nom complet d'utilisateur)
	information sur l'utilisateur;

command :
- change username		: sudo chfn -f "full_name" username
- add nom complet a l'USERNAME	: sudo useradd -c "full_name" username
//-------------------------------------------------------------------------------
//	USERNAME (nom d'utilisateur)
	(login): pseudo unique pour ce connecter ou s'identifier dans le terminal;

command :
- username actuel		: whoami
- username detailed		: finger username
- add newuser			: sudo useradd username
- add newuser + full name	: sudo useradd -c fullname username
- change username		: sudo usermod -l newname username
- change fullname		: sudo chfn -f newfullname username
- add password newuser		: sudo passwd username
- delete user			: sudo userdel username
- delete user + directory	: sudo userdel -r username
- change directory		: sudo usermod -d /nouveau/chemin/nom_utilisateur username
//-------------------------------------------------------------------------------
//	LVM (Logical Volume Management)
	systeme de gestion disque dur;
redimentionne, fusionne, divise, partitionne
LVM est diviser :
PV : (Physical Volume), disque physique ou partition que tu veux ajouter au systeme;
VG : (Volume Group), groupe qui regroupe plusieur plusieur (PV);
LV : (Logical Volume), volume logique 

command :
- aff partition			: lsblk
- liste les volume physique	: sudo pvdisplay
- liste les groupe de volume	: sudo vgdisplay
- liste le volume logique	: sudo lvdisplay
//-------------------------------------------------------------------------------

"	2. PARTIE CONFIGURATION	"
//	INSTALL SUDO (SuperUser Do)
La command sudo permet à un utilisateur (non-administrateur (ou ayant peu de privilèges))
d'exécuter une command avec les privilèges d'un superutilisateur,
(aussi appelé root), qui a un contrôle total sur le système.

utilisateur root	: su -

//	UFW
PARE-FEU QUI BLOCK LES PORT

command :
- aff info system ufw	: systemctl status ufw
- activer un port	: sudo ufw allow 4242 (numero du port)
- aff info port act	: sudo ufw status numbered

//	SSH
command :
- aff info ssh	: systemctl status ssh

//	CREER UN GROUPE
- aff user groups			: sudo getent group namegroup
- ajouter un groups			: sudo addgroup namegroup
- modif namegroup			: sudo gpass
- suprimer un group			: sudo delgroup namegroup
-
- Gestion utilisateurs et permissions	: donner les meme permition a un groupe d'utilisateur;
- Sécurisation et isolation des tâches	: separer les utilisateurs pour renforcer la securiter; 
- Simplification de l'administration	: attribuer les permissions à tout le groupe en une fois;
- Partage des ressources		: Partager facilement des ressources entre utilisateurs;
- Automat et gestion des configuration	: appliquant des règles ou des configurations communes;
- Gestion utilisateurs dans réseau virt	: classer et organiser les utilisateurs;

command :
- creer u groupe		: sudo groupadd groupname
- voir les groupe actif		: getent group

//	CREER UN USER
command :
- voir les user actif		: cut -d: -f1 /etc/passwd
- voir les user  dans un group	: getent group groupname
- voir le group de l'user actuel: groups
- creer un newuser		: sudo adduser new_username
- placer un user dans un group	: sudo usermod -aG groupname username
- delete user			: sudo userdel username
- delete user + directory	: sudo userdel -r username
- verifier les regle mdp	: chage -l username
- 

//	POLITIQUE DES MDP
PAM			= (Pluggable Authentication Module) est un gestionnaire de mdp sous linux;
libpam-pwquality	= module qui reforce la securiter des mdp et impose des regle;

command :
- install libpam-pwquality	= sudo apt-get install libpam-pwquality;
- ouvrir libpam-pwquality	= sudo vim /etc/pam.d/common-password;
- aff politique de mdp		= sudo chage -l
- modif politique de mdp	= sudo chage -m 2 -M 30 -w 7 antutsc



//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------



//	SCRIPT
command :
- execut le script	= sudo /usr/local/bin/monitoring.sh
- ajouter regle crontab	= sudo crontab -u root -e

utilisateurs connectés. Voici une explication ligne par ligne :

//#!/bin/bash
	exécute avec l'interpréteur Bash.

//arc=$(uname -a) :
    affiche des informations complètes sur le noyau, le nom de la machine, la version du système d'exploitation, etc.

//pcpu=$(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l) :
    donne le nombre de processeurs physiques (cœurs physiques) 

//vcpu=$(grep "^processor" /proc/cpuinfo | wc -l) :
    compte le nombre de processeurs virtuels (vCPU) 

//fram=$(free -m | awk '$1 == "Mem:" {print $2}') :
    récupère la mémoire totale disponible en mégaoctets (MB)

//uram=$(free -m | awk '$1 == "Mem:" {print $3}') :
    extrait la mémoire utilisée à partir de la sortie de la commande free

//pram=$(free | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}') :
    Calcule le pourcentage de mémoire utilisée en divisant la mémoire 

//fdisk=$(df -BG | grep '^/dev/' | grep -v '/boot$' | awk '{ft += $2} END {print ft}') :
y attention to the password chosen, it must follo    calcule la capacité totale des disques montés (GB) à partir de la sortie

//udisk=$(df -BM | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} END {print ut}') :
    calcule l'espace utilisé des disques (MB)

//pdisk=$(df -BM | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} {ft+= $2} END {printf("%d"), ut/ft*100}') :
    Calcule le pourcentage de disque utilisé divisant l'espace utilisé puis formate le résultat

//cpul=$(top -bn1 | grep '^%Cpu' | cut -c 9- | xargs | awk '{printf("%.1f%%"), $1 + $3}') :
    extrait l'utilisation CPU depuis top, en ajoutant les pourcentages de "user" et "system"

//lb=$(who -b | awk '$1 == "system" {print $3 " " $4}') :
    Affiche la date et l'heure du dernier démarrage du système

//lvmu=$(if [ $(lsblk | grep "lvm" | wc -l) -eq 0 ]; then echo no; else echo yes; fi) :
    Vérifie si des volumes logiques LVM sont présents sur le système en utilisant lsblk

//ctcp=$(ss -Ht state established | wc -l) :
    compte le nombre de connexions TCP et le stocke dans ctcp

//ulog=$(users | wc -w) :
    Compte le nombre d'utilisateurs actuellement connectés au système avec users

//ip=$(hostname -I) :
    récupère l'adresse IP du système et l'enregistre dans ip.

//mac=$(ip link show | grep "ether" | awk '{print $2}') :
    Extrait l'adresse MAC de l'interface réseau avec ip link show

//cmds=$(journalctl _COMM=sudo | grep COMMAND | wc -l) :
    Compte le nombre de commandes exécutées avec sudo 

//wall " ... " :
    Envoie un message à tous les utilisateurs connectés sur la machine en utilisant wall. 

En résumé, ce script génère un résumé des informations système (matériel, ressources, réseau, utilisateurs) et l'affiche à tous les utilisateurs connectés.


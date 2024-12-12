//	BORN2BEROOT

"	1. PARTIE INSTALLATION	"

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

//	CREER UN GROUPE
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

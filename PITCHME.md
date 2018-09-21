class: center, middle

![Logo ENSICAEN](figures/logo/ensicaen.svg)
# Outils de développement logiciel
_ .lightgray.italic[Alain Lebret (alain.lebret@ensicaen.fr)] _

<!-- ********************************************************************** -->
---
# A propos du cours
### Objectif
- Maîtriser un environnement et ses outils de développement logiciel

### Modalités
- Cours : 16 h / APP 12 h
- TP    : 22 h / APP 20 h

### Examens
2 notes : 
- TP (coef. 1)
- examen final (coef. 1)

<!-- ********************************************************************** -->
---
# Références

![The Linux command line](figures/a_propos/linux-shell.png)
![Linux](figures/a_propos/linux.png)
![GNU Emacs](figures/a_propos/emacs.png)

![GNU gdb](figures/a_propos/gdb.png)
![GNU make](figures/a_propos/make.png)

<!-- ********************************************************************** -->
---
# ODL dans la formation

![formation](figures/introduction/formation.png)

<!-- ********************************************************************** -->
---
# Contenu du cours
1. Introduction
2. Organisation des disques et commandes Unix/Linux
3. Édition
4. Compilation + bibliothèques statiques et dynamiques
5. Utilitaires de développement et mise au point
6. Langage de commande _shell_

<!-- ********************************************************************** -->
---
# Avant l'ordinateur
![The Linux command line](figures/introduction/machine.png)

<!-- ********************************************************************** -->
---
# Ordinateur
![The Linux command line](figures/introduction/ordinateur.png)

<!-- ********************************************************************** -->
---
# Architecture matérielle (_hardware_)
![The Linux command line](figures/introduction/architecture.png)

<!-- ********************************************************************** -->
---
# Architecture logicielle (_software_)
![The Linux command line](figures/introduction/OS.png)

<!-- ********************************************************************** -->
---
# Architecture logicielle (_software_)
![The Linux command line](figures/introduction/vueEnsembleUNIX.png)
 
<!-- ********************************************************************** -->
---
# Principaux environnements
![The Linux command line](figures/introduction/environnements.png)

<!-- ********************************************************************** -->
---
# Systèmes d'exploitation des développeurs
![The Linux command line](figures/introduction/os_devel_2016.png)
Source : stackoverflow.com, 2016

<!-- ********************************************************************** -->
---
# Systèmes à l'ENSICAEN
Machines sous Ms-Windows + Ubuntu
## Sites de référence
- Institutionnel : [https://www.ensicaen.fr](https://www.ensicaen.fr)
- Cours et TP : [http://foad.ensicaen.fr](http://foad.ensicaen.fr)

## Accès de l'utilisateur Jean Saigne
- Dossier perso : `/home/eleves/promo21/info/jsaigne`
- Espace Web : [http://www.ecole.ensicaen.fr/~jsaigne](http://www.ecole.ensicaen.fr/~jsaigne)
- Espace courrier : 
   - Courriel : jsaigne@ecole.ensicaen.fr ou jean.saigne@ecole.ensicaen.fr
   - Webmail : [https://zimbra.ensicaen.fr](https://zimbra.ensicaen.fr)       
- Accès distant SSH : [ssh://jsaigne@cybele.ecole.ensicaen.fr](ssh://jsaigne@cybele.ecole.ensicaen.fr)
  (clients Ms-Windows : Putty, MobaXterm, etc.)

<!-- ********************************************************************** -->
---
# Bureau Ubuntu
![The Linux command line](figures/introduction/bureau_ubuntu.png)

<!-- ********************************************************************** -->
---
# Accès distant Cybèle
![The Linux command line](figures/introduction/cybele.png)

<!-- ********************************************************************** -->
---
# Emacs sur Cybèle
![The Linux command line](figures/introduction/emacs_cybele.png)

<!-- ********************************************************************** -->
---
# Emacs sur Cybèle
[Chaîne de compilation](./sections/compilation.html)

<!-- ********************************************************************** -->
---
##  Étapes de compilation : *traduction*
### Rôle
Vérification de la syntaxe puis génération du code intermédiaire

### Outil sous-jacent 

- ``` cc1 ``` : **compilateur**

``` {frame="single"}
cc1 [options] fichier.i
```

### Options de *gcc*

- `-c` : compile uniquement sans étape d'édition des liens
- `-Wall` : avertissements
- `-Wextra` : avertissements 
- `-ansi` : vérifie le respect de la syntaxe ANSI
- `-pedantic` : + scrupuleux


```  {frame="single"}
gcc fichier.c -c
```

<!-- ********************************************************************** -->
---
## À propos des syntaxes (K&R, ANSI, C99)
```c
int foo(a, p)
int a,
char *p;
{
   /* ... */
   return 0;
}
```

```c
int foo(int a, char *p) {
   /* ... */
   return 0;
}
```

<!-- ********************************************************************** -->
---
## À propos des syntaxes (K&R, ANSI, C99)

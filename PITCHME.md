layout : center-right
logo : assets/images/logo.png
theme : night
theme-override : assets/css/PITCHME.css
highlight : ir-black
transition : none
published : true
charts : true
mathjax : TeX-AMS_HTML-full

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

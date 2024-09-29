# Syntaxe Markdown

## Titres

```default
# Un titre de niveau 1
## Un titre de niveau 2
### Un titre de niveau 3
#### Un titre de niveau 4
##### Un titre de niveau 5
###### Un titre de niveau 6
```

## Titre avec une ancre

```
## Un titre avec une ancre {#section3}
```
 
## Commentaires

```default
Un commentaire qui ne sera pas pris en compte par les visualiseurs :

	[//]: # (Un commentaire qui ne sera pas pris en compte par les visualiseurs)
```

## Mise en forme du texte

```
On peut mettre des mots en *italique*, en __gras__, en ***gras et italique***,
==surligner== du texte, ~~barrer~~ du texte, etc. 
```

Attention, tous les visualiseurs ne gèrent pas le surlignage et le texte barré.
 
## Liens

### Internet

```
[Site ENSICAEN](https://www.ensicaen.fr). 
```

### Vers une ancre

```
Allez voir la [section 3](#section3)
```

## Images

```
![La légende de mon image.](figures/image.png). 
```

## Code source

```
On peut insérer du code `mkdir ODL` dans le texte.
```

Ou le développer sur plusieurs lignes :

````````
```sh
$ tail -n5 fichier.txt | head -n2
```
````````

## Listes

### Listes à puces

```
- item 1 ;
- item 2 ;
- item 3.
```

### Listes numérotées

```
1. Item 1.
2. Item 2.
3. Item 3.
```

### Listes cochées

```
- [x] Cet item est coché
- [ ] Pas celui-là
- [ ] Ni celui-là
```

### Code dans une liste

Insérer des blocs de code dans des listes (on indentera le code de 4 ou 8 espaces ou de 1 ou 2 tabulations suivants les visualiseurs) :

```
- item 1 :

        int main() {
            return 0;
        }
- item 2 
- item 3
```
 
ou

```
1. item 1 :

		int main() {
		    return 0;
		}
2. item 2 
3. item 3
```

### Listes de définitions

```
Premier terme
: Ceci est la définition du premier terme.

Deuxième terme
: Ceci est la définition du deuxième terme.
: Ceci est une autre définition du deuxième terme.
```

## Tableaux 

### Tableau simple

```
| Colonne 1 | Colonne 2 |
| --------- | --------- |
| Cellule 1 | Cellule 2 |
| Cellule 1 | Cellule 2 |
```

### Tableau avec alignement

```
| Colonne à gauche  |  Colonne centrée  | Colonne à droite   | 
| :---------------  | :---------------: | -----------------: |
|     Cellule 1     |   Cellule 2       |   Cellule 3        |  
|     Cellule 1     |   Cellule 2       |   Cellule 4        |
```

## Note de bas de page

```
Voici une phrase avec une note de bas de page [^manote] en son sein.

	[^manote]: Ceci est la note de bas de page.
```

## Citation

```
> Voici une citation
> sur plusieurs 
> lignes
```

## Barre horizontale

```
----
```

Et tellement plus encore... 


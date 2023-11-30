/************************************************************************/
/*                          PROGRAMME CAVALIER                          */
/*                             Version  1.3                             */
/*                            A. Lebret 1992   L.I.E.                   */
/************************************************************************/
/* Reproduit les mouvements du Cavalier sur un Echiquier en passant une */
/* seule fois sur chaque case, et en effectuant la totalité de l'Echiquier */

#include <stdio.h>
#include <stdlib.h>

#define ANSI_CLRSCR \x1B[2J

/*----------------------------------------------------------------------*/
/*                  Déclaration Des Fonctions Utilisées                 */
/*----------------------------------------------------------------------*/

int mon_getch();
void affiche_echiquier();
void place_caval();
void tourne_autour_case(int, int, int);
void test_case_libre(int, int, int);
void choix_case();
void deplace_caval();

/*----------------------------------------------------------------------*/
/*                  Déclaration des Variables Globales                  */
/*----------------------------------------------------------------------*/

/* Tableau à deux dimensions représentant l'échiquier. Le tableau est */
/* surdimensionné pour éviter les coups hors de l'échiquier :         */
int echiquier[12][12];

/* Tableaux contenant les 8 possibilités d'échappement : */
int x_cases_fuites[9], y_cases_fuites[9], nb_cases_fuites[9];

/* Compteurs : */
int caval, compteur, compteur2;

/* Coordonnées sur l'échiquier */
int ligne, colonne;

/* Indicateur de case libre : 0 si libre et 1 sinon */
int case_de_fuite_existe;

/************************************************************************/
/*                        FONCTION PRINCIPALE                           */
/************************************************************************/
int main(void) {
    int i, j;
    char ch;

    /*---------------------------------*/
    /* Initialisation des paramètres : */
    /*---------------------------------*/

    /* Mise à 1 du tableau echiquier */
    for (i = 0; i <= 11; i++)
        for (j = 0; j <= 11; j++)
            echiquier[i][j] = 1;

    /* Mise à 0 des 64 cases interieures */
    for (i = 2; i <= 9; i++)
        for (j = 2; j <= 9; j++)
            echiquier[i][j] = 0;

    case_de_fuite_existe = 1;

    do {
        /*-------------------------------*/
        /*    Tracage de l'échiquier     */
        /*-------------------------------*/
        affiche_echiquier();

        /*------------------------------*/
        /* Positionnement du cavalier   */
        /*------------------------------*/
        caval = 1;
        printf("\x1B[21;15HEntrez les ligne et colonne de départ : ");
        scanf("%d %d", &ligne, &colonne);

        /*------------------------------*/
        /*   Deplacement du cavalier :  */
        /*------------------------------*/
        do {
            place_caval();
            deplace_caval();
            /* Teste s'il existe une case de fuite : */
            if (case_de_fuite_existe)
                choix_case();
            /* Attend la frappe d'une touche pour continuer : */
            ch = mon_getch(); /* anciennement getch() */
        } while (caval <= 64 && case_de_fuite_existe);
        /*------------------------------*/
        /*       Fin du programme       */
        /*------------------------------*/
        printf("\x1B[24;10HTapez q pour sortir : ");
        ch = getchar();
    } while (ch == 'q');
    return 0;
}

int mon_getch() {
    int c;
    system("stty cbreak -echo");
    c = getchar();
    system("stty cooked echo");
    return c;
}

/*----------------------------------------------------------------------*/
/*                    Fonction  Dessin de l'Echiquier                   */
/*----------------------------------------------------------------------*/
void affiche_echiquier() {
    printf("\x1B[2J"); /* séquence ANSI pour effacer l'écran */
    printf("\x1B[1;29HC A V A L I E R");
    printf("\x1B[3;19H0    1    2    3    4    5    6    7    ");
    printf("\x1B[4;15H  +---------------------------------------+ ");
    printf("\x1B[5;15H0 |    |    |    |    |    |    |    |    | ");
    printf("\x1B[6;15H  +---------------------------------------+ ");
    printf("\x1B[7;15H1 |    |    |    |    |    |    |    |    | ");
    printf("\x1B[8;15H  +---------------------------------------+ ");
    printf("\x1B[9;15H2 |    |    |    |    |    |    |    |    | ");
    printf("\x1B[10;15H  +---------------------------------------+ ");
    printf("\x1B[11;15H3 |    |    |    |    |    |    |    |    | ");
    printf("\x1B[12;15H  +---------------------------------------+ ");
    printf("\x1B[13;15H4 |    |    |    |    |    |    |    |    | ");
    printf("\x1B[14;15H  +---------------------------------------+ ");
    printf("\x1B[15;15H5 |    |    |    |    |    |    |    |    | ");
    printf("\x1B[16;15H  +---------------------------------------+ ");
    printf("\x1B[17;15H6 |    |    |    |    |    |    |    |    | ");
    printf("\x1B[18;15H  +---------------------------------------+ ");
    printf("\x1B[19;15H7 |    |    |    |    |    |    |    |    | ");
    printf("\x1B[20;15H  +---------------------------------------+ \n");
}

/*----------------------------------------------------------------------*/
/*       Fonction de Placement du Cavalier aux Coordonnées X, Y         */
/*----------------------------------------------------------------------*/
void place_caval() {
    int x, y;

    echiquier[ligne + 2][colonne + 2] = caval;

    /* Calcul des coordonnées écran et affichage */
    x = 19 + 5 * colonne;
    y = 5 + 2 * ligne;
    printf("\x1B[32m");  /* green color */
    printf("\x1B[%d;%dH%d", y, x, caval);
    caval += 1;
}

/*----------------------------------------------------------------------*/
/*                  Fonction de Déplacement du Cavalier                 */
/*----------------------------------------------------------------------*/
void deplace_caval() {
    int i, l1, c1;

    /* Vérification des 8 cases autour */
    tourne_autour_case(ligne, colonne, 1);

    /* Teste si des cases ont été trouvées libres */
    if (compteur != 0) {
        compteur2 = compteur;
        for (i = 1; i <= compteur2; i++) {
            c1 = x_cases_fuites[i];
            l1 = y_cases_fuites[i];
            /* Vérification des cases autour des 8 premières */
            tourne_autour_case(l1, c1, 2);
            nb_cases_fuites[i] = compteur;
        }
    } else
        case_de_fuite_existe = 0;
}

/*-----------------------------------------------------------------------*/
/*              Fonction de Déplacement autour d'une Case                */
/*-----------------------------------------------------------------------*/
/*   indic = 1 si c'est la premiçre recherche autour d'une case, et  */
/*   indic = 2 si c'est la recherche des cases de fuites au niveau 2 */

void tourne_autour_case(int l2, int c2, int indic) {
    int l, c;

    compteur = 0;
    case_de_fuite_existe = 1;

    /* Vérification des 8 cases autour */
    l = l2 - 1;
    c = c2 + 2;
    test_case_libre(l, c, indic);
    l = l2 - 2;
    c = c2 + 1;
    test_case_libre(l, c, indic);
    l = l2 - 2;
    c = c2 - 1;
    test_case_libre(l, c, indic);
    l = l2 - 1;
    c = c2 - 2;
    test_case_libre(l, c, indic);
    l = l2 + 1;
    c = c2 - 2;
    test_case_libre(l, c, indic);
    l = l2 + 2;
    c = c2 - 1;
    test_case_libre(l, c, indic);
    l = l2 + 2;
    c = c2 + 1;
    test_case_libre(l, c, indic);
    l = l2 + 1;
    c = c2 + 2;
    test_case_libre(l, c, indic);
}

/*----------------------------------------------------------------------*/
/*              Fonction Testant si la Case Visée est Libre             */
/*----------------------------------------------------------------------*/
void test_case_libre(int l, int c, int indic) {

    /* Teste si la case correspondante est libre. Les cases hors échiquier */
    /* valent 1 et ne sont donc pas prises en compte */
    if (echiquier[l + 2][c + 2] == 0) {
        /* Si oui on incrémente le compteur de cases */
        compteur += 1;

        /* Test si premier tour */
        if (indic == 1) {
            /* Si oui Entre les coordonnées de la case libre dans les
               tableaux correspondants */
            x_cases_fuites[compteur] = c;
            y_cases_fuites[compteur] = l;
        }
    }
}
/*----------------------------------------------------------------------*/
/*                Fonction de Choix de la Case Suivante                 */
/*----------------------------------------------------------------------*/
/* Le choix se fait dès la rencontre d'une case à fuites minimales */
void choix_case()

{
    int min, pos, i;

    /* Le nombre de cases de fuite est limité à 64
       dans le meilleur des cas */
    min = 64;
    pos = 0;

    /* Recherche des nombres de cases de fuite < 64
       et choix du premier trouvé */
    for (i = 1; i <= compteur2; i++) {
        if (nb_cases_fuites[i] < min) {
            min = nb_cases_fuites[i];
            pos = i;
        }
        /* Prise des coordonnées dans les tableaux, correspondant
           au premier nombre de cases de fuite minimal trouvé. */
        ligne = y_cases_fuites[pos];
        colonne = x_cases_fuites[pos];
    }
}

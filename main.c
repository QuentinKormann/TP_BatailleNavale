#include <stdio.h>
#include <stdlib.h>

#define MAXBATTEAU 2
#define TAILLE 10


typedef struct Cellule
{
    int ligne;
    int collone;
}Cellule;

typedef struct Bateau
{
    Cellule tabBateau[MAXBATTEAU];
}Bateau;

typedef struct Flotte
{
    Bateau tabFlotte[3];
}Flotte;

typedef enum RETOUR
{
    VRAI,FAUX
}RETOUR;

Cellule CreateCellule(int ligne,int collone,Bateau repBateau);
RETOUR Comparaison(Cellule test,Bateau repBateau);
void CreateBateau(Flotte repFlotte);
void VerifBateau(Cellule Tir,Bateau repBateau);
RETOUR VerifFlotte(Flotte repFlotte);

int main()
{
    int joueur=1;

    Flotte repFlotte;
    Cellule Tir;

    CreateBateau(repFlotte);

    while(VerifFlotte(repFlotte))
    {
        if(joueur == 1)
        {
            printf("J1 a vous de tirez!\n\n");

            printf("Ligne: ");
            scanf("%d",&Tir.ligne);
            fflush(stdin);

            printf("Collone: ");
            scanf("%d",&Tir.collone);
            fflush(stdin);
            printf("\n");

            VerifBateau(Tir,repFlotte.tabFlotte[2]);
            joueur = 2;
        }

        else
        {
            printf("J2 a vous de tirez!\n\n");

            printf("Ligne: ");
            scanf("%d",&Tir.ligne);
            fflush(stdin);

            printf("Collone: ");
            scanf("%d",&Tir.collone);
            fflush(stdin);
            printf("\n");

            VerifBateau(Tir,repFlotte.tabFlotte[1]);
            joueur = 1;
        }
    }

    printf("FIN DE PARTIE!");

    return 0;
}



Cellule CreateCellule(int ligne,int collone,Bateau repBateau)
{
    Cellule result;
    result.collone=collone;
    result.ligne=ligne;

    while(Comparaison(result, repBateau))
    {

        printf("ERREUR!\n");
        printf("Ligne: ");
        scanf("%d",&ligne);
        fflush(stdin);

        printf("Collone: ");
        scanf("%d",&collone);
        fflush(stdin);
        printf("\n");

        while(ligne<0 || ligne>11 || collone<0 || collone>11)
        {
            printf("ERREUR!\n");
            printf("Ligne: ");
            scanf("%d",&ligne);
            fflush(stdin);

            printf("Collone: ");
            scanf("%d",&collone);
            fflush(stdin);
            printf("\n");
        }

        result.collone=collone;
        result.ligne=ligne;
    }

    return result;
}

RETOUR Comparaison(Cellule test,Bateau repBateau)
{
    int i;

    for(i=1;i<=MAXBATTEAU;i++)
    {
        if(test.collone == repBateau.tabBateau[i].collone && test.ligne == repBateau.tabBateau[i].ligne)
        {
            return FAUX;
        }
    }

    return VRAI;
}

void CreateBateau(Flotte repFlotte)
{
    int ligne;
    int collone;
    int i;
    int j;

    for(j=1;j<=2;j++)
    {
        printf("J%d placez vos Bateaux:\n\n",j);

        for(i=0;i<MAXBATTEAU;i++)
        {
            while(ligne<0 || ligne>11 || collone<0 || collone>11)
            {
                printf("Bateau N%d:\n",i);
                printf("Ligne: ");
                scanf("%d",&ligne);
                fflush(stdin);

                printf("Collone: ");
                scanf("%d",&collone);
                fflush(stdin);
                printf("\n");

                //printf("%d %d",ligne,collone);
            }
            repFlotte.tabFlotte[j].tabBateau[i] = CreateCellule(ligne,collone,repFlotte.tabFlotte[j]);
            collone=42;
        }
        system("cls");
    }
}

void VerifBateau(Cellule Tir,Bateau repBateau)
{
    int i=1;
    if(Comparaison(Tir,repBateau))
    {
        printf("TOUCHE!");

        while(!(repBateau.tabBateau[i].collone == Tir.collone) && !(repBateau.tabBateau[i].ligne == Tir.ligne))
        {
            i++;
        }

        repBateau.tabBateau[i].collone = 0;
        repBateau.tabBateau[i].ligne = 0;
    }

    else
    {
        printf("LOUPE!");
    }

    system("pause");
    system("cls");
}

RETOUR VerifFlotte(Flotte repFlotte)
{
    int i;
    int j;

    for(j=1;j<=2;j++)
    {
        for(i=0;i<MAXBATTEAU;i++)
        {
            if(repFlotte.tabFlotte[j].tabBateau[i].collone != 0)
            {
                return FAUX;
            }
        }
    }

    return VRAI;
}

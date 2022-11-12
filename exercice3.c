#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

// ************************************
// definition des types : liste chainee 
// ************************************
typedef struct _Tcell
{
	int nb; // un entier
	struct _Tcell * suivant; // pointeur vers la cellule suivante
} Tcell;

typedef struct _TListe
{
	Tcell * debut; // pointeur vers la première case de la cellule
} TListe;

// **************************
//  prototypes des fonctions
// **************************
int saisir_entre(int min, int max);
void creerListeEntier(TListe * liste);
void libererListeEntier(TListe * liste);
void afficherListeEntier(TListe liste);
void rechercheEntierListe(TListe liste, int i, bool * trouver);
void supprimerListeEntier(TListe * liste, int i);
void ajout_fin(TListe * liste, int i);
void affichageMenu(TListe liste);

// **********************
//  programme principal
// **********************
int main ()
{
	TListe liste;
	liste.debut = NULL;
    printf("Pour commencer, nous allons creer une liste d'entier\n");
    creerListeEntier(&liste);
    afficherListeEntier(liste);
    
    affichageMenu(liste);

	return 0;
}

// procédure pour créer la liste d'entiers
void creerListeEntier (TListe * liste)
{
	Tcell * newCell; // pointeur vers la nouvelle cellule
	Tcell * aux; // pointeur sur la dernière cellule de la liste
	int n;
	do
	{
		// création de la nouvelle cellule
		newCell = (Tcell*) malloc(sizeof(Tcell)); //(Tcell*) => permet de dire que c'est un pointeur vers une Tcell, permet d'éviter des erreurs
		(*newCell).nb = saisir_entre(1,100);
		(*newCell).suivant = NULL;
		
		if ((*liste).debut == NULL)
		{	// la liste est vide - ajout du premier élément
			(*liste).debut = newCell;
			aux = (*liste).debut;
		}
		else
		{
			// la liste n'est pas vide - ajout après la dernière cellule
			(*aux).suivant = newCell;
			aux = newCell;
		}
		
		// on demande à l'utilisateur s'il veut entrer une nouvelle valeur
		do 
		{ 	printf("Continuer ? 0 ou 1 \n");
			scanf("%d",&n);
		} while ((n != 1) && (n != 0));
	} while (n == 1);
}

// procédure pour afficher une liste d'entiers
void afficherListeEntier (TListe liste)
{
	Tcell * aux;

    aux = liste.debut;
    if (liste.debut==NULL)
    {
        printf("Liste vide");
    }
    else
    {
        printf("Voici la liste : \n");
        while (aux!=NULL)
        {
            printf("%d\n", (*aux).nb);
            aux=(*aux).suivant;
        }
        
    }    
}

// procédure pour libérer une liste d'entiers
void libererListeEntier (TListe * liste)
{
	Tcell * aux;
	while ((*liste).debut != NULL)
	{	aux = (*((*liste).debut)).suivant;
		free((*liste).debut);
		(*liste).debut = aux;
	
	}
}

// procédure pour supprimer un entier i de la liste
void supprimerListeEntier (TListe * liste , int i)
{
	Tcell *aux;
    Tcell *prec;

    aux=(*liste).debut;
    prec=aux;

    while (aux!=NULL)
    {
        if ((*aux).nb=i)
        {
            if (aux==(*liste).debut)
            {
                (*liste).debut=(*aux).suivant;
            }
            else
            {
                (*prec).suivant=(*aux).suivant;
            }
            free(aux);
        }
        prec=aux;
        aux=(*aux).suivant;
    }
}

// fonction pour saisir un nombre entre min et max
int saisir_entre(int min, int max)
{
    int nb =  0; 
    do
    {
        printf("Donner un nombre entre %d et %d \n", min, max);
        scanf("%d", &nb);
    } while (nb<min || nb>max);

    return nb;
}

// procédure pour rechercher un entier i dans la liste 
void rechercheEntierListe(TListe liste, int i, bool * trouver)
{
	Tcell *aux;

    aux=liste.debut;
    (*trouver)=false; 

    while (!(*trouver) && aux!= NULL)
    {
        if((*aux).nb==i)
        {
            printf("Le nombre %d a ete trouve\n", i);
            *trouver=true;
        }
        else
        {
            aux=(*aux).suivant;
        }
        
    }

    if (aux==NULL)
    {
        printf("Dommage, le nombre n'a pas ete trouve.\n");
    }
    
    
    
}

// procédure pour ajouter un élément à la fin de la liste
void ajout_fin(TListe * liste, int i)
{
	Tcell * newCell; // pointeur vers la nouvelle cellule
	Tcell * aux = (*liste).debut; // pointeur sur la dernière cellule de la liste
	Tcell * prec = (*liste).debut; 

	while(aux != NULL)
	{
		prec = aux;
		aux =(*aux).suivant;
	}	
		
	newCell = (Tcell*) malloc(sizeof(Tcell));
	(*newCell).nb = i;
	(*newCell).suivant = NULL;

	if (prec == NULL)
	{
			(*liste).debut = newCell;
	}
	else
	{
			(*prec).suivant = newCell;	
	}
}
// procédure pour ajouter un élément à la liste de façon triée
void ajout_trie(TListe * liste, int i)
{
	Tcell * newCell; // pointeur vers la nouvelle cellule
	Tcell * aux = (*liste).debut; // pointeur sur la dernière cellule de la liste
	Tcell * prec = (*liste).debut; 

	while(aux != NULL)
	{
		if ((*aux).nb==i)
		{
			prec = aux;
			aux =(*aux).suivant;
		}
		
		
	}	
		
	newCell = (Tcell*) malloc(sizeof(Tcell));
	(*newCell).nb = i;
	(*newCell).suivant = NULL;

	if (prec == NULL)
	{
			(*liste).debut = newCell;
	}
	else
	{
			(*prec).suivant = newCell;	
	}

}
//Procédure qui gère l'affichage du menu ainsi que le menu 

void affichageMenu(TListe liste)
{
    int choix;
    int nombre;
    bool trouver;
    int continuer;
    int poursuivre;

    do
    {
        do
        {
            printf("Que souhaitez-vous faire maintenant ? \n"); 
            printf("1 : Ajouter un entier a la fin de la liste \n");
            printf("2 : Rechercher si un entier est present dans la liste \n");
            printf("3 : Afficher les entiers de la liste \n");
            printf("4 : Supprimer un entier de la liste\n"); 
            printf("5 : Faire un ajout trie dans la liste\n");
            printf("6 : Quitter\n");
            scanf("%d", &choix);
        } while (choix<1 || choix>6);

        switch (choix)
        {
        case 1:
            printf("Vous avez choisi d'ajouter un entier en fin de liste \n");
            printf("Quel nombre voulez-vous ajouter ? \n");
            scanf("%d\n", saisir_entre(1,100));
            ajout_fin(&liste, nombre);
            printf("Voici la liste : \n");
            afficherListeEntier(liste);
            printf("L'ajout s'est bien passe\n");
            do
            {
                printf("Voulez-vous ajouter un nouveau nombre ? (oui = 1, non =0)\n");
                
                scanf("%d", continuer);
                if (continuer!=1 || continuer !=0)
                {
                    printf("Le nombre saisi est différent de 1 ou de 0.\n");
                }
                
                
                
            }while (continuer!=1|| continuer!=0);
            
            
            while (continuer=1)
            {
                ajout_fin(&liste, nombre);
                printf("L'ajout s'est bien passe\n");
            }
            
            break;
        
        case 2: 
            printf("Vous avez choisi de rechercher un entier dans la liste\n");
            printf("Quel nombre voulez-vous rechercher ? \n");
            scanf("%d", &nombre);
            rechercheEntierListe(liste, nombre, &trouver);
            break;

        case 3: 
            printf("Vous avez choisi d'afficher les entiers de la liste \n");
            printf("Voici la liste : \n");
            afficherListeEntier(liste);
            break;

        case 4:
            printf("Vous avez choisi de supprimer un entier de la liste\n");
            printf("Quel nombre voulez-vous supprimer ? \n");
            scanf("%d", &nombre);
            rechercheEntierListe(liste, nombre, &trouver);
            if (trouver)
            {
                supprimerListeEntier(&liste, nombre);
                printf("Le nombre a bien ete supprime\n");
            }
            else
            {
                printf("Nous ne pouvons donc pas supprimer ce nombre. \n");
            }
            break;

        case 5:
            printf("Vous avez choisi d'ajouter un entier en fin de liste \n");
            printf("Quel nombre voulez-vous ajouter ? \n");
            scanf("%d\n", saisir_entre(1,100));
            ajout_trie(&liste, nombre);
            printf("Voici la liste : \n");
            afficherListeEntier(liste);
            printf("L'ajout s'est bien passe\n");
            do
            {
                printf("Voulez-vous ajouter un nouveau nombre ? (oui = 1, non =0)\n");
                
                scanf("%d", continuer);
                if (continuer!=1 || continuer !=0)
                {
                    printf("Le nombre saisi est différent de 1 ou de 0.\n");
                }
            }while (continuer!=1);
            
            
            while (continuer=1)
            {
                ajout_fin(&liste, nombre);
                printf("L'ajout s'est bien passe\n");
            }
            
            break; 
            

        case 6: 
            printf("Merci d'avoir utilise l'application.\nAu revoir !\n");
            break;
        }

        printf("Souhaitez-vous realiser une nouvelle action ? \noui : 1 non : 0\n");
        scanf("%d", &poursuivre);
    }while (poursuivre==1);
    
}


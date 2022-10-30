#include<stdio.h>
#include<stdbool.h>
#include <time.h>
#include <string.h> //Chaîne de caractère
#include <stdlib.h>

int saisir_entre(int min, int max);
    
int main()
{
    /*
    PARTIE 1 
    int * age = NULL;
    
    age = malloc(sizeof(int));
    *age=saisir_entre(0, 120);
    printf("Votre age est %d. \n", *age);
    printf("Cette information est stockee a cette adresse : %d. \n", &age);
    free(age);
    
    PARTIE 2 :*/

    int * age1;
    char prenom1[30];
    int * age2;
    char prenom2[30];

    printf("Quel est votre prenom ?\n");
    scanf("%s", &prenom1);
    age1 = malloc(sizeof(int));
    *age1=saisir_entre(0, 120);
    // printf("Votre age est %d. \n", *age1);
    
    
    
    printf("Quel est votre prenom ?\n");
    scanf("%s", &prenom2);
    age2 = malloc(sizeof(int));
    *age2=saisir_entre(0, 120);
    // printf("Votre age est %d. \n", *age2);

    
    

    printf("La premiere personne s'appelle %s et a %d ans. \n", prenom1, *age1);
    printf("La deuxieme personne s'appelle %s et a %d ans \n", prenom2, *age2);

    if (*age1>*age2)
    {
        printf("%s est plus vieux/vielle que %s. \n", prenom1, prenom2);
    }
    else
    {
        if (*age2>*age1)
        {
            printf("%s est plus vieux/vielle que %s. \n", prenom2, prenom1);
        }
        else
        {
            printf("Vous avez le meme age.\n");
        }
    }

    if (strcmp(prenom1, prenom2)<0)
    {
        printf("%s est avant %s dans l'ordre alphabetique. \n", prenom1, prenom2);
    }
    else
    {
        if (strcmp(prenom1, prenom2)==0)
        {
            printf("Le prenom est identique");
        }
        else
        {
            printf("%s est avant %s dans l'ordre alphabetique. \n", prenom2, prenom1);
        }
        
        
    }
    
    

    free(age1);
    free(age2);
    return 0;
}

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
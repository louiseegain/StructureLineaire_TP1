#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inversePassageValeur(int  a, int b);
void inversePassageAdresse(int * a, int * b);
int saisir_entre(int min, int max); 

int main()
{
    int a; 
    int b; 

    printf("Donner la valeur de a : \n");
    a=saisir_entre(1, 100);
    printf("Donnez la valeur de b : \n");
    b=saisir_entre(1, 100);
    printf("Valeurs initiales : \n A = %d, B = %d \n", a, b);
    inversePassageValeur(a, b);
    printf("Valeur apres passage par valeur : \n A = %d, B = %d \n", a, b);
    inversePassageAdresse(&a, &b);
    printf("Valeur apres passage par adresse : \n A = %d, B = %d \n", a, b);
    return 0;
}
    
void inversePassageValeur(int  a, int b)
{
    //Lexique
    int c;

    //Corps de l'algorithme
    c=b;
    b=a;
    a=c;

    // printf("%d, %d", a, b);
}

void inversePassageAdresse(int * a, int * b)
{
    //Lexique
    int c; 

    //début
    c=*b;
    *b=*a;
    *a=c;
    // printf("%d, %d", a, b);
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
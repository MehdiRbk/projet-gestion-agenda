//
// Created by MehdiRbk on 10/12/2023.
//

#include "schedule.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "level_list.h"
#include "timer.h"

char* scanString(void){
    int lenght = 0; //taille logique du tableau
    int max = 100; //taille physique du tableau
    char c;
    char* tab = malloc(max * sizeof(char));

    if (tab == NULL) // on vérifie que le malloc à bien marcher
    {
        printf("Memory allocation error !\\n");
        return NULL;
    }

    while((c = getchar()) != '\n'){ //Tant que le caractère n'est pas un retour à la ligne (touche entrée) on continue
        if(lenght == max){ //On vérifie que la taille physique n'est pas atteinte
            printf("Out of range !\n");
            return tab;
        }
        tab[lenght++] = c;
    }

    tab[lenght++]= '\0';
    tab = realloc(tab,lenght*sizeof(char));

    if (tab == NULL) //On vérifie que le realloc a bien marché
    {
        printf("Memory reallocation error !\n");
        return NULL;
    }
    return tab;
}

t_contact* createContact(){
    t_contact * newcontact = malloc(sizeof(t_contact));
    printf("Entrez le prénom et nom du contact en format 'Prénom Nom' : ");
    newcontact->surname_name = scanString();
    return newcontact;
}
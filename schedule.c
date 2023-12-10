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


void displayContact(t_contact contact){
    printf("Contact : %s", contact.surname_name);
}



t_date createDate(){
    t_date date;
    int day, month, year;
    do {
        printf("\nEntrez l'annee du rendez-vous (2024 , 2025 , ...) : ");
        year =;
    }while(year<0);
    do {
        printf("\nEntrez le mois du rendez-vous (1 , 2 , ...) : ");
        month=;
    }while(month<1 || month>12);
    do {
        printf("\nEntrez le jour du rendez-vous (1 , 2 , ...) : ");
        day=;
    }while((day<1) || (day>31) || ((year%4==0) && (day>29) && (month==2)) || ((year%4!=0) && (day>28) && (month==2)));
    date.year=year;
    date.month=month;
    date.day=day;
    return date;
}



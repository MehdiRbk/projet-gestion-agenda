//
// Created by MehdiRbk on 10/12/2023.
//

#include "time.h"
#include <stdio.h>

t_date insertDate(){ //Demande à l'utilisateur d'entrer une date valide
    t_date date;
    do {
        printf("Entrez l'annee du rendez-vous: \n");
        scanf("%d",&date.year);
    }while(date.year<2023);
    do {
        printf("Entrez le mois du rendez-vous: \n");
        scanf("%d",&date.month);
    }while(date.month<1 || date.month>12);
    do {
        printf("Entrez le jour du rendez-vous  : \n");
        scanf("%d",&date.day);
    }while((date.day<1) || (date.day>31) || ((date.year%4==0) && (date.day>29) && (date.month==2)) || ((date.year%4!=0) && (date.day>28) && (date.month==2)));
    return date;
}

t_hour insertHour(){ //Demande à l'utilisateur d'entrer une heure valide
    t_hour hour;
    do{
        printf("Entrez l'heure: \n");
        scanf("%d",&hour.hour);
    }while(hour.hour < 0 || hour.hour > 24);
    do{
        printf("Entrez les minutes: \n");
        scanf("%d",&hour.minute);
    }while(hour.minute < 0 || hour.minute > 60);
    return hour;
}

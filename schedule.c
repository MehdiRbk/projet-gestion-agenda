//
// Created by MehdiRbk on 10/12/2023.
//

#include "schedule.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "level_list.h"
#include "timer.h"

char* scanString(void){ //Permet de renvoyer un tableau de caractère de la taille exact de la phrase entrer
    int lenght = 0; //taille logique du tableau
    int max = 100; //taille physique du tableau
    char c;
    char* tab = malloc(max * sizeof(char));

    if (tab == NULL) // on vérifie que le malloc à bien marcher
    {
        printf("Erreur d'allocation de mémoire !\\n");
        return NULL;
    }

    while((c = getchar()) != '\n'){ //Tant que le caractère n'est pas un retour à la ligne (touche entrée) on continue
        if(lenght == max){ //On vérifie que la taille physique n'est pas atteinte
            printf("Trop de caractère !\n");
            return tab;
        }
        tab[lenght++] = c;
    }

    tab[lenght++]= '\0';
    tab = realloc(tab,lenght*sizeof(char));

    if (tab == NULL) //On vérifie que le realloc a bien marché
    {
        printf("Erreur de réallocation de mémoire!\n");
        return NULL;
    }
    return tab;
}

t_contact createContact(){ // Créer et renvoie un contact en demandant le prénom et le nom
    t_contact  newcontact;
    printf("Entrez le prénom et nom du contact en format 'Prénom Nom' : ");
    newcontact.surname_name = scanString();
    return newcontact;
}


void displayContactAppointment(t_contact_schedule contactSchedule){ //Affiche tous les rendez-vous d'un contact
    t_appointment_cell * temp = contactSchedule.appointment->head;
    int i = 1;
    while(temp != NULL){
        printf("Rendez vous %d :\n Date : %d/%d/%d \n",i++,temp->appointment.date_appointment.day,temp->appointment.date_appointment.month,temp->appointment.date_appointment.year);
        printf("Heure de début : %d h %d \n",temp->appointment.hour_appointment.hour,temp->appointment.hour_appointment.minute);
        printf("Durée : %d h %d \n",temp->appointment.duration.hour,temp->appointment.duration.minute);
        printf("Objet : %s \n", temp->appointment.object);
        temp = temp->next;
    }
}

t_date insertDate(){ //Demande à l'utilisateur d'entrer une date valide
    t_date date;
    do {
        printf("\nEntrez l'annee du rendez-vous (2024 , 2025 , ...) : ");
        scanf("%d",&date.year);
    }while(date.year<2023);
    do {
        printf("\nEntrez le mois du rendez-vous (1 , 2 , ...) : ");
        scanf("%d",&date.month);
    }while(date.month<1 || date.month>12);
    do {
        printf("\nEntrez le jour du rendez-vous (1 , 2 , ...) : ");
        scanf("%d",&date.day);
    }while((date.day<1) || (date.day>31) || ((date.year%4==0) && (date.day>29) && (date.month==2)) || ((date.year%4!=0) && (date.day>28) && (date.month==2)));
    return date;
}

t_hour insertHour(){ //Demande à l'utilisateur d'entrer une heure valide
    t_hour hour;
    do{
        printf("\nEntrez l'heure du rendez-vous (1 , 2 , ...) : ");
        scanf("%d",&hour.hour);
    }while(hour.hour < 0 || hour.hour > 24);
    do{
        printf("\nEntrez les minutes du rendez-vous (1 , 2 , ...) : ");
        scanf("%d",&hour.minute);
    }while(hour.minute < 0 || hour.minute > 60);
    return hour;
}

t_appointment createAppointment() //Créer et renvoie un rendez-vous
{
    t_appointment newAppointment;
    newAppointment.date_appointment=insertDate();
    newAppointment.hour_appointment=insertHour();
    newAppointment.duration=insertHour();
    printf("Insérer l'objet du rendez-vous :");
    newAppointment.object = scanString();
    return newAppointment;
}

t_contact_schedule* createContactSchedule() //Créer et l'agenda propre d'un même contact avec la liste de ces rendez-vous
{
    t_contact_schedule* newContactSchedule = malloc(sizeof(t_contact_schedule));
    newContactSchedule->contact = createContact();
    newContactSchedule->appointment = malloc(sizeof(t_appointment_list));
    newContactSchedule->appointment->head=NULL;
    return newContactSchedule;
}

t_appointment_cell* createAppointmentCell(){ //Créer une cellule d'une liste de rendez-vous
    t_appointment_cell* newAppointmentCell = malloc(sizeof(t_appointment_cell));
    newAppointmentCell->appointment = createAppointment();
    newAppointmentCell->next = NULL;
}

void insertNewAppointmentforContact(t_contact_schedule* contactSchedule) //Permet d'insérer un rendez-vous dans un agenda d'un contact
{
    t_appointment_cell *newAppointmentCell = createAppointmentCell();
    if (contactSchedule->appointment->head == NULL) {
        contactSchedule->appointment->head = newAppointmentCell;
    } else {
        t_appointment_cell *lastAppointmentCell = contactSchedule->appointment->head;
        while (lastAppointmentCell->next != NULL) {
            lastAppointmentCell = lastAppointmentCell->next;
        }
        lastAppointmentCell->next = newAppointmentCell;
    }
}

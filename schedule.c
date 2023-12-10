//
// Created by MehdiRbk on 10/12/2023.
//

#include "schedule.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>


char* scanString(void){ //Permet de renvoyer un tableau de caractère de la taille exact de la phrase entrer
    int lenght = 0; //taille logique du tableau
    int max = 100; //taille physique du tableau
    char c;
    char* tab = malloc(max * sizeof(char));

    if (tab == NULL) // on vérifie que le malloc à bien marcher
    {
        printf("Erreur d'allocation de memoire !\\n");
        return NULL;
    }

    while((c = getchar()) != '\n'){ //Tant que le caractère n'est pas un retour à la ligne (touche entrée) on continue
        if(lenght == max){ //On vérifie que la taille physique n'est pas atteinte
            printf("Trop de caractere !\n");
            return tab;
        }
        tab[lenght++] = c;
    }

    tab[lenght++]= '\0';
    tab = realloc(tab,lenght*sizeof(char));

    if (tab == NULL) //On vérifie que le realloc a bien marché
    {
        printf("Erreur de reallocation de memoire!\n");
        return NULL;
    }
    return tab;
}

t_contact createContact(){ // Créer et renvoie un contact en demandant le prénom et le nom
    t_contact  newcontact;
    printf("Entrez le prenom et nom du contact en format 'Prenom Nom' : ");
    newcontact.surname_name = scanString();
    return newcontact;
}


void displayContactAppointment(t_contact_schedule contactSchedule){ //Affiche tous les rendez-vous d'un contact
    t_appointment_cell * temp = contactSchedule.appointment->head;
    int i = 1;
    printf("Rendez-vous de %s\n\n",contactSchedule.contact.surname_name);
    while(temp != NULL){
        printf("Rendez vous %d :\nDate : %d/%d/%d \n",i++,temp->appointment.date_appointment.day,temp->appointment.date_appointment.month,temp->appointment.date_appointment.year);
        printf("Heure de debut : %d h %d \n",temp->appointment.hour_appointment.hour,temp->appointment.hour_appointment.minute);
        printf("Duree : %d h %d \n",temp->appointment.duration.hour,temp->appointment.duration.minute);
        printf("Objet : %s \n\n", temp->appointment.object);
        temp = temp->next;
    }
}

t_appointment createAppointment() //Créer et renvoie un rendez-vous
{
    t_appointment newAppointment;
    printf("Veuillez inserer l'objet du rendez-vous :\n");
    newAppointment.object = scanString();
    newAppointment.date_appointment=insertDate();
    printf("Veuillez inserer l'heure du rendez-vous :\n");
    newAppointment.hour_appointment=insertHour();
    printf("Veuillez inserer la durée du rendez-vous :\n");
    newAppointment.duration=insertHour();
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

void insertNewAppointmentforContact(t_contact_schedule* contactSchedule) //Permet d'insérer un rendez-vous dans un agenda d'un contact comme une liste chaîné simple une insertion en queue
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

t_schedule_cell * createScheduleCell(int nbr_level, t_contact_schedule contactSchedule)
{
    t_schedule_cell* newScheduleCell = malloc(sizeof(t_schedule_cell));
    newScheduleCell->level = nbr_level;
    *(newScheduleCell)->next = malloc(nbr_level*sizeof(t_schedule_cell*));
    newScheduleCell->contactSchedule = contactSchedule;
    newScheduleCell->pseudo = createPseudo(contactSchedule.contact.surname_name);
    return newScheduleCell;
}


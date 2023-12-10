//
// Created by MehdiRbk on 10/12/2023.
//

#ifndef PROJET2_GESTION_AGENDA_SCHEDULE_H
#define PROJET2_GESTION_AGENDA_SCHEDULE_H
#include "level_list.h"

typedef struct s_date {
    int day;
    int month;
    int year;
}t_date;

typedef struct s_hour{
    int hour;
    int minute;
}t_hour;

typedef struct s_contact{
    char* surname;
    char* name;
}t_contact;

typedef struct s_appointment{
    t_date date_appointment;
    t_hour hour_appointment;
    t_hour duration;
    char* object;
}t_appointment;

typedef struct s_appointment_cell{
    t_appointment appointment;
    struct s_appointment_list* next[];
}t_appointment_cell;

typedef struct s_appointment_list{
    t_level_cell* head;
}t_appointment_list;

typedef struct s_schedule {
    t_contact contact;
    t_appointment_list *appointment;
}t_schedule;

char *scanString(void);
void display_appointment();
t_contact* creerContact();
#endif //PROJET2_GESTION_AGENDA_SCHEDULE_H

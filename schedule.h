//
// Created by MehdiRbk on 10/12/2023.
//

#ifndef PROJET2_GESTION_AGENDA_SCHEDULE_H
#define PROJET2_GESTION_AGENDA_SCHEDULE_H
#include "time.h"

typedef struct s_contact{
    char* surname_name;
}t_contact;

typedef struct s_appointment{
    t_date date_appointment;
    t_hour hour_appointment;
    t_hour duration;
    char* object;
}t_appointment;

typedef struct s_appointment_cell{
    t_appointment appointment;
    struct s_appointment_cell* next;
}t_appointment_cell;

typedef struct s_appointment_list{
    t_appointment_cell * head;
}t_appointment_list;

typedef struct s_contact_schedule {
    t_contact contact;
    t_appointment_list * appointment;
}t_contact_schedule;

typedef struct s_schedule_cell{
    char* pseudo;
    int level;
    t_contact_schedule contactSchedule;
    struct s_schedule_cell* next[];
}t_schedule_cell;

typedef struct s_schedule_list{
    t_schedule_cell* head;
    int max_level;
}t_schedule_list;

char * scanString(void);
t_contact createContact();
void displayContactAppointment(t_contact_schedule);

char* createPseudo(char *);
void deleteAppointment(t_contact_schedule* contactSchedule,int nbrAppointment);
t_appointment createAppointment();
t_contact_schedule* createContactSchedule();
t_appointment_cell* createAppointmentCell();
void insertNewAppointmentforContact(t_contact_schedule* contactSchedule);
t_schedule_cell * createScheduleCell(int level, t_contact_schedule contactSchedule);
void InsertOrderSchedule(t_schedule_list myScheduleList);
#endif //PROJET2_GESTION_AGENDA_SCHEDULE_H
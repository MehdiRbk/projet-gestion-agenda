//
// Created by MehdiRbk on 10/12/2023.
//

#ifndef PROJET2_GESTION_AGENDA_TIME_H
#define PROJET2_GESTION_AGENDA_TIME_H

typedef struct s_date {
    int day;
    int month;
    int year;
}t_date;

typedef struct s_hour{
    int hour;
    int minute;
}t_hour;

t_date insertDate();
t_hour insertHour();

#endif //PROJET2_GESTION_AGENDA_TIME_H

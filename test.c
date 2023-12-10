//
// Created by MehdiRbk on 10/12/2023.
//

#include "test.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "level_list.h"
#include "timer.h"
#import "schedule.h"

void testpart1and2(){
    t_level_list MyLevelList = createLevelList(5);
    displayLevelList(MyLevelList);

    addHeadLevelList(&MyLevelList,createLevelCell(18,3));
    displayLevelList(MyLevelList);

    addHeadLevelList(&MyLevelList,createLevelCell(12,4));
    displayLevelList(MyLevelList);

    addHeadLevelList(&MyLevelList,createLevelCell(19,1));
    displayLevelList(MyLevelList);

    addHeadLevelList(&MyLevelList,createLevelCell(90,8));
    displayLevelList(MyLevelList);


    //Ajout en ordre croissant
    t_level_list MyLevelList2 = createLevelList(8);
    displayLevelList(MyLevelList2);
    addOrderLevelList(&MyLevelList2,createLevelCell(20,5));
    displayLevelList(MyLevelList2);

    addOrderLevelList(&MyLevelList2,createLevelCell(35,2));
    displayLevelList(MyLevelList2);

    addOrderLevelList(&MyLevelList2,createLevelCell(10,3));
    displayLevelList(MyLevelList2);

    addOrderLevelList(&MyLevelList2, createLevelCell(25,1));
    displayLevelList(MyLevelList2);

    addOrderLevelList(&MyLevelList2,createLevelCell(59,9));
    displayLevelList(MyLevelList2);

    addOrderLevelList(&MyLevelList2,createLevelCell(1,8));
    displayLevelList(MyLevelList2);


    t_level_list MyLevelList2N = createSorted2NLevelList(4);
    displayLevelList(MyLevelList2N);
    p_level_cell find= searchValInFirstLevel(MyLevelList2N,1);
    if( find !=NULL)
    {
        printf("FIND");
    }
    else
        printf("NOT FIND");

    //code pour calculer le temps de chaque recherche.
    int random_value,max;
    p_level_cell findcell;
    FILE *log_file = fopen("log.txt","w");
    char format[] = "%d\t%s\t%s\n" ;
    int level=7;
    char *time_lvl0;
    char *time_all_levels;
    t_level_list test_list;
    while (level <=15)
    {
        test_list= createSorted2NLevelList(level);
        startTimer();
        max = (int) pow(2,level)-1;
        for (int i = 0; i< 10000;i++)
        {
            random_value = (int) rand()%( max+1 );
            findcell = searchValInFirstLevel(test_list,random_value);
        }
        stopTimer();
        displayTime();
        time_lvl0 = getTimeAsString(); // fonction du module timer
        startTimer();
        for (int i = 0; i< 10000;i++)
        {
            random_value = (int) rand()%( max+1 );
            findcell = searchValInList(test_list,random_value);
        }
        stopTimer();
        time_all_levels = getTimeAsString();
        displayTime();
        fprintf(log_file,format,level,time_lvl0, time_all_levels);
        level++;
    }
    fclose(log_file);
}

void testpart3(){
    t_contact_schedule* ContactSchedule1 = createContactSchedule();
    insertNewAppointmentforContact(ContactSchedule1);
    insertNewAppointmentforContact(ContactSchedule1);
    insertNewAppointmentforContact(ContactSchedule1);
    displayContactAppointment(*ContactSchedule1);
    printf("Suppression du rendez-vous numéro 2\n");
    deleteAppointment(ContactSchedule1,2);
    printf("Création d'un nouveau contact");
    t_contact_schedule* ContactSchedule2 = createContactSchedule();
    insertNewAppointmentforContact(ContactSchedule2);
    printf("Création d'un nouveau contact\n");
    t_contact_schedule* ContactSchedule3 = createContactSchedule();
    insertNewAppointmentforContact(ContactSchedule3);
    t_schedule_cell *contact1 = createScheduleCell(2,ContactSchedule1);
    t_schedule_cell *contact2 = createScheduleCell(2,ContactSchedule2);
    t_schedule_list schedule = createScheduleList();
    InsertCellOrderInScheduleList(schedule,contact1);
    InsertCellOrderInScheduleList(schedule,contact2);

}
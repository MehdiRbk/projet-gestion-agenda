//
// Created by MehdiRbk on 06/12/2023.
//

#include "test.h"
#include <stdlib.h>
#include <stdio.h>
#include "level_list.h"
#include "timer.h"
#include <math.h>
void test_head()
{
    int level_max,level,val;
    printf("Rentrer le nombre max de level de votre level liste :\n");
    scanf("%d",&level_max);
    t_level_list MyLevelList = createLevelList(level_max);
    printf("Voici votre liste de base :\n");
    displayLevelList(MyLevelList);
    int headlist = 1;
    while(headlist)
    {
        printf("Choisir la valeur à mettre dans la nouvelle cellule:\n");
        scanf("%d",&val);
        printf("Choisir le nombre de level de la nouvelle cellule :\n");
        scanf("%d",&level);
        while(level>level_max)
        {
            printf("Choisir le nombre de level de la nouvelle cellule :\n");
            scanf("%d",&level);
        }
        addHeadLevelList(&MyLevelList, createLevelCell(val,level));
        displayLevelList(MyLevelList);
        printf("Continuer ? (0/1)");
        scanf("%d",&headlist);
    }
}
void test_ord()
{
    int level_max,level,val;
    printf("Rentrer le nombre max de level de votre level liste :\n");
    scanf("%d",&level_max);
    t_level_list MyLevelList = createLevelList(level_max);
    printf("Voici votre liste de base :\n");
    displayLevelList(MyLevelList);
    int orderlist = 1;
    while(orderlist)
    {
        printf("Choisir la valeur à mettre dans la nouvelle cellule:\n");
        scanf("%d",&val);
        printf("Choisir le nombre de level de la nouvelle cellule :\n");
        scanf("%d",&level);
        while(level>level_max)
        {
            printf("Choisir le nombre de level de la nouvelle cellule :\n");
            scanf("%d",&level);
        }
        addOrderLevelList(&MyLevelList, createLevelCell(val,level));
        displayLevelList(MyLevelList);
        printf("Continuer ? (0/1)");
        scanf("%d",&orderlist);
    }
}

void test_timesearch()
{
    int random_value,max;
    p_level_cell findcell;
    FILE *log_file = fopen("log.txt","w");
    char format[] = "%d\t%s\t%s\n" ;
    int level=7;
    char *time_lvl0;
    char *time_all_levels;
    while (level <=15)
    {
        t_level_list test_list = createSorted2NLevelList(level);
        startTimer();
        max = (int) pow(2,level)-1;
        for (int i = 0; i< 100000;i++)
        {
            random_value = (int) rand()%( max+1 );
            findcell = searchValInFirstLevel(test_list,random_value);
        }
        stopTimer();
        displayTime();
        printf(" First Level\n ");
        time_lvl0 = getTimeAsString(); // fonction du module timer
        startTimer();
        for (int i = 0; i< 100000;i++)
        {
            random_value = (int) rand()%( max+1 );
            findcell = searchValInList(test_list,random_value);
        }
        stopTimer();
        time_all_levels = getTimeAsString();
        displayTime();
        printf(" Multilevel\n ");
        fprintf(log_file,format,level,time_lvl0, time_all_levels);
        level++;
    }
    fclose(log_file);
}
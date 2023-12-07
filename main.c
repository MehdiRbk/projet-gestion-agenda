#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "level_list.h"
#include "timer.h"
#include "test.h"

int main() {
    /*
    t_level_list MyLevelList = createLevelList(5);
    displayLevelList(MyLevelList);
    //Ajout en tête de liste
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


    t_level_list MyLevelList = createSorted2NLevelList(4);
    displayLevelList(MyLevelList);
    p_level_cell find= searchValInFirstLevel(MyLevelList,1);
    if( find !=NULL)
    {
        printf("FIND");
    }
    else
        printf("NOT FIND");
    */
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
        for (int i = 0; i< 100000;i++)
        {
            random_value = (int) rand()%( max+1 );
            findcell = searchValInFirstLevel(test_list,random_value);
        }
        stopTimer();
        displayTime();
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
        fprintf(log_file,format,level,time_lvl0, time_all_levels);
        level++;
    }
    fclose(log_file);

    /*
    int start = 1;
    while(start)
    {
        printf("----------------------------------\n");
        printf(" Choisir le test de votre choix :\n");
        printf("----------------------------------\n");
        printf("1 - Test sur l'ajout en tete de liste\n");
        printf("2 - Test sur l'ajout dans l'ordre croissant\n");
        printf("3 - Test sur le temps des fonctions de recherche\n");
        printf("0 - Quitter les tests\n");
        printf("Votre choix : \n");
        scanf("%d",&start);
        if (start==1){
            test_head();
        }
        if (start==2){
            test_ord();
        }
        if (start==3){
           test_timesearch();
        }
    }
    */
    return 0;
}

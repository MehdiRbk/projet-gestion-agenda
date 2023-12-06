#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "level_list.h"

int main() {
    /*t_level_list MyLevelList = createLevelList(5);
    displayLevelList(MyLevelList);
    p_level_cell MyLevelCell = createLevelCell(18,4);
    addHeadLevelList(&MyLevelList,MyLevelCell);
    p_level_cell new_cell2 = createLevelCell(25,1);
    addOrderLevelList(&MyLevelList,new_cell2);
    p_level_cell new_cell3 = createLevelCell(32,5);
    addOrderLevelList(&MyLevelList,new_cell3);
    p_level_cell new_cell4 = createLevelCell(91,3);
    addOrderLevelList(&MyLevelList,new_cell4);
    p_level_cell new_cell5 = createLevelCell(59,1);
    addOrderLevelList(&MyLevelList,new_cell5);
    p_level_cell new_cell6 = createLevelCell(59,5);
    addOrderLevelList(&MyLevelList,new_cell6);
    p_level_cell new_cell7 = createLevelCell(31,2);
    addOrderLevelList(&MyLevelList,new_cell7);
    displayLevelList(MyLevelList);*/
    t_level_list MyLevelList = createSorted2NLevelList(4);
    displayLevelList(MyLevelList);
    p_level_cell find= searchValInFirstLevel(MyLevelList,1);
    if( find !=NULL)
    {
        printf("FIND");
    }
    else
        printf("NOT FIND");
    //printf("%d",bool);
    return 0;
}

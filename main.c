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
    int result =1;
    int n=4;
    for (int i = 0;i<n;i++)
    {
        result*=2;
    }
    result--;
    int *levels=malloc(result*(sizeof(int)));
    for (int i=0;i<result;i++)
    {
        levels[i]=0;
    }
    int x=2;
    for (int y=0;y<n-1;y++)
    {
        for (int z=0;z<result;z++)
        {
            if((z+1)%x==0)
                levels[z]++;
        }
        x*=2;
    }
    t_level_list MyLevelList = createLevelList(n);
    for (int i=0;i<result;i++){
        p_level_cell new_cell = createLevelCell(i+1,levels[i]+1);
        addOrderLevelList(&MyLevelList,new_cell);
    }
    //displayLevelList(MyLevelList);
    int bool = searchValInFirstLevel(MyLevelList,150);
    printf("%d",bool);
    return 0;
}

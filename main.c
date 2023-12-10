#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "level_list.h"
#include "timer.h"
#include "schedule.h"
#include "test.h"

int main() {
    int start=1;
    while(start)
    {
        printf("Choix test :\n");
        printf("1 - test PARTIE 1 et 2\n");
        printf("2 - test PARTIE 3\n");
        printf("0 - quit\n");
        scanf("%d",&start);
        if (start ==1){
            testpart1and2();
        }
        if (start==2){
            testpart3();
        }
    }
    return 0;
}

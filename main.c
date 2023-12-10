#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "level_list.h"
#include "timer.h"
#include "schedule.h"
int main() {
    char* str = scanString();
    int i=0;
    while(str[i] != '/0'){
        i++;
    }
    printf("%d",i);
    return 0;
}

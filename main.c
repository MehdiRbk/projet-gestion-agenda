#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "level_list.h"
#include "timer.h"
#include "schedule.h"
int main() {
    t_contact_schedule *marco = createContactSchedule();
    insertNewAppointmentforContact(marco);
    displayContactAppointment(*marco);
    insertNewAppointmentforContact(marco);
    displayContactAppointment(*marco);
    return 0;
}

cmake_minimum_required(VERSION 3.24)
project(projet2_gestion_agenda C)

set(CMAKE_C_STANDARD 11)

add_executable(projet2_gestion_agenda main.c fonction.c fonction.h level_list.c level_list.h timer.c test.c test.h schedule.c schedule.h time.c time.h)

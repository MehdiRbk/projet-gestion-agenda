//
// Created by MehdiRbk on 24/10/2023.
//

#ifndef PROJET2_GESTION_AGENDA_LEVEL_LIST_H
#define PROJET2_GESTION_AGENDA_LEVEL_LIST_H
typedef struct s_level_cell
{
    int value;
    int level;
    struct s_level_cell * next[];
} t_level_cell, *p_level_cell;

typedef struct s_level_list
{
    p_level_cell *heads;
    int max_level;
} t_level_list;

p_level_cell createLevelCell(int val, int nbr_level);
t_level_list createLevelList(int max_level);
void addHeadLevelList(t_level_list* MyLevelList,p_level_cell MyLevelCell);
void displayLevel(t_level_list MyLevelList,int level);
void displayLevelList(t_level_list MyLevelList);
void addOrderLevelList(t_level_list* MyLevelList,p_level_cell MyLevelCell);
p_level_cell searchValInFirstLevel(t_level_list MyLevelList,int val);
int FindLevelWhereHeadLevelValueInfSearchValue(int value, t_level_list MyLevelList);
p_level_cell searchValInList(t_level_list MyLevelList,int val);
t_level_list createSorted2NLevelList(int n);
#endif //PROJET2_GESTION_AGENDA_LEVEL_LIST_H

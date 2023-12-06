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

p_level_cell createLevelCell(int val, int nbr_level); // Créer une cellule de type level
t_level_list createLevelList(int max_level); // Créer une level liste vide
void addHeadLevelList(t_level_list* MyLevelList,p_level_cell MyLevelCell); //Ajoute une cellule en tête d'une level liste
void displayLevel(t_level_list MyLevelList,int level); // Affiche le level d'une level liste
void displayLevelList(t_level_list MyLevelList); // Affiche la level liste entière
void addOrderLevelList(t_level_list* MyLevelList,p_level_cell MyLevelCell); //Ajoute une cellule dans l'ordre croissant dans une level liste
p_level_cell searchValInFirstLevel(t_level_list MyLevelList,int val);//Cherche une cellule ayant une valeur et la renvoie en utilisant seulement le premier level
int FindLevelWhereHeadLevelValueInfSearchValue(int value, t_level_list MyLevelList); // Cherche le level où la valeur de son head est inférieur à une valeur rechercher
p_level_cell searchValInList(t_level_list MyLevelList,int val); //Cherche une cellule ayant une valeur et la renvoie en utilisant tous les levels
t_level_list createSorted2NLevelList(int n); // Créer une liste de 2^n -1 elem en forme de pyramide
#endif //PROJET2_GESTION_AGENDA_LEVEL_LIST_H

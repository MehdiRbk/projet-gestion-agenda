//
// Created by MehdiRbk on 24/10/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "level_list.h"
#include "math.h"

p_level_cell createLevelCell(int val, int nbr_level){
    p_level_cell MyLevelCell = malloc(sizeof(t_level_cell));
    MyLevelCell->value = val;
    MyLevelCell->level = nbr_level;
    *(MyLevelCell->next) = malloc(nbr_level*sizeof(p_level_cell));
    for (int i=0;i<nbr_level;i++){ // on initialise pour tous les levels de la cellule
        MyLevelCell->next[i]=NULL;
    }
    return MyLevelCell;
}

t_level_list createLevelList(int max_level){
    t_level_list MyLevelList ;
    MyLevelList.max_level = max_level;
    MyLevelList.heads = malloc(max_level * sizeof(p_level_cell));
    for (int i=0;i<max_level;i++){ // on initialise pour tous les levels de la liste
        MyLevelList.heads[i]=NULL;
    }
    return MyLevelList;
}

void addHeadLevelList(t_level_list* MyLevelList,p_level_cell MyLevelCell){
    int nbr_level = MyLevelCell->level;
    if (nbr_level < MyLevelCell->level)
    {
        printf("The number of level cell is bigger than the number of level list");
        return;
    }
    for (int i = 0; i < nbr_level; i++) { // parcourir les niveaux et mettre à jour les pointeurs de tête
        MyLevelCell->next[i] = MyLevelList->heads[i];
        MyLevelList->heads[i] = MyLevelCell;
    }
}

void addOrderLevelList(t_level_list* MyLevelList,p_level_cell MyLevelCell){
    int nbr_level = MyLevelCell->level;
    int val_cell = MyLevelCell->value;
    //on vérifie si la liste nest pas vide ou si la valeur de la première cellule nest pas inférieur à notre cellule qu'on ajoute
    //dans ces cas, on ajoute la cellule en tête de liste
    if(MyLevelList->heads[0]==NULL || val_cell < MyLevelList->heads[0]->value){ // si la liste est vide ajoute la cellule en tête
        addHeadLevelList(MyLevelList,MyLevelCell);
        return;
    }

    for (int i = 0; i < nbr_level; i++){ // Pour chaque level de la cellule on ajoute dans notre liste

        p_level_cell temp = MyLevelList->heads[i];
        p_level_cell prev = NULL;

        if (temp!=NULL) { //on vérifie que le level sur lequel on est n'est pas vide
            while (temp != NULL && val_cell > temp->value) {
                prev = temp;
                temp = temp->next[i];
            }
            MyLevelCell->next[i] = temp;
            prev->next[i] = MyLevelCell;
        }

        else{ //la cellule que l'on va ajouter sera la première sur le level
            MyLevelCell->next[i]=temp;
            MyLevelList->heads[i]=MyLevelCell;
        }
    }
}

void displayLevel(t_level_list MyLevelList,int level){
    p_level_cell temp = MyLevelList.heads[0];
    printf("[list_head_%d @-]--",level);
    while(temp != NULL){
        if (temp->level>level)
        {
            printf(">[%3d|@-]--", temp->value);
        }
        else {
            printf("-----------");
        }
        temp=temp->next[0];
    }
    printf(">NULL\n");
}

void displayLevelList(t_level_list MyLevelList){
    int nbr_level = MyLevelList.max_level;
    for(int i = 0; i < nbr_level; i++){
        displayLevel(MyLevelList,i);
    }
}

t_level_list createSorted2NLevelList(int n)
{
    t_level_list MyLevelList = createLevelList(n);
    int nbr_elem = pow(2,n)-1;
    int* levels = malloc(nbr_elem*sizeof(int));
    for (int i=0;i<nbr_elem;i++)
    {
        levels[i]=1;
    }
    for (int y=0;y<n-1;y++) // on recommence pour faire le nombre max de level
    {
        for (int z=0;z<nbr_elem;z++) // on recommence pour le nombre total d'éléments
        {
            if((z+1) % (int) pow(2,y+1) ==0) //permet de voir si l'index est un modulo pour chaque puissance de 2
                levels[z]++;
        }
    }
    for (int i=0;i<nbr_elem;i++){
        p_level_cell new_cell = createLevelCell(i+1,levels[i]);
        addOrderLevelList(&MyLevelList,new_cell);
    }
    return MyLevelList;

}
int searchValInFirstLevel(t_level_list MyLevelList,int val)
{
    p_level_cell temp=MyLevelList.heads[0];
    while(temp!=NULL)
    {
        if (temp->value==val)
        {
            return 1;
        }
        temp=temp->next[0];
    }
    return 0;
}

int searchValInList(t_level_list MyLevelList,int val)
{
    int max_level = MyLevelList.max_level;
    p_level_cell temp = MyLevelList.heads[max_level-1];
    p_level_cell  prev = temp;
    for(int i = 0;i<max_level-1;i++)
    {
        
    }
}
//
// Created by MehdiRbk on 24/10/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "level_list.h"
#include "math.h"
//Créer une cellule de level avec un nombre de level et une valeur assigné
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
//Créer une level liste vide avec un nombre maximum de level
t_level_list createLevelList(int max_level){
    t_level_list MyLevelList ;
    MyLevelList.max_level = max_level;
    MyLevelList.heads = malloc(max_level * sizeof(p_level_cell));
    for (int i=0;i<max_level;i++){ // on initialise pour tous les levels de la liste
        MyLevelList.heads[i]=NULL;
    }
    return MyLevelList;
}
//Ajoute une cellule en tête de la level liste
void addHeadLevelList(t_level_list* MyLevelList,p_level_cell MyLevelCell){
    int nbr_level = MyLevelCell->level;
    if (nbr_level < MyLevelCell->level)
    {
        printf("The number of level cell is bigger than the number of level list");
        return;
    }
    for (int i = 0; i < nbr_level; i++) { // Parcourir les niveaux et mettre à jour les pointeurs de tête
        MyLevelCell->next[i] = MyLevelList->heads[i];
        MyLevelList->heads[i] = MyLevelCell;
    }
}
//Ajoute des éléments dans une level liste dans l'ordre croissant
void addOrderLevelList(t_level_list* MyLevelList,p_level_cell MyLevelCell){
    int nbr_level = MyLevelCell->level;
    int val_cell = MyLevelCell->value;
    //On vérifie si la liste nest pas vide ou si la valeur de la première cellule n'est pas inférieure à notre cellule qu'on ajoute
    //dans ces cas, on ajoute la cellule en tête de liste
    if(MyLevelList->heads[0]==NULL || val_cell < MyLevelList->heads[0]->value){ // si la liste est vide ajoute la cellule en tête
        addHeadLevelList(MyLevelList,MyLevelCell);
        return;
    }

    for (int i = 0; i < nbr_level; i++){ // Pour chaque level de la cellule, on ajoute dans notre liste

        p_level_cell temp = MyLevelList->heads[i];
        p_level_cell prev = NULL;

        if (temp!=NULL) { //On vérifie que le level sur lequel on est n'est pas vide
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
//Affiche un niveau d'une level list
void displayLevel(t_level_list MyLevelList,int level){
    p_level_cell temp = MyLevelList.heads[0];
    printf("[list_head_%d @-]--",level);
    while(temp != NULL){
        if (temp->level>level) //Si le nombre de level de la cellule est supérieur au level actuel alors on affiche une case
        {
            printf(">[%3d|@-]--", temp->value);
        }
        else { //Sinon on affiche un saut qui permet d'obtenir une liste aligné
            printf("-----------");
        }
        temp=temp->next[0];
    }
    printf(">NULL\n");
}
//Affiche tous les niveaux d'une level liste
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
    for (int i=0;i<nbr_elem;i++) //Initialise toutes les valeurs du tableau levels à 1
    {
        levels[i]=1;
    }
    for (int y=0;y<n-1;y++) //On recommence pour faire le nombre max de level
    {
        for (int z=0;z<nbr_elem;z++) //On recommence pour le nombre total d'éléments
        {
            if((z+1) % (int) pow(2,y+1) ==0) //Permet de voir si l'index est un modulo pour chaque puissance de 2
                levels[z]++;
        }
    }
    for (int i=0;i<nbr_elem;i++){   //Ajoute chaque cell dans la liste avec son nombre de level attribué
        p_level_cell new_cell = createLevelCell(i+1,levels[i]);
        addOrderLevelList(&MyLevelList,new_cell);
    }
    return MyLevelList;

}
//Cherche une cellule avec une certaine valeur et la renvoie en utilisant seulement le premier level
p_level_cell searchValInFirstLevel(t_level_list MyLevelList,int val)
{
    p_level_cell temp=MyLevelList.heads[0];
    while(temp!=NULL)
    {
        if (temp->value==val)
        {
            return temp;
        }
        temp=temp->next[0];
    }
    return NULL;
}
//Permet de se mettre au niveau du Head au level où la valeur que l'on cherche est supérieur à la valeur du Head de ce level
int FindLevelWhereHeadLevelValueInfSearchValue(int val, t_level_list MyLevelList)
{
    for (int i = MyLevelList.max_level-1; i>0;i--) //On va visiter les head de chaque level
    {
        //si la valeur de la head du level est inférieur à celle de la valeur rechercher alors on retourne le level où cette valeur est inférieur
        if (MyLevelList.heads[i]->value<=val)
        {
            return i;
        }
    }
    return 1;

}
//Cherche la valeur d'une valeur dans une level liste le plus rapidement
p_level_cell searchValInList(t_level_list MyLevelList,int val)
{
    //Utilisation de cette fonction afin de n'allez seulement à droite dans la recherche
    int level = FindLevelWhereHeadLevelValueInfSearchValue(val,MyLevelList);
    p_level_cell temp = MyLevelList.heads[level];
    p_level_cell prev = temp;
    while(level>0) //Tant que le level que l'on va décrémenter au fur et à mesure n'atteint pas 0 alors on continue
    {
        if(temp->value == val) //Valeur trouver alors on retourne la cellule
            return temp;

        level--; // La valeur n'a pas été trouvé à ce level alors on descend d'un level

        //La valeur de la cellule est supérieure à la valeur recherchée alors on revient d'un pas et on descend de level
        if(temp->value > val){
            temp = prev;
            level--;
        }
        //La valeur de la cellule est inférieure à la valeur recherchée alors on passe à la cellule suivant sur le prochain level
        if(temp->value < val){
            prev = temp;
            temp = temp->next[level-1];
        }
    }
    return NULL; //retourne NULL si la valeur n'a pas été trouvé
}
#include <stdio.h>
#include <stdlib.h>

//defining element type
typedef struct element{
    int value;
    struct element* next;
}element;
//defining list type
typedef element* list;
//la fonction création d'un élément
element create();
//fonction affchage d'un élément
void affiche(element e);
//fonction affchage d'une liste
void Laffiche(list L);
//fonction d'ajout au début d'une liste
list add_beg(list L,element *e);
//fonction d'ajout à la fin de la liste
list add_end(list L,element *e);
//ajout d'un élément à une certaine positin
list add_pos(list L,element* e, int i);
//fonction de supression debut
list del_beg(list L);
//fonction de suppression fin
list del_end(list L);
//fonction supression à une certaine position
list del_position(list L, int i);
//fonction pour inverser la liste
list inverser(list L);
int main()
{
    element e0=create();
    affiche(e0);

    return 0;
}
//------------------------------------------------------
element create()
{
    int n;
    element *el= (element*)malloc(sizeof(element));//avant de créer un élément on lui alloue de la mémoire
    element e;
    el=&e;//puisque la fonction malloc retourne un pointeur on a créé ce pointeur pour retourner un élément
    printf("\nDonner la valeur\n");
    scanf("%d",&n);
    e.value=n;
    e.next=NULL;
    return e;
}
//----------------------------------------------------------------------
void affiche(element e)
{
    printf("[%d,%p]\t",e.value,e.next);
}
//------------------------------------------------------------------------
void Laffiche(list L)
{
    if (L==NULL)
        printf("\nLa liste est vide\n");
    else
    {
        printf("\n");
        element* current=L;
        while(current->next!=L)//on parcours la liste jusqu'au dernier élément
        {
            affiche(*current);//on utilise la fonction déjà définie pour afficher les éléments de la liste
            current=current->next;//on incrémente
        }
        affiche(*current);
    }
}

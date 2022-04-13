#include <stdio.h>
#include <stdlib.h>

//defining element type
typedef struct element{
    int value;
    struct element* next;
}element;
//defining list type
typedef element* list;
//la fonction cr�ation d'un �l�ment
element create();
//fonction affchage d'un �l�ment
void affiche(element e);
//fonction affchage d'une liste
void Laffiche(list L);
//fonction d'ajout au d�but d'une liste
list add_beg(list L,element *e);
//fonction d'ajout � la fin de la liste
list add_end(list L,element *e);
//ajout d'un �l�ment � une certaine positin
list add_pos(list L,element* e, int i);
//fonction de supression debut
list del_beg(list L);
//fonction de suppression fin
list del_end(list L);
//fonction supression � une certaine position
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
    element *el= (element*)malloc(sizeof(element));//avant de cr�er un �l�ment on lui alloue de la m�moire
    element e;
    el=&e;//puisque la fonction malloc retourne un pointeur on a cr�� ce pointeur pour retourner un �l�ment
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
        while(current->next!=L)//on parcours la liste jusqu'au dernier �l�ment
        {
            affiche(*current);//on utilise la fonction d�j� d�finie pour afficher les �l�ments de la liste
            current=current->next;//on incr�mente
        }
        affiche(*current);
    }
}

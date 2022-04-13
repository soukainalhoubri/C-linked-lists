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
//la fonction affichage d'un �l�ment
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
void tri_bulles(list L);
int main()
{
    element e0,e1,e2,e3,e5;
    e1=create();//on cr�e un �l�ment
    affiche(e1);// on affiche cet �l�ment
    list L=NULL;//on cr�e une liste vide
    Laffiche(L);//on affiche cette liste
    e2=create();
    e3=create();//on vr�e deux autres �l�ments
    e1.next=&e2;
    e2.next=&e3;//on cr�e la liaison entre les 3 �l�ments
    L=&e1;// on pointe la liste sur le premier �l�ment
    Laffiche(L);//on affiche la liste
    e0=create();//on cr�e u �l�ment et on l'ajoute au d�but de la liste
    L=add_beg(L,&e0);
    Laffiche(L);
    e5=create();//on cr�e un �l�ment et on l'ajoute � la fin de la liste
    L=add_end(L,&e5);
    Laffiche(L);
    element e6=create();//on cr�e un �l�ment et on l'ajoute � la position 2 par exemple
    L=add_pos(L,&e6,2);
    Laffiche(L);
    L=del_beg(L);//on supprime le premier �l�ment de la liste et n affiche
    Laffiche(L);
    L=del_end(L);//on supprime le dernier de la liste
    Laffiche(L);
    L=del_position(L,1);//on supprime l'�l�ment de la position 1 par exemple
    Laffiche(L);
    L=inverser(L);
    Laffiche(L);
    tri_bulles(L);
    Laffiche(L);
    return 0;
}
//----------------------------------------------------------------------
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
//-----------------------------------------------------------------------------------
void affiche(element e)
{
    printf("[%d,%p]\t",e.value,e.next);
}
//-----------------------------------------------------------------
void Laffiche(list L)
{
    if (L==NULL)
        printf("\nLa liste est vide\n");
    else
    {
        printf("\n");
        element* current=L;
        while(current!=NULL)//on parcours la liste jusqu'au dernier �l�ment
        {
            affiche(*current);//on utilise la fonction d�j� d�finie pour afficher les �l�ments de la liste
            current=current->next;//on incr�mente
        }
    }
}
//-----------------------------------------------------------------------------------------------
list add_beg(list L,element * e)
{
    if (L==NULL)
        L=e;
    else
    {
        e->next=L;
        L=e;
    }
    return(L);

}
//----------------------------------------------------------------------------------------------------------
list add_end(list L,element* e)
{
    if(L==NULL)
        L=e;
    else
    {
        element* current=L;
        while(current->next!=NULL)
        {
            current=current->next;
        }
        current->next=e;
    }
    return L;
}
//-------------------------------------------------------------------------------------------------------------
list add_pos(list L,element* e, int i)
{
    if(L==NULL)
    {printf("\nListe vide, ne va contenir qu un seul element apres l ajout\n");
        L=e;}
    else if (i==0)
        L=add_beg(L,e);
    else
    {
        int j=0;
        element* current=L;
        while(j!=(i-1))
        {
            current=current->next;
            j++;
        }
        e->next=current->next;
        current->next=e;
    }
    return L;
}
//-------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------
list del_beg(list L)
{
    if(L==NULL)
        printf("\nListe deja vide\n");
    else
    {
        element* first=L;
        L=first->next;
        free(first);
    }
    return L;
}
//-------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------
list del_end(list L)
{
    if(L==NULL)
        printf("\nListe deja vide\n");
    else if(L->next==NULL)
    {
        free(L);
        L=NULL;
    }
    else
    {
        element* current=L;
        element* b4last;
        while(current->next!=NULL)
        {
            b4last=current;
            current=current->next;

        }
        b4last->next=NULL;
        free(current);
    }
    return L;
}
//-------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------
list del_position(list L, int i)
{
    if(L==NULL)
        printf("\nListe deja vide\n");
    else if(i==0)
        L=del_beg(L);
    else
    {
        element* current=L;
        element* supp;// l'�l�ment � supprimer
        int j=0;
        while(j!=(i-1))
        {
            current=current->next;
            j++;
        }
        supp=current->next;
        current->next=supp->next;
        free(supp);
    }
    return L;
}
//-------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------
list inverser(list L)
{
    if(L==NULL)
        printf("\n Liste vide\n");
    else if (L->next==NULL)
        return(L);
    else
    {
        element* current=L;
        element* adress=NULL;
        element* store=NULL;
        while(current!=NULL)
        {
            adress=current->next;
            current->next=store;
            store=current;
            current=adress;
        }
        L=store;
    }
    return L;
}
//--------------------------------------
void tri_bulles(list L)
{
    int echange, i;
    element* current;
    element* avancer = NULL;
    element* inter=NULL;

    if (L == NULL)
        return L;
    else{
           do
    {
        echange = 0;
        current= L;

        while (current->next != avancer)
        {
            if (current->value > current->next->value)
            {
                inter=current;
                current=current->next;
                current->next=inter;
                echange= 1;
            }
            current = current->next;
        }
        avancer = current;
    }
    while (echange);
    }

}

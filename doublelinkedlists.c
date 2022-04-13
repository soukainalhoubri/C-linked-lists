#include <stdio.h>
#include <stdlib.h>
//definir le type élément
typedef struct element
{
    int value;
    struct element* next;
    struct element* previous;
}element;
//définir le type liste
typedef element* list;
//la fonction création d'un élément
element create();
//fonction affichage d'un élément
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
//fonction pour inverser la liste:
list inverser(list L);
//fonction pour inverser un élément
element* inv(element* e);
int main()
{
    element e1=create();
    affiche(e1);
    element e2=create();
    element e3=create();
    e1.next=&e2;
    e2.next=&e3;
    e2.previous=&e1;
    e3.previous=&e2;
    printf("\nOn cree un liaison manuellement et on affiche\n");
    list L=&e1;
    Laffiche(L);
    element e4=create();
    L=add_beg(L,&e4);
    printf("\nOn ajoute 4 au debut et on affiche\n");
    Laffiche(L);
    element e5=create();
    L=add_end(L,&e5);
    printf("\nOn ajoute 5 a la fin et on affiche\n");
    Laffiche(L);
    element e6=create();
    L=inverser(L);
    printf("\nOn inverse et on affiche\n");
    Laffiche(L);
    L=add_pos(L,&e6,1);
    printf("\nOn ajoute 6 a la position 1 et on affiche\n");
    Laffiche(L);
    L=del_beg(L);
    printf("\nOn supprime la tete et on affiche\n");
    Laffiche(L);
    L=del_end(L);
    printf("\nOn supprime la fin  et on affiche\n");
    Laffiche(L);
    L=del_position(L,3);
    printf("\nOn supprime la position 3  et on affiche\n");
    Laffiche(L);
    return 0;
}
//--------------------------------------------------------
element create()
{
    int n;
    element *el= (element*)malloc(sizeof(element));//avant de créer un élément on lui alloue de la mémoire
    element e;
    el=&e;
    printf("\nDonner la valeur\n");
    scanf("%d",&n);
    e.value=n;
    e.next=NULL;
    e.previous=NULL;
    return e;
}
//---------------------------------------------------------
void affiche(element e)
{
    printf("[%p,%d,%p]\t",e.previous,e.value,e.next);
}
//------------------------------------------------------------
void Laffiche(list L)
{
    if (L==NULL)
        printf("\nLa liste est vide\n");
    else
    {
        printf("\n");
        element* current=L;
        while(current!=NULL)//on parcours la liste jusqu'au dernier élément
        {
            printf("\t%d\t",current->value);//on utilise la fonction déjà définie pour afficher les éléments de la liste
            current=current->next;//on incrémente
        }
    }
}
//------------------------------------------------------------------------------
list add_beg(list L,element *e)
{
    if (L==NULL)
        L=e;
    else
    {
        element* current=L;
        current->previous=e;
        e->next=current;
        L=e;
    }
    return L;
}
//-------------------------------------------------
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
        e->previous=current;
    }
    return L;
}
//------------------------------------------------
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
        e->previous=current;
        e->next=current->next;
        current->next=e;
    }
    return L;
}
//---------------------------------------------------------
list del_beg(list L)
{
    if(L==NULL)
        printf("\nListe deja vide\n");
    else if (L->next==NULL)
    {
        L=NULL;
    }
    else
    {
        element* e=L;
        L=L->next;
        L->previous=NULL;

    }
    return L;
}
//-------------------------------------------------------------
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
        current=NULL;
    }
    return L;
}
//----------------------------------------------------------
list del_position(list L, int i)
{
    if(L==NULL)
        printf("\nListe deja vide\n");
    else if(i==0)
        L=del_beg(L);
    else
    {
        element* current=L;
        int j=0;
        while(j!=i && (current->next!=NULL))
        {
            current=current->next;
            j++;
        }//on s'arrete à l'element i-1
        if(current->next==NULL)
        {
            printf("\nFin atteinte supression du dernier element\n");
            L=del_end(L);
        }
        else
        {

        element* prec=current->previous;
        element* suiv=current->next;
        prec->next=current->next;
        (current->next)->previous=prec;
        free(current);
        current=NULL;
        }

    }
    return L;
}
//-----------------------------------------------------------
//----------------------------------------------------------
element* inv(element* e)
{
    element* inter=e->next;
    e->next=e->previous;
    e->previous=inter;
    return e;
}
//--------------------------------------------------------------
list inverser(list L)
{
    if(L==NULL)
        {printf("\nListe vide\n");
        return L;}
    else if(L->next==NULL)
        return L;
    else
    {
        element* current,*parcours;
        current = L;
        element* last;
        while(current != NULL)
        {
        last=current;
        parcours = current->next;
        current->next=current->previous;
        current->previous=parcours;
        current =parcours;
        }
        parcours=L;
        L=last;
        last =parcours;
        return L;
    }
}

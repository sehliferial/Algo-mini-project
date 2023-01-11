#include <stdio.h>
#include <stdlib.h>
    struct prof
    {
        int p_num;
        int Nom[20];
        int Prenom[20];
        int Cours;
        int TD;
        int TP;
        struct prof *next;
    };

        void ajt (struct prof **pp)
{

        int p_num;
        int Nom[20];
        int Prenom[20];
        int Cours;
        int TD;
        int TP;
        struct prof *temp,*t;
        temp=malloc(sizeof(struct prof));
        printf("Enter Le Num : ");
        scanf("%d",&p_num);
        temp->p_num=p_num;
        printf("Enter Le Nom : ");
        fflush(stdin);
        gets(temp->Nom);
        printf("Enter Le Prenom : ");
        gets(temp->Prenom);
        printf("Enter Le Nombre des Cours : ");
        scanf("%d",&Cours);
        temp->Cours=Cours;
        printf("Enter Le Nombre des TDs : ");
        scanf("%d",&TD);
        temp->TD=TD;
        printf("Enter Le Nombre des Tps : ");
        scanf("%d",&TP);
        temp->TP=TP;
        temp->next=NULL;
        if(*pp==NULL)
                *pp=temp;
                else
                {
                t=*pp;
                while(t->next!=NULL)
                t=t->next;
                t->next=temp;
                                }
}

    int rp (struct prof *pp,int pf_nm)
    { int i=0;
    if (pp==NULL)
        printf("404 :/");
    else {
        while(pp){
            if(pp->p_num==pf_nm){
                i=1;
                break;
            }
            pp=pp->next;
        }
            if (i!=1)
            printf("Faux");

             else {
                printf("Nom : ");
                puts(pp->Nom);
                printf("Prenom : ");
                puts(pp->Prenom);
                printf("Prof Num : %d\n",pp->p_num);
                printf("cours : %d \n",pp->Cours);
                printf("TDs : %d \n",pp->TD);
                printf("TPs : %d \n",pp->TP);
            }
    }



    }
    void aff (struct prof *pp)
{
        while(pp)
                {
                printf("\nNom : ");
                puts(pp->Nom);
                printf("Prenom : ");
                puts(pp->Prenom);
                printf("Le NUM : %d\n",pp->p_num);
                printf("Cours : %d \n",pp->Cours);
                printf("TDs : %d \n",pp->TD);
                printf("TPs : %d \n",pp->TP);
                pp=pp->next;
                }
}
int supp (struct prof **pp,int pf_nm) {
        struct prof *temp,*t;
        int i=0;
        if(*pp==NULL)
        printf("Non Comptes Enregistrer ICI ");
        else
        if((*pp)->p_num==pf_nm)
        {
       temp=*pp;
       *pp=(*pp)->next;
       free(temp);
        }
        else
        {
       temp=*pp;
       while(temp->next!=NULL)
       {
           if(temp->p_num==pf_nm)
           {
            i=1;
            break;

           }
           t=temp;
           temp=temp->next;

       }

    }   if(i!=1)
        printf("Vous avez supprimer un Compte :)\n");
       else
       {
           t->next=temp->next;
           free(temp);
       }

    }
int M (void)
{
    int c;
    printf("\n*****************************************************Bienvenu***********************************************************");
    printf("\n                                            Gestion Des Enseignants:");
     printf("\n------------------------------------------------------------------------------------------------------------------------");
    printf("\n                                                                                 1ING |Projet de Sehli Ferial Amina|");
    printf("\n------------------------------------------------------------------------------------------------------------------------");
    printf("\n1:Ajouter un enseignant");
    printf("\n2:Afficher tous les enseignants ");
    printf("\n3:Chercher Un enseignant");
    printf("\n4:Supprimer Un Compte");
    printf("\n------------------------------------------------------------------------------------------------------------------------");
    printf("                                                > Enter Votre Choix : ");
    scanf("%d",&c);
    printf("\n------------------------------------------------------------------------------------------------------------------------");
    return(c);
}
main()
{
    int dev;
    struct prof *pp=NULL;
    while(1)
    { system("cls");
        switch(M())
        {
        case 1:
            ajt(&pp);
            break;
        case 2:
            aff(pp);
            break;
            case 3:
            printf("Num De Prof : ");
            scanf("%d",&dev);
            rp(pp,dev);
            break;
            case 4:
            printf("Enter Le NUM de Prof : ");
            scanf("%d",&dev);
            supp(&pp,dev);
            break;
        }
        getche();
    }
}

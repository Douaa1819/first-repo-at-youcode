#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// version de modif status
// data struct de date
typedef struct
{
    int jour;
    int mois;
    int annee;
    int heurs;
} date;
// status de task
typedef enum statut
{
    TODO,
    DOING,
    DONE
} statut;
// data struct de tache(Titre ,description,status,deadline et identificateur
typedef struct
{
    char titre[50],description[200];
    statut st;
    int id;
    date deadline;
} tache;

// variable i need it
int d=1,i =0,s=0;
int compt = 0;
tache ajt[100];
tache T[100];
// ajouter une tache
tache ajouteTache()
{
    int n;
    printf("Entrez un unique identifiant : ");
    scanf("%d", &ajt[compt].id);

    printf("Entrez le titre de la tache : ");
    scanf(" %[^\n]",ajt[compt].titre);
    printf("Entrez la description de la tache : ");
    scanf( " %[^\n]",ajt[compt].description);
    printf("deadline  de task  \n");
    do
    {
        printf (" entrer jour :");
        scanf(" %d",&ajt[compt].deadline.jour);
    }
    while(ajt[compt].deadline.jour<0 || ajt[compt].deadline.jour>31);

    do
    {
        printf (" \n entrer le mois :");
        scanf(" %d",&ajt[compt].deadline.mois);
    }
    while (ajt[compt].deadline.mois<=0  || ajt[compt].deadline.mois>12);

    do
    {
        printf (" \n entre annee :");
        scanf(" %d",&ajt[compt].deadline.annee);
    }
    while (ajt[compt].deadline.annee<1940 || ajt[compt].deadline.annee> 10000 );

    do
    {
        printf (" \n  entrer lheur :");
        scanf("%d",&ajt[compt].deadline.heurs);
    }
    while (ajt[compt].deadline.heurs<=0 || ajt[compt].deadline.heurs >24 );


    do
    {
        printf(" ajouter le status ( 0:TODO/ 1:DOING/ 2:DONE ) :");
        scanf("%d",&n);
        ajt[compt].st=n;
    }
    while(ajt[compt].st<0 || ajt[compt].st > 2);
    compt++;

    printf("the task %d add Successfully !\n", compt);

}
// Affiche une tâche
void afficherTache()
{

    for (int x = 0; x<compt; x++)
    {
        printf("**ID %-15d | Titre %-12s |Deadline %d/%d/%d/%-5d | ",ajt[x].id,ajt[x].titre,ajt[x].deadline.annee,ajt[x].deadline.mois,ajt[x].deadline.jour,ajt[x].deadline.heurs);
        switch(ajt[x].st)
        {
        case 0:
            printf("status : TODO\n");

            break;
        case 1 :
            printf("status : DOING\n");
            break;
        case 2 :
            printf("status : Done\n");
            break;

        }
       /* printf("Statut: %s",ajt[x].st== TODO"TODO\n":ajt[x].st==DOING"DOING\n":ajt[x].st==DONE?"Done\n":"inconnu\n");*/
    }

}
void trierEtAfficherTachesAlphabetique()
{

    tache temp;
    int e,f;
    for (int a = 1; a <= f; a++)
    {
        temp = ajt[a];
        e = a - 1;
        while (e >= 0 && strcmp(ajt[e].titre, temp.titre) > 0)
        {
            ajt[e + 1] = ajt[e];
            e = e - 1;
        }
        ajt[e + 1] = temp;
    }

    printf("\nListe de toutes les tâches triées par ordre alphabétique\n");
    if (f == -1)
    {
        printf("Aucune tâche trouvée.\n");
        return;
    }
    printf("%-10s %-20s %-30s %-15s %-20s\n", "ID", "Titre", "Description", "Deadline");
    for (int e = 0; e <= f; e++)
    {
        printf("%-10d %-20s %-30s %d/%d/%d/%-5d |\n",ajt[e].id, ajt[e].titre, ajt[e].description, ajt[e].deadline.annee,ajt[e].deadline.mois,ajt[e].deadline.jour,ajt[e].deadline.heurs);
        switch(ajt[e].st)
        {
        case 0:
            printf("status : TODO\n");
            break;
        case 1 :
            printf("status : DOING\n");
            break;
        case 2 :
            printf("status : Done\n");
            break;

        }
    }
}
// mofification

void modif_des(int x)
{
    char n[100];
    printf("***********|Modifier la description|**********\n");
    printf("entrer  une nouvelle description s'il vous plait \n: ");
    scanf(" %[^\n]",n);
    strcpy(ajt[x].description,n);
}

void modif_statut(int x) // position
{
    int n;
    printf(" taper 0 pour changer a TO DO\n");
    printf(" taper 1 pour changer DOING  a \n");
    printf("taper 2 pour changer a DONE \n");

    scanf("%d",&n);
    if(n>=1 || n<=3)
        ajt[x].st=n-1;
    else
        printf("Choix invalide. Veuillez entrer un nombre valide.\n");
}
// recherche
void rechercherparTitre()
{
	char titreRecherche[50];
	printf("Entrez le Titre de la tâche à rechercher : ");
	scanf(" %[^\n]", titreRecherche);

	int found = 0;
	for (int j = 0; j <= i; j++)
	{
		if (strcmp(ajt[j].titre, titreRecherche) == 0)
		{
			if (found == 0)
			{
				printf("%-10s %-20s %-30s %-15s %-20s\n", "ID", "Titre", "Description", "Deadline", "Statut");
			}
			printf("**ID %-15d | Titre %-12s |Deadline %d/%d/%d/%-5d | ",ajt[j].id,ajt[j].titre,ajt[j].deadline.annee,ajt[j].deadline.mois,ajt[j].deadline.jour,ajt[j].deadline.heurs);
        switch(ajt[j].st)
        {
        case 0:
            printf("status : TODO\n");

            break;
        case 1 :
            printf("status : DOING\n");
            break;
        case 2 :
            printf("status : Done\n");
            break;
            found = 1;
        }

	}

	if (found == 0)
	{
		printf("Aucune tâche avec le titre '%s' trouvée.\n", titreRecherche);
	}
}
}

// recherch par ID
void rechercherParidentifiant()
{
	int idrecherch;
	printf("Entrez l'Identifiant de la tache a rechercher : ");
	scanf("%d", &idrecherch);

	for (int j = 0; j <= i; j++)
	{
		if (ajt[j].id == idrecherch)
		{
			printf("%-10s %-20s %-30s %-15s %-20s\n", "ID", "Titre", "Description", "Deadline", "Statut");
			printf("**ID %-15d | Titre %-12s |Deadline %d/%d/%d/%-5d | ",ajt[j].id,ajt[j].titre,ajt[j].deadline.annee,ajt[j].deadline.mois,ajt[j].deadline.jour,ajt[j].deadline.heurs);
        switch(ajt[j].st)
        {
        case 0:
            printf("status : TODO\n");

            break;
        case 1 :
            printf("status : DOING\n");
            break;
        case 2 :
            printf("status : Done\n");
            break;}
		}
		}

	printf("Tache avec l'ID %d non trouvée.\n", idrecherch);
}

int main()
{
    // ajtplusieurtaches
    int nbrTache = 0;
    int t,k,x;
    int choix;
    int idModif;

    do
    {
        printf("_____________________________MENU_____________________________\n");
        printf("cliquez sur 1 pour Ajouter une nouvelle tache  :\n");
        printf("cliquez sur 2 pour  Ajouter une plusieur tache  :\n");
        printf("cliquez sur 3 pour Afficher toutes les taches  :\n");
        printf("cliquez sur 4 pour Modifier une tache : \n");
        printf("cliquez sur 5 pour Supprimer une tache par identifiant :\n");
        printf("cliquez sur 6 pour Rechercher les Taches :\n");
        printf("cliquez sur 7 pour les statistique  :\n");
        printf("cliquez sur 8 pour Quitter  :\n");
        printf("\n entrez votre choix s'il vous plait :");
        scanf("%d",&choix);
        switch (choix)
        {
        case 1:
            ajouteTache();
            break;
        case 2:
            printf("combien de tache peut ajouter :");
            scanf("%d",&t);
            int j = nbrTache;
            for(int i=j; i < t+j; i++)  // hit 100 khwya nbr de tach li ki3mrha o matatsali hta tzid nbr li baghi utilisateur
            {
                T[i] = ajouteTache();
                nbrTache++;
            }
            break;
        case 3:
            do
            {
                printf("______________________sous MENU de l afichage____________________________\n");
                printf("cliquez sur 1 pour Trier les tâches par ordre alphabétique  :\n");
                printf("cliquez sur 2 pour  Trier les tâches par deadline :\n");
                printf("cliquez sur 3 pour Afficher les tâches dont le deadline est dans 3 jours ou moins :\n");
                printf("cliquer sur 4 pour quitter : \n ");
                scanf("%d",&k);
                switch(k)
                {
                case 1:afficherTache();
                    trierEtAfficherTachesAlphabetique();

                    break;
                }
            }
            while(k!=4);

            break;
        case 4:{
            int position_id=-1;
         printf("______________________sous MENU de modifier une tache____________________________\n");
            printf("cliquez sur 1 pour modifier la description d'une tache :\n");
            printf("cliquez sur 2 pour modifier le statut d’une tache :\n");
            printf("cliquez sur 3 pour modifier le deadline d’une tache:\n");
            scanf("%d",&k);
            printf("***********|Modifier une tache|**********\n");
            printf("pour modifier taper le iD de tache que tu peux le  modifier \n :");
            scanf("%d",&idModif);
            for (int x = 0 ; x <= compt; x++)
            {
                if(ajt[x].id == idModif)
                {
                position_id=x;
                    printf("-task        : %s\n", ajt[x].titre);
                     printf("status      : %s\n", ajt[x].st);

                    printf("-description : %s\n", ajt[x].description);
                }
            }
                                                                                                                                   /*printf("-deadline    : %d\n", ajt[x].date);*/
                                                                                                                                       /*printf("\033[0;33m***********|Modifier une tache|**********\n\n\033[0m");*/


            switch(k)
            {
            case 1:
                modif_des(x);
                break;
            // k = 0;
            case 2:
                if(position_id!=-1)
                modif_statut(x);
                //  k= 0;
                break;
            }

        }

break;
        case 5:
        case 6:
            do {printf("______________________sous MENU de RECHERCHER les tache____________________________\n");
            printf("cliquez sur 1 pour rechercher une tache par son Titre:\n");
            printf("cliquez sur 2 pour Rechercher une tache par son Identifiant :\n");
            scanf("%d",&k);
            switch (k){
            case 1:rechercherparTitre();
            break;
            case 2: rechercherParidentifiant();
            break;

            }
            }while(k!=4);

        case 7 :
            printf("______________________sous MENU Les Statistique____________________________\n");
            printf("cliquez sur 1 pour afficher le nombre total des tâches :\n");
            printf("cliquez sur 2 pour afficher le nombre de taches complètes et incomplètes :\n");
            printf("cliquez sur 3 pour afficher le nombre de jours restants jusqu'au délai de chaque tâche:\n");
            scanf("%d",&k);


        }



    }
    while(choix != 8);
// had lversion nj7aat bach der desc jdida et recherch par titre
    return 0;
}

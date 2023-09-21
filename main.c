#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

   // data struct de date
    typedef struct{
	    int jour;
	    int mois;
	    int annee;
	    int heurs;
	     }date;
	     // status de task
	     enum statut {
	     TODO,
	     DOING,
	     DONE};
         // data struct de tache(Titre ,description,status,deadline et identificateur
	     typedef struct{
	     char titre[50],description[200];
	     enum statut st;
	     int id;
	     date deadline;
	     }tache;
	   // ajouter une tache
	     tache ajouteTache() {
    int n;
    tache ajt;
    printf("Entrez un unique identifiant : ");
    scanf("%d", &ajt.id);

    printf("Entrez le titre de la tache : ");
    scanf(" %[^\n]",ajt.titre);
    printf("   deadline  de task  \n");

    do {
        printf (" entrer jour :");
        scanf("%d",&ajt.deadline.jour);
    }while(ajt.deadline.jour<0 || ajt.deadline.jour>31);

    do{
        printf (" \n entrer le mois :");
        scanf("%d",&ajt.deadline.mois);
    }while (ajt.deadline.mois<=1  || ajt.deadline.mois>12);

    do{
        printf (" \n entre annee :");
        scanf("%d",&ajt.deadline.annee);
    }while (ajt.deadline.annee<1940 ||ajt.deadline.annee> 10000 );

    do {
        printf (" \n  entrer lheur :");
        scanf("%d",&ajt.deadline.heurs);
    }while (ajt.deadline.heurs<=0 || ajt.deadline.heurs >24 );

    printf("Entrez la description de la tache : ");
    scanf( " %[^\n]",ajt.description);

    do{
        printf(" ajouter le status ( 0:TODO/ 1:DOING/ 2:DONE ) :");
        scanf("%d",&n);
        ajt.st=n;
    }while(ajt.st<0 || ajt.st > 2);

    printf("the task add Successfully !\n");

    return ajt;
    }
int main(){
    // ajtplusieurtaches
    int nbrTache = 0;
    tache T[100];
    int t;

    int choix;
    do{
    printf("_____________________________MENU_____________________________\n");
        printf("cliquez sur 1 pour Ajouter une nouvelle tache  :\n");
        printf("cliquez sur 2 pour  Ajouter une plusieur tache  :\n");
        printf("cliquez sur 3 pour Afficher toutes les taches  :\n");
        printf("cliquez sur 4 pour trier les taches par ordre alphabetique :\n");
        printf("cliquez sur 5 pour trier les taches par deadline  :\n");
        printf("cliquez sur 6 pour afficher les taches avec un deadline dans 3 jours ou moins :\n");
        printf("cliquez sur 7 pour Modifier une tâche : \n");
	    printf("cliquez sur 8 pour Modifier la description d'une tâche : \n");
        printf("cliquez sur 9 pour Modifier le statut d’une tâche :\n");
	    printf("cliquez sur 10 pour Modifier le deadline d’une tâche :\n");
	    printf("cliquez sur 11 pour Supprimer une tâche par identifiantk :\n");
	    printf("cliquez sur 12 pour Rechercher les Tâches :\n");
	    printf("cliquez sur 13 pour Rechercher une tâche par son Identifiant :\n");
	    printf("cliquez sur 14 pour Rechercher une tâche par son Titre :\n");
	    printf("cliquez sur 15 pour Afficher le nombre total des tâches  :\n");
	    printf("cliquez sur 16 pourAfficher le nombre de tâches complètes etincomplètes :\n");
	    printf("cliquez sur 17 pour Afficher le nombre de jours restants jusqu'au délai de chaque tâche:\n");
	    printf("\n entrez votre choix s'il vous plait :");
	   scanf("%d",&choix);
	switch (choix){
		case 1:
            ajouteTache();
			break;
        case 2:
           printf("combien de tache peut ajouter :");
    scanf("%d",&t);
    int j = nbrTache;
    for(int i=j; i < t+j; i++) {// hit 100 khwya nbr de tach li ki3mrha o matatsali hta tzid nbr li baghi utilisateur
        T[i] = ajouteTache();
        nbrTache++;
    }
            break;
            case 3:
}

 }while(choix!=15);


    return 0;
}

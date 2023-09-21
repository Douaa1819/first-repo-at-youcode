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
	     typedef enum statut {
	     TODO,
	     DOING,
	     DONE}statut;
         // data struct de tache(Titre ,description,status,deadline et identificateur
	     typedef struct{
	     char titre[50],description[200];
	     statut st;
	     int id;
	     date deadline;
	     }tache;
	     tache T[100];
int compt = 0;
tache ajt[100];
	   // ajouter une tache
	     tache ajouteTache() {
    int n;
    printf("Entrez un unique identifiant : ");
    scanf("%d", &ajt[compt].id);

    printf("Entrez le titre de la tache : ");
    scanf(" %[^\n]",ajt[compt].titre);
    printf("Entrez la description de la tache : ");
    scanf( " %[^\n]",ajt[compt].description);
    printf("deadline  de task  \n");
    do {
        printf (" entrer jour :");
        scanf(" %d",&ajt[compt].deadline.jour);
    }while(ajt[compt].deadline.jour<0 || ajt[compt].deadline.jour>31);

    do{
        printf (" \n entrer le mois :");
        scanf(" %d",&ajt[compt].deadline.mois);
    }while (ajt[compt].deadline.mois<=0  || ajt[compt].deadline.mois>12);

    do{
        printf (" \n entre annee :");
        scanf(" %d",&ajt[compt].deadline.annee);
    }while (ajt[compt].deadline.annee<1940 || ajt[compt].deadline.annee> 10000 );

    do {
        printf (" \n  entrer lheur :");
        scanf("%d",&ajt[compt].deadline.heurs);
    }while (ajt[compt].deadline.heurs<=0 || ajt[compt].deadline.heurs >24 );


    do{
        printf(" ajouter le status ( 0:TODO/ 1:DOING/ 2:DONE ) :");
        scanf("%d",&n);
        ajt[compt].st=n;
    }while(ajt[compt].st<0 || ajt[compt].st > 2);
    compt++;

    printf("the task %d add Successfully !\n", compt);

    }
// Affiche une tâche
void afficherTache(){

for (int x = 0;x<compt;x++){
    printf("**ID %-15d | Titre %-12s |Deadline %d/%d/%d/%-5d | ",ajt[x].id,ajt[x].titre,ajt[x].deadline.annee,ajt[x].deadline.mois,ajt[x].deadline.jour,ajt[x].deadline.heurs);
    switch(ajt[x].st){
        case 0: printf("status : TODO\n");

        break;
        case 1 :printf("status : DOING\n");
        break;
        case 2 : printf("status : Done\n");
        break;

    }
}

}
void trierEtAfficherTachesAlphabetique() {

        tache temp;
        int e,f;
         for (int a = 1; a <= f; a++)
         {
                 temp = ajt[a];
                 e = a - 1;
        while (e >= 0 && strcmp(ajt[e].titre, temp.titre) > 0)
                {      ajt[e + 1] = ajt[e];
                 e = e - 1;
                 }
                 ajt[e + 1] = temp;
         }

     printf("\nListe de toutes les tâches triées par ordre alphabétique\n");
     if (f == -1) {
         printf("Aucune tâche trouvée.\n");
        return;
     }
    printf("%-10s %-20s %-30s %-15s %-20s\n", "ID", "Titre", "Description", "Deadline");
     for (int e = 0; e <= f; e++) {
        printf("%-10d %-20s %-30s %d/%d/%d/%-5d |\n",ajt[e].id, ajt[e].titre, ajt[e].description, ajt[e].deadline.annee,ajt[e].deadline.mois,ajt[e].deadline.jour,ajt[e].deadline.heurs);
         switch(ajt[e].st){
        case 0: printf("status : TODO\n");
        break;
        case 1 :printf("status : DOING\n");
        break;
        case 2 : printf("status : Done\n");
        break;

    }
    }}
// modifier

int main(){
    // ajtplusieurtaches
    int nbrTache = 0;
    int t;
    int k;
    int choix;

    do{
    printf("_____________________________MENU_____________________________\n");
        printf("cliquez sur 1 pour Ajouter une nouvelle tache  :\n");
        printf("cliquez sur 2 pour  Ajouter une plusieur tache  :\n");
        printf("cliquez sur 3 pour Afficher toutes les taches  :\n");
        printf("cliquez sur 4 pour Modifier une tâche : \n");
	    printf("cliquez sur 5 pour Supprimer une tâche par identifiantk :\n");
	    printf("cliquez sur 6 pour Rechercher les Tâches :\n");
	    printf("cliquez sur 7 pour les statistique  :\n");
	    printf("cliquez sur 8 pour Quitter  :\n");
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
            case 3:do {printf("______________________sous MENU____________________________\n");
        printf("cliquez sur 1 pour Trier les tâches par ordre alphabétique  :\n");
        printf("cliquez sur 2 pour  Trier les tâches par deadline :\n");
        printf("cliquez sur 3 pour Afficher les tâches dont le deadline est dans 3 jours ou moins :\n");
        scanf("%d",&k);
            switch(k){
            case 1:
                afficherTache();
                trierEtAfficherTachesAlphabetique();
                break;
            }
            }while(k);

	break;
	}
 }while(choix != 8);

    return 0;
}

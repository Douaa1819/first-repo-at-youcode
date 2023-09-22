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
        int d=1;
int compt = 0;
tache ajt[100];
tache T[100];
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
// Affiche une t�che
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

     printf("\nListe de toutes les t�ches tri�es par ordre alphab�tique\n");
     if (f == -1) {
         printf("Aucune t�che trouv�e.\n");
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
// statistique
/*int stats(){

        while(d<compt){
            printf("la tache num %-20d ----> \n",d);
            printf("Titre : %-20s  \n",ajt[d].titre);
            printf("description : %-20s  \n",ajt[d].description);
            printf("combien de jour reste  :  %-20d  \n",ajt[d].deadline);
            printf("ID de tache %d:   \n",ajt[d].id);
             switch(ajt[compt].st){
        case 0: printf("status : TODO\n");

        break;
        case 1 :printf("status : DOING\n");
        break;
        case 2 : printf("status : Done\n");
        break;

    }

            d++ ;

        }
}*/


// modification


 void modif_desc(int x){
    char n[100];
        printf("*************|Modifier la description|*************") ;
        printf("donner un nouveau description : ");
        scanf(" %[^\n]",n);
        strcpy(ajt[x].description,n);}

        void modif_deadline(int x){
    char n[100];
        printf("**********|Modifier deadline|********** ");
        printf("donner un noveau deadline : ");
        scanf(" %[^\n]",n);
        strcpy(ajt[x].deadline,n);}

 int main(){
    // ajtplusieurtaches
    int nbrTache = 0;
    int t,k;
    int choix;

    do{
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
            case 3:do {printf("______________________sous MENU de l afichage____________________________\n");
        printf("cliquez sur 1 pour Trier les t�ches par ordre alphab�tique  :\n");
        printf("cliquez sur 2 pour  Trier les t�ches par deadline :\n");
        printf("cliquez sur 3 pour Afficher les t�ches dont le deadline est dans 3 jours ou moins :\n");
        scanf("%d",&k);
            switch(k){
            case 1:
                afficherTache();
                trierEtAfficherTachesAlphabetique();
                break;
            }
            }while(k);

	break;
	case 4:do {printf("______________________sous MENU de modifier une tache____________________________\n");
        printf("cliquez sur 1 pour modifier la description d'une tache :\n");
        printf("cliquez sur 2 pour modifier le statut d�une tache :\n");
        printf("cliquez sur 3 pour modifier le deadline d�une tache:\n");
        scanf("%d",&k);
        switch(choix){
            case 1:intvoid modif_desc();
            break;
            case 2:
                break;
                case 3:
        void modif_deadline();






        }

    case 5:
    case 6:do {printf("______________________sous MENU de RECHERCHER les tache____________________________\n");
        printf("cliquez sur 1 pour rechercher une tache par son Identifiant:\n");
        printf("cliquez sur 2 pour Rechercher une tache par son Titre :\n");
        scanf("%d",&k)
	case 7 :
	    do {printf("______________________sous MENU Les Statistique____________________________\n");
        printf("cliquez sur 1 pour afficher le nombre total des t�ches :\n");
        printf("cliquez sur 2 pour afficher le nombre de taches compl�tes et incompl�tes :\n");
        printf("cliquez sur 3 pour afficher le nombre de jours restants jusqu'au d�lai de chaque t�che:\n");
        scanf("%d",&k);

        /*if (compt==1){
                        printf("choix invalide !!");

                    }
                   stats();
                   d = 1;
                    break;*/
	}


 }while(choix != 8);

    return 0;
}

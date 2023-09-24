#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct date
{
	int year;
	int month;
	int day;
} date;
typedef struct tache
{
	int id;
	char titre[50];
	char description[100];
	date deadline;
	char status[100];
} tache;
tache Tache[100];
int k, i = -1;
int is_valid_date(int day, int month, int year)
{
	if (year < 0 || month < 1 || month > 12)
		return 0;

	int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};  //  fevrier
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		days_in_month[2] = 29;

	return day >= 1 && day <= days_in_month[month];
}

void afficheMenu()
{
	printf("\n____________________________________Menu____________________________________\n");
	printf(" 1. Ajouter une nouvelle tache                                    \n");
	printf(" 2. Ajouter Plusieur taches                                       \n");
	printf(" 3. Afficher la liste de toutes les taches                        \n");
	printf(" 4. Modifier une tache                                            \n");
	printf(" 5. Rechercher les Taches                                         \n");
	printf(" 6. Voir les Statistiques                                         \n");
	printf(" 7. Supprimer une tache par Identifiant                           \n");
	printf(" 8. Exit le Programme                                             \n");
;
}
int nbrSuppr = 0;

void ajoutertache()
{
	int n,j;
	int compt = 0;
debut:
	printf("\n Ajouter une Nouvelle Tache :\n");
	i++;
	Tache[i].id = i + 1 + nbrSuppr;
	printf("Entrer un Titre %d : ", i + 1);
	scanf(" %[^\n]", Tache[i].titre);
	printf("Ajouter une Description : ");
	scanf(" %[^\n]", Tache[i].description);
	do
	{
		j = 1;
		printf("Entrer un Deadline de votre Tache\nEntrer l year : ");
		scanf("%d", &Tache[i].deadline.year);

		printf("Entrer le Mois : ");
		scanf("%d", &Tache[i].deadline.month);

		printf("Entrer le Jour  : ");
		scanf("%d", &Tache[i].deadline.day);

		if (!is_valid_date(Tache[i].deadline.day, Tache[i].deadline.month, Tache[i].deadline.year))
		{
			printf("Date invalide. Veuillez saisir une date valide.\n");
			j = 0;
		}
	} while (j != 1);
	do
	{
		printf(" \n\"1 - ToDo\"\n\"2 - Doing\"\n\"3 - Done\"\nEntrer le Status de la tache: 1 or 2 or 3 : ");
		scanf(" %[^\n]", Tache[i].status);
		n = atoi(Tache[i].status);
		switch (n)
		{
		case 1:
			strcpy(Tache[i].status, "To do");
			compt++;
			break;
		case 2:
			strcpy(Tache[i].status, "Doing");
			compt++;
			break;
		case 3:
			strcpy(Tache[i].status, "Done");
			compt++;
			break;
		default:
			printf("nombre n est pas exist");
		}
	} while (n != 1 && n != 2 && n != 3);
	if (compt != 0)
	{
		printf("                      \n");
		printf("  \t votre tache numro %d et ajoutee  \t \n", i + 1);
		printf("                   \n");
	}
	if (k == 1)
	{
		printf("si vous avez continue entre 1 ou bien autre chiffre pour terminer : ");
		scanf("%d", &k);
	}
	if (k == 1)
		goto debut;
}

void trierEtAfficherTachesAlphabetique()
{

	tache temp;
	int j;
	for (int a = 1; a <= i; a++)
	{
		temp = Tache[a];
		j = a - 1;
		while (j >= 0 && strcmp(Tache[j].titre, temp.titre) > 0)
		{
			Tache[j + 1] = Tache[j];
			j--;
		}
		Tache[j + 1] = temp;
	}

	printf("\nListe de toutes les tâches triées par ordre alphabétique\n");
	if (i == -1)
	{
		printf("Aucune tâche trouvée.\n");
		return;
	}
	printf("%-10s %-20s %-30s %-15s %-20s\n", "ID", "Titre", "Description", "Deadline", "Statut");
	for (int j = 0; j <= i; j++)
	{
		printf("%-10d %-20s %-30s %d/%d/%-8d %-20s\n", Tache[j].id, Tache[j].titre, Tache[j].description, Tache[j].deadline.year, Tache[j].deadline.month, Tache[j].deadline.day, Tache[j].status);
	}
}

void trierEtAfficherTachesParDeadline()
{
	tache temp;
	int j;
	for (int a = 1; a <= i; a++)
	{
		temp = Tache[a];
		j = a - 1;

		while (j >= 0 && (Tache[j].deadline.year > temp.deadline.year || (Tache[j].deadline.year == temp.deadline.year && (Tache[j].deadline.month > temp.deadline.month || (Tache[j].deadline.month == temp.deadline.month && Tache[j].deadline.day > temp.deadline.day)))))
		{
			Tache[j + 1] = Tache[j];
			j = j - 1;
		}
		Tache[j + 1] = temp;
	}
	printf("\nListe de toutes les tâches triées par deadline\n");
	if (i == -1)
	{
		printf("Aucune tâche trouvée.\n");
		return;
	}
	printf("%-10s %-20s %-30s %-15s %-20s\n", "ID", "Titre", "Description", "Deadline", "Statut");
	for (int j = 0; j <= i; j++)
	{
		printf("%-10d %-20s %-30s %d/%d/%-8d %-20s\n", Tache[j].id, Tache[j].titre, Tache[j].description, Tache[j].deadline.year, Tache[j].deadline.month, Tache[j].deadline.day, Tache[j].status);
	}
}

void afficherTachesTroisJoursOuMoins()
{
	printf("\n Liste de toutes les tâches avec un délai de trois jours ou moins\n");
	if (i == -1)
	{
		printf("Aucune tâche trouvée.\n");
		return;
	}

	time_t now = time(NULL);
	struct tm *current_time = localtime(&now);
	current_time->tm_hour = 0;
	current_time->tm_min = 0;
	current_time->tm_sec = 0;

	time_t trois_jours_plus_tard = now + (3 * 24 * 60 * 60);

	printf("%-10s %-20s %-30s %-15s %-20s\n", "ID", "Titre", "Description", "Deadline", "Statut");
	for (int j = 0; j <= i; j++)
	{
		struct tm deadline_tm = {0};
		deadline_tm.tm_year = Tache[j].deadline.year - 1900;
		deadline_tm.tm_mon = Tache[j].deadline.month - 1;
		deadline_tm.tm_mday = Tache[j].deadline.day;

		time_t deadline_time = mktime(&deadline_tm);

		if (deadline_time <= trois_jours_plus_tard && deadline_time >= now)
		{
			printf("%-10d %-20s %-30s %d/%d/%-8d %-20s\n", Tache[j].id, Tache[j].titre, Tache[j].description,
				   Tache[j].deadline.day, Tache[j].deadline.month, Tache[j].deadline.year, Tache[j].status);
		}
	}
}

void modifierDescriptionTache()
{
	int id;
	printf("Entrez l'ID de la tache à modifier : ");
	scanf("%d", &id);

	for (int j = 0; j <= i; j++)
	{

		if (Tache[j].id == id)
		{
			printf("Nouvelle description : ");
			scanf(" %[^\n]", Tache[j].description);
			printf("Description modifiée avec succès.\n");
			return;
		}
	}
	printf("Tache avec l'ID %d non trouvée.\n", id);
}

void modifierStatutTache()
{
	int id, n, compt = 0;
	printf("Entrez l'ID de la tâche à modifier : ");
	scanf("%d", &id);

	for (int j = 0; j <= i; j++)
	{
		if (Tache[j].id == id)
		{
			do
			{
				printf(" \n\"1 - ToDo\"\n\"2 - Doing\"\n\"3 - Done\"\n Nouveau statut : 1 or 2 or 3 : ");
				scanf(" %[^\n]", Tache[i].status);
				n = atoi(Tache[i].status);
				switch (n)
				{
				case 1:
					strcpy(Tache[i].status, "Todo");
					compt++;
					break;
				case 2:
					strcpy(Tache[i].status, "Doing");
					compt++;
					break;
				case 3:
					strcpy(Tache[i].status, "Done");
					compt++;
					break;
				default:
					printf("nombre n est pas exist");
				}
			} while (n != 1 && n != 2 && n != 3);
			return;
		}
	}
	printf("Tache avec l'ID %d non trouve.\n", id);
}

void modifierDeadlineTache()
{
	int id, j;
	printf("Entrez l'ID de la tache a modifier : ");
	scanf("%d", &id);

	for (int j = 0; j <= i; j++)
	{
		if (Tache[j].id == id)
		{
			do
			{
				j = 1;
				printf("Entrer un Deadline de votre Tache\nEntrer l year : ");
				scanf("%d", &Tache[i].deadline.year);

				printf("Entrer le Mois : ");
				scanf("%d", &Tache[i].deadline.month);

				printf("Entrer le Jour  : ");
				scanf("%d", &Tache[i].deadline.day);

				if (!is_valid_date(Tache[i].deadline.day, Tache[i].deadline.month, Tache[i].deadline.year))
				{
					printf("Date invalide. Veuillez saisir une date valide.\n");
					j = 0;
				}
			} while (j != 1);
		}
		else
			printf("Tâche avec l'ID %d non trouvée.\n", id);
	}
}

void rechercherParIdentifiant()
{
	int id;
	printf("Entrez l'Identifiant de la tache a rechercher : ");
	scanf("%d", &id);

	for (int j = 0; j <= i; j++)
	{
		if (Tache[j].id == id)
		{
			printf("%-10s %-20s %-30s %-15s %-20s\n", "ID", "Titre", "Description", "Deadline", "Statut");
			printf("%-10d %-20s %-30s %d/%d/%-8d %-20s\n", Tache[j].id, Tache[j].titre, Tache[j].description, Tache[j].deadline.year, Tache[j].deadline.month, Tache[j].deadline.day, Tache[j].status);
			return;
		}
	}
	printf("Tâche avec l'ID %d non trouvée.\n", id);
}

void rechercherParTitre()
{
	char titreRecherche[50];
	printf("Entrez le Titre de la tache à rechercher : ");
	scanf(" %[^\n]", titreRecherche);

	int trouve = 0;
	for (int j = 0; j <= i; j++)
	{
		if (strcmp(Tache[j].titre, titreRecherche) == 0)
		{
			if (trouve == 0)
			{
				printf("%-10s %-20s %-30s %-15s %-20s\n", "ID", "Titre", "Description", "Deadline", "Statut");
			}
			printf("%-10d %-20s %-30s %d/%d/%-8d %-20s\n", Tache[j].id, Tache[j].titre, Tache[j].description, Tache[j].deadline.year, Tache[j].deadline.month, Tache[j].deadline.day, Tache[j].status);
			trouve = 1;
		}
	}

	if (trouve == 0)
	{
		printf("Aucune tâche avec le titre '%s' trouvée.\n", titreRecherche);
	}
}

void afficherNombreTotalTaches()
{
	printf("Le nombre total de taches est : %d\n", i + 1);
}

void afficherNombreTachesCompletesEtIncompletes()
{
	int completes = 0;
	int incompletes = 0;

	for (int j = 0; j <= i; j++)
	{
		if (strcmp(Tache[j].status, "Done") == 0)
			completes++;
		else
			incompletes++;
	}

	printf("Nombre de taches completes : %d\n", completes);
	printf("Nombre de taches incomplètes : %d\n", incompletes);
}

void afficherNombreJoursRestants()
{
	time_t now = time(NULL);

	printf("%-10s %-20s %-30s %-15s %-20s %-15s\n", "ID", "Titre", "Description", "Deadline", "Statut", "Jours Restants");
	for (int j = 0; j <= i; j++)
	{
		struct tm deadline_tm = {0};
		deadline_tm.tm_year = Tache[j].deadline.year - 1900;
		deadline_tm.tm_mon = Tache[j].deadline.month - 1;
		deadline_tm.tm_mday = Tache[j].deadline.day;

		time_t deadline_time = mktime(&deadline_tm);
		int joursRestants = (int)((deadline_time - now) / (24 * 60 * 60));

		printf("%-10d %-20s %-30s %d/%d/%-8d %-20s %-15d\n", Tache[j].id, Tache[j].titre, Tache[j].description,
			   Tache[j].deadline.day, Tache[j].deadline.month, Tache[j].deadline.year, Tache[j].status, joursRestants);
	}
}
void supprimerTacheParIdentifiant()
{
    nbrSuppr++;
	int taskId;
	printf("Entrez l'Identifiant de la tache à supprimer : ");
	scanf("%d", &taskId);

	int trouve = 0;
	for (int j = 0; j <= i; j++)
	{
		if (Tache[j].id == taskId)
		{
			// Shift elements to remove the task
			for (int k = j; k < i; k++)
			{
				Tache[k] = Tache[k + 1];
			}
			i--; // Decrement the total task compt
			trouve = 1;
			printf("Tâche avec l'ID %d supprimée.\n", taskId);
			break;
		}
	}

	if (trouve == 0)
	{
		printf("Tâche avec l'ID %d non trouve\n", taskId);
	}
}

int main()
{
	char choice[10];
	int n;

	do
	{
	debut:
		afficheMenu();
		printf("\nVeuillez entrer un choix parmi les options du Menu Principal : ");
		scanf(" %[^\n]", choice);
		n = atoi(choice);
		switch (n)
		{
		case 1:
			k = 0;
			ajoutertache();
			break;
		case 2:
			k = 1;
			ajoutertache();
			break;
		case 3:
			do
			{
			debut1:
				printf(" _______ sous Menu_____\n");
				printf(" 1 - Trier les taches par ordre alphabétique                          \n");
				printf(" 2 - Trier les tches par deadline                                    \n");
				printf(" 3 - Afficher les taches dont le deadline est dans 3 jours ou moins   \n");
				printf(" 4 - Retour au Menu Principal                                         \n");
				printf(" \n");
				printf("  Veuillez entrer un choix parmi les options de tri : ");
				scanf(" %[^\n]", choice);
				n = atoi(choice);
				switch (n)
				{
				case 1:
					trierEtAfficherTachesAlphabetique();
					break;
				case 2:
					trierEtAfficherTachesParDeadline();
					break;
				case 3:
					afficherTachesTroisJoursOuMoins();
					break;
				case 4:
					break;
				default:
					printf("\n---------- votre choix invalide ----------\n");
					goto debut1;
				}
			} while (n != 4);
			break;
		case 4:
			do
			{
			debut2:
				printf(" 1 - Modifier la description d'une tâche                              \n");
				printf(" 2 - Modifier le statut d'une tâche                                   \n");
				printf("3 - Modifier le deadline d'une tâche                                 \n");
				printf(" 4 - Retour au Menu Principal                                         \n");
				printf(" \n");
				printf("Veuillez entrer un choix pour la modification : ");
				scanf(" %[^\n]", choice);
				n = atoi(choice);
				switch (n)
				{
				case 1:
					modifierDescriptionTache();
					break;
				case 2:
					modifierStatutTache();
					break;
				case 3:
					modifierDeadlineTache();
					break;
				case 4:
					break;
				default:
					printf("---------- votre choix n'est pas exist ---------");
					goto debut2;
				}
			} while (n != 4);
			break;
		case 5:
			do
			{
			debut3:
				printf("  _______ sous Menu_____\n");
				printf(" 1 - Rechercher une tâche par son Identifiant                        \n");
				printf(" 2 - Rechercher une tâche par son Titre                              \n");
				printf(" 3 - Retour au Menu Principal                                        \n");
				printf(" \n");
				printf("Veuillez entrer un choix pour la recherche : ");
				scanf(" %[^\n]", choice);
				n = atoi(choice);
				switch (n)
				{
				case 1:
					rechercherParIdentifiant();
					break;
				case 2:
					rechercherParTitre();
					break;
				case 3:
					break;
				default:
					printf("---------- votre choix invalide ----------\n");
					goto debut3;
				}
			} while (n != 3);
			break;
		case 6:
			do
			{
			debut4:
				printf("  _______ sous Menu_____\n");
				printf(" 1 - Afficher le nombre total des taches                                   \n");
				printf(" 2 - Afficher le nombre de taches completes et incomplète                  \n");
				printf(" 3 - Afficher le nombre de jours restants jusqu'au délai de chaque tache   \n");
				printf("4 - retour au Menu Principal                                              \n");
				printf("entrer votre choix s'il vous plait : ");
				scanf(" %[^\n]", choice);
				n = atoi(choice);
				switch (n)
				{
				case 1:
					afficherNombreTotalTaches();
					break;
				case 2:
					afficherNombreTachesCompletesEtIncompletes();
					break;
				case 3:
					afficherNombreJoursRestants();
					break;
				case 4:
					break;
				default:
					printf("---------- votre choix invalide ----------\n");
					goto debut2;
				}
			} while (n != 4);
			break;
		case 7:
			supprimerTacheParIdentifiant();
			break;
		case 8:
			printf("----------| fin programme |----------\n");
			break;
		default:
			printf("---------- votre choix  invalide ----------\n");
			goto debut;
		}
	} while (n != 8);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>//pour sys 'pause' et sys'CLS'
#include<conio.h>//pour l'utulisation de getch()
typedef struct {
    int id;
    char marque[50];
    char utilisateur[50];
    char modele[50];
    char carburant[50];
    int places;
    float prix;
    char disponibilite[50];
} Voiture;//structure principal de voiture

Voiture* createProject(Voiture *voitures, int *nbVoitures, int *capacity) {
    if (*nbVoitures >= *capacity) {
        *capacity *= 2;
        voitures = (Voiture*)realloc(voitures, *capacity * sizeof(Voiture));
        if (voitures == NULL) {
            printf("Memory reallocation failed.\n");
            exit(1);// pour indiquer qu'il q un erreur et terminer le progrqmme
        }
    }
    return voitures;
}

void destroyProject(Voiture *voitures) {
    free(voitures);
}

void ajouterVoiture(Voiture *voiture, int *nbVoitures, int *capacity) {
    voiture = createProject(voiture, nbVoitures, capacity);  // pour redemonsioner le tableau si il'est plein

    voiture[*nbVoitures].id = *nbVoitures + 1;

    printf("Entrez la marque de la voiture: ");
    scanf("%s", voiture[*nbVoitures].marque);

    printf("Entrez l'utilisateur de la voiture: ");
    scanf("%s", voiture[*nbVoitures].utilisateur);

    printf("Entrez le modele de la voiture: ");
    scanf("%s", voiture[*nbVoitures].modele);

    printf("Entrez le carburant de la voiture: ");
    scanf("%s", voiture[*nbVoitures].carburant);

    printf("Entrez le nombre de places de la voiture: ");
    scanf("%d", &voiture[*nbVoitures].places);

    printf("Entrez le prix de la voiture: ");
    scanf("%f", &voiture[*nbVoitures].prix);

    printf("Entrez la disponibilite de la voiture: ");
    scanf("%s", voiture[*nbVoitures].disponibilite);

    (*nbVoitures)++;

    FILE *fichier = fopen("voitures.txt", "a");  //ouvrire le fichier voiture .txt  "a" pour ajouter les voiture sans perder les ancienne append mode data ecrit en fin de fichier 
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(1);
    }
    fprintf(fichier, "%d,%s,%s,%s,%s,%d,%.2f,%s\n",
            voiture[*nbVoitures - 1].id, voiture[*nbVoitures - 1].marque, voiture[*nbVoitures - 1].utilisateur,
            voiture[*nbVoitures - 1].modele, voiture[*nbVoitures - 1].carburant, voiture[*nbVoitures - 1].places,
            voiture[*nbVoitures - 1].prix, voiture[*nbVoitures - 1].disponibilite);
    fclose(fichier);//fermer le fichier apres lecriture du data 

    printf("Voiture ajoutee avec succes.\n");
}

void modifierVoiture(Voiture *voiture, int nbVoitures) {
    int id;
    printf("Entrez l'ID de la voiture que vous souhaitez modifier: ");
    scanf("%d", &id);

    for (int i = 0; i < nbVoitures; i++) {//boucle qui cherche sur l*id est aficher les les donner pour les changer
        if (voiture[i].id == id) {
            printf("Entrez la nouvelle marque de la voiture: ");
            scanf("%s", voiture[i].marque);

            printf("Entrez le nouvel utilisateur de la voiture: ");
            scanf("%s", voiture[i].utilisateur);

            printf("Entrez le nouveau modele de la voiture: ");
            scanf("%s", voiture[i].modele);

            printf("Entrez le nouveau carburant de la voiture: ");
            scanf("%s", voiture[i].carburant);

            printf("Entrez le nouveau nombre de places de la voiture: ");
            scanf("%d", &voiture[i].places);

            printf("Entrez le nouveau prix de la voiture: ");
            scanf("%f", &voiture[i].prix);

            printf("Entrez la nouvelle disponibilite de la voiture: ");
            scanf("%s", voiture[i].disponibilite);

            printf("Voiture modifiee avec succes.\n");
            return;
        }
    }
    printf("Aucune voiture avec cet ID n'a ete trouvee.\n");
}

void supprimerVoiture(Voiture *voiture, int *nbVoitures) {
    int id;
    printf("Entrez l'ID de la voiture que vous souhaitez supprimer: ");
    scanf("%d", &id);

    int i, j;
    int voitureTrouvee = 0;
    for (i = 0; i < *nbVoitures; i++) {
        if (voiture[i].id == id) {
            voitureTrouvee = 1;//si la voiture avec lid est trouver

            for (j = i; j < *nbVoitures - 1; j++) {
                voiture[j] = voiture[j + 1];
            }
            (*nbVoitures)--; //shifte le voiture apres la voiture du id 
            printf("Voiture supprimee avec succes.\n");
            break;
        }
    }

    if (!voitureTrouvee) {
        printf("Aucune voiture avec cet ID n'a ete trouvee.\n");
    }
}

void afficherVoitures(Voiture *voiture, int nbVoitures) {
    printf("Liste des voitures :\n");
    printf("-------------------------------------------------------------------------------------------------------------------\n");
    printf("| ID | Marque       | Utilisateur    | Modele        | Carburant     | Places | Prix   | Disponibilite |\n");
    printf("-------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < nbVoitures; i++) {
        printf("| %-2d | %-12s | %-14s | %-12s | %-12s | %-6d | %-6.2f | %-13s |\n",
               voiture[i].id, voiture[i].marque, voiture[i].utilisateur, voiture[i].modele, voiture[i].carburant,
               voiture[i].places, voiture[i].prix, voiture[i].disponibilite);//-%12s on est utuliser le moins pour signifier que lq chqine de caracter sera afficher dans un espace de largeur fix 
    }
    printf("-------------------------------------------------------------------------------------------------------------------\n");
}

void rechercherVoiture(Voiture *voitures, int nbVoitures, char *marque, char *disponibilite) {//une simple fonction qui prend la marque , la disponsibilte est afficher les donner du voiture preciser
    printf("Resultats de la recherche pour la marque '%s' et disponibilite '%s':\n", marque, disponibilite);
    printf("-------------------------------------------------------------------------------------------------------------------\n");
    printf("| ID | Marque       | Utilisateur    | Modele        | Carburant     | Places | Prix   | Disponibilite |\n");
    printf("-------------------------------------------------------------------------------------------------------------------\n");
    int found = 0;
    for (int i = 0; i < nbVoitures; i++) {
        if (strcmp(voitures[i].marque, marque) == 0 && strcmp(voitures[i].disponibilite, disponibilite) == 0) {
            printf("| %-2d | %-12s | %-14s | %-12s | %-12s | %-6d | %-6.2f | %-13s |\n",
                   voitures[i].id, voitures[i].marque, voitures[i].utilisateur, voitures[i].modele,
                   voitures[i].carburant, voitures[i].places, voitures[i].prix, voitures[i].disponibilite);
            found = 1;
        }
    }
    if (!found) {
        printf("Aucun vehicule trouve pour la marque '%s' et disponibilite '%s'.\n", marque, disponibilite);
    }
    printf("-------------------------------------------------------------------------------------------------------------------\n");
}

void trierVoitures(Voiture *voitures, int nbVoitures, char *critere) {
    int i, j;
    Voiture temp;

    if (strcmp(critere, "prix") == 0) {
        int choixTri;
        printf("1. Tri par prix croissant\n");
        printf("2. Tri par prix decroissant\n");
        printf("Entrez votre choix de tri : ");
        scanf("%d", &choixTri);

        switch (choixTri) {
            case 1://un algo qui parcourt le tableau plusieur fois en comparant et echangeant les elements adjacents en fonction du critere de tri prix dans ce cas
                for (i = 0; i < nbVoitures - 1; i++) {
                    for (j = 0; j < nbVoitures - i - 1; j++) {
                        if (voitures[j].prix > voitures[j + 1].prix) {
                            temp = voitures[j];//emp c'est comme une voiture temporaire por ne pas perder la voiture
                            voitures[j] = voitures[j + 1];
                            voitures[j + 1] = temp;
                        }
                    }
                }
                break;
            case 2:
                for (i = 0; i < nbVoitures - 1; i++) {//le meme algorithm mais ici decroissant
                    for (j = 0; j < nbVoitures - i - 1; j++) {
                        if (voitures[j].prix < voitures[j + 1].prix) {
                            temp = voitures[j];
                            voitures[j] = voitures[j + 1];
                            voitures[j + 1] = temp;
                        }
                    }
                }
                break;
            default:
                printf("Choix de tri non valide.\n");
                return;
        }
    } else if (strcmp(critere, "marque") == 0) {//ici trie par  marque on utulise strcmp pour la comparaison
        for (i = 0; i < nbVoitures - 1; i++) {
            for (j = 0; j < nbVoitures - i - 1; j++) {
                if (strcmp(voitures[j].marque, voitures[j + 1].marque) > 0) {
                    temp = voitures[j];
                    voitures[j] = voitures[j + 1];
                    voitures[j + 1] = temp;
                }
            }
        }
    } else {
        printf("Critere de tri non valide.\n");
        return;
    }

    afficherVoitures(voitures, nbVoitures);
}
int login() {//une fct de login pour securiser notre sys et le mot de pass c'est admin par default
    char pass[50];
    char ch;
    int i = 0;

    printf("\n\n\n\n\n\n\n\n\tLOCATION DES VOITURE PROGRAMME \n\n");
    printf("\t------------------------------");
    printf("\n\tLOGIN \n");
    printf("\t------------------------------\n\n");
    printf("\tEnter Password: ");

    while (1) {
        ch = getch(); // Utuliser getch() pour lire les mot sans afficher
        if (ch == 13) // Enter key
            break;
        pass[i] = ch;
        printf("*");
        i++;
    }
    pass[i] = '\0'; // la fin (null)

    if (strcmp(pass, "admin") == 0) {
        printf("\n\n\n\tAccess Granted! \n");
        system("PAUSE");
        system("CLS");
        return 1; // Login successful
    } else {
        printf("\n\n\tAccess Aborted...\n\tPlease Try Again\n\n");
        system("PAUSE");
        system("CLS");
        return 0; // Login failed et la fin du program
    }
}

int main() {//la main fonction
	 char username[50];
    

	 printf("Enter your username: ");
    scanf("%s", username);
    if (!login()) {
        return 0; 
    }
    Voiture voitures[100];
    int nbVoitures = 0;
    int capacity = 100;

    int choix;
    do {
    	printf("\n************ GESTION DES LIVRES ************\n");
        printf("1. Ajouter une voiture\n");
        printf("2. Modifier une voiture\n");
        printf("3. Supprimer une voiture\n");
        printf("4. Afficher les voitures\n");
        printf("5. Rechercher une voiture\n");
        printf("6. Trier les voitures\n");
        printf("7. Quitter\n");
        printf("*********************************\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterVoiture(voitures, &nbVoitures, &capacity);
                break;
            case 2:
                modifierVoiture(voitures, nbVoitures);
                break;
            case 3:
                supprimerVoiture(voitures, &nbVoitures);
                break;
            case 4:
                afficherVoitures(voitures, nbVoitures);
                break;
            case 5: {
                char marqueRecherche[50];
                char disponibiliteRecherche[50];

                printf("Entrez la marque à rechercher: ");
                scanf("%s", marqueRecherche);

                printf("Entrez la disponibilite à rechercher (oui/non): ");
                scanf("%s", disponibiliteRecherche);

                rechercherVoiture(voitures, nbVoitures, marqueRecherche, disponibiliteRecherche);
                break;
            }
            case 6: {
                char critereTri[20];
                printf("Entrez votre choix de tri (marque/prix): ");
                scanf("%s", critereTri);
                trierVoitures(voitures, nbVoitures, critereTri);
                break;
            }
            case 7:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
                break;
        }
    } while (choix != 7);

    destroyProject(voitures);  // Free allocated memory before exit
    return 0;
}


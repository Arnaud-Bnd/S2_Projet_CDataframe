//
// Created by Arnaud Bernard on 29/04/2024.
//
#include "../include/features.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *tab, int left, int right) {
    int pivot = tab[right];
    int i = left - 1;
    for (int j = left ; i <= right ; j++) {
        if (tab[j] < pivot) {
            i++;
            int temp = tab[i];
            tab[i] = tab[j];
            tab[j] = temp;
        }
    }
    int temp = tab[i + 1];
    tab[i + 1] = tab[right];
    tab[right] = temp;

    return i + 1;
}
void quicksort(int *tab, int left, int right) {
    if (left < right) {
        int pi = partition(tab, left, right);
        quicksort(tab, left, pi - 1);
        quicksort(tab, pi + 1, right);
    }
}


void sort(Column *col, SortType sort_dir) {
    /* Vérification de la taille de la colonne */
    if (col == NULL || col->data == NULL || col->T_Logique <= 1) {
        printf("La colonne est vide ou contient un seul élément.\n");
        return;
    }

    /* Vérifier que la colonne ne soit pas triée */

    /* Si la colonne est triée dans l'ordre souhaité*/
    if (col->mValidIndex == 1 && col->mSortDir == sort_dir) {
        printf("La colonne est déjà triée.\n");
        return;
    }

    /* Si la colonne n'est pas triée dans l'ordre souhaité */
    switch (sort_dir) {
        case asc: {
            /* Si la colonne n'est pas triée */
            if (col->mValidIndex == 0) {
                quicksort(col->data, 0, col->T_Logique - 1);
            }

            /* Si la colonne est partiellement triée */
            else if (col->mValidIndex == -1) {
                for (int i = 0; i < col->T_Logique - 1; i++) {
                    int max_idx = i;
                    for (int j = i + 1; j < col->T_Logique; j++) {
                        if (col->data[col->index[j]] < col->data[col->index[max_idx]]) {
                            max_idx = j;
                        }
                    }
                    if (max_idx != i) {
                        int temp = col->index[i];
                        col->index[i] = col->index[max_idx];
                        col->index[max_idx] = temp;
                    }
                }
            }

            break;
        }

        case desc: {
            /* Si la colonne n'est pas triée */
            if (col->mValidIndex == 0) {
                quicksort(col->data, 0, col->T_Logique - 1);
            }

            /* Si la colonne est partiellement triée */
            else if (col->mValidIndex == -1) {
                for (int i = 0; i < col->T_Logique - 1; i++) {
                    int min_idx = i;
                    for (int j = i + 1; j < col->T_Logique; j++) {
                        if (col->data[col->index[j]] > col->data[col->index[min_idx]]) {
                            min_idx = j;
                        }
                    }
                    if (min_idx != i) {
                        int temp = col->index[i];
                        col->index[i] = col->index[min_idx];
                        col->index[min_idx] = temp;
                    }
                }
            }

            break;
        }
    }

    /* Indiquer que la colonne a été triée */
    col->mValidIndex = 1;

    /* Indiquer l'ordre du tri de la colonne */
    col->mSortDir = sort_dir;
}




void printSortCdt(CDataFrame *cdt, int index){
    /* Vérification de la taille du CDataframe */
    if (cdt == NULL) {
        printf("Le pointeur CDataframe est NULL.\n");
        return;
    }

    if (cdt->mColumn[index]->mValidIndex != 1) {
        printf("La colonne n'est pas triée.\n");
        return;
    }

    /* Afficher le titre du CDataframe */
    printf("%s\n", cdt->mTitle);

    /* Vérification du nombre de colonnes */
    if (cdt->mNumColumns == 0) {
        printf("Le CDataframe n'a pas de colonnes.\n");
        return;
    }

    /* Boucle pour les titres des colonnes */
    printf("\t\t");
    for (int i = 0 ; i < cdt->mNumColumns ; i++) {
        // Afficher le titre de la colonne
        printf("%s\t\t", (char *) cdt->mColumn[i]->title);
    }
    printf("\n");

    /* Trouver la colonne avec le plus de lignes */
    uint64_t max_rows = (uint64_t)numberOfLines(cdt);

    /* Boucle pour les valeurs des colonnes */
    for (uint64_t j = 0 ; j < max_rows ; j++){   // Variation de la ligne
        /* Afficher le numéro de la ligne */
        printf("[%" PRIu64 "]\t\t", j + 1);

        /* Afficher les valeurs */
        for (int i = 0 ; i < cdt->mNumColumns ; i++) {    // Variation de la colonne
            for (int k = 0 ; i < cdt->mNumColumns ; k++) {    // Variation de l'index
                if (j == cdt->mColumn[index]->index[k]) {
                    // Afficher la valeur
                    printf("%d\t\t\t\t", cdt->mColumn[i]->data[k]);
                    break;
                }
            }
        }
        printf("\n"); // Passage à la ligne suivante
    }
    printf("\n");
}


void printColByIndex(Column *col) {
    /* Vérification du pointeur colonne */
    if (col == NULL) {
        printf("Le pointeur colonne est NULL.\n");
        return;
    }

    if (col->mValidIndex != 1) {
        printf("La colonne n'est pas triée.\n");
        return;
    }

    /* Afficher les données de la colonne triée */
    for (uint64_t i = 0 ; i < (uint64_t)col->T_Logique ; i++) {
        for (int j = 0 ; j < col->T_Logique ; j++) {
            if (i == col->index[j]) {
                printf("[%" PRIu64 "] : %" PRId32 "\n", col->index[j] + 1, col->data[j]);
            }
        }
    }
    printf("\n");
}


void eraseIndex(Column *col) {
    /* Libérer la mémoire allouée pour l'index */
    free(col->index);
    col->index = NULL;

    /* Mise à jour de l'attribut valid_index */
    col->mValidIndex = 0;
}


int checkIndex(Column *col) {
    return col->mValidIndex;
}


void updateIndex(Column *col) {
    sort(col, desc);
}


int searchValueInColumn(Column *col, int val) {
    /* Vérification du tri de la colonne */
    if (col->mValidIndex == -1 || col->mValidIndex == 0){
        printf("La colonne n'est pas triée.\n");
        return -2;
    }

    /* Initialisation des variables */
    int m, g = 0, d = col->T_Logique - 1;

    /* Recherche dichotomique par ordre croissant*/
    if (col->mSortDir == asc) {
        while (g <= d) {
            m = (g + d) / 2;
            if (val == col->data[m]) {
                return m;
            } else if (val > col->data[m]) {
                g = m + 1;
            } else {
                d = m - 1;
            }
        }
    }
    /* Recherche dichotomique par ordre décroissant*/
    else {
        while (g <= d) {
            m = (g + d) / 2;
            if (val == col->data[m]) {
                return m;
            } else if (val < col->data[m]) {
                g = m + 1;
            } else {
                d = m - 1;
            }
        }
    }
    return -1;
}


int displayMenu1() {
    printf("\n========== Menu ==========\n"
           "Attention !!! :\n"
           "- Toutes les actions sur des colonnes effectuer sur des colonnes intégrées au CDataFrame\n"
           "- Après avoir créé une colonne, il faut l'insérer dans le CDataFrame\n\n"
           "1 - Créer une colonne d'entiers\n"
           "2 - Remplir un CDataframe avec une saisie\n"
           "3 - Afficher le CDataframe\n"
           "4 - Afficher une colonne du CDataframe\n"
           "5 - Afficher une partie des lignes du CDataFrame\n"
           "6 - Afficher une partie des colonnes du CDataFrame\n"
           "7 - Ajouter une ligne de valeurs au CDataFrame\n"
           "8 - Supprimer une ligne de valeurs du CDataFrame\n"
           "9 - Supprimer une colonne du CDataFrame\n"
           "10 - Renommer le titre d'une colonne du CDataFrame\n"
           "11 - Chercher une valeur dans le CDataFrame\n"
           "12 - Remplacer une cellule du CDataFrame\n"
           "13 - Accéder à la valeur d'une cellule du CDataFrame\n"
           "14 - Afficher le nom des colonnes du CDataFrame\n"
           "15 - Afficher le nombre de lignes du CDataFrame\n"
           "16 - Afficher le nombre de colonnes du CDataFrame\n"
           "17 - Nombre de cellules égale à une valeur x dans une colonne\n"
           "18 - Nombre de cellules plus grandes qu'une valeur x dans une colonne\n"
           "19 - Nombre de cellules plus petites qu'une valeur x dans une colonne\n"
           "20 - Nombre de cellules égale à une valeur x dans le CDataFrame\n"
           "21 - Nombre de cellules plus grandes qu'une valeur x dans le CDataFrame\n"
           "22 - Nombre de cellules plus petites qu'une valeur x dans le CDataFrame\n"
           "23 - Trier une colonne\n"
           "24 - Afficher le contenu d'une colonne triée\n"
           "25 - Afficher le CDataframe en fonction d'une colonne triée\n"
           "26 - Effacer l'index d'une colonne\n"
           "27 - Vérifier si une colonne possède un index\n"
           "28 - Mettre à jour un index\n"
           "29 - Faire une recherche dichotomique\n"
           "30 - Charger un fichier data.csv\n"
           "31 - Sauvegarder le CDataframe dans un cdataframe.csv\n"
           "32 - Ne rien faire\n");
    int action;

    do {
        printf("Que voulez-vous faire ?\n");
        scanf("%d", &action);
    } while (action <= 0 || action > 32);

    return action;
}


int displayMenu2() {
    printf("\n\n========== Menu ==========\n"
           "Attention !!! :\n"
           "- Si vous souhaitez créer une autre colonne, supprimez la colonne déjà\n"
           "  existante, en pensant à l'insérer préalablement dans le CDataframe si nécessaire\n\n"
           "1 - Insérer une valeur dans la colonne préalablement créée\n"
           "2 - Supprimer la colonne préalablement créée\n"
           "3 - Afficher la colonne préalablement créée\n"
           "4 - Remplir un CDataframe avec une saisie\n"
           "5 - Afficher le CDataframe\n"
           "6 - Afficher une colonne du CDataframe\n"
           "7 - Afficher une partie des lignes du CDataFrame\n"
           "8 - Afficher une partie des colonnes du CDataFrame\n"
           "9 - Ajouter une ligne de valeurs au CDataFrame\n"
           "10 - Supprimer une ligne de valeurs du CDataFrame\n"
           "11 - Ajouter une colonne au CDataFrame\n"
           "12 - Supprimer une colonne du CDataFrame\n"
           "13 - Renommer le titre d'une colonne du CDataFrame\n"
           "14 - Chercher une valeur dans le CDataFrame\n"
           "15 - Remplacer une cellule du CDataFrame\n"
           "16 - Accéder à la valeur d'une cellule du CDataFrame\n"
           "17 - Afficher le nom des colonnes du CDataFrame\n"
           "18 - Afficher le nombre de lignes du CDataFrame\n"
           "19 - Afficher le nombre de colonnes du CDataFrame\n"
           "20 - Nombre de cellules égale à une valeur x dans une colonne\n"
           "21 - Nombre de cellules plus grandes qu'une valeur x dans une colonne\n"
           "22 - Nombre de cellules plus petites qu'une valeur x dans une colonne\n"
           "23 - Nombre de cellules égale à une valeur x dans le CDataFrame\n"
           "24 - Nombre de cellules plus grandes qu'une valeur x dans le CDataFrame\n"
           "25 - Nombre de cellules plus petites qu'une valeur x dans le CDataFrame\n"
           "26 - Trier une colonne\n"
           "27 - Afficher le contenu d'une colonne triée\n"
           "28 - Afficher le CDataframe en fonction d'une colonne triée\n"
           "29 - Effacer l'index d'une colonne\n"
           "30 - Vérifier si une colonne possède un index\n"
           "31 - Mettre à jour un index\n"
           "32 - Faire une recherche dichotomique\n"
           "33 - Charger un fichier data.csv\n"
           "32 - Sauvegarder le CDataframe dans un cdataframe.csv\n"
           "34 - Ne rien faire\n");
    int action;

    printf("Que voulez-vous faire ?\n");
    do {
        scanf("%d", &action);
    } while (action <= 0 || action > 34);

    return action;
}


CDataFrame* loadFromCsv(char *file_name, int /*size*/) {
    /* Ouverture du fichier en mode lecture */
    FILE* file = fopen(file_name, "rt");;

    /* Vérifier si le fichier est vide ou non */
    if (!file) {
        printf("Ouverture du fichier impossible.\n");
        return NULL;
    }

    char ligne[150]; // ??? la ligne est-elle assez grande ????
    if (fgets(ligne, 150, file) == NULL) {
        printf("Erreur lors de la lecture du fichier.\n");

        /* Fermeture du fichier */
        fclose(file);
        return NULL;
    }

    /* Création du CDataframe */
    CDataFrame *cdt = createCDataFrame("Loaded CDataframe");

    /* Enlever les caractères en fin de ligne */
    ligne[strcspn(ligne, "\n")] = 0;

    /* Créer les colonnes à partir des noms et les insérer dans le CDataframe */
    /* Création d'un token */
    char *ptr_chaine = strtok(ligne, ";");
    while (ptr_chaine) {
        //printf("%s\n", ptr_chaine);
        /* Création de la colonne à partir du nom */
        Column *new_col = createColumn(ptr_chaine);
        /* Insérer la colonne dans le CDataframe */
        insertColumn(cdt, new_col);
        /* Mettre le token à NULL */
        ptr_chaine = strtok(NULL, ";");
    }

    /* Parcours de chaque ligne */
    while (fgets(ligne, 150, file) != NULL) {
        /* Considérer les \n comme nul, donc 0 */
        ligne[strcspn(ligne, "\n")] = 0;

        /* Indique la colonne dans laquelle on se trouve */
        int col_idx = 0;

        /* Séparation des valeurs */
        ptr_chaine = strtok(ligne, ";");
        while (ptr_chaine) {
            int value;
            /* Si la chaine est NULL, alors donner la valeur 0 */
            if (0 == strcmp(ptr_chaine, "NULL"))
                value = 0;
            /* Sinon la convertir en int */
            else
                value = atoi(ptr_chaine);

            /* Insertion de la valeur dans la colonne */
            insertValue(cdt->mColumn[col_idx], value);
            /* Changement de colonne */
            col_idx++;
            ptr_chaine = strtok(NULL, ";");
        }
    }

    /* Fermeture du fichier */
    fclose(file);
    return cdt;
}


void saveIntoCsv(CDataFrame *cdf, char *file_name) {
    /* Ouverture du fichier en mode écriture */
    FILE *file = fopen(file_name, "w");
    /* Vérifier que l'ouverture s'est bien faite */
    if (!file) {
        printf("Erreur lors de l'ouverture du fichier pour écriture.\n");
        return;
    }

    /* Écrire les noms des colonnes */
    for (int i = 0; i < cdf->mNumColumns; i++) {
        fprintf(file, "%s", cdf->mColumn[i]->title);

        /* Écrire le séparateur après chaque nom sauf le dernier */
        if (i < cdf->mNumColumns - 1) {
            fprintf(file, ";");
        }
    }
    fprintf(file, "\n");

    /* Écriture des données du CDataframe */
    for (int i = 0; i < cdf->mColumn[0]->T_Logique; i++) {   // Variation des lignes
        for (int j = 0; j < cdf->mNumColumns; j++) {        // Variation des colonnes
            fprintf(file, "%d", cdf->mColumn[j]->data[i]);

            /* Écrire le séparateur après chaque nom sauf le dernier */
            if (j < cdf->mNumColumns - 1) {
                fprintf(file, ";");
            }
        }
        fprintf(file, "\n");
    }

    /* Fermeture du fichier */
    fclose(file);
}

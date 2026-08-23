//
// Created by Arnaud Bernard on 20/04/2024.
//
#include "../include/cdataframe.h"
#include "../include/Errors.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


CDataFrame *createCDataFrame(char* title) {
    CDataFrame *cdataframe = (CDataFrame *) malloc(sizeof (CDataFrame));
    cdataframe->mTitle = title;
    cdataframe->mNumColumns = 0;
    cdataframe->mColumn = NULL;

    return cdataframe;
}

void userInput(CDataFrame* cdt) {
//    if (!cdt) {
//        printf("Le pointeur CDataframe est NULL.\n");
//        return;
//    }
    POINTER_CHECK_AND_RETURN(cdt, "Le pointeur CDataframe\n");

    /* Initialisation de la variable qui vérifie les insertions */
    int verif;

    // Saisie du nombre de colonnes souhaitées
    int nbr_col;
    printf("Saisir le nombre de colonnes que vous souhaitez : ");
    do {
        scanf("%d", &nbr_col);
    } while (nbr_col <= 0);
    printf("\n");

    // Boucle pour ajouter une colonne
    for (int i = 0; i < nbr_col; i++) {
        // Saisie du nom de la colonne
        char name_col[50];
        printf("Saisir le nom de la %d-ième colonne : ", i + 1);
        scanf("%s", name_col);

        // Création de la colonne portant le nom
        Column *new_col = createColumn(name_col);

        // Saisie du nombre de valeurs qu'il veut rentrer
        int nbr_value;
        printf("Saisir le nombre de valeurs que vous souhaitez entrer : ");
        do {
            scanf("%d", &nbr_value);
        } while (nbr_value <= 0);
        printf("\n");

        // Boucle pour d'une valeur
        for (int j = 0; j < nbr_value; j++) {
            // Saisie de la valeur
            int value;
            printf("Saisir la %d-ième valeur : ", j + 1);
            scanf("%d", &value);

            // Insertion de la valeur
            do {
                verif = insertValue(new_col, value);
            } while (verif == 0);

            printf("\n");
        }

        // Insertion de la colonne
        do {
            verif = insertColumn(cdt, new_col);
        } while (verif == 0);
    }
}


CDataFrame *hardFilling(){
    CDataFrame *cdt = createCDataFrame("Hard Filling Dataframe");

    Column *col1 = createColumn("Colonne-1");
    insertValue(col1, 1);
    insertValue(col1, 2);
    insertValue(col1, 3);
    insertColumn(cdt, col1);

    Column *col2 = createColumn("Colonne-2");
    insertValue(col2, 4);
    insertValue(col2, 5);
    insertValue(col2, 6);
    insertColumn(cdt, col2);

    Column *col3 = createColumn("Colonne-3");
    insertValue(col3, 7);
    insertValue(col3, 8);
    insertValue(col3, 9);
    insertColumn(cdt, col3);

    return cdt;
}

void printCdt(CDataFrame *cdt){
//    if (!cdt) {
//        printf("Le pointeur CDataframe est NULL.\n");
//        return;
//    }
    POINTER_CHECK_AND_RETURN(cdt, "ctd, type CDataframe\n");


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
    int max_rows = numberOfLines(cdt);

    /* Boucle pour les valeurs des colonnes */
    for (int j = 0 ; j < max_rows ; j++){   // Variation de la ligne
        /* Afficher le numéro de la ligne */
        printf("[%d]\t\t", j + 1);

        /* Afficher les valeurs */
        for (int i = 0 ; i < cdt->mNumColumns ; i++) {    // Variation de la colonne
                // Afficher la valeur
                printf("%d\t\t\t\t", cdt->mColumn[i]->data[j]);
        }
        printf("\n"); // Passage à la ligne suivante
    }
    printf("\n");
}


void printLines(CDataFrame *cdt, int x, int y){
    /* Afficher le titre du CDataframe */
    printf("%s\n", (char *) cdt->mTitle);

    /* Vérification du nombre de colonnes */
    if (cdt->mNumColumns == 0) {
        printf("Le CDataframe n'a pas de colonnes.\n");
        return;
    }

    /* Boucle pour les titres des colonnes */
    for (int i = 0 ; i < cdt->mNumColumns ; i++) {
        // Afficher le titre de la colonne
        printf("\t\t%s", cdt->mColumn[i]->title);
    }
    printf("\n");

    /* Boucle pour les valeurs des colonnes */
    for (int j = x - 1 ; j < y; j++){ // Variation de la ligne
        /* Afficher le numéro de la ligne */
        printf("[%d]\t\t", j + 1);

        /* Afficher les valeurs */
        for (int i = 0; i < cdt->mNumColumns; i++) {    // Variation de la colonne
            // Afficher la valeur
            printf("%d\t\t\t\t", cdt->mColumn[i]->data[j]);
        }
        printf("\n"); // Passage à la ligne suivante
    }
    printf("\n");
}


void printColOfCdt(CDataFrame* cdt, int x, int y) {
    /* Afficher le titre du CDataframe */
    printf("%s\n", (char *) cdt->mTitle);

    /* Vérification du nombre de colonnes */
    if (cdt->mNumColumns == 0) {
        printf("Le CDataframe n'a pas de colonnes.\n");
        return;
    }

    /* Boucle pour les titres des colonnes */
    for (int i = x ; i <= y ; i++) {
        // Afficher le titre de la colonne
        printf("\t\t%s", cdt->mColumn[i]->title);
    }
    printf("\n");

    /* Boucle pour les valeurs des colonnes */
    for (int j = 0 ; j < numberOfLines(cdt) ; j++){ // Variation de la ligne
        /* Afficher le numéro de la ligne */
        printf("[%d]\t\t", j + 1);

        /* Afficher les valeurs */
        for (int i = x ; i <= y ; i++) {    // Variation de la colonne
            // Afficher la valeur
            printf("%d\t\t\t\t", cdt->mColumn[i]->data[j]);
        }
        printf("\n"); // Passage à la ligne suivante
    }
    printf("\n");
}


void insertLine(CDataFrame* cdt) {
    for (int i = 0 ; i < cdt->mNumColumns ; i++){
        int val;

        printf("Saisir la valeur de la colonne '%s' : \n", cdt->mColumn[i]->title);
        scanf("%d", &val);

        insertValue(cdt->mColumn[i], val);
    }
}


int deleteLine(CDataFrame* cdt, int index) {
    if (!cdt) {
        printf("Le pointeur CDataframe est NULL.\n");
        return 0;
    }

    for (int i = 0 ; i < cdt->mNumColumns ; i++) {
        /* Décaler les autres lignes */
        if (index != numberOfLines(cdt) - 1) {
            for (int j = index; j < cdt->mColumn[i]->T_Logique - 1; j++) {
                cdt->mColumn[i]->data[j] = cdt->mColumn[i]->data[j + 1];
            }
        }

        cdt->mColumn[i]->data = realloc(cdt->mColumn[i]->data, --(cdt->mColumn[i]->T_Logique) * sizeof (int));
    }

    return 1;
}


int insertColumn(CDataFrame* cdt, Column* column) {
    if (!cdt || !column) {
        printf("Le pointeur CDataframe ou colonne est NULL.\n");
        return 0;
    }

    /* Si la colonne n'a pas encore été utilisée, faire une allocation */
    if (!cdt->mColumn) {
        cdt->mColumn = (Column **) malloc(sizeof (Column *));
        if (!cdt->mColumn) {
            printf("Échec de la réallocation de la mémoire.\n");
            return 0;
        }
    }

    /* Sinon faire une réallocation (toujours à la bonne taille) */
    else {
        cdt->mColumn = realloc(cdt->mColumn, (cdt->mNumColumns + 1) * sizeof (Column *));
    }

    // Dupliquer le titre de la colonne avant de l'insérer
    char *col_title = (char *) malloc(strlen(column->title) + 1);
    strcpy(col_title, column->title);
    column->title = col_title;

    // Insertion de la colonne dans le CDataframe
    cdt->mColumn[cdt->mNumColumns++] = column;

    return 1;
}


int deleteCol(CDataFrame * cdt, int index) {
    /* Vérification de la taille du CDataframe et de la colonne */
    if (!cdt || !cdt->mColumn[index]) {
        printf("Le pointeur CDataframe ou colonne est NULL.\n");
        return 0;
    }

    // Libérer la mémoire allouée pour le titre de la colonne
    free(cdt->mColumn[index]->title);
    cdt->mColumn[index]->title = NULL;


    // Libérer le tableau de pointeurs vers les lignes
    free(cdt->mColumn[index]->data);
    cdt->mColumn[index]->data = NULL;

    // Réinitialiser la taille logique de la colonne
    cdt->mColumn[index]->T_Logique = 0;

    // Réinitialiser la taille physique de la colonne
    cdt->mColumn[index]->T_Physique = 0;

    /* Réallocation de la taille du CDataframe */
    if (index == cdt->mNumColumns - 1) {
        cdt->mColumn = realloc(cdt->mColumn, --(cdt->mNumColumns) * sizeof (Column *));
    }
    else if (index < cdt->mNumColumns - 1) {
        /* Décalage des autres colonnes */
        for (int i = index ; i < cdt->mNumColumns - 1 ; i++) {
            cdt->mColumn[i] = cdt->mColumn[i + 1];
        }

        cdt->mColumn = realloc(cdt->mColumn, --(cdt->mNumColumns) * sizeof (Column *));
    }

    return 1;
}


int renameCol(CDataFrame *cdt, int index, char *new_name) {
    if (!cdt || !cdt->mColumn[index]) {
        printf("Le pointeur CDataframe ou colonne est NULL.\n");
        return 0;
    }

    // Dupliquer le titre de la colonne avant de l'insérer
    char *col_title = (char *) malloc(strlen(new_name) + 1);
    strcpy(col_title, new_name);
    new_name = col_title;

    cdt->mColumn[index]->title = new_name;
    return 1;
}


int searchValue(CDataFrame* cdt, int value) {
    int cpt = 0;

    /* Boucle pour parcourir les colonnes */
    for (int i = 0 ; i < cdt->mNumColumns ; i++) {
        /* Boucle pour parcourir les lignes */
        cpt += numberOcc(cdt->mColumn[i], value);
    }

    return cpt;
}


int selectCell(CDataFrame* cdt, int index_l, int index_c) {
    return cdt->mColumn[index_c]->data[index_l];
}


int replaceCell(CDataFrame* cdt, int index_l, int index_c, int value) {
    if (!cdt) {
        printf("Le pointeur CDataframe est NULL.\n");
        return 0;
    }

    /* Si la case n'existe pas retourner 0 */
    if (index_c < 0 || index_c >= cdt->mNumColumns || index_l < 0 || index_l >= numberOfLines(cdt)) {
        printf("Cette cellule n'existe pas.\n");
        return 0;
    }
    /* Sinon remplacer la valeur et retourner 1 */
    cdt->mColumn[index_c]->data[index_l] = value;

    return 1;
}


void printNameCol(CDataFrame *cdt) {
    if (!cdt) {
        printf("Le pointeur CDataframe est NULL.\n");
        return;
    }

    /* Boucle pour les titres des colonnes */
    for (int i = 0 ; i < cdt->mNumColumns ; i++) {
        // Afficher le titre de la colonne
        printf("%s\t\t", cdt->mColumn[i]->title);
    }
    printf("\n\n");
}


int numberOfLines(CDataFrame *cdt) {
    if (!cdt) {
        printf("Le pointeur CDataframe est NULL.\n");
        return 0;
    }


    /* Recherche de la colonne avec le plus de lignes */
    int max = 0;
    for (int i = 0 ; i < cdt->mNumColumns ; i++) {
        if (max < cdt->mColumn[i]->T_Logique)
            max = cdt->mColumn[i]->T_Logique;
    }

    return max;
}


int numberOfCols(CDataFrame *cdt) {
    /* Vérification de la taille du CDataframe */
    if (!cdt) {
        printf("Le pointeur CDataframe est NULL.\n");
        return 0;
    }

    return cdt->mNumColumns;
}


int cellEqualTo(CDataFrame *cdt, int x) {
    /* Vérification de la taille du CDataframe */
    if (!cdt) {
        printf("Le pointeur CDataframe est NULL.\n");
        return 0;
    }

    /* Parcours des valeurs */
    int cpt = 0;
    for (int i = 0 ; i < cdt->mNumColumns ; i++) {
        for (int j = 0 ; j < cdt->mColumn[i]->T_Logique ; j++) {
            if (cdt->mColumn[i]->data[j] == x)
                cpt++;
        }
    }

    return cpt;
}


int cellGreaterThan(CDataFrame *cdt, int x) {
    if (!cdt) {
        printf("Le pointeur CDataframe est NULL.\n");
        return 0;
    }

    /* Parcours des valeurs */
    int cpt = 0;
    for (int i = 0 ; i < cdt->mNumColumns ; i++) {
        for (int j = 0 ; j < cdt->mColumn[i]->T_Logique ; j++) {
            if (cdt->mColumn[i]->data[j] > x)
                cpt++;
        }
    }

    return cpt;
}


int cellLessThan(CDataFrame *cdt, int x) {
    if (!cdt) {
        printf("Le pointeur CDataframe est NULL.\n");
        return 0;
    }

    /* Parcours des valeurs */
    int cpt = 0;
    for (int i = 0 ; i < cdt->mNumColumns ; i++) {
        for (int j = 0 ; j < cdt->mColumn[i]->T_Logique ; j++) {
            if (cdt->mColumn[i]->data[j] < x)
                cpt++;
        }
    }

    return cpt;
}

//
// Created by Arnaud Bernard on 28/03/2024.
//

#ifndef PROJET_CDATAFRAME_COLUMN_H
#define PROJET_CDATAFRAME_COLUMN_H


#define REALLOC_SIZE 256

#include "SortType.h"

#include <stdint.h>

typedef struct {
    char *title;
    int32_t T_Logique; // pourquoi pas uint64_t ????
    // que veux dire T_ ????
    int32_t T_Physique;
    int32_t *data;
    uint64_t *index;
    // Index valid
    // 0 : no index
    // -1 : invalid index
    // 1 : valid index
    int32_t mValidIndex;
    // direction de tri : Ascendant ou Descendant
    // 0 : ASC
    // 1 : DESC
    SortType mSortDir;
} Column;


// exemple de documentation avec doxygen
/**
 * @brief Create a column.
 * * Description détaillée de ce que fait la fonction.
 * Elle peut s'étendre sur plusieurs lignes.
 * * @param title Column title.
 * @param param2 Description du deuxième paramètre.
 * @return Pointer to created column.
 */
Column *createColumn(char* title);


/* Add a new value to a column
 * @param1 : Pointer to a column
 * @param2 : The value to be added
 * @return : 1 if the value is added 0 otherwise
 */
int insertValue(Column* col, int value);


/* Free allocated memory
 * @param1 : Pointer to a column
 */
void deleteColumn(Column *col);


/* Print a column content
 * @param1 : Pointer to a column
 */
void printColumn(Column* col);


/* Number of occurrences
 *  @param1 : Pointer to a column
 *  @param2 : Value to count
 *  @return : Number of occurrences of the value
 */
int numberOcc(Column* col, int value);


/* Value at position x
 * @param1 : Pointer to a column
 * @param2 : Position
 * @return : The value at the position x or 0 if the value doesn't exist
 */
int valAtPos(Column* col, int pos);


/* Number of value > x
 * @param1 : Pointer to a column
 * @param2 : X
 * @return : Number of value greater than x
 */
int greater_than(Column* col, int x);


/* Number of value < x
 * @param1 : Pointer to a column
 * @param2 : X
 * @return : Number of value less than x
 */
int lessThan(Column* col, int x);


/* Number of value = x
 * @param1 : Pointer to a column
 * @param2 : X
 * @return : Number of value equal to x
 */
int equalTo(Column* col, int x);


#endif // PROJET_CDATAFRAME_COLUMN_H

//
// Created by Arnaud Bernard on 29/04/2024.
//

#ifndef PROJET_CDATAFRAME_FEATURES_H
#define PROJET_CDATAFRAME_FEATURES_H


#include "SortType.h"

#include "cdataframe.h"

/*
typedef struct {
    char *ligne;
    char *ptr_chaine;
    short int num_ligne;
    short int data_entier;
} FILE;*/

/* Sort a column according to a given order
 * @param1 : Pointer to the column to sort
 * @param2 : Sort type (ASC or DESC)
 */
void sort(Column *col, SortType sort_dir);


/* Print a CDataframe content
 * @param1 : Pointer to a CDataframe
 */
void printSortCdt(CDataFrame *cdt, int index);


/* Display the content of a sorted column
 * @param1 : Pointer to a column
 */
void printColByIndex(Column *col);


/* Remove the index of a column
 * @param1 : Pointer to a column
 */
void eraseIndex(Column *col);


/* Check if an index is correct
 * @param1 : Pointer to a column
 * @return :  0 : index not existing,
             -1 : the index exists but invalid,
              1 : the index is correct
 */
int checkIndex(Column *col);


/* Update the index
 * @param1 : Pointer to a column
 */
void updateIndex(Column *col);


/* Check if a value exist in a column
 * @param1 : Pointer to a column
 * @param2 : Pointer to the value to search
 * @return : -1 : column not sorted
              0 : value not found
              1 : value found
*/
int searchValueInColumn(Column *col, int val);


/* Display menu 1
 * (without column created)
 */
int displayMenu1();


/* Display menu 2
 * (with column created)
 */
int displayMenu2();

/* Create a CDataframe from csv file
 * @param1: CSV filename
 * @param2: Array of types
 * @param3: Size of array in param2
 */
CDataFrame* loadFromCsv(char *file_name, int size);

/* Export into a csv file
 * @param1: Pointer to the CDataframe
 * @param2: csv filename where export file, if the file exists,
 *          it will be overwritten
 */
void saveIntoCsv(CDataFrame *cdf, char *file_name);


#endif // PROJET_CDATAFRAME_FEATURES_H

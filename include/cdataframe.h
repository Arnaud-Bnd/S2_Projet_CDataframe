//
// Created by Arnaud Bernard on 20/04/2024.
//

#ifndef PROJET_CDATAFRAME_CDATAFRAME_H
#define PROJET_CDATAFRAME_CDATAFRAME_H


#include "column.h"


typedef struct {
    char *mTitle;
    int mNumColumns;
    Column **mColumn;
} CDataFrame;


/* Create a CDataframe
 * @param1 : CDataframe title
 * @return : Pointer to created column
 */
CDataFrame *createCDataFrame(char* title);


/* Insert user input in a CDataframe
 * @param1 : Pointer to a CDataframe
 */
void userInput(CDataFrame* cdt);


/* Hard filling of CDataframe */
CDataFrame *hardFilling();


/* Print a CDataframe content
 * @param1 : Pointer to a CDataframe
 */
void printCdt(CDataFrame* cdt);


/* Print lines of the CDataframe
 * @param1 : Pointer to a CDataframe
 * @param2 : Starting line number
 * @param3 : End line number
 */
void printLines(CDataFrame* cdt, int x, int y);


/* Print columns of the CDataframe
 * @param1 : Pointer to a CDataframe
 * @param2 : Starting column number
 * @param3 : End column number
 */
void printColOfCdt(CDataFrame* cdt, int x, int y);


/* Insert line in the CDataframe
 * @param1 : Pointer to a CDataframe
 */
void insertLine(CDataFrame* cdt);


/* Delete line in the CDataframe
 * @param1 : Pointer to a CDataframe
 * @param2 : Number of the line to be deleted
 * @return : 1 if the line is deleted 0 otherwise
 */
int deleteLine(CDataFrame* cdt, int index);


/* Add a new column to a CDataframe
 * @param1 : Pointer to a CDataframe
 * @param2 : Pointer to a column to be added
 * @return : 1 if the column is added 0 otherwise
 */
int insertColumn(CDataFrame* cdt, Column* column);


/* Delete column in the CDataframe
 * @param1 : Pointer to a CDataframe
 * @param2 : Number of the column to be deleted
 * @return : 1 if the column is deleted 0 otherwise
 */
int deleteCol(CDataFrame* cdt, int index);


/* Rename a CDataframe column title
 * @param1 : Pointer to a CDataframe
 * @param2 : Number of the column to be change
 * @return : 1 if the column is renamed 0 otherwise
 */
int renameCol(CDataFrame *cdt, int index, char *new_name);


/* Search value in the CDataframe
 * @param1 : Pointer to a CDataframe
 * @param2 : Value we search
 * @return : Number of times the value appears
 */
int searchValue(CDataFrame* cdt, int value);


/* Select a cell
 * @param1 : Pointer to a CDataframe
 * @param2 : Index of the line
 * @param3 : Index of the column
 * @return : Value in the cell
 */
int selectCell(CDataFrame* cdt, int index_l, int index_c);


/* Replace a cell
 * @param1 : Pointer to a CDataframe
 * @param2 : Index of the line
 * @param3 : Index of the column
 * @param4 : The value we want
 * @return : 1 replacement successful otherwise 0
 */
int replaceCell(CDataFrame* cdt, int index_l, int index_c, int value);


/* Print names of columns
 * @param1 : Pointer to a CDataframe
 */
void printNameCol(CDataFrame* cdt);


/* Number of lines
 * @param1 : Pointer to a CDataframe
 * @return : Number of lines in the CDataframe
 */
int numberOfLines(CDataFrame* cdt);


/* Number of columns
 * @param1 : Pointer to a CDataframe
 * @return : Number of columns in the CDataframe
 */
int numberOfCols(CDataFrame* cdt);


/* Number of cells equal to x
 * @param1 : Pointer to a CDataframe
 * @param2 : X
 * @return : Number of cells equal to x
 */
int cellEqualTo(CDataFrame* cdt, int x);

/* Number of cells greater than x
 * @param1 : Pointer to a CDataframe
 * @param2 : X
 * @return : Number of cells greater than x
 */
int cellGreaterThan(CDataFrame* cdt, int x);


/* Number of cells less than x
 * @param1 : Pointer to a CDataframe
 * @param2 : X
 * @return : Number of cells less than x
 */
int cellLessThan(CDataFrame* cdt, int x);


#endif // PROJET_CDATAFRAME_CDATAFRAME_H

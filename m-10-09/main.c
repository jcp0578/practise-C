#include <stdio.h>
#include <stdlib.h>


bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    if(matrix == NULL || matrixSize == 0 || matrixColSize == NULL) {
        return false;
    }
    int row = matrixSize;
    int col = matrixColSize[0];
    int findRow = row -1;
    int findCol = 0;

    while ( (findRow >= 0) && (findCol < col) ) {
        if(matrix[findRow][findCol] == target) {
            return true;
        } else if (matrix[findRow][findCol] < target) {
            findCol++;
        } else {
            findRow--;
        }
    }
    return false;
}


int main()
{
    printf("Hello world!\n");
    return 0;
}

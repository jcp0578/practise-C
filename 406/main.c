#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

/*
 * AC
 * https://leetcode-cn.com/submissions/detail/75262673/
 */

int cmpfunc(const void * a, const void * b)
{
    int *pa= *(int **)a;
    int *pb= *(int **)b;
    if( pa[0] == pb[0]){
        return (pa[1] - pb[1] );
    } else {
        return ( pb[0] - pa[0] );
    }
}

void move(int** people,int index,int to_index) {
    if(index <= to_index) {
        return;
    }
    int *temp = people[index];
    for(int i=index;i> to_index;i--) {
        people[i] = people[i-1];
    }
    people[to_index] = temp;
}


int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes){
    int **res = NULL;
    int *res_col = NULL;
    if(people == NULL || peopleSize == 0) {
        goto back;
    }
    res = (int **)malloc(sizeof(int *) * peopleSize);
    res_col = (int *)malloc(sizeof(int) * peopleSize);
    for(int i = 0;i < peopleSize;i++) {
        res[i] = (int*)malloc(sizeof(int)*peopleColSize[i]);
        for(int j=0;j<peopleColSize[i];j++) {
            res[i][j] = people[i][j];
        }
        res_col[i] = peopleColSize[i];
    }


    qsort(res,peopleSize,sizeof(res[0]),cmpfunc);

    for(int i=0;i<peopleSize;i++) {
        move(res, i,res[i][1]);
    }

back:
    *returnColumnSizes = res_col;
    *returnSize = peopleSize;
    return res;
}




int main()
{
    printf("Hello world!\n");
    return 0;
}

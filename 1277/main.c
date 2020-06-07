#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int countSquares(int** matrix, int matrixSize, int* matrixColSize){
    if(matrix == NULL || matrixSize == 0 || matrixColSize == NULL) {
        return 0;
    }
    int row = matrixSize;
    int col = matrixColSize[0];
    printf("row is %d,col is %d\n",row,col);
    int dp[row][col];
    int visit[row][col];

    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            if(matrix[i][j] == 0) {
                dp[i][j] = 0;
            } else {
                int dpRes = 1;
                for(;;dpRes++) {
                    int checkRow = i + dpRes;
                    int checkCol = j + dpRes;
                    bool checkFalg = true;
                    if(checkCol >= col || checkRow >= row) {
                        checkFalg = false;
                    }
                    for(int z=j;z<=checkCol && checkFalg;z++) {
                        if(matrix[checkRow][z] == 1) {
                            continue;
                        } else {
                            checkFalg = false;
                        }
                    }

                    for(int z=i;z<checkRow && checkFalg;z++) {
                        if(matrix[z][checkCol] == 1) {
                            continue;
                        } else {
                            checkFalg = false;
                        }
                    }

                    if(checkFalg == false) {
                        dpRes;
                        break;
                    }
                }
                dp[i][j] = dpRes;
            }
        }
    }

    printf("dp\n");
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            visit[i][j] = 0;
        }
    }

    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            if(dp[i][j] == 0) {
                continue;
            } else {
                int setRow = i + dp[i][j];
                int setCol = j + dp[i][j];

                for(int ii=i;ii<setRow;ii++) {
                    for(int jj =j;jj<setCol;jj++){
                        visit[ii][jj]+=dp[i][j];
                        //printf("DEBUG:(%d ,%d);visit(%d %d) is %d\n",i,j,ii,jj,visit[ii][jj]);
                    }
                }
            }
        }
    }
    printf("visit\n");
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            printf("%d ",visit[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int smallLen = (row <col)?row:col;
    int *dpMap = (int *)malloc(sizeof(int) * (smallLen + 1));
    dpMap[0] = 0;
    for(int i=1;i<=smallLen;i++) {
        dpMap[i] = dpMap[i-1] + i*i;
    }

    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            dp[i][j] = dpMap[dp[i][j]];
        }
    }

    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    free(dpMap);
    dpMap = NULL;

    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            if(visit[i][j] != 0 && visit[i][j] != 1) {
                visit[i][j] = 1 - visit[i][j];
            }
        }
    }

    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            printf("%d ",visit[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int res = 0;

    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            res += dp[i][j] * visit[i][j];
        }
    }

    return res;
}


int main()
{
#define row  3
#define col  4
    int matrix[row][col]={{0,1,1,1},{1,1,1,1},{0,1,1,1}};
    int *test_in[row];
    for(int i=0;i<row;i++) {
        test_in[i]=matrix[i];
    }
    int col_in[1] = {col};
    int res = countSquares(test_in,row,col_in);
    printf("res is %d\n",res);
    printf("Hello world!\n");
    return 0;
}

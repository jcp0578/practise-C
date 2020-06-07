#include <stdio.h>
#include <stdlib.h>

//299
//AC

char * getHint(char * secret, char * guess){
    int len = strlen(secret);
    int map1[10] = {0};
    int map2[10] = {0};
    int A=0,B=0;
    for(int i=0;i<len;i++) {
        if (secret[i] == guess[i]){
            A++;
        } else {
            map1[secret[i] - '0']++;
            map2[guess[i] - '0']++;
        }
    }
    for(int i=0;i<10;i++) {
        if (map1[i] <= map2[i]) {
            B += map1[i];
        } else {
            B += map2[i];
        }
    }
    char *res = calloc(20, sizeof(char));
    sprintf(res,"%dA%dB\0",A,B);
    return res;
}

int main()
{

    char *secret = "";
    char *guess = "";
    char *res = getHint(secret,guess);
    printf("%s\n",res);
    free(res);
    return 0;
}

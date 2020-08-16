
int longestAwesome(char *s)
{
    if (s == NULL)     {
        return 0;
    }
    int len = strlen(s);
    if (len <= 1)     {
        return len;
    }
    int indexSave[1024] = {};
    memset(indexSave, 0xff, sizeof(int) * 1024);
    indexSave[0] = 0;
    int countTemp = 0;
    int res = 0;

    for (int i = 0; i < len; i++)     {
        countTemp ^= (1 << (s[i] - '0'));
        for (int j = 0; j <= 10; j++) {
            int checkTemp;
            if (j == 10) {
                checkTemp = countTemp;
            } else {
                checkTemp = countTemp ^ (1 << j);
            }
      
            int matchIndex = indexSave[checkTemp];
            if (matchIndex != -1) {
                int resTemp = i - matchIndex + 1;
                res = (res < resTemp) ? resTemp : res;
            }
        }
        
        if (indexSave[countTemp] == -1) {
            indexSave[countTemp] = i + 1;
        }
    }
    return res;
}

int main()
{
    char *test_in = "3242415";
    int res = longestAwesome(test_in);
    printf("res is %d\n", res)
}
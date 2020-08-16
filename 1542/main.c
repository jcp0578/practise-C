
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
    memset(indexSave, 0, sizeof(int) * 1024);
    int countTemp = 0;
    int res = 0;

    for (int i = 0; i < len; i++)     {
        countTemp ^= (1 << (s[i] - '0'));
        if(countTemp == 0) {
            res = i + 1;
            continue;
        }
        for (int j = 0; j <= 10; j++) {
            int checkTemp;
            if (j == 10) {
                checkTemp = countTemp;
            } else {
                checkTemp = countTemp ^ (1 << j);
            }

            
            if(checkTemp == 0) {
                res = i + 1;
                break;
            } else {
                int matchIndex = indexSave[checkTemp];
                if (matchIndex != 0) {
                    int resTemp = i - matchIndex + 1;
                    res = (res < resTemp) ? resTemp : res;
                }
            }
        }
        int saveIndex = countTemp;
        if (indexSave[saveIndex] == 0) {
            indexSave[saveIndex] = i + 1;
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
#include <stdio.h>
#include <string.h>
#include <iostream>
 
#define MAX_M 50
#define MAX_N 50
 
static char a[MAX_M][MAX_N],b[MAX_M][MAX_N];
static int m, n;
// 8way
static int di[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
static int dj[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
 
int num_cases, t, i, j, k;
char line[256], word[256] = "teemo";
 
int change[50][3];
int indexOfChange = 0;
int direction;
 
 
// i, j to find word
int find_match(char word[], int start_i, int start_j,int dir)
{
    int sw = 0;        //0:noproblem, 1:diff word
 
    int x=0;
 
    int i, j, t;
    //for (dir = 0; dir < 8; dir++) {
    i = start_i;
    j = start_j;
    t = 0;
    while (i >= 0 && i < m && j >= 0 && j < n
        && word[t] != '\0') {
            if(x>2){
                
                sw=0;
                break;
            }
 
            if (word[t] == a[i][j]) {
                sw = 0;
 
            }
            else if (word[t] != a[i][j] && sw == 0) {
                sw = 1;
                x++;
                if(x>2){
                    
                    sw=0;
                    break;
                }
            }
            else if (word[t] != a[i][j] && sw == 1) {
                sw = 0;
                break;
            }
            else {
                sw = 0;
                break;
            }
            i += di[dir];
            j += dj[dir];
            t++;
    }
    //printf("x is %d\n",x);
    if (word[t] == '\0') {
 
        return 1;
    }
    //}
    return 0;
}
 
void changeToShap() {
    int idx = 0;
    int mapi, mapj, dir;
    for(idx=0;idx<indexOfChange;idx++){
 
        mapi = change[idx][0];
        mapj = change[idx][1];
        dir = change[idx][2];
 
        for (int i = 0; i < 5; i++) {
            a[mapi][mapj] = '#';
            b[mapi][mapj] = '#';
            mapi = mapi + di[dir];
            mapj = mapj + dj[dir];
        }
    }
}
 
int main(void)
{
 
    num_cases = 1;
    while (scanf("%d", &m) == 1) {
        for (t = 0; t < num_cases; t++) {
            if (t > 0)
                putchar('\n');
            //fgets(line, 256, stdin); // gets(line);
            // read grid
            scanf("%d", &n);
 
            fgets(line, 256, stdin); // gets(line);
            for (i = 0; i < m; i++) {
                for (j = 0; j < n; j++) {
                    a[i][j] = getchar();
 
                    b[i][j]=a[i][j];
                    
                    if (a[i][j] >= 'A' && a[i][j] <= 'Z')
                        a[i][j] += ('a' - 'A');
                }
                fgets(line, 256, stdin); // gets(line);
            }
 
            //scanf("%d", &k);
            k = 1;
 
            //fgets(line, 256, stdin); // gets(line);
            while (k-- > 0) {
                //fgets(word, 256, stdin); // gets(word);
                //word[strlen(word) - 1] = '\0'; // 
 
                for (i = 0; i < strlen(word); i++)
                    if (word[i] >= 'A' && word[i] <= 'Z')
                        word[i] += ('a' - 'A'); // 
 
 
 
                for (i = 0; i < m; i++)
                    for (j = 0; j < n; j++)
 
                        for (int dir = 0; dir < 8; dir++) {
                            if (find_match(word, i, j, dir)) {
                                //printf("%d %d\n", i + 1, j + 1);
 
                                change[indexOfChange][0] = i;
                                change[indexOfChange][1] = j;
                                change[indexOfChange][2] = dir;
 
                                //printf("i: %d j: %d dir: %d\n", i, j, dir);
                                indexOfChange++;
                                //printf("idxofchange: %d\n", indexOfChange);
 
                                //change it and check it
                                //changeToShap();
                                /*for (i = 0; i < m; i++) {
                                    for (j = 0; j < n; j++) {
                                        printf("%c", a[i][j]);
                                    }
                                    printf("\n");
                                }*/
 
                            }
                        }
 
 
            }
 
            changeToShap();
 
            for (i = 0; i < m; i++) {
                for (j = 0; j < n; j++) {
                    printf("%c", b[i][j]);    //not a b is right
                }
                printf("\n");
            }
            direction = 0;
            indexOfChange = 0;
            //printf("\n");
        }
    }
 
 
 
    return 0;
}
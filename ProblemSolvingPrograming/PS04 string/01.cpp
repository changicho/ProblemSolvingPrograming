#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>    //need to change upper or lower
 
#define BUFFSIZE 2000
 
using namespace std;
 
char INPUT[BUFFSIZE], INPUT2[BUFFSIZE];
int firstWord[27] = { 0 , }, secondWord[27] = { 0, };
char first[BUFFSIZE], second[BUFFSIZE];
 
 
int ABS(int NUM) {
    if (NUM < 0) {
        return -NUM;
    }
    return NUM;
}
 
 
int main() {
    while (fgets(first, BUFFSIZE, stdin) != NULL) {
        fgets(second, BUFFSIZE, stdin);
        
        int indexSecond = 0;
        int indexFirst = 0;
 
        while (first[indexFirst] != '\0')
            indexFirst++;
        while (second[indexSecond] != '\0')
            indexSecond++;
 
        for (int i = 0; i < indexFirst - 1; i++) {
            firstWord[first[i] - 'a']++;
        }
        for (int i = 0; i < indexSecond - 1; i++) {
            secondWord[second[i] - 'a']++;
        }
 
        int result = 0;
 
        for (int i = 0; i < 26; i++) {
            result = result + ABS(firstWord[i] - secondWord[i]);
            //cout << firstWord[i] << " " << secondWord[i] << endl;
 
 
            //delete log of firstWord and secondWord
            firstWord[i] = 0;
            secondWord[i] = 0;
        }
 
        cout << result << endl;
    }
 
    return 0;
}
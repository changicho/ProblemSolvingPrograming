//this code makes error in linux. because of hangul
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>	//need to change upper or lower

#define BUFFSIZE 4000

using namespace std;

char INPUT[BUFFSIZE];
char ENG[BUFFSIZE];
char KOR[BUFFSIZE];
int ENGINDEX = 0;
int KORINDEX = 0;

char *my_strcpy(char *des, const char *src) 
{ 
	int i = 0;       
	while (src[i] != '\0')         
		des[i] = src[i++];       
	des[i] = '\0';       
	return des; 
}

int STRLEN(char IN[]) {
	int i = 0;
	for (i = 0; IN[i] != NULL; i++);

	return i;
}

void trim(char* string)
{

	int i = 0, j = 0;

	if (string == NULL)
		return;

	//trim right
	j = STRLEN(string) - 1;
	while (j >= 0 && string[j] == ' ')
		j--;

	string[j + 1] = 0;


	//trim left
	while (string[i] == ' ')
		i++;
	if (i != 0)
		my_strcpy(string, string + i);

}



int main()
{
	int countOfUpper = 0;
	int countOfLower = 0;
	int countOfHangul = 0;
	int countOfNumber = 0;
	int countOfWord = 0;
	int countOfEng = 0;

	while (fgets(INPUT, BUFFSIZE, stdin) != NULL) {

		trim(INPUT);
		//cout << STRLEN(INPUT) << endl;

		INPUT[STRLEN(INPUT)-1] = '\0';	//delete INPUT's last word \n		
		//cout << STRLEN(INPUT) << endl;

		//cout << INPUT << endl;	//to check input is correct
		//cout << strlen(INPUT) << endl;	//real length of INPUT
		
		for (int i = 0; INPUT[i] != NULL; i++) {
			if ('A' <= INPUT[i] && INPUT[i] <= 'Z') {
				ENG[ENGINDEX] = INPUT[i];
				ENGINDEX++;
				countOfUpper++;
				countOfEng++;
			}
			else if ('a' <= INPUT[i] && INPUT[i] <= 'z') {
				ENG[ENGINDEX] = INPUT[i];
				ENGINDEX++;
				countOfLower++;
				countOfEng++;
			}
			else if (INPUT[i] & 0x80)  
			{
				KOR[KORINDEX] = INPUT[i];
				KORINDEX++;
				KOR[KORINDEX] = INPUT[i + 1];
				
				KORINDEX++;
				i++;
				countOfHangul ++;
			}
		}

		ENG[ENGINDEX] = '\0';
		KOR[KORINDEX] = '\0';

		countOfWord = countOfHangul + countOfLower + countOfUpper;

		printf("%s%s\n", ENG, KOR);
		printf("%d %d %d\n", countOfEng, countOfHangul, countOfEng + countOfHangul);

		ENGINDEX = 0;
		KORINDEX = 0;


		countOfEng = 0;
		countOfUpper = 0;
		countOfLower = 0;
		countOfHangul = 0;
		countOfNumber = 0;
		countOfWord = 0;
		
	}

	return 0;
}
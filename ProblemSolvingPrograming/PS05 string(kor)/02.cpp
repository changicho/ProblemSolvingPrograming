#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

#define gets(x) gets_s(x)	//To Solve gets Error
#define BUFFSIZE 1000
#define MAX_DIC_SIZE 1000
#define MAX_WORD_LENGTH 10

char pltxt[] = "the quick brown fox jumps over the lazy dog";
char pltxt_output[100];

char FOX[BUFFSIZE];
char INPUT[BUFFSIZE];

char map[256], inv[256];

static char dic[MAX_DIC_SIZE][MAX_WORD_LENGTH + 1];

int dic_size = 0;
int line_len = 0;
int num_of_q = 0;
int max_of_q = 0;

int STRLEN(char IN[]) {	
	int i = 0;
	for (i = 0; IN[i] != NULL; i++);
	return i;
}


int search(unsigned int k, char *map, char *inv)
{
	char word[MAX_WORD_LENGTH + 1];
	char map2['z' + 1], inv2['z' + 1];		//map : ori -> crypt, inv : crypt -> ori
	int i, j, t;
	char c;
	char pltxt_temp[100];

	while (INPUT[k] == ' ')	//skip space
		k++;

	if (k >= line_len) { 
		num_of_q = 0;
		//cout << "end of line" << endl;

		for (i = 0; i < STRLEN(pltxt); i++) {
			if (pltxt[i] == ' ') {
				pltxt_temp[i] = ' ';
			}
			else if (map[pltxt[i]] == '\0') {
				pltxt_temp[i] = '?';
				num_of_q++;
			}
			else {
				pltxt_temp[i] = map[pltxt[i]];
			}
		}
		//cout << "num of q" << num_of_q << endl;

		if (num_of_q < max_of_q) {
			max_of_q = num_of_q;

			for (i = 0; i < STRLEN(pltxt); i++) {
				pltxt_output[i] = pltxt_temp[i];
			}
			pltxt_output[i] = '\0';
			//cout << pltxt_output << endl;
		}
		//putchar('\n');
		return 1;
	}

	// k is start point. 
	for (t = 0; INPUT[k + t] >= 'a' && INPUT[k + t] <= 'z'; t++)
		word[t] = INPUT[k + t];
	word[t] = '\0';	//there are first word in word[]	this word is crypt


	for (i = 0; i < dic_size; i++) {
		//cout << dic[i] << " start find" << endl;
		if (STRLEN(dic[i]) == t) {
			//cout << "same length" << endl;
			for (c = 'a'; c <= 'z'; c++) {
				map2[c] = map[c];
				inv2[c] = inv[c];
			}
			// is that ok?
			for (j = 0; j < t; j++) {

				if (inv2[word[j]] == '\0') {
					map2[dic[i][j]] = word[j];
					inv2[word[j]] = dic[i][j];
					//cout << dic[i][j] << " :: " << word[j] << endl;;
				}
				else if (inv2[word[j]] == dic[i][j])
				{
					continue;
				}
				else {

					//if (inv2[word[j]] != dic[i][j] && map2[dic[i][j]] != word[j]) {
					for (c = 'a'; c <= 'z'; c++) {
						map2[c] = map[c];
						inv2[c] = inv[c];
					}
					goto end_of_loop_i;
					//}

				}

				//// must match if
				//if (map2[word[j]] && map2[word[j]] != dic[i][j]
				//	|| inv2[dic[i][j]] && inv2[dic[i][j]] != word[j])
				//{
				//	cout << "not match bye" << endl;
				//	goto end_of_loop_i;
				//}
				//else
				//{
				//	// update mapping
				//	map2[word[j]] = dic[i][j];
				//	inv2[dic[i][j]] = word[j];
				//}
			}
			//cout << "detect next" << endl;
			//for (char c = 'a'; c <= 'z'; c++) {
			//	if (map2[c] != '\0') {
			//		cout << c << " : " << map2[c] << endl;
			//	}
			//}
			search(k + t, map2, inv2);
		end_of_loop_i:;

		}
	}
	if (i == dic_size) {
		//cout << "detect all word" << endl;
		search(k + t, map, inv);
	}
	return 0;
}


int main(void)
{
	char c;
	int i = 0;


	while (fgets(FOX, BUFFSIZE, stdin) != NULL) {
		FOX[STRLEN(FOX) - 1] = '\0';
		max_of_q = 0;

		for (int c = 'a'; c <= 'z'; c++) {
			map[c] = '\0';
			inv[c] = '\0';
		}

		for (int i = 0; FOX[i] != NULL; i++) {		//to make first map, inv system.
			if (FOX[i] != '?' && FOX[i] != ' ') {
				map[pltxt[i]] = FOX[i];
				inv[FOX[i]] = pltxt[i];
				pltxt_output[i] = FOX[i];
			}
			if (FOX[i] == '?') {
				max_of_q++;
				pltxt_output[i] = '?';
			}
			else if (FOX[i] == ' ') {
				pltxt_output[i] = ' ';
			}
		}

		//for (char c = 'a'; c <= 'z'; c++) {
		//	if (map[c] != '\0') {
		//		cout << c << " : " << map[c] << endl;
		//	}
		//}

		fgets(INPUT, BUFFSIZE, stdin);
		int lengIN = STRLEN(INPUT);
		INPUT[STRLEN(INPUT) - 1] = '\0';

		dic_size = 0;
		int wordLeng = 0;
		char TEMP[BUFFSIZE];

		for (i = 0; i < STRLEN(INPUT) + 1; i++) {	//to INPUT_COR word
			if (INPUT[i] != ' ') {
				TEMP[wordLeng] = INPUT[i];
				dic[dic_size][wordLeng] = TEMP[wordLeng];
				wordLeng++;
			}
			else {
				dic_size++;
				wordLeng = 0;
				continue;
			}
		}
		dic[dic_size][wordLeng] = '\0';
		dic_size++;

		//int final_dic_size = dic_size;
		//for (int i = 0; i < dic_size; i++) {
		//	for (int j = 0; dic[i][j]; j++) {
		//		dic[dic_size + i][j] = dic[i][STRLEN(dic[i]) - 1 - j];
		//	}
		//	final_dic_size++;
		//}
		//dic_size = final_dic_size;
		//cout << "dic size : " << dic_size << endl;

		//for (int j = 0; j < dic_size; j++) {		//print of inputed dics
		//	cout << j << " " << dic[j] << endl;
		//}

		fgets(INPUT, BUFFSIZE, stdin);
		INPUT[STRLEN(INPUT) - 1] = '\0';

		line_len = STRLEN(INPUT);

		//cout << "len : " << line_len << endl;


		search(0, map, inv);

		cout << pltxt_output << endl;
		//cout << FOX << endl;
		//cout << pltxt << endl;

	}

	return 0;
}

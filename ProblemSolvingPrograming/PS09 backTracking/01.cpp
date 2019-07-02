#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

#define arrLength 4                // change arrLength
#define element int

//double mysqrt(unsigned int src)
//{
//    unsigned int NUM_REPEAT = 16;
//    unsigned int k;
//    double t;
//    double buf = (double)src;
//    for(k=0,t=buf;k<NUM_REPEAT;k++)
//    {
//        if(t<1.0)
//            break;
//        t = (t*t+buf)/(2.0*t);
//    }
//    return t;
//}

int squreRoot(int num) {
	return (int)sqrt(num) + 1;
}



int arrNum[10] = { 2,3,5,7 };    // if add 1,
int input;


bool isPrime(element num) {
	//int temp = num/2;
	int temp = squreRoot(num);

	//cout << "isPrime?" << endl;
	for (element i = 2; i < temp; i++) { //detect output is prime?
		if (num%i == 0) {
			return false;
		}
	}
	return true;
}

void solve(int);
int DFS(element, int);

int main() {

	while (cin >> input) {
		//cout << "input is : " << input << endl;
		/*if(input == 8){
		for(int i=0;i<5;i++){
		cout<<eight[i]<<endl;
		}
		}else{*/
		solve(input);
		//}
	}

	return 0;
}

void solve(int input) {
	for (int i = 0; i < arrLength; i++) {
		DFS(arrNum[i], 1);
	}
}

int DFS(element num, int index) {
	if (index == input) {
		//cout << "end!" << endl;
		//cout << num ;
		if (isPrime(num)) {
			//cout << num << endl;
			printf("%d\n", num);
			//cout << " is Prime" << endl;
		}
		return 0;
	}

	int numTen = num * 10;

	for (element i = 1; i < 10; i = i + 2) {
		if (isPrime(numTen + i)) {
			DFS(numTen + i, index + 1);
		}
	}
	return 0;
}
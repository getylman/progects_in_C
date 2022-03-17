#include <stdio.h>
#include <stdlib.h>

#define N 100
#define Num 100000

typedef struct {
	char Key[N], Data[N];
} Key_and_Data;

Key_and_Data HASH[Num];
char Used[Num] = {};

int hash_fun(char * s) {
	int num = 0, id = 0;
	while(*(s + id) != '\0') {
		num += (int)s[id] * (id + 1);
		num %= Num;
		++ id;
	}
	return num;
}

int main() {
	int id = 0;
	char A[N], B[N];
	
	while(scanf("%s %s", A, B) != EOF) {
		int it = hash_fun(A);
		if(Used[it]) {
			while(Used[it]) {
				it ++;
				it %= Num;
			}
		}
		id = 0;
		while(*(A + id) != '\0') {
			HASH[it].Key[id] = A[id];
			id ++;
		}
		HASH[it].Key[id] = '\0';
		id = 0;
		while(*(B + id) != '\0') {
			HASH[it].Data[id] = B[id];
			id ++;
		}
		HASH[it].Data[id] = '\0';
		Used[it] = 1;
	}
	for(int i = 0; i < Num; i ++) {
		if(Used[i]) {
			printf("%s ~ %s\n", HASH[i].Key, HASH[i].Data);
		}
	}
	
	return 0;
}

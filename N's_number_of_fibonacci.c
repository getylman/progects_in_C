#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned long long ll;
typedef unsigned int ui;
const ui L = 1000000000;


typedef struct {
	int size, copasity;
	ui * A;
}S;

void add(S * a, S * b, S * c) {
	int an = a -> size, bn = b -> size, next = 0;
	int M = (an >= bn) ? (an) : (bn);
	int it = 0;
	
	c -> copasity = M + 3;
	c -> A = (ui *)realloc(c -> A, (M + 3) * sizeof(ui));
	
	for(int i = 0; i <= M; i ++) {
		ll sum = 0;
		if(i <= an) {
			sum += *(a -> A + i);
		}
		if(i <= bn) {
			sum += *(b -> A + i);
		}
		sum += next;
		next = sum / L;
		c -> A[it ++] = sum % L;
	}
	if(next) {
		c -> A[it ++] = next;
	}
	c -> size = it - 1;
}

void set(S * a, S * b) {
	a -> A = (ui*)realloc(a -> A, (b -> copasity) * sizeof(ui));
	a -> copasity = b -> copasity;
	int bn = b -> size;
	for(int i = 0; i <= bn; i ++) {
		a -> A[i] = b -> A[i];
	}
	a -> size = b -> size;
}

void print_S(S * a) {
	for(int i = a -> size; i >= 0; i --) {
		printf("%u", a -> A[i]);
	}
}


void fib(int n) {
	S a, b, c;
	a.size = 0;
	a.copasity = 100;
	a.A = (ui*)malloc(sizeof(ui) * a.copasity);
	a.A[0] = 0;
	
	b.size = 0;
	b.copasity = 100;
	b.A = (ui*)malloc(sizeof(ui) * b.copasity);
	b.A[0] = 1;
	
	c.size = 0;
	c.copasity = 100;
	c.A = (ui*)malloc(sizeof(ui) * c.copasity);
	c.A[0] = 0;
	
	while(n --) {
		add(&a, &b, &c);
		set(&a, &b);
		set(&b, &c);
	}
	print_S(&c);
	free(a.A);
	free(b.A);
	free(c.A);
}





int main() {
	int n;
	scanf("%d", &n);
	fib(n);
	return 0;
}

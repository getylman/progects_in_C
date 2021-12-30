#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define N 105


typedef unsigned long long ll;
typedef unsigned int ui;
int dp[N][N], id[N][N], I;

void rek(int l, int r, char * s, char * c) {
	if(dp[l][r] == r - l + 1) {
		return;
	}
	if(dp[l][r] == 0) {
		for(int i = l; i <= r + l; i ++) {
			c[I ++] = s[i];
		}
		return;
	}
	if(id[l][r] == -1) {
		c[I ++] = s[l];
		rek(l + 1, r - 1, s, c);
		c[I ++] = s[r];
		return;
	}
	rek(l, id[l][r], s, c);
	rek(id[l][r] + 1, r, s, c);
}



int is_open(char c) {
	int res = 0;
	if(c == '[' || c == '(' || c == '{') res = 1;
	return res;
}

char closer(char c) {
	char t;
	if(c == '(') t = ')';
	else if(c == '{') t = '}';
	else if(c == '[') t = ']';
	return t;
}

int main() {
	char s[N], c[N];
	scanf("%s", s);
	int len = 0;
	while(s[len] != '\0') ++ len;
	for(int i = 0; i < len; i ++) {
		for(int j = i; j >= 0; j --) {
			if(i == j) dp[i][j] = 1;
			else {
				int M = 100000;
				int it = -1;
				if(is_open(s[j]) && s[i] == closer(s[j])) M = dp[j + 1][i - 1];
				for(int k = j; k < i; k ++) {
					if(M > dp[j][k] + dp[k + 1][i]) {
						M = dp[j][k] + dp[k + 1][i];
						it = k;
					}
				}
				dp[j][i] = M;
				id[j][i] = it;
			}
		}
	}
	rek(0, len - 1, s, c);
	if(I) {
		for(int i = 0; i < I; i ++) {
			printf("%c", c[i]);
		}
	}
	else printf("NOOOOOOOOOOOOO");
	return 0;
}

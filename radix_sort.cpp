#include <iostream>
#include <queue>
#include <vector>

const int N = 32;
unsigned int bit_mask_arr[N] = {};

void merch(std::vector<int> & V, std::queue<int> q0, std::queue<int> q1) {
	int it = 0;
	while(!q0.empty()) {
		V[it ++] = q0.front();
		q0.pop();
	}
	while(!q1.empty()) {
		V[it ++] = q1.front();
		q1.pop();
	}
}

void radiX(std::vector<int> & V) {
	for(int i = 0; i < N; i ++) {
		std::queue<int> q0, q1;
		for(auto j : V) {
			int l = j;
			if(l & bit_mask_arr[i]) {
				q1.push(j);
			}
			else {
				q0.push(j);
			}
		}
		
		if(i != N - 1) {
			merch(V, q0, q1);
		}
		else {
			merch(V, q1, q0);
		}
	}
}


int main() {
	int l = 1;
	for(int i = 0; i < N; i ++) {
		bit_mask_arr[i] = l;
		l <<= 1;
	}
	std::vector<int> v;
	int n;
	std::cin >> n;
	v.reserve(n);
	for(int i = 0, a; i < n; i ++) {
		std::cin >> a;
		v.push_back(a);
	}
	radiX(v);
	for(auto i : v) {
		std::cout << i << ' ';
	}
	return 0;
}




#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAX  100

int visited[MAX];
int N;
char Out[MAX];
char ch[MAX];
void solve(int i) {
	if (i == N) {
		for (int k = 0; k < N; k++) {
			printf("%c", Out[k]);
	   }
		printf("\n");
		return ;
	}
	int j;
	for(j = 0 ; j < N ; j++)if(!visited[j]){
		visited[j] = 1;
		Out[i] = ch[j];
		solve(i + 1);
		visited[j] = 0;
	}
}

int main() {

	N = 3;
	ch[0] = 'a';
	ch[1] = 'b';
	ch[2] = 'c';
	solve(0,0);
	return 0;
}

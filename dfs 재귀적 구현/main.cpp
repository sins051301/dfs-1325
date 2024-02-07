#include <vector>
#include <iostream>
#include <stack>
#include <cmath>
#include<algorithm>
using namespace std;

vector<bool> visit(100000, false);
vector<int> computer[100000];
vector<int> countComputer[100000];
vector<int>Compare;

void dfs(int start, int *cnt) {
	visit[start] = true;
	(*cnt)++;
	for (int i = 0; i < computer[start].size(); i++) {
		int next = computer[start][i];
		if (!visit[next]) {
			dfs(next, cnt);
		}
	}
	
}




int main() {
	int N, M, i, A, B, cnt =0, maxcount =0;
	int* pcnt=&cnt;
	cin >> N >> M;

	for (i = 0; i < M; i++) {
		cin >> A >> B;
		computer[B].push_back(A);
	}

	for (i = 1; i <= N; i++) {
		*pcnt = 0;
		dfs(i, pcnt);
		maxcount = max(maxcount, *pcnt);
		countComputer[*pcnt].push_back(i);

		fill(visit.begin(), visit.end(), false);
	}
	for (i = 0; i < countComputer[maxcount].size(); i++) {
		Compare.push_back(countComputer[maxcount][i]);
	}
	sort(Compare.begin(), Compare.end());
	for (auto iter : Compare) {
		cout << iter << '\n';
	}


}
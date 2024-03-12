#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

int main(int argc, char* argv[]) {
	int N, M;
	stack<int> s;
	char cmd[6];
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", cmd);
		if (!strcmp(cmd, "push")) {
			scanf("%d", &M);
			s.push(M);
		}
		if (!strcmp(cmd, "pop")) {
			if (!s.empty()) {
				printf("%d\n", s.top());
				s.pop();
			}
			else
				printf("-1\n");
		}
		if (!strcmp(cmd, "size"))
			printf("%d\n", s.size());
		if (!strcmp(cmd, "empty")) {
			if (!s.empty())
				printf("0\n");
			else
				printf("1\n");
		}
		if (!strcmp(cmd, "top")) {
			if (!s.empty())
				printf("%d\n", s.top());
			else
				printf("-1\n");
		}
	}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct QE
{
	int ver;
	int dis;
};

int getMinDiceThrows(int steps[], int N)
{
	bool *visited = new bool[N]();
	queue<QE> q;
	visited[0] = true;
	QE start = {0, 0};
	q.push(start);

	QE current;
	while (!q.empty())
	{
		current = q.front();
		int v = current.ver;
		if (v == N - 1)
			break;
		q.pop();
		for (int j = v + 1; j <= (v + 6) && j < N; ++j)
		{
			if (!visited[j])
			{
				QE next;
				next.dis = (current.dis + 1);
				visited[j] = true;
				next.ver = (steps[j] != -1) ? steps[j] : j;
				q.push(next);
			}
		}
	}
	return current.dis;
}

int main()
{
	int size = 50;
	int steps[size] = {-1};

	steps[2] = 21;
	steps[4] = 7;
	steps[10] = 25;
	steps[19] = 28;
	steps[30] = 50;
	steps[25] = 49;

	steps[49] = 0;
	steps[37] = 10;
	steps[26] = 0;
	steps[20] = 8;
	steps[16] = 3;
	steps[18] = 6;

	cout << "Minimum number of dice throws required is " << getMinDiceThrows(steps, size) << endl;

	return 0;
}
#include <bits/stdc++.h>

#define MAXN 123456

using namespace std;

int main()
{
	int test = 5;
	srand(time(0));
	while( test-- )
	{
		int N = rand() % MAXN + 1;
		int v[N];
		// Initialize
		for(int i=0; i<N; i++)
		{
			v[i] = i+1;
		}
		// Shuffle
		for(int i=0; i<N; i++)
		{
			for(int i=0; i<N; i++)
			{
				int x=rand()%N, y=rand()%N;
				swap(v[x],v[y]);
			}
		}
		//Print
		printf("%d\n",N);
		for(int i=0; i<N; i++)
		{
			printf("%d ",v[i]);
		}
		printf("\n");
	}
	return 0;
}

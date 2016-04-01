#include <iostream>
#include <stdio.h>
#include <memory.h>

#define MAXN 10000

using namespace std;

enum Team {NONE,A,B};

int N, p[MAXN], Rank[MAXN];
Team team[MAXN];

int init(int n)
{
	if(n >= MAXN)
		return -1;
	N = n;
	for(int i=0; i<n; i++)
	{
		p[i] = i;
		team[i] = NONE;
		Rank[i] = 0;
	}
	return 0;
}

void link(int x, int y)
{
	if (Rank[x] > Rank[y])
		p[y] = x;
	else
	{
		p[x] = y;
		if (Rank[x] == Rank[y])
			Rank[y] = Rank[y] + 1;
	}
}

int find_set(int x)
{
	if (x != p[x])
		p[x] = find_set(p[x]);
	return p[x];
}

void union_set(int x, int y)
{
	link(find_set(x), find_set(y));
}

int areFriends(int u, int v)
{
	return 0;
}

int areEnemies(int u, int v)
{
	return 0;
}

int setFriends(int u, int v)
{
	return 0;
}

int setEnemies(int u, int v)
{
	return 0;
}

int main()
{
	int n, c, x, y, ret;
	scanf("%d",&n);
	ret = init(n);
	if (ret)
	{
		printf("ERR: %d is to large!",n);
	}
	while(scanf("%d %d %d",&c,&x,&y)!=EOF)
	{
		if (!c && !x && !y)
			break;
		switch(c)
		{
			case 1:
			{
				ret = setFriends(x,y);
				if (ret)
					printf("%d\n",ret);
				break;
			}
			case 2:
			{
				ret = setEnemies(x,y);
				if (ret)
					printf("%d\n",ret);
				break;
			}
			case 3:
			{
				ret = areFriends(x,y);
				printf("%d\n",ret);
				break;
			}
			case 4:
			{
				ret = areEnemies(x,y);
				printf("%d\n",ret);
				break;
			}
			default: printf("ERR: c=%d invalid option!",c);
		}
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <pthread.h>

#define MAXN 1234567 // ~ 10^6

using namespace std;

typedef long long int i64;

// We declare variables here to save heap memory
int raw[MAXN],ord[MAXN],aux[MAXN];


//Merge
i64 merge(int v[], int va[], int L, int R)
{
	i64 cnt = 0LL; //swapping ops
	if( L<R ) //More than one element
	{
		// Split array in two
		int mid = (L+R)/2;

		//Solve each part
		cnt += merge(va,v,L,mid);
		cnt += merge(va,v,mid+1,R);

		//Merge both solutions
		int i = L, j = mid + 1, k = L;
		while( i<=mid && j<=R )
		{
			if(va[i] <= va[j])
				v[k++] = va[i++];
			else
			{
				v[k++] = va[j++];
				cnt += (mid+1) - i; // swaps 
			}
		}
		//Fill the rest
		while ( i <= mid ) v[ k++ ] = va[ i++ ];
		while ( j <= R ) v[ k++ ] = va[ j++ ];
	}
	return cnt;
}

//Merge Sort
i64 merge_sort(int data[], int size)
{
	// Initialize
	for(int i=0; i<size; i++)
	{
		ord[i] = aux[i] = data[i];
	}
	i64 movs = merge(ord,aux,0,size-1);

	printf("It takes %lld moves to sort\n",movs);
	for(int i = 0; i < size; i++)
	{
		printf("%d ",ord[i]);
	}printf("\n");

	return movs;
}


int main()
{
	int array_size;

	puts("Please specify the size of array:");
	scanf("%d",&array_size);
	puts("Please introduce the elements of the array:");
	for(int i = 0; i < array_size; i++)
	{
		scanf("%d",&raw[i]);
	}
	// Call sorting algorithms
	merge_sort(raw,array_size);
	return 0;
}


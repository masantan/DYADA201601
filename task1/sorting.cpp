#include <iostream>
#include <cstdio>
#include <algorithm>
#include <pthread.h>

#define MAXN 1234567 // ~ 10^6

using namespace std;

typedef long long int i64;

// We declare variables
int raw[MAXN];
// Merge Variables
int m_array[MAXN], m_aux[MAXN];
// Heap Variables
int h_array[MAXN], h_aux[MAXN], h_size, h_root;


//  Merge
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
		m_array[i] = m_aux[i] = data[i];
	}
	i64 movs = merge(m_array,m_aux,0,size-1);

	printf("It takes %lld moves to sort\n",movs);
	for(int i = 0; i < size; i++)
	{
		printf("%d ",m_array[i]);
	}printf("\n");

	return movs;
}

// A heap reference 
// http://algorithms.tutorialhorizon.com/binary-min-max-heap/

// Heap initialization 
inline void heap_init()
{
	h_size = 0;
	h_root = 1;
}

// Heap is_root
inline int is_root(int node)
{
	return node == 1;
}

// Heap get_parent
inline int get_parent(int node)
{
	return node >> 1;
}

// Heap insert
i64 heap_insert(int heap[], int val)
{
	int parent = 0;
	int node = ++h_size;
	i64 cicles = 0LL;
	heap[node] = val;
	while( !is_root(node) )
	{
		parent = get_parent(node);
		//printf("%s n=%d p=%d\n",__FUNCTION__,node,parent);
		if(heap[node] >= heap[parent]) break;
		//printf("%d %d\n",heap[node],heap[parent]);
		swap(heap[node], heap[parent]);
		node = parent;
		cicles++;
	}
	return cicles;
}

// Heap delete
i64 heap_delete(int heap[], int &val)
{
	int parent, left, right;
	i64 cicles = 0LL;

	if( h_size == 0) return -1LL;
	val = heap[h_root];
	h_size--;

	if(h_size >= h_root)
	{   // Set the last element
		heap[h_root] = heap[h_size+1];
		int node, small=h_root;
		do
		{
			node = small;
			left = node << 1;
			right = left + 1;
			if(left<=h_size && heap[left]<heap[small])
			{
				small = left;
			}
			if(right<=h_size && heap[right]<heap[small])
			{
				small = right;
			}
			//printf("n=%d s=%d sm=%d\n",node,small,heap[small]);
			swap(heap[node],heap[small]);
			cicles++;
		}while(small != node);
	}

	return cicles;
}

// Heap Sort
i64 heap_sort(int data[], int size)
{
	i64 movs = 0LL;
	heap_init();
	// Insert elements
	for(int i=1; i<=size; i++)
	{
		movs += heap_insert(h_aux, data[i-1]);
	}

	printf("It takes %lld moves to sort\n",movs);
	for(int i = 0; i < size; i++)
	{
		movs += heap_delete(h_aux, h_array[i]);
		printf("%d ",h_array[i]);
	}printf("\n");

	return movs;
}


int main()
{
	int array_size;

	while(scanf("%d",&array_size) != EOF)
	{
	/*
	 * puts("Please specify the size of array:");
	 * scanf("%d",&array_size);
	 * puts("Please introduce the elements of the array:");
	 */
		for(int i = 0; i < array_size; i++)
		{
			scanf("%d",&raw[i]);
		}
		// Call sorting algorithms

		// Call merge sort
		merge_sort(raw, array_size);

		// Call Heap sort
		heap_sort(raw, array_size);
	}

	return 0;
}


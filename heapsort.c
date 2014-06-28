//Heap sort
#include<stdio.h>

int swap(int *a,int *b)
{
        int temp=*a;
        *a=*b;
        *b=temp;
}

void heapify(int heap[],int i,int n)
{
        int left=2*i;
        int right=2*i+1;
        int largest=i;
        if(left<n && heap[left]>heap[i])
        {
                largest=left;
        }
        if(right<n && heap[right]>heap[largest])
        {
                largest=right;
        }
        if(largest!=i)
        {
                swap(&heap[i],&heap[largest]);    
                heapify(heap,largest,n);
        }
}

void build_heap(int heap[],int n)
{
        int i;
        for (i =(n/2); i>=0; i--)
        {
                 heapify(heap,i,n);
        }
}


void sort(int heap[],int n)
{
        int i;
        build_heap(heap,n);
        for(i=n-1;i>=1;i--)
        {
             swap(&heap[0],&heap[i]);
             heapify(heap,0,i);
        }
}

int main()
{
	int heap[100],n,i;
	printf("\nEnter the no of elements:");
	scanf("%d",&n);
	printf("\nEnter the elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&heap[i]);
	}
	sort(heap,n);
	printf("\nSorted array is:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",heap[i]);
	}
	return 0;
}

Output:-
Enter the no of elements:5
Enter the elements:1 5 3 7  9
Sorted array is:1 3 5 7 9
	
                

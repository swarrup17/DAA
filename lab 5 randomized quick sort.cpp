#include<iostream>
#include<cstdlib>
using namespace std;
int count=0;
int partition(int A[],int l, int r)
{
    int x=l;
    int y=r;
    int pivot = A[l];
    count = count+3;
    while(x<y)
    {
        while(A[x]<=pivot)
        {
            x++;
            count =count+3;    
        }
    
        while(A[y]>pivot)
        {
             y--;
            count =count+3;        
        }
        if(x<y)
        {
            int t = A[x];
            A[x]=A[y];
            A[y] = t;
            count =count+4;        
        }  
    }
     A[l] =A[y];
    A[y]= pivot;
    count = count+3;
    return y;  
}
int randpartition(int A[],int l, int r)
{    
int k = l+rand()%(r-l);
int t = A[l];
A[l]=A[k];
A[k]=t;
count =count +4;
return partition(A,l,r);    
}
void RandQuickSort(int A[],int l ,int r)
{
    if(l<r)
    {
        count++;
    int p = randpartition(A,l,r);
    RandQuickSort(A,l,p-1);
    RandQuickSort(A,p+1,r);    
    }    
}
int main()
{
  int n;
	cout<<"Enter the size of data:";
	cin>>n;
	int a[n];
	cout<<"Enter the Elements:"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"Elements before sorting:"<<endl;
		for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<"\nElements after sorting:"<<endl;
RandQuickSort(a,0,n);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<"\n";
	cout<<"The total number of steps required is:"<<count<<
	endl;
}
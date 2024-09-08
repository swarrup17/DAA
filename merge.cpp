#include<iostream>
using namespace std;
int B[100];
int count = 0;
void Merge(int A[],int l, int m ,int r)
{
    int x= l;
    int y= m;
    int k= l;
    count = count + 3;
    while(x<m && y<=r)
    {
        if(A[x]<A[y])
        {
        B[k]=A[x];
        k++;
        x++;
        count = count + 6;
        }
        else
        {
        B[k]=A[y];
        k++;
        y++; 
        count = count +  6;    
        } 
    }
        while(x<m)
        {
        B[k]=A[x];
        k++;
        x++;
        count =count+6;    
        } 
        while(y<=r)
        {
        B[k]=A[y];
        k++;
        y++;
        count =count+6;        
        }
        for(int i=l ;i<=r;i++)
        {
        A[i] = B[i];
        count = count+    5;
        }
}
void MergeSort(int A[9],int l ,int r)
{
    if(l<r)
    {
        count = count+3;
        int m = (l+r)/2;
        MergeSort(A,l,m);
        MergeSort(A,m+1,r);
        Merge(A,l,m+1,r);
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
MergeSort(a,0,n);
 for(int i=0 ;i<n ;i++)
        {
    cout<<a[i]<<"\t" ;
        }
cout<<endl;        
cout<<"No. of Steps required : "<<count;              
return 0;
}
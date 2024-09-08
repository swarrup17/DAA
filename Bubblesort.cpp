    #include<iostream>
using namespace std;
int count=0;
void Bubblesort(int a[], int n)
{
	int temp;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
			count=count+10;
		}
		count=count+5;
	}
	for(int i=0;i<n;i++)
	{
			cout<<a[i]<<"\t";
	}
	cout<<"\nThe total number of steps for bubble sort is:"<<count<<endl;
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
	Bubblesort(a,n);
}
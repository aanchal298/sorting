#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;

int temp[100];

void quicksort(int a[],int i,int j)
{
    int pivot = a[i];

    int x = i, y = j;
    while(x<=y)
    {
        while(a[x] < pivot)
            x++;

        while(a[y] > pivot)
            y--;

        if(x<=y)
        {
            int temp = a[x];
            a[x] = a[y];
            a[y] = temp;

            x++;
            y--;
        }

    }
    if(i<y)
        quicksort(a,i,y);
    if(j>x)
        quicksort(a,x,j);

}


/*


int Partition(int a[], int beg, int end)          //Function to Find Pivot Point
{
int p=beg, pivot=a[beg], loc;

for(loc=beg+1;loc<=end;loc++)
{
if(pivot>a[loc])
{
a[p]=a[loc];
a[loc]=a[p+1];
a[p+1]=pivot;

p=p+1;
}
}
return p;
}


void quicksort(int a[], int beg, int end)
{
if(beg<end)
{
int p=Partition(a,beg,end);                       //Calling Procedure to Find Pivot

quicksort(a,beg,p-1);                             //Calls Itself (Recursion)
quicksort(a,p+1,end);			              //Calls Itself (Recursion)
}
}

*/
int main()
{
    int t = 10;

    while(t--)
    {
        int n = 10;
        int a[20];
        int b[20];
        for(int i = 0; i<n ; i++)
            a[i] = rand()%20;
        cout<<"\n\nORIGINAL     ";
        for(int i = 0; i<n ; i++)
            cout<<a[i]<<"   ";

        copy(a,a+n,b);
        sort(b,b+n);

        cout<<"\n\nSORTED       ";

        quicksort(a,0,n-1);
        for(int i = 0; i<n ; i++)
            cout<<a[i]<<"   ";
        cout<<"\n\n             ";
        for(int i = 0; i<n ; i++)
            cout<<b[i]<<"   ";

    }
}


#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;

int temp[100];

void mergesort(int a[],int i,int j)
{
    if(i == j)
        return;

    int mid = (i+j)/2;
    mergesort(a,i,mid);
    mergesort(a,mid+1,j);

    int x = i,y=mid+1,idx=0;

    while(x<=mid && y<=j)
    {
        if(a[x] <= a[y])
            temp[idx++] = a[x++];
        else
            temp[idx++] = a[y++];
    }

    while(x<=mid)
        temp[idx++] = a[x++];

    while(y<=j)
        temp[idx++] = a[y++];

    for(x = 0 ; x<idx ; x++)
        a[i++] = temp[x];

}


int main()
{
    int t = 10;

    while(t--)
    {
        int n = 10;
        int a[20],b[20];

        for(int i = 0; i<n ; i++)
            a[i] = rand()%20;
        cout<<"\n\nORIGINAL     ";
        for(int i = 0; i<n ; i++)
            cout<<a[i]<<"   ";

        copy(a,a+n,b);
        sort(b,b+n);

        cout<<"\n\nSORTED       ";

        mergesort(a,0,n-1);
        for(int i = 0; i<n ; i++)
            cout<<a[i]<<"   ";

        cout<<"\n\n             ";
        for(int i = 0; i<n ; i++)
            cout<<b[i]<<"   ";


    }
}


#include<iostream>
using namespace std;


int main()
{
    int a[20];
    int n;
    cin>>n;
    for(int i = 0 ; i<n ; i++)
        cin>>a[i];

    for(int i = 1; i<n ; i++)
    {
        int j = i;
        int v = a[i];

        while(j>=1 && a[j-1] > v )
        {
            a[j] = a[j-1];
            j--;

        }
        a[j] = v;

    }

    for(int i = 0 ; i<n ; i++)
        cout<<a[i];

    return 0;

}

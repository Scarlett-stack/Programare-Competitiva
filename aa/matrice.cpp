#include <iostream>
using namespace std;
int main()
{
    int a[10][10];
    int n,i,j;
    cin>>n;
    for (i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            cin>>a[i][j];
        }
    int ok = 0;
    i=0;
    j=0;
    while (j)
        for (j = 0; j<n; j++)
        {   
            if (a[i][j] == 0)
            {   ok = 1;
                break;
            }
            cout<<"after"<<endl;
        }
    return 0;
}
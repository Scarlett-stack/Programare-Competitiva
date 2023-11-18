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
    while (i < n)
       { cout<<"aci"<<endl;
       j = 0;
        while (j<n && a[i][j] != 0) 
        {
            if (a[i][j] % 2 == 0 && a[i][j+1] %2 == 0 && j+1 < n && a[i][j+1] != 0)
                cout<<"pereche: "<<i<<' '<<j<<"---"<<i<<' '<<j+1<<endl;
            j++;
        }
        if (j < n)
        break;
        if (i + 1 <n && a[i+1][1]%2 == 0 && a[i][n-1] % 2 == 0 && a[i+1][1] != 0)
        cout<<"pereche magine : "<<i<<' '<<n-1<<"---"<<i+1<<' '<<1<<endl;
        
        i++;
       }
    return 0;
}
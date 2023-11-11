#include <iostream>
using namespace std;
int A[501][501], s[502][502];
int main()
{
    int n,i,j,q,l1,c1,l2,c2,v;
    cin>>n;
    for(i = 1; i<=n; i++)
        for (j =1 ; j<=n; j++)
        cin>>A[i][j];
    cin>>q;
    while (q--)
    {
        cin>>l1>>c1>>l2>>c2>>v;
        s[l1][c1]+=v;
        s[l1][c2+1]-=v;
        s[l2+1][c1]-=v;
        s[l2+1][c2+1]+=v;

    }
    for (i=1; i<=n; i++)
        for (j =1 ; j<=n; j++)
            s[i][j] = s[i][j]+s[i-1][j]+s[i][j-1] - s[i-1][j-1];
    
     for (i=1; i<=n; i++)
        {for (j =1 ; j<=n; j++)
            cout<<s[i][j]<<' ';
        cout<<endl;
        }
    for (i=1; i<=n; i++)
        for (j =1 ; j<=n; j++)
            A[i][j] = s[i][j] +A[i][j];// A[i-1][j] + A[i][j-1] - A[i-1][j-1];
    
     for (i=1; i<=n; i++)
        {for (j =1 ; j<=n; j++)
            cout<<A[i][j]<<' ';
        cout<<endl;
        }
}
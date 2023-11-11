#include <iostream>
#include <fstream>
using namespace std;

ifstream f("maria.in");
ofstream g("maria.out");
/*
int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
*/
int verific(int i, int j, int n, int m)
{
  if (i<=n && i>=1 && j<=m && j>=1)
    return 1;
 return 0;
}
int a[1001][1001], s[1001][1001];
int main()
{
    int n, m, p, q;
       int i,j;
    f >> n >> m >> p >> q;
    int k;
    f >> k;
    for ( i = 1; i <= k; i++)
    {
        int x, y;
        f >> x >> y;
        a[x][y] = 1;
    }

    
    for ( i = 1; i <= n; i++)
        for ( j = 1; j <= m; j++)
        {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    
    int cnt = 0,suma;

    // slide pentru careu de arie qxp
        for (int i = 1; i <= n; i++)
            {for(int j =1; j<=m; j++)
                    cout<<s[i][j]<<' ';
                cout<<endl;
                    
                }
    int  lin, col;
    for (i = 1; i<=n; i++)
        for (j=1; j<=m; j++)
        {
            lin = i+p-1;
            col = j+q- 1;
            suma = s[lin ][col] - s[lin][j-1] - s[i-1][col] + s[i-1][j-1];
            if (verific(lin,col,n,m) && suma == 0)
                {cnt++;
                cout<<"afis 1 "<<lin<<' '<<col<<"----"<<i<<' '<<j<<endl;
                }
            lin = i+q-1;
            col = j+p-1;
            suma = s[lin][col] - s[lin][j-1] -s[i-1][col] + s[i-1][j-1];

            if (verific(lin,col,n,m) && suma == 0)
                {cnt++;
                cout<<"afis 2 "<<lin<<' '<<col<<"--- "<<i<<' '<<j<<endl;
                }
        }
    
    g<<cnt<<endl;
    return 0;
}
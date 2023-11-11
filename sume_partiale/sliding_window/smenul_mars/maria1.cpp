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
//ce se intampla dupa cele p linii si q coloane? for urile nu trec mai departe aici dar ar trb sa o faca
int maxim(int x, int y)
{
    if (x > y)
        return x;
    return y;
}
int a[1001][1001], s[1001][1001];
int main()
{
    int n, m, p, q;
       int i,j;
    f >> n >> m >> p >> q;
    int k;
    f >> k;
    for (int i = 1; i <= k; i++)
    {
        int x, y;
        f >> x >> y;
        a[x][y] = 1;
    }

    for (int i = 1; i <= m; i++)
        s[1][i] = s[1][i-1] + a[1][i];
    for (int i = 1; i <= n; i++)
        s[i][1] = s[i-1][1] + a[i][1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
     for (int i = 1; i <= n; i++)
            {for(int j =1; j<=m; j++)
                    cout<<s[i][j]<<' ';
                cout<<endl;
                    
                }
    int cnt = 0;
  
    int suma;

    // slide pe primele p linii
    for ( j = 1; j <= m - q + 1; j++)
    {
        suma = s[p][j + q - 1] - s[p][j - 1];
        if (suma == 0)
        {
            cnt++;
            cout<<"slide pe prima 1 "<<1<<' '<<j<<endl;
        }
    }
 
    for ( i = 1; i+p-1 <= n; i++)
    {
        for ( j = 1; j+q-1 <= m ; ++j)
            suma = s[i + p - 1][j + q - 1] - s[i + p - 1][j - 1] - s[i - 1][j + q - 1] + s[i - 1][j - 1];

        if (suma == 0)
        {cnt++;
        cout<<"coord 1 "<<i<<' '<<j<<endl;
        }
    }
    //-------------------------------------q p
    
    if (p != q)
    {
        int aux = p;
        p = q;
        q = aux;

        
   

    // slide pe primele p linii
    for ( j = 1; j <= m - q + 1; j++)
    {
        suma = s[p][j + q - 1] - s[p][j - 1];
        if (suma == 0)
        {
            cnt++;
         cout<<"slide pe prima 2 "<<1<<' '<<j<<endl;
        }
    }
    for ( i = 1; (i + p -1) <=n; i++)
    {
        for ( j = 1; (j+q-1)<=m; j++)
            suma = s[i + p - 1][j + q - 1] - s[i + p - 1][j - 1] - s[i - 1][j + q - 1] + s[i - 1][j - 1];

        if (suma == 0)
        {cnt++;
        cout<<"coord 2"<<i<<' '<<j<<endl;
        }
    }
    }
    g<<cnt;
    return 0;
}
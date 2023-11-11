#include <fstream>
#include <iostream>
using namespace std;
ifstream f ("easyquery.in");
ofstream g ("livada2.out");
int n, q, s[100002], dr[100002], st[100002],v[100001],nr[100001]; 
int main ()
{
    f >> n;    
    for (int i=1; i<=n; i++)
        f >> nr[i];
    for (int i=1; i<=n; i++)
        f>> v[i];
    int i1 = 0;
    for (int i=n; i>=1; i--)
    {
        if (v[i])
            i1 = i;
        dr[i] = i1;    // copac special in dreapta    
    }
    i1 = 0;
    for (int i=1; i<=n; i++)
    {
        
        if (v[i])
           i1 = i;
        st[i] = i1;// copac special in stinga
    }
     for (int i=1; i<=n; i++)
        cout<<st[i]<<' ';
    cout<<endl;
     for (int i=1; i<=n; i++)
     cout<<dr[i]<<' ';
     cout<<endl;
    f >> q;
    for (int i=1; i<=q; i++)
    {
        int x, y, p, c;
        f >> c >> x >> y >> p;
        if (c==1)
        {
            if (dr[y])// copac special in dreapta
            {
                y = dr[y];// 
            }
            s[x] += p;
            s[y+1] -= p;
        }
        else
        {
            if (st[x]) //copac specil in stinga
            {
                x = st[x];
            }
            s[x] -= p;
            s[y+1] += p;
        }
     }
    for (int i=1; i<=n; i++)
          s[i] += s[i-1];
    for (int i = 1; i<=n; i++)
        nr[i]=s[i] + nr[i];
    
    for (int i = 1; i<=n; i++)
        g << nr[i]<< ' ';
    
    return 0;   
}
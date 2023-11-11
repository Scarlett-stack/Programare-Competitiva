#include <iostream>
#include <fstream>
using namespace std;
struct interval
{
    int x,y;
};
int main()
{
    fstream input("intervale4.in", ios::in);
    fstream output("intervale4.out", ios::out);
    int n;
    input >> n;
    interval v[n+1];
    int i;
    for (i=1; i<=n; i++)
     input>>v[i].x>>v[i].y;
     //sortare
    for (i=1; i<n; i++)
        for (int j=i+1;j<=n; j++)
            {if (v[i].y >v[j].y)
            {
                interval aux = v[i];
                v[i]= v[j];
                v[j] = aux;
            }
            else
                if (v[i].y == v[j].y)
                {
                    int aux = v[i].x;
                    v[i].x = v[j].x;
                    v[j].x = aux;
                }
            }
        //for (i=1; i<=n; i++)
           // cout<<v[i].x<<' '<<v[i].y<<endl;
        int a, b;
        a = v[1].x;
        b = v[1].y;
        int cnt = 1; //primul interval
        i = 2;
        while (i<=n)
        {   
            while (v[i].y == b && i<=n)
            i++;
            if (v[i].x <= b) //reuniune
            {
                 b = v[i].y;
                 //verif daca v[i]. x <a
                 if (v[i].x <a)
                 a = v[i].x;
            }
            else {
                a = v[i].x;
                b = v[i].y;
                cnt++; //am un nou interval
            }
           //cout<<" a si b "<<a<<' '<<b<<endl;
            i++;
        }
    output<<cnt;

    return 0;
}
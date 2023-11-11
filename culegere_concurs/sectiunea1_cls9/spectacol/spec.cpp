#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
struct program
{
    float x,y;
};
int main()
{   
    program a[100];
    int n,i,j;
    cin>>n;
    for (i=0; i<n; i++)
    {
        cin>>a[i].x>>a[i].y;

    }
    for (i=0; i<n-1; i++)
        for (j=i+1; j<n; j++)
        if ((a[i].x > a[j].y ) || (a[i].x == a[j].x && a[i].y > a[j].y)) //daca au acelasi x? ord dupa y
        {
            swap(a[i],a[j]);
        }
    int u = 0,sf = a[0].y;
    for (i = 1; i<n; i++)
    {
        if (a[i].y <sf) //suprapunere cu prev
        {
            cout<<a[u].x<<' '<<a[u].y<<endl;
            u = i;
            sf = a[i].y;
        }
        else
            if(a[i].x < sf) // suprapunere inceput cutent - end precedent
            {
                u = i;
                cout<<a[i].x<<' '<<a[i].y<<endl;
            }
            else{ //merg mai departe
                u = i;
                sf = a[i].y;
            }
    }
    
    return 0;
}
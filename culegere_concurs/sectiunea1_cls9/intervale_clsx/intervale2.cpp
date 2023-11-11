#include <iostream>
using namespace std;
struct interval
{
    int x,y;
};
int main()
{
    int n,i,j;
    interval a[100],aux;
    
    cin>>n;
    //se ordoneaza intervalele in functie de x -capat stang
    //pt reuniune parcurg vectorul pastarnd capetele si actualizandule la nevoie
    for (i = 1; i<=n; i++)
        cin>>a[i].x>>a[i].y;
    //sortare
    for (i = 1; i<n; i++)
        for (j = i+1; j<=n; j++)
            if (a[i].x > a[j].x )
            {
                aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }
    int stanga, dreapta;
    stanga = a[1].x;
    dreapta = a[1].y;

    for (i = 1; i<=n; i++)
    {
        //le am sortate nu ma mai uit la x1 x2 ci la y si x2 sa vada daca se confunda capetele
        if (a[i].x > dreapta)
        {
            cout<<stanga<<' '<<dreapta<<endl;
            stanga = a[i].x;
            dreapta = a[i].y;
        }
        else // capat stanga curent > capat dreapat precedent
            if (a[i].y > dreapta)
            {
                dreapta = a[i].y;
            }

    }
    cout<<stanga<<' '<<dreapta;
    return 0;
}
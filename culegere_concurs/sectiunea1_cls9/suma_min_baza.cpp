#include <iostream>
using namespace std;
int sum(int n, int b)
{
    int s=0,r;
    while (n > 0)
    {
        r = n%b;
        //cout<<r<<endl;
        s = s+r;
        n/=b;
    }
    return s;
}
int main()
{   
    int i = 0;
    int n, x, min=9999;
    cin>>n;
    for (i = 2; i <= 10; i++)
    {
        x = sum(n,i);
        if (x < min)
            min = x;
        if (min == x)
           cout<<i<<endl;
    }
    return 0;
}
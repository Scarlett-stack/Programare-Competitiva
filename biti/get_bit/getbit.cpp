#include <iostream>
#include <bitset>
#include <queue>
using namespace std;
int main()
{   
    int T, b;
    queue<int> c;
    cin>>T;
    int i;
    unsigned long long int x;
    unsigned long long int unu = 1;
    for (i=1; i<=T; i++)
    {
        cin>>x>>b;

        unsigned long long int mask = unu<<b;
        unsigned long long int res = x & mask;
        if (res == 0)
            c.push(0);
        else
            c.push(1);
        //cout<<bitset<1>(res)<<endl;
    }
    while (c.empty() == 0)
    {
        cout<<c.front();
        c.pop();
    }
    return 0;
}
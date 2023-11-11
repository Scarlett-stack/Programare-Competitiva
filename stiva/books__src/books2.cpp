#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    queue <int> c;
    vector <int>f(200001, 0);
    int n,i,x,cnt;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>x;
        c.push(x);

    }
    for (i=1; i<=n; i++)
    {
        cin>>x;
        cnt = 0; //reinitializez
        if (f[x] == 0)
        {
        while (c.front()!= x && c.empty() == 0)
        {   
            f[c.front()] = 1;
            c.pop();
            cnt++;
        }
        //acum il scot si pe x
        
        f[c.front()] = 1;
        c.pop();
        cnt++;
        }
        cout<<cnt<<' ';
        
    }
    return 0;
}
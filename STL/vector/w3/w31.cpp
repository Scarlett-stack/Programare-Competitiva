#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{   vector<int> v;
    int n,x;
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
      for (int i=0; i<n; i++)
      {
        cout<<v.at(i)<<' ';
      }
      cout<<endl;
    int ok = 1;
    for (int i=0; i<n-1; i++)
    { 
        if (!ok)
            break;
        if (abs(v.at(i) - v.at(i+1)) != 1)
        {
            ok = 0;
            cout<<v.at(i)<<' '<<v.at(i+1)<<endl;
            cout<<0;
        }
       
    }
    if (ok)
    cout<<1;
    return 0;
}
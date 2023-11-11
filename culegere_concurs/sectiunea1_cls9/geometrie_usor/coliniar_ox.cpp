#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{   //detrminanr
int n;
cin>>n;
int x, y;
vector <int> v;
    for (int i = 0; i<n; i++)
    {   
        cin>>x>>y;
        v.push_back(x);
        v.push_back(y);
    }

    return 0;
}
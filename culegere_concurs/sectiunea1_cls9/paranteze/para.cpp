#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main()
{
    string sir;
    stack <char> c;
    cin>>sir;
    cout<<sir;
    for (int i =0; i<sir.length(); i++)
        if (sir[i] == '(')
        c.push(sir[i]);
        else
        c.pop();
    if (c.empty())
    cout<<"Corect";
    else
    cout<<"Incorect";
}
// (()()(())
#include <iostream>
using namespace std;
int &f(int &x)
{
    x++;
    return x;
}
int main()
{   int y = 1;
    int& z = f(y);
    int t = f(y);
    cout<<y<<' '<<z<<' '<<t<<' ';
    int a = 1;
    int *b = &a;
    int *&c = b;
    cout<<*c;
    return 0;
}
#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int val(char c)
{
    if (c == 'I')
        return 1;
    if (c == 'V')
        return 5;
    if (c == 'X')
        return 10;
    if (c == 'L')
        return 50;
    if (c == 'C')
        return 100;
    if (c == 'D')
        return 500;
    if (c == 'M')
        return 1000;
    return 0;
}
int roman_arab(char v[])
{
    int arab = 0, aux1, aux2;
    for (int i=0; i<strlen(v) - 1; i++)
    {
        aux1 = val(v[i]);
        if (v[i] != '\0')
        {
            aux2 = val(v[i+1]);
                if (aux1 <aux2)
                    arab-=aux1;
                else
                    arab+=aux1;
        }
        else //e lafinal o adun oricum
            arab+=aux1;
    }
    return arab;
}
stack <char>& arab_roman(int nr)
{
    int ordin = 0;
    stack <char> v;
    string units = "IVXLCD";
    while (nr%10 <= 3)
    {
        if (nr <= 3)    
            for (int i=0; i<nr%10; i++)
                v.push(units[ordin]);
        
        if (nr % 10 == 4)
            {
                v.push(units[ordin+1]);
                v.push(units[ordin]);
            }
        if (nr % 10 == 5)
            v.push(units[ordin+1]);
        if (nr%10 >=6 && nr %10 <=8)
          {  for (int i = 0; i< nr%10 - 5; i++)
                v.push(units[ordin]);
            v.push(units [ordin+1]);
          }
        if (nr % 10 == 9)
        {
            v.push(units[ordin+2]);
            v.push(units[ordin]);
        }
        ordin+=2;
        nr/=10;
    

    }
    if (ordin == 6 && nr!= 0)
    {
        for (int i = 0; i<nr; i++)
            v.push('M');
    }   
    return v;
}
int main()
{   
    stack <char> v = arab_roman(851);
    while (v.empty())
    {
        char c = v.top();
        v.pop();
        cout<<c;
    }
    return 0;
}
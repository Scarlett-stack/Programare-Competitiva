#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
ifstream f("balba.in");
ofstream g("balba.out");
int nr_dif(vector <int> v)
{   
    int cnt = 0;
    for (int element : v)
    {
        if (element > 0)
        {
            cnt++;
            cout<<element<<' ';
        }
    }
    return cnt;
}
int nr_nr(vector <int> v)
{
    int cnt = 0, ok = 0, i = 0;
    while ( i<v.size() - 1)
        {   ok = 0;
            while (v.at(i) == v.at(i+1))
        { 
            ok = 1;
            i++;
        }
        if 
        }
    return cnt;
}
int main()
{   
    vector <int> nr;
    
    int i, cerinta, cate_nr, nr_cifre, cifra;
    f>>cerinta;
    if (cerinta == 1)
    {
        f>>nr_cifre;
        vector <int> frecv(10,0);
        for (i = 0; i<nr_cifre; i++)
            {   f>>cifra;
                nr.push_back(cifra);
                frecv[cifra]++;
            }
        int rez1 = nr_dif(frecv); 
        int rez2 = nr_nr(nr); 
        g<<rez1<<endl<<rez2<<endl;   
    }

    return 0;
}
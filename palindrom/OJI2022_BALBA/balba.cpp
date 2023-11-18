#include <iostream>
#include <vector>
#include <fstream>
// 224422
using namespace std;
ifstream f("balba.in");
ofstream g("balba.out");
int nr_dif(vector<int> v)
{ // 2 2 4 4 6 6 6 6 4 8 8 8 3 0 0
    int cnt = 0;
    int i = 1;
    int ok;
    while (i < v.size())
    { //  ok = 0;
        while (v[i - 1] == v[i] && i < v.size())
        {
            ok = 1; // 1 2 3 4 5 6 7 8
            cout << v[i] << ' ';
            i++;
        }
        // if (ok)
        //  i--;
        cnt++;
        i++;
    }
    if (v[v.size() - 1] != v[v.size() - 2])
        cnt++;
    return cnt;
}
int nr_nr(vector<int> v)
{
    int cnt = 0, ok = 0, i = 0;
    while (i < v.size() - 1)
    {
        ok = 0;
        while (v[i] == v[i + 1] && i < v.size() - 1)
        {
            ok = 1;
            i++;
        }
        if (ok)
            cnt++;
        else
            i++;
    }
    return cnt;
}
int main()
{
    vector<int> nr;

    int i, cerinta, cate_nr, nr_cifre, cifra;
    f >> cerinta;
    if (cerinta == 1)
    {
        f >> nr_cifre;
        cout << nr_cifre;
        vector<int> frecv(10, 0);
        for (i = 0; i < nr_cifre; i++)
        {
            f >> cifra;
            nr.push_back(cifra);
            frecv[cifra]++;
        }
        int rez1 = nr_dif(nr);
        int rez2 = nr_nr(nr);
        g << rez1 << endl
          << rez2 << endl;
    }
    if (cerinta == 2)
    {
        f >> nr_cifre;
        cout << nr_cifre;
        vector<int> frecv(10, 0);
        for (i = 0; i < nr_cifre; i++)
        {
            f >> cifra;
            // nr.push_back(cifra);
            frecv[cifra]++;
        }
        int ib = -1, im = -1, i, j, frmax = 0;
        for (i = 9; i >= 0; i--)
            if (frecv[i] == 1)
               { if (im == -1)
                    im = i;
               }
                else if (frecv[i] % 2 == 1)
                {
                    if (ib == -1)
                        ib = i;
                    else if (im == -1)
                        im = i;
                }
        cout << endl
             << "im si ib " << im << ' ' << ib << endl;
        for (i = 9; i >= 0; i--)
        {
            for (j = 1; j <= frecv[i] / 2; j++)
            {
                g << i;
                cout << i;
            }
            if (i == ib) // egal cu balbaiala
            {
                g << i;
                cout << i;
            }
        }
        if (im != -1)
        {
            cout << im;
            g << im;
        }

        for (i = 0; i <= 9; i++)
            for (j = 1; j <= frecv[i] / 2; j++)
            {
                g << i;
                cout << i;
            }
    }

    return 0;
}
// 2 0 3 1 3 1 5 0 3 0
// 0 1 2 3 4 5 6 7 8 9
//     - - - - -   -
// 8 8 6 6 4 2 0 6 0 2 4 6 6 8 8 (final se balbaie)

// 2 0 3 1 3 1 0 0 3 0
// 0 1 2 3 4 5 6 7 8 9
//     - - -     -
// 8 8 4 2 0 5 0 2 4 8 8 (final se balbaie)
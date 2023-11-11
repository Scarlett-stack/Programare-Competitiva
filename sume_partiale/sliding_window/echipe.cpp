#include <iostream>
using namespace std;
// O(t * min(a,b))
bool formeaza_echipa(long long int a, long long int b)
{
    if (a >= 1 && b >= 3)
        return true;
    if (a >= 3 && b >= 1)
        return true;
    if (a >= 2 && b >= 2)
        return true;
    return false;
}
int max_echipe(long long int a, long long int b)
{
    int nr = 0;
    while (formeaza_echipa(a, b))
    {
        while (a > b) // while a > b
        {  // calc a/3
        //a = 40 , b = 20, c1 = 13 c2 = 1
        //40 - 13*3 = 1  b = 7 
        //nr  = 13
        //nu ar merge in toate cazurile 
            a -= 3;
            b -= 1;
            nr++;
        }

        while (b > a)
        {
            b -= 3;
            a -= 1;
            nr++;
        }
        if (a == b)
        {
            a -= 2;
            b -= 2;
            nr++;
        }
    }
    return nr;
}
int main()
{
    int t, nr = 0;
    cin >> t;
    long long int a, b;

    while (t)
    {
        cin >> a >> b;
        nr = nr + max_echipe(a, b);
        cout << nr << endl;
        nr = 0;
        t--;
    }
    return 0;
}
/*
int main()
{
    int t;
    long long a, b, k, d, mini;
    cin >> t; //t e mare
    for (int i = 1; i <= t; i++)
    {
        cin >> a >> b; // 5 5
        cout<<"Ami citit a si b"<<endl;
        k = 0;
        if (a == b && a + b >= 4)
        {
            k = k + a / 2;
            a = a % 2;
            b = b % 2;
        }
        while (a + b >= 4 && a > 0 && b > 0)
        {
            if (a > b)
            {
                a = a - 3;
                b--;
                k++;
            }
            if (b > a)
            {
                b = b - 3;
                a--;
                k++;
            }
            if (a == 2 && b == 2)
            {
                a = 0;
                b = 0;
                k++;
            }
        }
        cout << k << endl;
    }
    return 0;
} //bucla
*/
/*
#include <iostream>
using namespace std;
int main()
{
    int t;
    long long a, b, k, d, mini;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> a >> b;
        k = 0;
        while (a > 0 && b > 0 && (a + b >= 4))
        {
            // fout<<a<<' '<<b<<endl; // 14 5
            while (b < a && a > 0 && b > 0 && (a + b >= 4))
            {
                // cout<<"a\n";
                mini = min(a / 3, b); // 4 5
                a = a - mini * 3;     // 14-12=2
                b = b - mini;         // 5-4=1
                k += mini;            // 4
            }
            while (a < b && a > 0 && b > 0 && (a + b >= 4))
            {
                // cout<<"b\n";
                mini = min(a, b / 3);
                b = b - mini * 3;
                a = a - mini;
                k += mini;
            }
            if (a == b && (a + b >= 4)) // 11 11 9 9 7 7 5 5 3 3 1 1
            {
                while (a > 1)
                {
                    // cout<<"c\n";
                    k = k + a / 2; // 10
                    a = a % 2;     // 0 sau 1
                    b = b % 2;     // 0
                }
            }
        }
        if (a < 0 || b < 0)
            k--;
        cout << k << endl;
        // fout<<k<<"\n---------------\n";
    }
    return 0;
}
*/
#include <vector>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;
ifstream f("cat2pal.in");
ofstream g("cat2pal.out");
int nr_cifre(int n)
{
    // return nr;
    // g << nr;
    // lg
    int res = log10((n));
    // g << res;
    return res + 1;
}
void sort(int v[], int dim)
{
    for (int i = 1; i<dim; i++)
        for(int j = i+1; j<=dim; j++)
            if (v[i] > v[j])
                swap(v[i], v[j]);
}
void afis(int v[], int dim)
{   cout<<"Afis v: "<<endl;
    for (int i=1; i<=dim; i++)
        cout<<v[i]<<' ';
    cout<<endl<<"stop afis"<<endl;
}
bool pal(unsigned long long int n)
{
    unsigned long long int inv = 0;
    unsigned long long int c = n;
    while (n)
    {
        inv = inv * 10 + n % 10;
        n /= 10;
    }
    if (inv == c)
        return true;
    return false;
}
int main()
{
    // vector<int> vect(10000, 0);
    int cerinta;
    f>>cerinta;
    if (cerinta == 1){

    
    int v[30];
    unsigned long long int nr, c, p, inv = 0, n1, n2;
    int cnt = 0;
    f >> nr;
    c = nr;
    p = 1;

    while (nr)
    {
        inv = inv * 10 + nr % 10;
        nr /= 10;
        p *= 10;
    }
    int y = inv;
    int a, b, k = 0, d1, d2;
    p = pow(10, nr_cifre(y));
   // cout << "p : " << ' ' << p << ' ' << nr_cifre(y) << endl;
    for (int i = 0; i <= 9; i++)
    {
        a = i * p + inv;
        b = inv * 10 + i;

        if (a <= 10 * c)
        {
            v[++k] = a;
            cout << v[k] << " a--- " << endl;
        }
        if (b <= 10 * c && b != a)
        {
            v[++k] = b;
            cout << v[k] << " b --- " << endl;
        }
    }
    int t = 10;
    while (inv / t > 0)
    {
        v[++k] = inv%t;
        v[++k] = inv /t;
        t*=10;
    }
    sort(v,k);
   // afis(v,k);
    // inv  221
    //v : 22, 1, 2, 21, 221, 2210
    for (int i = 1; i <= k; i++)
    {
        d1 = v[i] * p + c;
        int pv = pow(10, nr_cifre(v[i]));
        d2 = c * pv + v[i];
        //cout << "d1 si d2 : " << d1 << ' ' << d2 << endl;
        if (pal(d1) || pal(d2))
            cnt++;
    }
    //100 
    // 1001 
       g << cnt;
    }
    if (cerinta == 2) {
        int nr;
        int v[10000];
        int v2[10000];
        f >> nr;
        int k =0;
        int val, cnt = 1;
        for (int i=1; i<=nr; i++)
            f>>v[i];
        for (int i=1; i<=nr; i++)
            for (int j=i; j<=nr; j++)
                {val = v[i] * pow(10,nr_cifre(v[j])) + v[j];
                
                if (pal(val))
                    {//cnt++;
                    v2[++k] = val;
                    cout<<"val: "<<val<<endl;
                    }
                }
        sort(v2,k);
        for (int i = 2; i<=k; i++)
        {
            if (v[i-1] != v[i])
            cnt++;
        }
        g<<cnt;
    

    }
    // p /= 10;
    /*n1 = c * p + inv;
    n2 = inv * p + c;
    //cout<<"n1 si n2 : "<<n1<<' '<<n2<<endl;
    if (pal(n1))
        cnt++;
    if (pal(n2))
        cnt++;
    int i = 0;
    while (i <= 9)
    {
        n1 = (c * 10 + i) * p + inv;
        n2 = (inv * 10 + i) * p + c;
        // cout<<"n1 si n2 din while : "<<n1<<' '<<n2<<endl;
        if(i * 10 * p + inv < c* 10)
            if (pal(n1))
                cnt++;
        if (inv * 10 + i< c*10)
            if (pal(n2))
                cnt++;
        i++;
    }
    g<<cnt<<endl;

    /* int x = nr*10; //val maxima pe care o pot lipi la nr
     //int a[20] = {0};
     int s[20], p[20]; //sufix prefix
     int ks = 1, kp = 19;
     while (nr > 0)
     {
         s[ks++] = nr%10;
         p[kp--] = nr %10;
         nr/=10;
     }
     ks--;
     kp++;
     */
    /*
    253 -> 1 - 2530
    s: 3,5,2 ; 2 5 3 in loc de ; pot sa un 0,1
    p:                  2, 5, 3
    */
    return 0;
}
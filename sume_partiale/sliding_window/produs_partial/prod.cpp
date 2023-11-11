#include <iostream>
using namespace std;
int s[1000], p[1000], a[999];
int main()
{   
    int i,j,n;
    cin>>n;
    p[0]=1;
    for (i=1; i<=n; i++)
        cin>>a[i];
    for (i=1; i<=n; i++)
        s[i] = s[i-1] + a[i];
    cout<<"sume partiale"<<endl;
    for (i=1; i<=n; i++)
        cout<<s[i]<<' ';
    cout<<endl;
    for (i=1; i<=n; i++)
        p[i] = p[i-1]*a[i];
     cout<<"prduse "<<endl;
    for (i=1; i<=n; i++)
        cout<<p[i]<<' ';
    cout<<endl;
    /*intre i si j suma este:
        s[j] - s[i-1]
     si produsul :
        p[j]/p[i-1]
        iau for in for
        pt al doilea for s = s+ p[j] + suma
*/  
int sum, sumamax =  0;
for (i=1; i<=n-1; i++)
    {for (j=i+1; j<=n; j++)
        {sum = s[i-1] + p[j]/p[i-1] + s[n] - s[j];  
         cout<<p[j]/p[i-1]<<' ';
        }
        cout<<endl;
    if (sum >sumamax)
    {
        sumamax = sum;
    }
   //cout<<sum<<endl;
    }
    if (sumamax < s[n])
        cout<<s[n];
    else
     cout<<sumamax;


    
    return 0;
}
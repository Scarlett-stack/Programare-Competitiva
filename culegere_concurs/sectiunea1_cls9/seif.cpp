#include <iostream>
using namespace std;
int main()
{   int n;
    cin>>n;

    int lacate = n*(n-1)/2;
    int chei = n*(n-1);
    cout<<"lacate: "<<lacate<<' '<<"chei "<<chei<<endl;
    //distributia:
    int nr = 1;
    for (int i=1 ; i<=n-1; i++)
        for(int j=i+1; j<=n; j++)
        {
            cout<<"lacat nr "<<nr<<"cu cheia la persoanele"<<i<<' '<<j<<endl;
            nr++;
        }
    return 0;
}
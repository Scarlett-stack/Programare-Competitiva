#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
/*vector<int> sort_cyclic_shifts(string const &s)
{
    int n = s.size();
    const int alphabet = 256;
    vector <int> p(n), c(n), cnt(max(alphabet,n),0);
    for (int i = 0; i<n; i++)
        cnt[s[i]]++; //nr carcaterele 
    for (int i = 1; i<alphabet; i++)


}*/
int main()
{
    char s[100];
    int i, j, ci,cj,n,cnt = 0;
    cin>>n;
    cin.get();
    cin.getline(s,100);
    cout<<"subsiruri"<<endl;
    char aux[100][100];
    int k = 0,z=0;
    for (i = 0; i<n; i++)
    {
        j =  n-1;
        ci = i;
        while (j>=i)
        {   cj = j;
            j--;
            //cnt++;
           k = 0;
            for (int o = ci; o<=cj; o++)
            {cout<<s[o];
             aux[z][k++] = s[o];
            }
            aux[z][k] = '\0';
            z++;
            cout<<endl;
            
        }
    }
    //char aux1[100];
    for (i = 0; i<z-1; i++)
        for (j =i +1; j<z; j++)
            if (strcmp(aux[i],aux[j]) == 0)
            {
                aux[i][0] = '\0';
            }
    cout<<"dupa ce am pus in matrice"<<endl;
    for (i = 0; i<z; i++)
        if (aux[i][0] != '\0')
        {cout<<aux[i]<<endl;
        cnt++;
        }
    cout<<"contorul e "<<cnt<<endl;
    return 0;
}
//nu e un approach bun pt ca daca am litere alaturate identice am o problema! ii nu e diferit ca substring de i pt ca 
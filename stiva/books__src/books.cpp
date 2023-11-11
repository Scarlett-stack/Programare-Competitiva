#include <iostream>
#include <vector>
using namespace std;

struct nod
{
    int nr;
    nod *next;
};
void push(nod *&start, int nr);
void pop(nod *&start);
void TyperR(nod *start);
int caut(nod *start, int nr,  std::vector<int>& f);
void eliberez(nod *start);
int main()
{
    int n, b;
    cin >> n;
    int i, cnt, ok;
    nod *start = NULL;
    nod *start2 = NULL; //am luat inca o lista pt cartile ce le scot
    for (i = 0; i < n; i++)
    {
        cin >> b;
        push(start, b);
    }
    //TyperR(start);
    for (i = 0; i < n; i++)
    {
        cin>>b;
        push(start2,b);
    }
  //  TyperR(start2);
    int c;
    vector<int>f(200000,0);
    //cout<<"CINE E START "<<start->nr<<endl;
    while (start2 != NULL)
    {   if (f[start2->nr-1] == 1)
        {cout<<0<<' ';
         //cout<<endl<<"ce vix "<<start2->nr<<' '<<f[start2->nr-1]<<endl;
        }
        else
        {
            cnt = caut(start,start2->nr,f);
        cout<<cnt<<' ';
        }
         //cout<<"CINE E START "<<start->nr<<endl;
        if (cnt)
        {
             c = cnt;
            // c--;
            while (c>0 && start != NULL)
            {  f[start->nr-1] = 1;
                //start = start->next;
               pop(start); 
               c--;
             
            }
             
        }    
        start2 = start2->next;

    }
     eliberez(start);
    eliberez(start2);
    return 0;
}
void push(nod *&start, int nr)
{
    nod *c = new nod;
    c->next = NULL;
    c->nr = nr;
    if (start == NULL)
    {
        start = c;
        return;
    }
    nod *d = start;
    while (d->next != NULL)
        d = d->next;
   d->next = c;
}
void TyperR(nod *start)
{
    if (start != NULL)
    {
        cout << start->nr << ' ';
        TyperR(start->next);
    }
}
void pop(nod *&start)
{
    nod *d;
  // cout<<"din pop"<<' '<<start->nr<<endl;
    d = start;
    start = start->next;
    if (start)
    
    delete d;
    //delete d; --->seg fault uitate atent unde ii atribui zona de memorie lui d
    //tu incerci sa dai free la ceva ce nu are malloc ->munmap_chunk() invalid pointer
   
}
int caut(nod *start, int nr, std::vector<int>& f)
{
    int ok = 0;
    int cnt =0;
    nod *d = start;
    while (d != NULL && ok == 0)
    {
        if (d->nr == nr)
            ok =1;
        cnt++;
       // f[d->nr - 1] = 1;
        d = d->next;
        

    }
   // cout<<ok<<" din functie"<<endl;
    if (ok)
     return cnt;
    return 0; 
}
void eliberez(nod *start)
{
   while (start != NULL)
    {
        nod *d = start;
        start = start->next;
        delete d;
    }
}
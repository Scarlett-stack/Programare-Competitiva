#include <iostream>
using namespace std;
struct nod
{
    float cof;
    int grd;
    nod *next;
};
void adaug(struct nod *&v, struct nod *&f, int gr, float cf);
void Typer(nod *v);
int main()
{   
    float cf;
    int i,n, gr;
    nod *v =  NULL;
    nod *sf = new nod;
    cin>>n;
    for (i=0; i<n; i++)
    {
        cin>>cf>>gr;
        adaug(v, sf, gr, cf);
    }
    Typer(v);
    return 0;
}
void adaug(struct nod *&v, struct nod *&sf, int gr, float cf)
{
    nod *c = new nod;
    c->cof = cf;
    c->grd = gr;
    c->next = NULL;
    if (v == NULL)
    {
        sf = c;
        v = c;
    }
    else
    {
        sf->next = c;
        sf = c;
    }
}
void Typer(nod *v)
{
    while (v != NULL)
    {
      cout<<v->cof<<'*'<<'x'<<'^'<<v->grd<<endl;
      v = v->next;
    }
    
}
#include <iostream>
using namespace std;

struct nod
{
    unsigned int size;
    unsigned int ordin;
    nod *next;
};
void adaug_lista(nod *&start, unsigned int nr, unsigned int ord);
void TyperR(nod *start);
void free(nod *start);
void stiva(nod *&start, unsigned int size, unsigned int ord);
void pop(nod *&start);
int number(nod *start);
int main()
{
    unsigned int nr, size;
    nod *start = NULL;
    cin >> nr; // cate sunt
    unsigned int i;
    for (i = 0; i < nr; ++i)
    {
        cin >> size;
        stiva(start, size, i + 1);
    }
    int n = number(start);
    cout << n << endl;
    TyperR(start);

    free(start);
    return 0;
}
void adaug_lista(nod *&start, unsigned int nr, unsigned int ord)
{
    nod *c = new nod;

    c->size = nr;
    c->ordin = ord;
    //cout << "am intrat cu nr " << nr << endl;
    if (start == NULL)
    {
        c->next = NULL;
        start = c;
    }
    else
    {
        c->next = start;
        start = c;
    }
  //  cout << "din adaug" << start->size << endl;
}
void TyperR(nod *start)
{
    if (start != NULL)
    {
        TyperR(start->next);
        cout << start->ordin << ' ';
    }
}
void free(nod *start)
{

    while (start != NULL)
    {
        nod *d = start;
        start = start->next;
        delete d;
    }
}
void pop(nod *&start)
{
    nod *d = start;
    if (start->next == NULL)
    {
        d = start;
        delete d;
        start = NULL;
    }
    else
    {
        start = start->next;
        delete d;
        cout << start << endl;
    }
}
void stiva(nod *&start, unsigned int size, unsigned int ord)
{
    if (start == NULL)
    {
        adaug_lista(start, size, ord); // 77
        //cout << "din null" << size << endl;
    }
    else
    {  
        while (size > start->size)
        {
            if (start != NULL)
            {
                //pop(start); // pop 2 5 7
                nod *x = start;
                //cout << "ce scot" << start->size << endl;
                start = start->next;
               // cout << "ce scot" << start->size << endl; aici da seg fault pt ca start poate sa fie NULL 
                delete x;
                     
            }        
            if (start == NULL)
            {   // cout<<"e NULLLL"<<endl;
                 goto here;
            }
            
        }
here:
       // cout<<"aicii"<<endl;
        adaug_lista(start, size, ord);
        //cout << "ce adaug " << size << endl;
    }
        
        // 5 2 se duce aici cu start null pt 8
    
    }

int number(nod *start)
{
    int cnt = 0;
    while (start != NULL)
    {
        start = start->next;
        cnt++;
    }
    return cnt;
}

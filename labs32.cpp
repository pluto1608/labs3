#include <iostream>
using namespace std;

struct jazol4e{
    int podato4e;
    jazol4e *sled;
    jazol4e *pret;
};

struct listi4ka{
  jazol4e *shef;
  jazol4e *gz;
  void init(){shef=gz=nullptr;}
  void pishiPo(jazol4e *p,int n){
      jazol4e *nov=new jazol4e;
      nov->podato4e=n;
      nov->pret=p;
      nov->sled=p->sled;
      if(p->sled==nullptr)gz=nov;
      else p->sled->pret=nov;
      p->sled=nov;
  }
  void pishiPre(jazol4e *p,int n){
    jazol4e *nov=new jazol4e;
    nov->podato4e=n;
    nov->sled=p;
    nov->pret=p->pret;
    if(p->pret==nullptr)shef=nov;
    else p->pret->sled=nov;
    p->pret=nov;
  }
  void pishiPrv(int n){
    jazol4e *nov=new jazol4e;
    nov->podato4e=n;
    nov->pret=nullptr;
    nov->sled=shef;
    if(shef==nullptr)gz=nov;
    else shef->pret=nov;
    shef=nov;
  }
  void pishiPosl(int n){
    jazol4e *nov=new jazol4e;
    nov->podato4e=n;
    nov->sled=nullptr;
    nov->pret=gz;
    if(gz==nullptr)gz=nov;
    else gz->sled=nov;
    gz=nov;
  }
  void brishiPosl(){
    if(shef!=nullptr){
      if(shef->sled==nullptr){
        delete shef;
        shef=gz=nullptr;
      }else{
        jazol4e *p=gz;
        gz=gz->pret;
        gz->sled=nullptr;
        delete p;
      }
    }
  }
  void brishi(){
    while(shef!=nullptr)brishiPosl();
  }
  void pechatiLista(){
    cout<<"NA BE NA eee koa si zapnal ";
    for(jazol4e *p=shef;p!=nullptr;p=p->sled)cout<<p->podato4e<<"\t";
    cout<<endl;
  }
  int len()
  {
    int n=0;
    jazol4e *p=shef;
    while(p!=nullptr)
    {
      p=p->sled;
      n++;
    }
    return n;
  }
  void pechatiJazol(jazol4e *p){
    cout<<"a sea i pribirash koj jazol da se pechati? MRSH kopile ";
    cout<<p->podato4e<<endl;
  }

};

void sort(listi4ka &l) {
  if (l.shef == nullptr || l.shef->sled == nullptr) return; // empty or single-node list

  bool swapped;
  do {
    swapped = false;
    jazol4e *current = l.shef;

    while (current->sled != nullptr) {
      if (current->podato4e > current->sled->podato4e) {
        // Swap the nodes
        jazol4e *next = current->sled;

        // Update surrounding nodes' pointers
        if (current->pret != nullptr)
          current->pret->sled = next;
        else
          l.shef = next; // current was head

        if (next->sled != nullptr)
          next->sled->pret = current;
        else
          l.gz = current; // next was tail

        // Swap the nodes
        current->sled = next->sled;
        next->pret = current->pret;
        current->pret = next;
        next->sled = current;

        swapped = true;
      } else {
        current = current->sled;
      }
    }
  } while (swapped);
}

int main(){
  listi4ka l;
  int n,m,p;
  bool eb=true;
  l.init();
  cin>>n>>m;
  l.pishiPrv(n);
  p=m-1;
  while (true)
  {
    if (m>n && m>p)
    {
      p=m;
      l.pishiPosl(m);
      cin>>m;
    }else break;
  }
  if (p!=m)p=m+2;
  while (true)
  {
    if (m<p)
    {
      p=m;
      l.pishiPosl(m);
      cin>>m;
    }else break;
  }
  l.pechatiLista();
  sort(l);
  l.pechatiLista();
}
#include <iostream>
using namespace std;
//niza ama nema indeksi tuku sekoj clen pokazuva nakaj sledniot a posledniot nakaj nullptr ili NULL isto e iskreno nema
//nekoja razlika bitno krajot da pokazuva kon neso konkretno i zaso se pointeri ne se zadava vrednost zaso ne znaes na
//sho e adresata
struct jazol{//jazol zamislete go kako celina so 2 karakteristiki mi pomogna mene da sfatam :)
  int pod; //podatokot zacuvan vo jazolot
  jazol *sled;//pokazuvac kon sledniot jazol
};

struct lista{
    jazol *shef;//pokazuvac kon prviot jazol (@dora shef ne znaci nisto samo ime na promenliva e)
    //disclaimer: ne koristam pola i poise od funkciive ne mora site na labs samo tie so se koristat t.e.
    //init, pechati, kreirajLista, turiOdPozadi
    void init(){shef=nullptr;}//nullptr znaci nisto u sustina isto kako za int koa stavame 0
    void kreirajLista(int a){
      shef=new jazol;//so new se obezbeduva mesto za odreden tip pormenliva vo ovoj slucaj jazol
      shef->pod=a;//se dodava podatok, shef->pod e isto kako (*shef).pod samo razlicna sintaksa zasho e poazuvac
      //i tie mora da bitat posebni i unikatni
      shef->sled=nullptr;//za da mozeme da najdeme kade zavrsuva listata stavame posledniot jazol t.e. sled na istiot
    }//da e nullptr da ima vrednost nullptr ne mozeme da stavme konkretna vrednost z.s. e pokazuvac ako stavime
    //odredena adresa moze da se sjebe mnogu
    void turiOdNapred(int n){
      jazol *p=new jazol;//pomosna promenliva
      p->pod=n;//se dodeluva vrednost na jazolot
      p->sled=shef;//zatoa sto dodavame od napred pravime noviot prv cled da pokazuva kon stariot prv clen
      shef=p;//vrednosta na noviot prv clen se dodeluva na shef
    }
    void turiOdPozadi(int n){
        jazol *d=shef,*p=new jazol;//pomosni promenliva
        p->pod=n;//go stavame n vo p
        if(shef==nullptr)shef=p;//dokolku listata e prazna se dodeluva vrednosta na shef
        else{
          while(d->sled!=nullptr)d=d->sled;//se proveruva za sekoj jazol dali sled e nullptr dokolku ne se pomestuva d da
          //pokazuva na sledniot clen
          d->sled=p;//koga d e posledniot clen namesto sled na toj clen da e nullptr sled pokazuva kon p
        }
        p->sled=nullptr; //sled na p se stava da e nullptr z.s. toj e sega posledniot clen
    }
    void pechati(){
      cout<<"Listata ili nesho: ";
      for(jazol *p=shef; p!=nullptr; p=p->sled)cout<<p->pod<<"\t";//p pocnuva od shef i se pomestuva za eden se dur
      //ne stigne do posledniot jazol VO PREZ IMA GRESKA uslovot e p->sled!=nullptr taka nema da se ispecati posledniot
      //clen
    }
    void brishiOdPozadi(){
      if(shef!=nullptr){//za ako e prazna nizata
        if(shef->sled==nullptr){//ovoj uslov e za ako ima samo eden clen vo listata
          delete shef;//delete ja prazni promenlivata shef
          shef=nullptr;//stavame da e nullptr z.s. ako ne stavime ke se stavi random adresa
        }
        else{
          jazol *p=shef,*b;
          while(p->sled->sled!=nullptr)p=p->sled;//se proveruva dali jazolot posle sledniot na p pokazuva kon nullptr
          //dokolku ne p se pomestuva za eden jazol na kraj p e pretposledniot jazol
          b=p->sled;//b se stava da e posledniot jazol
          p->sled=nullptr;//noviot posleden jazol se stava da pokazuva kon nullptr
          delete b;//b se prazni, ne se stava na nullptr pak zaso e nebitna promenliva
        }
      }
    }
    void brishi(){
      while(shef!=nullptr)brishiOdPozadi();//se dodeka shef ne se izbrishe se brishe od pozadi
    }
    void brishiPrv(){
      if(shef!=nullptr){
        if(shef->sled==nullptr){//za koga ima samo eden clen
          delete shef;
          shef=nullptr;
        }else{
          jazol *p=shef;
          shef=shef->sled;//shef se pomestuva na vtoriot clen
          delete p;
        }
      }
    }
    int len(){
      int n=0;
      jazol *p=shef;
      while(p!=nullptr){//vrti niz celata lista i se zgolemua n za 1 se dur ne se stigne do posledniot clen
        p=p->sled;
        n++;
      }
      return n;
    }
    void pishiKonk(jazol *j,int n){//vnesuva jazol posle konkreten jazol
      jazol *p=new jazol;//jazolot shto ke se vnese posle jazol j
      p->pod=n;
      p->sled=j->sled;//se stava sled na p da e jazolot posle j
      j->sled=p;//sled na j da e p
    }
    void brishiKonk(jazol *j){
      if(j->sled==nullptr)return;//ako j e posledniot jazol funkcijata prekinuva return tuka ne vraka nisto ima ista
      //funkcija kako break vo loop
      jazol *p=j->sled;//p pojazuva kon sledniot jazol na j
      j->sled=p->sled;//j da pokazuva kon jazolot posle sledniot
      delete p;
    }
    void spoiRek(jazol *a,jazol *b){//spojuvanje so rekurzija(rekurzija e sranje metod moze i bez ama taka e u prez)
      if((a!=nullptr)&&(b!=nullptr)){//se proveruva dali nizite se prazni
        if(a->sled==nullptr)a->sled=b;//koga ke se stigne a da e posledniot clen na prvata niza
        else spoiRek(a->sled,b);//se povikuva funkcijata so toa sto se dava sledniot clen na a kako argument
      }
      else cout<<"edna od listite e L lista icel gng(prazna)"<<endl;//@dora icel(i can't even lie) gng(gang)
    }
};

void smeni(lista &a)//gospod(deepseek) me prosvetli za ova ako mi najdete maana da se ebete
{
  if (a.shef==nullptr)return;//za ako e prazna listata, ne se proveruva za 1 clen z.s. vo zadacata e potencirano da se
  //pretpostavi paren broj clenovi
  jazol *c=a.shef,*p=nullptr;//c e prviot jazol sto go menuvame t.e. na neparnata pozicija p e pomosna promenliva
  while (c!=nullptr)//koga ima paren broj clenovi e ovoj uslov samo za neparen bi bilo c->sled!=nullptr a ako ne znaeme
  {//dali ima paren ili neparen broj c!=nullptr && c->sled!=nullptr KONKRETNO VO TOJ REDOSLED zaso ako c==nullptr i
    //probate c->sled da napraite ke crashne
    jazol *n=c->sled;//vtor jazol t.e. na parnata pozicija
    jazol *np=n->sled;//jazolot posle tie sto gi menuvame
    n->sled=c;//parniot jazol da pokazuva kon neparniot
    c->sled=np;//neparniot da pokazuva kon jazolot posle tie sto gi menuvame
    if (a.shef==c)a.shef=n;//za prvoto izvrsuvanje da se smeni a.shef
    if (p!=nullptr)p->sled=n;//jazolot pred tie shto gi menuvame da se povrze so n so if za prviot pat koga se izvrsuva
    //i nema prethoden
    p=c;//p se zgolemuva
    c=np;//c se zgolemuva
  }
}

int main(){
  int n;
  lista a;
  a.init();
  cout<<"The word shower should be a slur.It's really offensive to people that don't shower. "
        "As an anti-showerer, I am very offended by that word. It's a fucking slur and people shouldn't be using it "
        "unless you are an anti-showerer"<<endl;//@dora ova nisto ne znaci :)
  cin>>n;
  if (!cin.fail())a.kreirajLista(n);//isk ne znam tocno so e cin.fail samo znam deka koa so posledniot cin e vnesen
  //int vraka false koa e char/string vraka true
  else cout<<"daj broevi ne dupi"<<endl;
  cin>>n;
  while (!cin.fail())//se dur se vnesuva broj
  {
    a.turiOdPozadi(n);//se stava vo listata
    cin>>n;//se vnesuva nov
    if (cin.fail())cout<<"toa ne e broj >:("<<endl;
  }
  //moze tuka da se stai proverka na brojot na clenovi so a.len() ama me mrzi i u zadacata vika da se pretpostavi paren
  //broj clenovi taka da ja opravduvam mojata mrza
  smeni(a);
  a.pechati();
}









































































































//ma4ko ja bi te pro4a4ko
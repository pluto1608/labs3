#include <iostream>
using namespace std;

struct jazol4e{
    int podato4e;
    jazol4e *sled;
    jazol4e *pret;
};

struct listi4ka{
  jazol4e *shef;
  jazol4e *gz;//pokazuvac kon posledniot jazol
  void init(){shef=gz=nullptr;}//isto kako edinecno povrzana samo sega ima i pointer za posledniot clen
  void pishiPo(jazol4e *p,int n){//dodava jazol posle konkreten jazol
      jazol4e *nov=new jazol4e;
      nov->podato4e=n;
      nov->pret=p;
      nov->sled=p->sled;//se povrzuva pointerot sled na noviot jazol so jazolot koj e posle jazolot koj veke postoi
      if(p->sled==nullptr)gz=nov;//dokolku postoeckiot jazol bil posleden gz da pokazuva kon nego
      else p->sled->pret=nov;//pointerot pret na jazolot koj bil po p se stava da pokazuva kon noviot
      p->sled=nov;//p da pokazuva kon noviot jazol
  }
  void pishiPre(jazol4e *p,int n){//dodava jazol pred konkreten jazol(slicno so pishiPo me mrzi da objasnam)
    jazol4e *nov=new jazol4e;//pishete ako neso konkretno ne e jasno :)
    nov->podato4e=n;
    nov->sled=p;
    nov->pret=p->pret;
    if(p->pret==nullptr)shef=nov;
    else p->pret->sled=nov;
    p->pret=nov;
  }
  void pishiPrv(int n){//dodava prv jazol slicno so drugite pishi
    jazol4e *nov=new jazol4e;
    nov->podato4e=n;
    nov->pret=nullptr;//zaso e prv jazol pret pointerot pokazuva kon nullptr
    nov->sled=shef;//nov sled NE POKAZUVA KON SHEF shef e pokazuvac kon prviot jazol nov->sled sega pokazuva
    //kon jazolot shto prethodno bil prv
    if(shef==nullptr)gz=nov;
    else shef->pret=nov;
    shef=nov;
  }
  void pishiPosl(int n){//slicno so pishi prv
    jazol4e *nov=new jazol4e;
    nov->podato4e=n;
    nov->sled=nullptr;
    nov->pret=gz;
    if(gz==nullptr)gz=nov;
    else gz->sled=nov;
    gz=nov;
  }
  void brishiPosl(){//skoro isto so kaj edinecno povrzana
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
  if (l.shef == nullptr || l.shef->sled == nullptr) return;//za ako nema ili ima samo eden clen

  bool swapped;
  do {//bubble sort ama pokomplicirano zasho e povrzana lista
    swapped = false;
    jazol4e *current = l.shef;

    while (current->sled != nullptr) {//vrti niz celata lista
      if (current->podato4e > current->sled->podato4e) {//ako podatokot na tekovniot jazol e pogolen od podatokot na sledniot
        jazol4e *next = current->sled;
        if (current->pret != nullptr)
          current->pret->sled = next;//pokazuvacot sled na jazolot pred tekovniot da pokazuva kon sledniot jazol
        else
          l.shef = next;//ako nema jazol pred tekovniot shef se menuva

        if (next->sled != nullptr)
          next->sled->pret = current;//pokazuvacot pret na jazolot posle sledniiot da pokazuva kon tekovniot
        else
          l.gz = current;//ako nema jazol posle sledniot gz se menuva
        current->sled = next->sled;//sled da pokazuva kon jazolot posle sledniot
        next->pret = current->pret;//pret na sledniot da pokazuva kon jazolot pred tekovniot
        current->pret = next;//tekovniot da pokazuva kon sledniot
        next->sled = current;//sledniot da pokazuva kon tekovniot
        swapped = true;//koga nizata e sortirana nema da bide ispolnet ovoj if uslov i swapped ke ostane false  
      } else {
        current = current->sled;//ako ne se menuvaat se odi na sledniot jazol koga e ispolnet uslovot 
        //nema potreba da od current = current->sled zatoa shto togash current go pomestuvame za edno mesto na desno
      }
    }
  } while (swapped);
}

int main(){
  listi4ka l;
  int n,m,p;
  bool eb;
  l.init();
  cout<<"A list of the Italian brainrot characters(tralalelo tralala supremacy):Tralalelo Tralala,
  Bombardino coccodrillo, Bombombini Gusini, Trippi Troppi, Burbaloni Luliloli,
  Tracotocutulo Lirilì Larilà, Brr brr Patapim, Trulimero Trulicina, Bobrini Cocosini,
  Frigo Camello, Frulli Frulla, La vaca saturno saturnita, Crocodildo Penisini,
  Bobritto bandito, Giraffa Celeste, Cappuccino Assassino, Glorbo Fruttodrillo, Camelrino Tazzino,
  Ambatron, Kaktus tus tus kutus kutus, Mic Sahur, Her Tehaer, Mie ayam, Mubajir nasinya,
  Beduk dug dug, Pat pat ketupat, Polisi sok asik, Ten ten tentara, Tuyuh tuyuh tuyuh,
  Kur kur Kukuruyuk, Hi hi hi hi hiu, Karpet masjid, Monyet pura pura puasa, Pengajak Mokel,
  Boneca Ambalabu, Tang tang tang bayar hutang kau, Bis Hitam, Tralaluli Patraluli, Hamster mata merah,
  Pencil Dud dud gendud, Kaktus Tidak Taraweh, Pulpen biru, Pohon pisang, Monyet azan, Cik cik cikal cik,
  Hor Hor Hor Horeg, Sahur Puasa tapi tidak sholat 5 waktu, Bombinarium, Nerpinarium,
  El Bobrito de Kurvito, El szczurito kurwito golfito"<<endl;//@dora ova nisto ne znaci
  cin>>n>>m;
  l.pishiPrv(n);
  if((m>n || m<n)&& !cin.fail())eb=true;//ako ova e ispolneto znaci deka se vneseni barem 2 validni clena
  while (true)
  {
    if ((m>n || m>p) && !cin.fail()) //tuka e cin.fail za da prekine vnesuvanjeto koga ke se vnese karakter
    {
      p=m;
      l.pishiPosl(m);
      cin>>m;
    }else if (m<p && !cin.fail())
    {
      p=m;
      l.pishiPosl(m);
      cin>>m;
    }else break;
  }
  
  if(eb)sort(l);
  l.pechatiLista();
}

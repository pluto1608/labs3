#include<stdio.h>
#include<string.h>
#include <ctype.h>
int main(int argc, char *argv[]){
if(argc<4){printf("Nepravilen povik na programata. Treba da se povika kako %s ime_dat_vlez ime_dat_izlez1 ime_dat_izlez2",argv[0]);return 0;}
FILE *fin = fopen(argv[1],"r");
if(fin==NULL){
printf("Neuspesno otvoranje na vleznata datoteka");return 0; 
}
FILE *f1 = fopen(argv[2],"w");
if(f1==NULL){
printf("Neuspesno otvoranje na prvata izlezna datoteka");return 0; 
}
FILE *f2 = fopen(argv[3],"w");
if(f2==NULL){
printf("Neuspesno otvoranje na vtorata izlezna datoteka");return 0; 
}
char zbor[21],c;int i=0,iw=0;
while((c=fgetc(fin))!=EOF){
if(isalpha(c)){
    if(iw==0)iw=1;
    zbor[i++]=c;
}else {
    if(iw){iw=0;
    zbor[i]=0;
    if(i%2==0){
    // paren broj na bukvi
    fprintf(f1,"%s ",zbor);
    }else {
    fprintf(f2,"%s ",zbor);  
    }
    i=0;
    }

}
}
if(iw){iw=0;
    zbor[i]=0;
    if(i%2==0){
    // paren broj na bukvi
    fprintf(f1,"%s ",zbor);
    }else {
    fprintf(f2,"%s ",zbor);  
    }
    }
fclose(fin);
fclose(f1);
fclose(f2);
 return 0;   
}
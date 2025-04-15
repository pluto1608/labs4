#include <iostream>
using namespace std;

const int dol=10;

struct queue{//standardno osven brishenje na konkreten clen
    int q[dol],f,r;
    void init(){f=r=-1;}
    void overflow(){
        cout<<"overflow"<<endl;
        exit(-1);
    }
    void underflow(){
        cout<<"undeflow"<<endl;
        exit(-1);
    }
    void dodadi(int n){
        if(r>=dol-1)overflow();
        if(f==-1)f=0;
        q[++r]=n;
    }
    int izvadi(){
        if(f==-1)underflow();
        int n=q[f];
        if(f==r)f=r=-1;
        else f++;
        return n;
    }
    void pechati(){
        for(int i=f;i<=r;i++)cout<<q[i]<<"\t";
        cout<<endl;
    }
    bool iEmp(){return f==-1;}
    bool iFul(){return r==dol-1;}
    int len(){return r-f+1;}
    void brishi(int n){
        int temp=f;
        while(temp!=r && q[temp]!=n)temp++;//temp da e indeksot na clenot shto treba da se izbrishe
        for(int i=temp;i!=r;i++)q[i]=q[i+1];//pocnuvanjki od clenot so indeks temp sekoj clen ja zema vrednosta na
        //sledniot
        r--;//r se namaluva za 1 z.s. izbrishavme clen
    }
    int dze(){
        if(f==-1)underflow();
        return q[f];
    }
};

void funk(queue &q){//2 isti suma, >2 i paren isfrla, >2 i neparen 1 element so taa vrednost
    queue q1;
    int n,br;
    q1.init();
    while(!q.iEmp()){
        br=0;//se resetira brojachot
        do{//do while zasho ako e clen shto nema ist do nego br da bide 1
            n=q.izvadi();//se vadi 1 clen
            br++;//se brojat kolku isti clenovi ima
        }while(!q.iEmp() && n==q.dze());//za da nema underflow,clenot shto go izvadivme go sporeduvame so 
        //sledniot
        if(br==2)q1.dodadi(n*2);//ako e par se dodava sumata
        else if(br%2!=0)q1.dodadi(n);//ako e neparen broj samo se dodava, vazi i za ako e 1 clen nemora posebeben
    }//uslov za toa
    q=q1;
}

int main(){
    queue q;
    int n;
    q.init();
    cout<<"Somebody leaked my sex tapes. Now I'm actually actively selling it on many vids."
    "What an easy money for so little effort. 💯 Me clappina fat piece of a$$. "
    "My face is seen from side ways in between the footage. During the climax shot camera snaps to right viewer's "
    "pov so it's like I'm giving viewer facial. Smart eh?"<<endl;
    for(int i=0;i<dol && cin>>n;i++)q.dodadi(n);

    funk(q);

    q.pechati();
}
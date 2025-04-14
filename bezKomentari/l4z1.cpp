#include <iostream>
using namespace std;

const int dol=10;

struct queue{
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
        while(temp!=r && q[temp]!=n)temp++;
        for(int i=temp;i!=r;i++)q[i]=q[i+1];
        r--;
    }
    int dze(){
        if(f==-1)underflow();
        return q[f];
    }
};

void funk(queue &q){
    queue q1;
    int n,br;
    q1.init();
    while(!q.iEmp()){
        br=0;
        do{
            n=q.izvadi();
            br++;
        }while(!q.iEmp() && n==q.dze());
        if(br==2)q1.dodadi(n*2);
        else if(br%2!=0)q1.dodadi(n);
    }
    q=q1;
}

int main(){
    queue q;
    int n;
    q.init();

    for(int i=0;i<dol && cin>>n;i++)q.dodadi(n);

    funk(q);
    q.pechati();
}
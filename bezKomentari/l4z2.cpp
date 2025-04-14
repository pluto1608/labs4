#include <iostream>
using namespace std;

struct jazol{
    jazol *sled;
    int pod;
};

struct lista{
    jazol *head,*tail;
    void init(){head=tail=nullptr;}
    void vnesiPozadi(int n){
        jazol *p=new jazol;
        p->pod=n;
        if(head==nullptr){
            head=tail=p;
            head->sled=tail;
            tail->sled=head;
        }else{
            tail->sled=p;
            tail=p;
            tail->sled=head;
        }
    }
    void brishiPozadi(){
        if(head!=nullptr){
            if(head==tail){
                delete head,tail;
                head=tail=nullptr;
            }else{
                jazol *b=tail->sled;
                while(b->sled->sled!=head)b=b->sled;
                delete b->sled;
                tail=b;
                tail->sled=head;
            }
        }
    }
    void vnesiNapred(int n){
        jazol *p=new jazol;
        p->pod=n;
        if(head==nullptr){
            head=tail=p;
            tail->sled=head;
            head->sled=tail;
        }else{
            p->sled=head;
            head=p;
            tail->sled=head;
        }
    }
    void brishiNapred(){
        if(head!=nullptr){
            if(head==tail){
                delete head,tail;
                head=tail=nullptr;
            }else{
                jazol *b=head;
                head=head->sled;
                delete b;
                tail->sled=head;
            }
        }
    }
    void brishi(){
        while(head!=nullptr)brishiPozadi();
    }
    void brishiKonk(jazol *b){
        if(head!=nullptr){
            if(head!=b){
                jazol *p=head;
                while(p->sled!=b && p->sled!=head)p=p->sled;
                p->sled=b->sled;
                if(b==tail)tail=p;
                delete b;
            }else brishiNapred();
        }
    }
    void pechati(){
        jazol *p=head;
        cout<<p->pod<<"\t";
        p=p->sled;
        while(p!=head){
            cout<<p->pod<<"\t";
            p=p->sled;
        }
        cout<<endl;
    }
    void funk(int k){
        jazol *p=tail;
        while(head!=tail){
            for(int i=0;i<k;i++)p=p->sled;
            cout<<p->pod<<" eliminiran"<<endl;
            brishiKonk(p);
        }
    }
};

int main(){
    lista l;
    int n;
    l.init();
    while(cin>>n)l.vnesiPozadi(n);
    l.funk(3);
    cout<<"pobednik: "<<endl;
    l.pechati();
}
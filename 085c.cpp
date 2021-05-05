//ABC085C-Otoshidama
#include <iostream>
using namespace std;
int main(){
    int y,n,k,a,b,c;
    cin >> n >> y;
    bool f = false;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n-i; j++){
             k = n-i-j;
             if(10000*i+5000*j+1000*k==y){
                 a=i;b=j;c=k;
                 f=true;
                 break;
             }
        }
    }
    if(!f){
        a=-1;
        b=-1; 
        c=-1;
    }
    cout << a << " " << b << " " << c << endl;
    
}
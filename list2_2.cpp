#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main(){
    int n,m,q;
    cin >> n >> m >> q;

    list<int> L;

    for(int i=0; i<n; i++){
        L.push_front(i);
    }
    for(int i=0; i<m; i++){
        int a;
        cin >> a;
        L.remove(a);
    }
    for(int i=0; i<q; i++){
        int q; 
        cin >> q;
        auto result = find(L.begin(), L.end(), q);
        if(result==L.end()){ 
            cout << 1 << endl; 
        } else{ 
            cout << 0 << endl; 
        }
    }
}
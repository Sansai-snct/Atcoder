#include <iostream>
#include <list>

using namespace std;

int main(){
    list<int> L;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        int a;
        cin >> s;
        if(s=="insert"){
            cin >> a;
            L.push_front(a);
        }else if(s=="delete"){
            cin >> a;
            L.remove(a);
        }else if(s=="deleteFirst"){
            L.pop_front();
        }else if(s=="deleteLast"){
            L.pop_back();
        }
    }
    for(auto itr = L.begin(); itr != L.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;

}
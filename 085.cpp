//ABC085B-Kagami Mochi
#include <iostream>
#include <set>
using namespace std;

int main(){
    int n;
    int count=0;
    cin >> n;
    int a[n];
    set<int> b;
    for(int i=0; i<n; i++){
        cin >> a[i];
        b.insert(a[i]);
    }
    for(auto x : b){
        if(b.count(x)==1){
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
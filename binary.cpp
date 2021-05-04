#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int cnt = 0;
bool serch(int s[], int n, int x){
    int b = 0;
    int e = n-1;
    while(b<=e){
        int mid=(b+e)/2;
        if(s[mid]==x){
            return 1;
        }else if(s[mid]<x){
            b=mid+1;
        }else if(s[mid]>x){
            e=mid-1;
        }

    }
    return 0;
  
}

int main(){
    int n,q;
    cin >> n;
    int s[n];
    for(int i=0; i<n; i++){
        cin >> s[i];
    }
    cin >> q;
    int key[q];
    for(int i=0; i<q; i++){
        cin >> key[i];
        if(serch(s,n,key[i]))
          cnt++;
    }
    cout << cnt << endl;
    
}

//使いたきゃデータをソートしないといけない
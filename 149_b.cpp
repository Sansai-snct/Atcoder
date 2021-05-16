#include <iostream>
using namespace std;
typedef long long int ll;
int main(){
  ll a,b,k;
  cin >> a >> b >> k;
  if(a>k){
      cout << a-k <<" "<< b << endl;
  }else if(a+b >= k){
      cout << 0 << " "<< b-(k-a) << endl;
  }else{
      cout << 0 << " " << 0 << endl;
  }

  return 0;
}
//ABC194 C問題

#include <iostream>
using namespace std;
typedef long long int ll;
int main(){
  int n;
  ll ans= 0;
  cin >> n;
  ll an;
  ll a2 = 0;
  int a = 0;
  cin >> a;
  a2 = a*a;
  for(int i=1;i<n;i++){
    cin >> an;
    ans = ans + i*an*an - 2*an*a+a2;
    a = a + an;
    a2 = a2 + an*an;
  }
  
  cout << ans << endl;
}
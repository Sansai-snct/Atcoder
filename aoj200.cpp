#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> vec;
typedef vector<vec> mat;
const int INF  = 9999;
int main(){
   int n;
   while(cin>>n){
      if(cin.eof()) break; 
      mat w(15,vec(15,INF));
      
      int m=0;
      for(int i=0; i<n; i++){
          int a,b,c;
          cin >> a >> b >> c;
          w[a][b] = c;
          w[b][a] = c;
          m = max(m,a);
          m = max(m,b);
      }
      m++;
      for(int i=0; i<m; i++){
          w[i][i] = 0;
      }
      for(int k=0; k<m; k++){
          for(int i=0; i<m; i++){
              for(int j=0; j<m; j++){
                   w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
              }
          }
      }
      int ans_m ,ans_w = INF;
      for(int i=0; i<m; i++){
          int sum=0;
          for(int j=0; j<m; j++){
              sum += w[i][j];
          }
          if(ans_w>sum){
              ans_w = sum;
              ans_m = i;
          }
      }
      cout << ans_m << ' ' << ans_w << endl;
    
   }
}
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 110;
const int INF = 100000;
int T[N][N];
int C[N][N];

int main(){
  int n,m;
  while(cin >> n >> m){
    if(n==0 && m==0)
		break;
    for(int i=0;i<N;++i){
      for(int j=0;j<N;++j){
        if(i==j){
			C[i][j] = T[i][j] = 0;
		}else{
			C[i][j] = T[i][j] = INF;
		}
      } 
    }
    for(int i=0;i<n;++i){
      int a,b,c,t;
      cin >> a >> b >> c >> t;
      C[a][b] = C[b][a] = c;
      T[a][b] = T[b][a] = t;
    }

    for(int k=0;k<N;++k){
      for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
           C[i][j] = min(C[i][j], C[i][k] + C[k][j]);
           T[i][j] = min(T[i][j], T[i][k] + T[k][j]);
        }
      }
    }
    int k;
    cin >> k;
    while(k--){
      int p,q,r;
      cin >> p >> q >> r;
      if(r)
        cout << T[p][q] << endl;
      else
        cout << C[p][q] << endl;
    }
  }
  return 0;
}
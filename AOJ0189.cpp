#include <iostream>
#include <algorithm>
const int N =  2000;
const int  INF = 999999;

using namespace std;

int COST[N + 1][N + 1];
int TIME[N + 1][N + 1];
int v[N + 1];
bool visit[N + 1];
int n,m,k,p,q,r,ti,co;
int from,too;
int MI,mi;

// ダイクストラ法
int get_time(void){ 

  for( int i = 0 ; i <= N ; i++ ){
    visit[i] = false;
    v[i] = INF;
  }
  v[p] = 0;
  
  while(1){
    mi = INF;
    for( int i = 1 ; i <= m ; i++ ){
      if( !visit[i] && v[i] < mi ){
	    MI = i;
	    mi = v[i];
      }
    }

    if( mi == INF ) break;
    visit[MI] = true; 

    for( int i = 1 ; i <= m ; i++ ){
      if( TIME[MI][i] + v[MI] < v[i] ){
	     v[i] = TIME[MI][i] + v[MI];
      }
    }
  }
  return v[q];
}

int get_cost(void){

  for( int i = 0 ; i <= N; i++ ){
    v[i] = INF;
    visit[i] = false;
  }

  v[p] = 0; 

  while(1){

    mi = INF;

    for( int i = 1 ; i <= m ; i++ ){
      if( !visit[i] && v[i] < mi ){
	    MI = i;
	    mi = v[i];
      }
    }

    if( mi == INF ) break;
    visit[MI] = true;

    for( int i = 1 ; i <= m ; i++ ){
      if( COST[MI][i] + v[MI] < v[i] ){
	     v[i] = COST[MI][i] + v[MI];
      }
    }
  }
  return v[q];
}



int main(void){

  while( cin >> n >> m , n || m ){

    for( int i = 0 ; i <= N; i++){
      for( int j = 0 ; j <= N; j++){ 
	    TIME[i][j] = INF;
	    COST[i][j] = INF;
      }
    }

    for( int i = 0 ; i < n ; i++ ){
      cin >> from >> too >> co >> ti;
      COST[from][too] = COST[too][from] = co;
      TIME[from][too] = TIME[too][from] = ti;
    }

    cin >> k;

    for( int i = 0 ; i < k ; i++ ){
      cin >> p >> q >> r;

      if(r==0)
	    cout << get_cost() << endl;
      else
	    cout << get_time() << endl;

    }

  }
  return 0;
}
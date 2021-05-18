#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef long double ld;
//intとstringのペアを定義
typedef pair<int,string> Pr;
#define rep(i,s,n) for(ll i=s;i<n;i++)
#define repd(i,s,n) for(ll i=n-1;i>=s;i--)
#define FOR(i,s,n) for(ll i=s;i<=n;i++)
#define all(x) x.begin(),x.end()
#define size(x) ll(x.size())
#define PB push_back


int main(){
  int dx[4] = {-1,1,-4,4}; //進む方向(文字列だから横だけ)

  map<string,int> ans;   //mapで連想配列を作る
  
  ans["01234567"] = 0; //01234567の場合は何も動かさないので0

  queue <Pr> que;

  que.push(Pr(0,"01234567")); //キューにパズルの状態と移動回数をぶちこむ

  while(!que.empty()){ //キューの中身が空になるまで

    Pr p = que.front();  //キューの先頭を取り出す
    que.pop();

    int k = ans[p.second];
    rep(i,0,4){

      int n = p.first + dx[i]; //次の探索場所

      if(i==0 && n==3){
        continue;  //探索済みはスルー
      }else if(i==1 && n==4){
        continue;
      }else if(n >= 0 && n < 8){
        string tmp;
  
        tmp = p.second;
        
        tmp[p.first] = tmp[n]; 
       
        tmp[n] = '0'; //同じところを辿らないように

        if(ans.find(tmp) == ans.end()){
	        ans[tmp] = k + 1;
         
	        que.push(Pr(n,tmp)); //次の状態をキューに格納
        }
	    }
    }
  }

  string s;
  char t;
  while(1){
    cin >> t;
    if(cin.eof()) break;

    s+=t;
    rep(i,0,7){
        cin >> t;
        //文字列に文字を追加していく
        s += t;
    }
    //文字列に対応した回数を出力する。
    cout << ans[s] << endl;
    //次の処理のため初期化
    s.clear();
  } 

  return 0; 
}

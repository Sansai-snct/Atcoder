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
  //進む方向
  int d[4] = {-1,1,-4,4};
  //mapで連想配列を作る
  map<string,int> ans;
  //最終形の設定
  ans["01234567"] = 0;

  queue <Pr> que;
  //queにパズルの状態と回数をぶちこむ
  que.push(Pr(0,"01234567"));

  while(size(que)){
    //キューの先頭を取り出す
    Pr p = que.front(); que.pop();
    //パズルの状態に対応したansを代入
    int k = ans[p.second];
    rep(i,0,4){
      //pの一つ目(int)の要素とdを足す
      int n = p.first + d[i];
      if(i==0 && n==3){
        continue;
      }else if(i==1 && n==4){
        continue;
      }else if(n >= 0 && n < 8){
        string tmp;
        //tmpに二つ目の要素(string)を代入
        tmp = p.second;
        //一つ目の要素に対応させる。
        tmp[p.first] = tmp[n];
        //同じところを辿らないように
        tmp[n] = '0'; 
        
        if(ans.find(tmp) == ans.end()){
	      ans[tmp] = k + 1;
	      que.push(Pr(n,tmp));
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
        s += t;
    }
    cout << ans[s] << endl;
    s.clear();
  } 

  return 0; 
}

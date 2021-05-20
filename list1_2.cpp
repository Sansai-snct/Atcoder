#include <iostream>
using namespace std;
// Nodeクラス
class Node{
  public:
    Node* prev; 
    Node* next; 
    int data; 
    Node(){
      prev = 0; next = 0; data = 0;
    }
};
// Listクラス
class List{
  public:
    Node head; 
    Node* btn;
  List(){
    head.prev = &head; 
    head.next = &head; 
    head.data =-1;
  } 
  int append(int nd); 
  int del(int a); 
  bool search(int d); 
};
// appendメソッド
int List::append(int nd){
  Node* p = new Node();
  if(p==0) return -1; 
  Node* q = head.prev;
  Node* r = &head;
  p->prev = q;
  p->next = r;
  p->data = nd;
  q->next = p;
  r->prev = p;
  return 0; 
}
// delメソッド
int List::del(int a){
  if(a%2==0){ 
    for(int i=0; i<a; i++){ 
      btn = btn->next;
      if(btn==&head){ 
        btn = btn->next; 
      } 
    }
  }else{ 
    for(int i=0; i<a; i++){ 
      btn = btn->prev;
      if(btn==&head){ 
        btn = btn->prev; 
      } 
    }
  }
  Node* p = btn;
  btn = btn->next;
  if(btn==&head){ 
      btn = btn->next;
  }
  Node* q = p->prev;
  Node* r = p->next;
  q->next = r;
  r->prev = q;
  delete p;
  return 0; 
}
// searchメソッド
bool List::search(int d){
  for(Node* p=head.next; p!=&head; p=p->next)
    if(p->data==d) return true; 
  
  return false;
}

int main(){
  int N, M, Q;
  cin >> N >> M >> Q;
  List L;
  for(int i=0; i<N; i++){ 
      L.append(i);
  }
  L.btn = L.head.next;
  for(int i=0; i<M; i++){ 
    int a; 
    cin >> a;
    L.del(a);
  }
  for(int i=0; i<Q; i++){ 
      int q; 
      cin >> q;
      if(L.search(q)){ 
         cout << 1 << endl; 
      }else{ 
        cout << 0 << endl; 
      }
  }
  return 0;
}
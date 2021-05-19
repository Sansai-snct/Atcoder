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
  private:
    Node head; 
  public:
    List(){
        head.prev = &head; head.next = &head;
    } 
    int insert(int x); 
    int del(int x);
    int deleteFirst(); 
    int deleteLast(); 
    void print();
};
//insert
int List::insert(int x){
  Node* p = new Node();
  if(p==0) return -1; 
  Node* q = &head;
  Node* r = head.next;
  p->prev = q;
  p->next = r;
  p->data = x;
  q->next = p;
  r->prev = p;
  return 0; 
}
// del
int List::del(int x){
  Node* p;
  for(p=head.next; p!=&head; p=p->next){ 
    if(p->data==x) 
      break;
  }
  if(p==&head) return -2; 
  Node* q = p->prev;
  Node* r = p->next;
  q->next = r;
  r->prev = q;
  delete p;
  return 0; 
}
// deleteFirst
int List::deleteFirst(){
  Node* p = head.next;
  if(p==&head) return -2; 
  Node* q = p->prev;
  Node* r = p->next;
  q->next = r;
  r->prev = q;
  delete p;
  return 0; 
}
// deleteLast
int List::deleteLast(){
  Node* p = head.prev;
  if(p==&head) return -2; 
  Node* q = p->prev;
  Node* r = p->next;
  q->next = r;
  r->prev = q;
  delete p;
  return 0; 
}
// print
void List::print(){
  for(Node* p=head.next; p!=&head; p=p->next){ 
    cout << p->data;
    if(p->next!=&head){ 
        cout << ' '; 
    }else{ 
        cout << endl; 
    }
  }
}

int main(){
  List L;
  int n;
  cin >> n;
  for(int i=0; i<n; i++){ 
    char com[20];
    if(com[0]=='i'){ 
      int x;
      cin >> x;
      L.insert(x); 
    }else if(com[6]=='F'){ 
      L.deleteFirst(); 
    }else if(com[6]=='L'){ 
      L.deleteLast(); 
    }else{ 
      int x;
      cin >> x;
      L.del(x); 
    }
  }
  L.print();
  return 0;
}
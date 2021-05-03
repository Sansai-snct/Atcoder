#include <iostream>
using namespace std;
int cnt=0;
void bubbleSort(int A[],int N){
    bool flag = 1;
    while(flag){
        flag=0;
        for(int j=N-1; j>0; j--){
            if(A[j]<A[j-1]){
                swap(A[j],A[j-1]);
                flag=1;
                cnt++;
            }
        }
    }
}
int main(void){
    int n;
    cin >> n;
    int a[n];
    
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    bubbleSort(a,n);
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    cout << cnt << endl;
    return 0;
}

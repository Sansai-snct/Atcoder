#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int n;
    int sum = 0;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
      cin >> a[i];
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            sum+= pow((a[j]-a[i]),2);
        }
    }

    cout << sum << endl;
    return 0;

}
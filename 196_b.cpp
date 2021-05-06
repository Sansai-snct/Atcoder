//196_B
#include <iostream>
#include <string>
using namespace std;

int main(){
    string n;
    cin >> n;
    string ans = n.substr(0, n.find('.'));
    cout << ans << endl;
    
    return 0;


}
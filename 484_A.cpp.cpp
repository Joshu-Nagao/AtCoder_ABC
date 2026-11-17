#include <iostream>
using namespace std;

int main(){
    int B, R;
    cin >> B >> R;
    int sum = 900;
    for (int i = 0; i < B; i++){
        sum -= 30;
    }
    for (int j = 0; j < R; j++){
        sum -= (30 - B);
    }
    cout << sum << "\n";
}

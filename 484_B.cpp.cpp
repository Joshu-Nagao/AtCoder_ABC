#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int K;
    cin >> K;
    vector<int> A(K);
    for(int i = 0; i < K; i++){
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    if (A[K - 1] == 9){
        cout << A[0] << "\n";
        return 0;
    }
    else {
        cout << -1 << "\n";
        return 0;
    }
}

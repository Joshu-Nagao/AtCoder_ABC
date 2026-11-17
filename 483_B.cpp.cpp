#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, Q;
    cin >> N >> Q;
    vector<int> K(Q);
    for (int i = 0; i < Q; i++){
        cin >> K[i];
    }
    vector<int> order(N);
    for (int i = 0; i < N; i++){
        order[i] = i + 1;
    }
    for (int i = 0; i < Q; i++){
        for (int j = 0; j < K[i]; j++){
            order[j] = -order[j];
        }
        reverse(order.begin(), order.begin() + K[i]);
    }
    for (int i = 0; i < N; i++){
        cout << order[i] << endl;
    }
    return 0;
}
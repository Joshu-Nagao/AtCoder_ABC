#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    unordered_map<long long, int> freq;
    long long total_unique = 1;
    for (int i = 0; i < N; i++) {
        if (i > 0 && A[i] != A[i - 1]) {
            int count = i - freq[A[i]];
            total_unique += count;
        }
        freq[A[i]]++;
    }
    cout << total_unique << endl;
    return 0;
}


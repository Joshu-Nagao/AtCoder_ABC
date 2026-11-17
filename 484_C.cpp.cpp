#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long N;
    cin >> N;
    vector<long long> A(N);
    vector<long long> B(N);
    for(long long i = 0; i < N; i++){
        cin >> A[i];
    }
    for(long long i = 0; i < N; i++){
        cin >> B[i];
    }
    long long front_count = 0;
    long long back_count = N;
    for(long long i = 0; i < N; i++){
        if(A[i] == B[i]){
            front_count++;
        }
        else{
            break;
        }
    }
    for(long long i = 0; i < N; i++){
        if(A[N - 1 - i] == B[N - 1 - i]){
            back_count--;
        }
        else{
            break;
        }
    }
    if(front_count == N && back_count == 0){
        cout << "Yes" << "\n";
        return 0;
    }
    vector<long long> check;
    vector<long long> answer;
    for(long long i = 0; i < back_count - front_count; i++){
        check.push_back(B[front_count + i]);
        answer.push_back(A[front_count + i]);
    }
    vector<long long> check_left = check;
    vector<long long> check_right = check;
    long long front = B[front_count];
    long long back = B[back_count - 1];
    check_left.erase(check_left.begin());
    check_left.push_back(front);
    check_right.pop_back();
    check_right.insert(check_right.begin(), back);
    if(check_left == answer || check_right == answer){
        cout << "Yes" << "\n";
    }
    else{
        cout << "No" << "\n";
    }
}

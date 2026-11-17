#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool compareHeavyweights(const pair<long long, long long>& a, const pair<long long, long long>& b) {
    if (a.first != b.first) {
        return a.first > b.first;
    }
    return a.second < b.second;
}

int main(){
    long long N, M;
    cin >> N >> M;
    vector<long long> votes(N + 1, 0);
    vector<map<long long, long long>> moves(N + 1);

    for (long long i = 0; i < M; i++){
        long long a, b;
        cin >> a >> b;
        votes[a]++;
        moves[a][b]++;
    }

    vector<pair<long long, long long>> winning;
    for (long long i = 1; i <= N; i++){
        winning.push_back({votes[i], i});
    }
    sort(winning.begin(), winning.end(), compareHeavyweights);

    for (long long i = 1; i <= N; i++){
        long long best = -1;
        long long winner = -1;
        vector<long long> candidates;
        for (long long k = 0; k < min((long long)winning.size(), 10LL); k++){
            candidates.push_back(winning[k].second);
        }
        for (auto const& entry : moves[i]){
            candidates.push_back(entry.first);
        }
        for (long long k : candidates){
            if (k == i){
                continue;
            }
            long long current_score = votes[k];
            if (moves[i].count(k)){
                current_score += moves[i][k];
            }
            if (current_score > best){
                best = current_score;
                winner = k;
            }
            else if(current_score == best){
                if(k  < winner){
                    winner = k;
                }
            }
        }
        cout << winner << "\n";
    }
    return 0;
}

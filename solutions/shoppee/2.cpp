#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <climits>

using namespace std;

typedef pair<int, int> pi; 

int process(vector<int> v, int n) { // use greedy
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    set<int> s;
    set<int> pending;
    int sum = 0;
    
    for (int i = 0; i < v.size(); i++) {
        pq.push(make_pair(v[i], i)); // pair of price, index
    }

    while (n > 0) {
        pair<int, int> top = pq.top();
        pq.pop();
        int price = top.first;
        int index = top.second;

        if (n == 1 && !pending.empty()) { // ！
            int minv = INT_MAX;

            for (int i : pending) {
                minv = min(minv, v[i]);
            }

            sum += minv;
            // s.push();
            n--;
            continue;
        }
        
        if (index == 0) {
            if (s.count(index+1) && n > 1) {
                pending.insert(index);
                continue;
            } else if (s.count(index+1) && n == 1) {
                s.insert(index);
                sum += price;
                n--;
                continue;
            } else {
                s.insert(index);
                s.insert(index+1);
                sum += price;
                n -= 2;
                continue;
            }
        } else if (index == v.size()-1) {
            if (s.count(index-1) && n > 1) {
                pending.insert(index);
                continue;
            } else if (s.count(index-1) && n == 1) {
                s.insert(index);
                sum += price;
                n--;
                continue;
            } else {
                s.insert(index);
                s.insert(index-1);
                sum += price;
                n -= 2;
                continue;
            }
        } else {
            if (s.count(index-1) && s.count(index+1)) {
                pending.insert(index);
                continue;
            } else if (s.count(index-1)) {
                s.insert(index);
                s.insert(index+1);
                sum += price;
                n -= 2;
                continue;
            } else if (s.count(index+1)) {
                s.insert(index);
                s.insert(index-1);
                sum += price;
                n -= 2;
                continue;
            } else {
                s.insert(index);
                v[index-1] > v[index+1] ? s.insert(index-1) : s.insert(index+1); // always push larger
                sum += price;
                n -= 2;
                continue;
            }
        }

    }

    return sum;
}

int main() {
    int numberofcase, numberofserver, requiredserver, temp, i = 1;
    cin >> numberofcase;

    while (numberofcase--) {
        cin >> numberofserver >> requiredserver;
        vector<int> v(numberofserver);

        for (int i = 0; i < numberofserver; ++i) {
            cin >> v[i];
        }

        cout << "Case " << i << ": " << process(v, requiredserver) << endl;
        i++;
    }
    
    return 0;
}
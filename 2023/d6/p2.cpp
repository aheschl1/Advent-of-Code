#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;

ll compute(double c, double b){
    double first = -b + (sqrt((b*b)-4.0*c));
    double second = -b - (sqrt((b*b)-4.0*c));
    first /= -2.0; second /= -2.0;
    second = min(b, second);
    first = max(0.0, first);

    ll rf = ceil(first);
    if(first == rf){
        rf++;
    }
    ll rs = ceil(second);
    return abs(rf-rs);

}

void solve(){
    string _; cin >> _;
    string dists, records = "";
    int t;
    while(cin >> t){
        dists.append(to_string(t));
    }
    cin.clear();
    cin >> _;
    while(cin >> t){
        records.append(to_string(t));
    }
    ll record = stol(records);
    ll dist = stol(dists);
    cout << compute(record, dist) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
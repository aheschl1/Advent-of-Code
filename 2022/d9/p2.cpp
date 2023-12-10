#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<queue>
#include"knot.h"

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;


bool is_new(map<int, vector<int>> &visited, pair<int, int> &tail_pos){
    if(visited.count(tail_pos.first)){
        vector<int> ys = visited[tail_pos.first];
        if(find(ys.begin(), ys.end(), tail_pos.second) != ys.end()){
            return false;
        }else{
            visited[tail_pos.first].push_back(tail_pos.second);
            return true;
        }
    }else{
        vector<int> temp;
        temp.push_back(tail_pos.second);
        visited[tail_pos.first] = temp;
        return true;
    }
}

void solve(){
    int visit_count = 1;
    Knot *head;

    Knot *tempparent = nullptr;
    for(int i = 0; i < 10; i++){
        Knot *newKnot = new Knot(i, &visit_count, tempparent);
        if(tempparent){
            tempparent->set_child(newKnot);
        }else{
            head = newKnot;
        }
        tempparent = newKnot;
    }
    tempparent = nullptr;

    char direction;
    int counter = 0;
    while(cin >> direction){
        int num_times;
        cin >> num_times;
        for(int i = 0; i < num_times; i ++){
            head->move(direction);
        }
    }

    cout << visit_count << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<queue>

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;


bool inRange(pair<int, int> &head_pos, pair<int, int> &tail_pos){
    return abs(head_pos.first - tail_pos.first) <= 1 && abs(head_pos.second - tail_pos.second) <= 1;
}

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

void move(map<int, vector<int>> &visited, int*visit_count, pair<int, int> &head_pos, pair<int, int> &tail_pos){
    
    if(inRange(head_pos, tail_pos)){
        return;
    }
    //same y
    if(head_pos.second == tail_pos.second){
        //to the right
        if(head_pos.first > tail_pos.first + 1){
            tail_pos.first++;
            if(is_new(visited, tail_pos)){
                *visit_count+=1;
            }
        }else if(head_pos.first < tail_pos.first - 1){
            //left
            tail_pos.first--;
            if(is_new(visited, tail_pos)){
                *visit_count+=1;
            }
        }
    }
    //same x
    else if(head_pos.first == tail_pos.first){
        //above
        if(head_pos.second > tail_pos.second + 1){
            tail_pos.second++;
            if(is_new(visited, tail_pos)){
                *visit_count+=1;
            }
        }else if(head_pos.second < tail_pos.second - 1){
            //bellow
            tail_pos.second--;
            if(is_new(visited, tail_pos)){
                *visit_count+=1;
            }
        }
    }
    //different both
    else{
        int y_diff = head_pos.second - tail_pos.second; // 1
        int x_diff = head_pos.first - tail_pos.first; // 2
        if(abs(x_diff) > abs(y_diff)){ // 2 > 1
            tail_pos.second += y_diff;
            if(x_diff > 0){
                tail_pos.first++;
            }else{
                tail_pos.first--;
            }
            if(is_new(visited, tail_pos)){
                *visit_count+=1;
            }
        }else{
            tail_pos.first += x_diff;
            if(y_diff > 0){
                tail_pos.second++;
            }else{
                tail_pos.second--;
            }
            if(is_new(visited, tail_pos)){
                *visit_count+=1;
            }
        }
    }

}

void solve(){
    int visit_count = 1;
    //  x    y
    map<int, vector<int>> visited;
    pair<int, int> tail_pos = make_pair<int, int>(0, 0);
    pair<int, int> head_pos = make_pair<int, int>(0, 0);
    visited[0] = {0};

    char direction;
    int counter = 0;
    while(cin >> direction){
        int num_times;
        cin >> num_times;
        for(int i = 0; i < num_times; i ++){
            switch(direction){
                case 'U':
                    head_pos.second ++;
                    break;
                case 'D':
                    head_pos.second --;
                    break;
                case 'L':
                    head_pos.first --;
                    break;
                case 'R':
                    head_pos.first++;
                    break;
            }
            move(visited, &visit_count, head_pos, tail_pos);
        }
    }
    for(pair<int, vector<int>> p : visited){
        cout << p.first << ": ";
        for(int i : p.second){
            cout << i << ", ";
        }
        cout << endl;
    }
    cout << visit_count << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
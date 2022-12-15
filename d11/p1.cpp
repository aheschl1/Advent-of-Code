#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include"monkey.h"

typedef unsigned long long ll;

using namespace std;

void solve(){
    vector<Monkey> monkey_map;
    ll id;
    ll monkeymod = 1;
    while(cin >> id){
        vector<ll> items;
        ll temp;
        while(cin >> temp){
            items.push_back(temp);
            char check;
            cin.get(check);
            if(check == ':'){
                break;
            }
        }
        cin.ignore(5);
        operation my_op;
        char op;
        if(cin.get(op) && op == '+'){
            my_op.type = my_op.ADD;
        }else{
            my_op.type = my_op.MULTIPLY;
        }
        string quantity;
        getline(cin, quantity);
        if(quantity[0] == 'o'){
            my_op.type +=2;
        }else{
            my_op.quantity = stoi(quantity);
        }
        ll check;
        cin >> check;
        ll true_throw, false_throw;
        cin >> true_throw >> false_throw;

        Monkey new_monkey(id, items, check, true_throw, false_throw, my_op, &monkey_map);
        monkey_map.push_back(new_monkey);
        if(my_op.quantity != -1){
            monkeymod *= my_op.quantity;
        }

    }

    for(ll r = 0; r < 10000; r++){
        for(ll i = 0; i < monkey_map.size(); i++){
            while(monkey_map[i].items.size() > 0){
                monkey_map[i].inspect();
            }
        }
    }
    vector<ll> inspections;
    for(ll i = 0; i < monkey_map.size(); i++){
        inspections.push_back(monkey_map[i].inspect_count);
    }
    sort(inspections.begin(), inspections.end());
    cout << inspections[inspections.size()-2] * inspections[inspections.size()-1] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
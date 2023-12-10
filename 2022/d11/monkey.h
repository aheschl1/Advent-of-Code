#include<queue>
#include<map>
#include<iostream>

typedef unsigned long long ll;

struct operation{
    static const int ADD = 0;
    static const int MULTIPLY = 1;
    static const int SELF_ADD = 2;
    static const int SELF_MULTIPLY = 3;

    ll quantity;
    ll type;
    bool reset = false;
    ll perform_operation(ll current){
        if(type == SELF_ADD){
            return current + current;
        }else if(type == SELF_MULTIPLY){
            return current * current;
        }
        else if(type == ADD){
            return current + quantity;
        }else{
            return current * quantity;
        }
    }
};

class Monkey{
    public:
    Monkey(ll id, std::vector<ll> items, ll test_num, ll true_throw, ll false_throw, operation operation_type, std::vector<Monkey> *monkey_map);
    void inspect();
    void display();
    ll id;
    std::vector<ll> items;
    ll inspect_count = 0;

    private:
    void catch_item(ll level);
    void take_turn();
    ll true_throw;
    ll false_throw;
    std::vector<Monkey> *monkey_map;
    ll test_num;
    operation operation_type;
};
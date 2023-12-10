#include "monkey.h"
#include<iostream>
#include<algorithm>

Monkey::Monkey(ll id, std::vector<ll> items, 
    ll test_num, ll true_throw, ll false_throw, operation operation_type, std::vector<Monkey> *monkey_map){
        this->monkey_map = monkey_map;
        this->id = id;
        this->items = items;
        this->test_num = test_num;
        this->true_throw = true_throw;
        this->false_throw = false_throw;
        this->operation_type = operation_type;
}
void Monkey::display(){
    std::cout << id << std::endl;
    std::cout << "True throw: " << true_throw << std::endl;
    std::cout << "False throw: " << false_throw << std::endl;
    std::cout << "Items: ";
    for(ll i : items){
        std::cout << i << ',' ;
    }
    std::cout << std::endl;
    std::cout << "Divisible check: " << test_num << std::endl;
    std::cout << "Operation: " << operation_type.quantity << std::endl; 
}
void Monkey::inspect(){
    inspect_count++;
    items[0] = operation_type.perform_operation(items[0]);
    //part 1:
    //items[0]/=3
    //part 2:
    items[0] %= 9699690; //product of primes of divisibility checks: all inputs are prime
    take_turn();
}

void Monkey::catch_item(ll level){
    this->items.push_back(level);
}

void Monkey::take_turn(){
    ll level = items[0];
    if(!(level % test_num)){
        monkey_map->at(true_throw).catch_item(level);
    }else{
        monkey_map->at(false_throw).catch_item(level);
    }
    items.erase(items.begin());
}
#include "knot.h"
#include<algorithm>

Knot::Knot(int index, int*visit_count, Knot *parent, Knot *child){
    this->parent = parent;
    this->child = child;
    this->visit_count = visit_count;
    this->index = index;
    visited[0] = {0};
}

void Knot::set_child(Knot *child){
    this->child = child;
}

bool Knot::is_new(std::pair<int, int> &new_pos){
    if(visited.count(pos.first)){
        std::vector<int> ys = visited[pos.first];
        if(find(ys.begin(), ys.end(), pos.second) != ys.end()){
            return false;
        }else{
            visited[pos.first].push_back(pos.second);
            return true;
        }
    }else{
        std::vector<int> temp;
        temp.push_back(pos.second);
        visited[pos.first] = temp;
        return true;
    }

}

void Knot::move(char direction){
    switch(direction){
        case 'U':
            pos.second ++;
            break;
        case 'D':
            pos.second --;
            break;
        case 'L':
            pos.first --;
            break;
        case 'R':
            pos.first++;
            break;
    }
    child->parent_moved();
}

void Knot::parent_moved(){
    std::pair<int, int> &head_pos = parent->pos;
    std::pair<int, int> &tail_pos = pos;

    if(inRange(head_pos, tail_pos)){
        return;
    }
    if(abs(head_pos.second - tail_pos.second) == 2 && abs(head_pos.first-tail_pos.first) == 2){
        int y_diff = head_pos.second - tail_pos.second; // 1
        int x_diff = head_pos.first - tail_pos.first; // 2
        if(x_diff < 0){
            tail_pos.first--;
        }else{
            tail_pos.first++;
        }
        if(y_diff < 0){
            tail_pos.second--;
        }else{
            tail_pos.second++;
        }
        if(child == nullptr && is_new(tail_pos)){
            *visit_count+=1;
        }
        if(child != nullptr){
            child->parent_moved();
        }
        return;
    }
    //same y
    if(head_pos.second == tail_pos.second){
        //to the right
        if(head_pos.first > tail_pos.first + 1){
            tail_pos.first++;
            if(child == nullptr && is_new(tail_pos)){
                *visit_count+=1;
            }
        }else if(head_pos.first < tail_pos.first - 1){
            //left
            tail_pos.first--;
            if(child == nullptr && is_new(tail_pos)){
                *visit_count+=1;
            }
        }
    }
    //same x
    else if(head_pos.first == tail_pos.first){
        //above
        if(head_pos.second > tail_pos.second + 1){
            tail_pos.second++;
            if(child == nullptr && is_new(tail_pos)){
                *visit_count+=1;
            }
        }else if(head_pos.second < tail_pos.second - 1){
            //bellow
            tail_pos.second--;
            if(child == nullptr && is_new(tail_pos)){
                *visit_count+=1;
            }
        }
    }
    //different both
    else{
        int y_diff = head_pos.second - tail_pos.second; // 1
        int x_diff = head_pos.first - tail_pos.first; // 2
        if(std::abs(x_diff) > std::abs(y_diff)){ // 2 > 1
            tail_pos.second += y_diff;
            if(x_diff > 0){
                tail_pos.first++;
            }else{
                tail_pos.first--;
            }
            if(child == nullptr && is_new(tail_pos)){
                *visit_count+=1;
            }
        }else{
            tail_pos.first += x_diff;
            if(y_diff > 0){
                tail_pos.second++;
            }else{
                tail_pos.second--;
            }
            if(child == nullptr && is_new(tail_pos)){
                *visit_count+=1;
            }
        }
    }
    if(child != nullptr){
        child->parent_moved();
    }
}



#include"dir.h"
#include<string>
#include<vector>

typedef unsigned long long ull;
Directory::Directory(std::string label, Directory *parent){
    name = label;
    my_parent = parent;
}

std::vector<Directory*> Directory::getChildDirs(){
    return childrenDir;
}

void Directory::addChildDir(Directory *child){
    childrenDir.push_back(child);
}

ull Directory::getSize(){
    ull file_count = 0;
    for(int i : files){
        file_count+=i;
    }
    for(Directory*directory : childrenDir){
        file_count += directory->getSize();
    }
    return file_count;
}

void Directory::get_map(std::vector<ull> &map){
    map.push_back(getSize());
    for(Directory*directory : childrenDir){
        directory->get_map(map);
    }
}

void Directory::addFile(int size){
    files.push_back(size);
}

Directory* Directory::containsChild(std::string label){
    for(Directory *dir : childrenDir){
        if(dir->get_label() == label){
            return dir;
        }
    }
    return nullptr;
}

std::string Directory::get_label(){
    return name;
}

std::vector<int>& Directory::getFiles(){
    return files;
}

Directory* Directory::getParent(){
    return my_parent;
}
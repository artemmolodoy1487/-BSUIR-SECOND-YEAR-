#include <iostream>
#include <vector>
#include<string>
using namespace std;

class node{
private:
    string id;
    node* parent;
    vector<node*> children;
public:
    node(){
        id = "undefined";
    }

    node(string id){
        this->id = id;
    }

    node(node* parent){
        this->parent = parent;
    }

    void add_child(node* child){
        this->children.push_back(child);
    }

    string get_id(){
        return this->id;
    }

};



int main(){

    node test;
    cout<<test.get_id();


    return 0;
}
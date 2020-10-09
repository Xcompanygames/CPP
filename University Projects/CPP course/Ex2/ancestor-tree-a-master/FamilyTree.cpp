#include <iostream>
#include "FamilyTree.hpp"
using namespace std;
using namespace family;

Tree& Tree::addFather(string child, string father) {

    Tree* T = look_up(this, child); //Found the child tree
    if (T == NULL) throw runtime_error{ "Child name dosen't exict in famliy tree" }; //child dosn't exist
    if(T->father !=NULL)throw runtime_error {"There is already a father"};
    T->father = new Tree(father); //add up a new father tree
    T->father->child = T; //assign the father to the child
    T->father->gender="male";
    int distance= findDistance(this,father);
    T->father->rela=reliniz(distance,"male");
    return *this; 
}
Tree& Tree::addMother(string child, string mother) {

    Tree* T = look_up(this, child); //Found the child tree
    if (T == NULL) throw runtime_error{ "Child name dosen't exict in famliy tree" }; //child dosn't exist
    if(T->mother !=NULL)throw runtime_error {"There is already a mother"};
    T->mother = new Tree(mother); //add up a new mother tree
    T->mother->child = T; //assign the mother to the child
    T->mother->gender="female";
    int distance= findDistance(this,mother);
    T->mother->rela=reliniz(distance,"female");
    return *this;
}


int Tree::findDistance(Tree* root, string name) {
    Tree* T = look_up(this, name);
    int counter = 0;
    while (T->name != this->name) {
        T = T->child;
        counter++;
    }
    return counter;
}


void Tree::printTree ( Tree* n, int space )
{
    if (n==NULL) {
        for(int i = 0; i < space; ++i)
            cout << "\t";
        cout << 'X' << endl;
        return;
    }
    printTree(n->mother,space+1);
    for(int i = 0; i < space; i++)
        cout << "\t";
    cout << n->name << endl;
    printTree(n->father,space+1);
}


void Tree::display(){
printTree(this,0);
}


string Tree::GettingName(int x)
{
    Tree* T = this;
    int count=x;
while(x<0){
    if(T->father!=NULL){
        T=T->father;
        x--;
    }
    else if(T->mother!=NULL){
        T=T->mother;
        x--;
    }else{
        return "No Relation";
        break;
    }
}
    return T->name;

}

string Tree::reliniz(int distance,string gender) {
    if (distance==0) return "me";
    string rel = "";
    while (distance > 0) {
        if (distance == 1 && gender=="male" ) {
            rel = rel + "father";
            distance--;
        }
        if (distance == 1 && gender == "female") {
            rel = rel + "mother";
            distance--;
        }
        if (distance == 2) {
            rel =rel+"grand";
            distance--;
        }
        if(distance>2){
           rel =  rel+"great-";
           distance--;
        }
    }
    return rel;
}


string Tree::relation(string name) {
    if (this->name==name) return "me";
    Tree* T = look_up(this, name);
    if (T == NULL) return "unrelated";
    return T->rela;
}

string Tree::find(string relation) {
    if (relation == "me") return this->name;
    if (relation == "mother" && this->mother != NULL) return this->mother->name;
    if (relation == "father" && this->father != NULL) return this->father->name;
    if (relation.find("mother") != string::npos && relation.find("father") != string::npos)
        throw runtime_error{ "unrelated"};
    Tree* T = look_up_relation(this, relation);
    if(T==NULL)throw runtime_error{"The tree cannot handle the '"+relation+"' relation"};
    string name=T->name;
        return name;
}

void Tree::remove(string name){
    if(this->name == name)
         throw runtime_error {"This is unvalid to remove the root! "};
    Tree* T = look_up (this, name);
    if(T == NULL){
        throw runtime_error {"There is no person in the tree named: "+name};
        return;
    }
    if(T->child!=NULL)
    {    
        if(T->child->father != NULL && T->child->father->name == name) T->child->father=NULL;
        if(T->child->mother != NULL && T->child->mother->name == name) T->child->mother=NULL;
    }
    delete T;
 
}

Tree* Tree::look_up(Tree* T, string name) {
    if (T == NULL) return NULL;
    if (T->name == name) return T;
    else {

        Tree* f = look_up(T->father, name);
        Tree* m = look_up(T->mother, name);
        if (f != NULL) return f;
        if (m != NULL) return m;
    }
    return NULL;


}

Tree* Tree::look_up_relation(Tree* T, string rela) {
    if (T == NULL) return NULL;
    if (T->rela == rela) return T;
    else {

        Tree* f = look_up_relation(T->father, rela);
        Tree* m = look_up_relation(T->mother, rela);
        if (f != NULL) return f;
        if (m != NULL) return m;
    }
    return NULL;
}

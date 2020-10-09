#pragma once
#include <string>
using namespace std;

namespace family{

    class Tree{
        
        Tree* father;
        Tree* mother;
        Tree* child;
        string name;
        string gender;
        string rela; //Relation
        public:
       
        Tree(string name){
            this->name=name;
            this->father=NULL;
            this->mother=NULL;
            this->child=NULL;
            this->gender="";
            this->rela="me";
        }

         ~Tree(){
             delete this->father;
             delete this->mother;
        }
        
        Tree& addFather(string child, string father);
        Tree& addMother(string child, string mother);
        Tree* look_up (Tree* current , string name);    
        void display(); 
        void remove(string name);
        int findDistance(Tree* root, string name);
        string GettingName(int x);
        string reliniz(int distance, string gender);
        string relation(string name);
        string find (string relation);
        Tree* look_up_relation(Tree* T, string rela);
        void printTree(Tree *root, int space);
    };
}

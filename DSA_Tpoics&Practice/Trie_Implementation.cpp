#include<iostream>
#include<string>

using namespace std;

class Trienode{
    public:
      char ch;
      Trienode * children[26];
      bool isTerminal;

      Trienode(char c){
        this->ch = c;
        for (int i = 0;i<26;i++){
            children[i] = NULL;
        }
        this->isTerminal = false;
      }

};

class trie{
    public:
        Trienode * root;

        trie(){
            root = new Trienode('\0');
        }

        void insert(Trienode* root, string word){
            //base case 
            if (word.size() == 0){
                root->isTerminal = true;
                return ;
            }

            int index = word[0] - 'a';
            Trienode* child;

            if (root->children[index] != NULL){
                child = root->children[index];
            }
            else {
                child = new Trienode(word[0]);
                root->children[index] = child;
            }

            //Recursive call
            insert(child,word.substr(1));
        }

        void insertfunction(string word){
            insert(root, word);
        }

        bool search(Trienode* root, string word){
            //base case;
            if (word.length() == 0){
                return root->isTerminal;
            }

            int index = word[0] - 'a';
            Trienode * child;

            // for present condition 
            if (root->children[index] != NULL){
                child = root->children[index];
            }
            else { // for absent condition 
                return false;
            }

            //Recursive call 
            return search(child, word.substr(1));

        }

        bool searchfunction(string word){
            return search(root, word);
        }

        void remove(Trienode* root, string word){
            //base case
            if (word.length() == 0){
                root->isTerminal = false;
                return ;
            }

            int index = word[0] - 'a';
            Trienode* child;

            //present
            if (root->children[index] != NULL){
                child = root->children[index];
            }
            else {
                cout<<"String is not present!\n";
                return ;
            }

            //Recursive call
            remove(child,word.substr(1));
        }

        void removalfunction(string str){
            remove(root,str);
        }

        bool start(Trienode* root, string prefix){
            //base case;
            if (prefix.length() == 0){
                return true;
            }

            int index = prefix[0] - 'a';
            Trienode * child;

            if(root->children[index] != NULL){
                child = root->children[index];
            }
            else {
                return false;
            }

            //Recursive call 
            return start(child,prefix.substr(1));
        }

        bool startprefix(string str){
            return start(root,str);
        }

};

int main(){
    trie t;

    t.insertfunction("sandeep");
    t.insertfunction("swami");

    // cout<<t.searchfunction("swam")<<endl;
    cout<<t.searchfunction("swami")<<endl;
    // cout<<t.searchfunction("swamii")<<endl;

    cout<<t.startprefix("swa")<<endl;

    t.removalfunction("swami");
    cout<<t.searchfunction("swami")<<endl;

    cout<<t.startprefix("swa")<<endl;
    return 0;
}
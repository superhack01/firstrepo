#include<iostream>
#include<vector>

#define ll long long 

using namespace std;

class Trienode{
    public:
       char data;
       Trienode * children[26];
       int childcount;
       bool isTerminal;

       Trienode(char val){
         this->data = val;
         for (int i = 0;i<26;i++){
            children[i] = NULL;
         }
         this->childcount = 0;
         this->isTerminal = false;
       }
};

class Trie{
    public:
        Trienode * root;

        Trie(){
            root = new Trienode('\0');
        }


        void insert(Trienode * root, string word){
            //base case
            if (word.length() == 0){
                root->isTerminal = true;
                return;
            }

            int index = word[0] - 'a';
            Trienode * child;

            //present 
            if (root->children[index] != NULL){
                child = root->children[index];
            }
            else {// for absent
                child = new Trienode(word[0]);
                root->children[index] = child;
                root->childcount++;
            }

            // Recursive call 
            insert(child,word.substr(1));
        }

        void insertfunction(string str){
            insert(root, str);
        }

        string lcp(string str){
            string prefix = "";
            for (int i = 0;i<str.length();i++){
                char ch = str[i];

                if (root->childcount == 1){
                    prefix.push_back(ch);
                    //next iteration
                    int index = ch-'a';
                    root = root->children[index];
                }
                else break;

                if (root->isTerminal) break;
            }

            return prefix;
        }
};

int main() {
    Trie t;

    // t.insertfunction("sandeep");
    // t.insertfunction("skumar");
    // t.insertfunction("swami");
    int n;
    cin>>n;

    string * arr = new string[n];

    for (int i = 0;i<n;i++){
        cin>>arr[i];

        t.insertfunction(arr[i]);
    }


    cout<<t.lcp(arr[0])<<endl;

    return 0;
}

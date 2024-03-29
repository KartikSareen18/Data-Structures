#include <iostream>
#include <string>
using namespace std;

class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
	}
};

class Trie {
    TrieNode *root;
    
    public :
    
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insertWord(TrieNode *root, string word) {
    
        if(word.size() == 0) {
            root -> isTerminal = true;
            return;
        }
        
        int index = word[0] - 'a';
        TrieNode *child;
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        }
        else {
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }
        
        insertWord(child, word.substr(1));
    }
    
    void insertWord(string word) {
        insertWord(root, word);
    }
    
    bool search(TrieNode *root,string word)
    {
        if(word.size()==0)
        {
            return root->isTerminal;
        }
        
        int index=word[0]-'a';
        if(root->children[index]!=NULL)
        {
            TrieNode *child=root->children[index];
            return search(child,word.substr(1));
        }
        else
            return false;
    }
    bool search(string word) {
       return search(root,word);
        
    }
};

int main() {
	int choice;
	cin >> choice;
	Trie t;

	while(choice != -1){
		string word;
        bool ans;
		switch(choice) {
            case 1 : // insert
            	
            	cin >> word;
                t.insertWord(word);
                break;
            case 2 : // search
            	
            	cin >> word;
                ans = t.search(word);
                if (ans) {
                    cout << "true" << endl;
                } else {
                    cout << "false" << endl;
                }
                break;
            default :
                return 0;
        }
        cin >> choice;
	}
	return 0;
}


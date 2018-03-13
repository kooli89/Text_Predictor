#include <bits/stdc++.h> 
     
using namespace std;

int getId(char c) //function to return the id of evry alphabeic letter
{                 // this function ignore the case
    if(isupper(c))
    {
        c = tolower(c);
    }
    return (int)(c-'a');
}


struct node
{
    int letter;
    int weight[26]; // array of weights of the edges going to every other node
    vector<node*> nxt; // array of pointers of next nodes
    bool isEndOfWord; // boolean flag to detect leafs

    node() // default values
    {
        letter = 0;
        isEndOfWord = false;
        memset(weight,0,sizeof weight);
        nxt.clear();
    }

    node(int c)
    {
        letter = c;
        isEndOfWord = false;
        memset(weight,0,sizeof weight);
        nxt.clear();
    }

};

node src = node(); // global variable : the root of the Trie

void addWord(string s, node *curNode) //
{
    for(int i=0;i<(int)s.size() ; ++i)
    {
        if(!isalpha(s[i])) continue; // ignore non alphabetic letters
        int c(getId((char)s[i]));
        node* newNode = new node();
        if(!curNode->weight[c]) // if there is no node with node.letter = s[i]
        { // create new node
            curNode->weight[c] = 1;
            newNode->letter = c;
            curNode->nxt.push_back(newNode); // add the new node to the neighbors of the current node
        }
        else // if the node exist increment it's weight and go to the next node
        {
            curNode->weight[c]++;
            for(int j=0;j<(int)curNode->nxt.size() ;++j)
            {
                if(curNode->nxt[j]->letter == c)
                {
                    newNode = curNode->nxt[j];
                    break;
                }
            }
        }
        curNode = newNode;

    }

    curNode->isEndOfWord = true; //end of the world flag
}


priority_queue<pair<int,string>> q;

int dfs(node nod,int score,string word) // function to traverse the Trie and count the scores of words
{
    int ret(0);
    if(nod.isEndOfWord) q.push(make_pair( score, word)); // if the current node is an end of word we push the word
    for(int i=0;i<(int)nod.nxt.size() ; ++i)           // and it's score to the priority queue
    {
        ret = nod.weight[nod.nxt[i]->letter] + dfs(*nod.nxt[i] , nod.weight[nod.nxt[i]->letter] , word + (char)((nod.nxt[i]->letter)+'a'));
    }
    return ret;
}


node startNode(string s) // find the starting node wich is the end point of the path
{                        // correspending to the given word in the Trie
    node curNode = src;
    for(int i=0;i<(int)s.size();++i)
    {
        int c(getId((char)s[i]));
        for(int j=0;j<(int)curNode.nxt.size();++j)
        {
            if((curNode.nxt[j]->letter) == c)
            {
                curNode = *curNode.nxt[j];
                break;
            }
            if(j == (int)curNode.nxt.size() - 1) return node(-1); // no suggestions found
        }
    }
    return curNode;
}




int main()
{
    ifstream read("in");
    string s;
    while(read>>s)
    {
        addWord(s,&src);
    }
    label:
    cin>>s;
    for(int i=0;i<(int)s.size();++i) s[i] = tolower(s[i]); // the code ignores the case
    node st = startNode(s);
    if(st.letter == -1)
    {
        cout<<"No suggestions found"<<endl<<"Try again"<<endl;
        goto label;
    }
    dfs(st,0,s);
    while(!q.empty()) // Print all the words and scores pushed in the priority queue
    {
        string s = q.top().second;
        int score = q.top().first;
        q.pop();
        cout<<s<<" "<<score<<endl;
    }
    return 0;
}

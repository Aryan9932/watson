#include<iostream>
#include<map>
#include<functional>
#include<queue>
using namespace std;

struct Node{
  public:
  int freq;
  char alpha;
  Node *left;
  Node *right;
  Node(int f,char a){
    freq=f;
    alpha=a;
    left=nullptr;
    right=nullptr;
  }
};


void printcodes(Node *root,string code){
  if(!root)return ;
  if(!root->left && !root->right){
    cout<<root->alpha<<" : ";
    if(code==""){
      cout<<" 0"<<endl;
      return;
    }else{
      cout<<code<<endl;
      return ;
    }




  }

  printcodes(root->left,code+'0');
  printcodes(root->right,code+'1');

}

int main(){
  string text;
  cout<<"Enter the text line"<<endl;
  cin>>text;
  map<char,int>mp;
  for(int i=0;i<text.length();i++){
    mp[text[i]]++;
  }
  priority_queue<pair<int , Node*>, vector<pair<int,Node*>>,greater<pair<int,Node*>>>pq;
  for(auto it:mp){
    Node *newnode= new Node(it.second,it.first);
    pq.push({it.second,newnode});
  }
  while(pq.size()>1){
    Node* first=pq.top().second;
    pq.pop();
    Node *second=pq.top().second;
    pq.pop();
    Node *newnode=new Node('-',first->freq+second->freq);
    newnode->left=first;
    newnode->right=second;
    pq.push({newnode->freq,newnode});
  }
  Node *root=pq.top().second;
  printcodes(root,"");







}
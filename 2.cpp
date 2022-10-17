#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class BinaryTreeNode{
    public:
    char data;
    BinaryTreeNode*left;
    BinaryTreeNode*right;
    BinaryTreeNode*parent;
    BinaryTreeNode(char data,BinaryTreeNode* parent){
        this->data=data;
        left=NULL;
        right=NULL;
        this->parent=parent;
    }
};


string infixToPrefix(string str){
    int openBracket=0;
    if(str.size()==0){
        return "";
    }
    if(str.size()==1){
        return str;
    }
    for(int i=0;str[i]!='\0';i++){
        if(str[i]=='('){
            openBracket++;
        }
        else if(str[i]==')'){
            openBracket--;
        }
        else if(str[i]=='*'||str[i]=='+'|| str[i]=='>' || str[i]=='~'){
            if(openBracket==1){
                return str[i]+infixToPrefix(str.substr(1,i-1))+infixToPrefix(str.substr(i+1,str.size()-2-i));
            }
        }
    }
    return "";
}

/*class Pair{
    BinaryTreeNode* root;
    int index;
};
*/
void prefixToTree(string str,BinaryTreeNode* root){
    BinaryTreeNode* p=new BinaryTreeNode(str[0],root);
     if(str[0]=='*'||str[0]=='+'|| str[0]=='>' || str[0]=='~'){
         if(root->left==NULL)
          {
              root->left=p;
          }
          else
          {
              root->right=p;
          }
           prefixToTree(str.substr(1,str.size()-1),p);
     }
     if(isalpha(str[0]))
     {
          if(root->left==NULL)
          {
              root->left=p;
          }
          else
          {
              root->right=p;
          }
          while(root->right)
          {
            root=root->parent;
            if(root==NULL)
            break;
          }
          if(root!=NULL)
          prefixToTree(str.substr(1,str.size()-1),root);
     }
    
}


int main(){

    string str;
    cin>>str;
    string ans=infixToPrefix(str);
    cout<<ans;
    BinaryTreeNode* root=new BinaryTreeNode(ans[0],NULL);
    prefixToTree(ans.substr(1,ans.size()-1),root);  
    return 0;
}
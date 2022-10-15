#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class BinaryTreeNode{
    public:
    char data;
    BinaryTreeNode*left;
    BinaryTreeNode*right;
    BinaryTreeNode(char data){
        this->data=data;
        left=NULL;
        right=NULL;
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

class Pair{
    BinaryTreeNode* root;
    int index;
};

/*Pair prefixToTree(string str, BinaryTreeNode*root){
    BinaryTreeNode*left=new BinaryTreeNode(str[0]);
    BinaryTreeNode*finalLeft=prefixToTree(str+1,left);
    BinaryTreeNode*
}*/


int main(){

    string str;
    cin>>str;
    string ans=infixToPrefix(str);
    cout<<ans;
    /*BinaryTreeNode* root=new BinaryTreeNode(ans[0]);
    BinaryTreeNode*finalRoot=prefixToTree(ans+1,root);*/    

    return 0;
}
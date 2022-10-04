
#include <bits/stdc++.h>

using namespace std;

class treeNode
{

public :

    int data;
    treeNode * leftchild;
    treeNode * rightchild;
    
    treeNode(int value)
    {
        
        data = value;
        leftchild = NULL;
        rightchild = NULL;
    }
    
    
    
};


int findMax(treeNode* root)
{
    
    if (root == NULL)
        return INT_MIN;
 
   
    int res = root->data;
    int lres = findMax(root->leftchild);
    int rres = findMax(root->rightchild);
    if (lres > res)
        res = lres;
    if (rres > res)
        res = rres;
    return res;
}




int main() {
    
    int n;
    cin>>n;
    
    treeNode * allNodes[n];
    
    for ( int i =0; i<n; i++){
        allNodes[i] = new treeNode(-1);
    }
    
    for ( int i =0; i<n; i++)
    {
       
        int value,left,right;
        cin>>value>>left>>right;
        allNodes[i]->data = value;
        
        if(left>n-1 || right>n-1)
        {
            cout<< " Invalid Index "<<endl;
            break;
        }
        if (left != -1){
            allNodes[i]->leftchild=allNodes[left];
        }
        
         if (right != -1){
            allNodes[i]->rightchild=allNodes[right];
        }
    }
    
    
    cout <<  findMax(allNodes[0]) << endl;
    return 0;
}






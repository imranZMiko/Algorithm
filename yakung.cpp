#include<bits/stdc++.h>
using namespace std;
int N,Q,i,j,k,flag,res,ans,tree_val,arr[100010],size_of_tree;
struct query
{
  char ch ;
  int number ;
};
struct node
{
     int data,_count = 0,left_child=0, right_child=0;
     node *left = NULL;
     node *right = NULL;
     node(){
 
     }
     
     node(int _data ,node *_left ,node *_right,int _counts,int _left_child,int _right_child){
        data = _data;
        left = _left;
        right = _right;
        _count = _counts ;
        left_child = _left_child ;
        right_child = _right_child ;
     }
   
};
 
struct tree
{
 
node *root = NULL;

void Buildthistree(int start, int end){
   if (start > end) 
    return ; 
  
    int mid = (start + end)/2; 
    insert(arr[mid]);
   
    Buildthistree(start, mid - 1); 
  
    Buildthistree(mid + 1, end); 
}

void insert(int data){
    root = insertData(root,data);
  }
node *insertData(node *root, int data){
    node *cur = new node(data,NULL,NULL,0,0,0);
    if(root == NULL){
      root = cur;
      return root;
    }
    if(data == root->data) {
    }
    else if(data> root->data){
      root->right = insertData(root->right,data);
    }
    else{
      root->left = insertData(root->left,data);
    }
    return root;
  }

void insert2(int data){
     insertData2(root,data);
  }
node *insertData2(node *root, int data){
    if(data == root->data) {
       (root->_count)++;
       return NULL;
    }
    else if(data> root->data){
      (root->right_child)++;
       insertData2(root->right,data);
    }
    else{
      (root->left_child)++;
       insertData2(root->left,data);
    }
    return NULL ;
  }


node *countlessthan(node *cur,int data)
   {
    if(cur==NULL ) return NULL;

    else if (data >=cur->data) {
      ans += (cur->_count) + cur->left_child ;
      countlessthan(cur->right,data); 
    }
    else
      countlessthan(cur->left,data) ;
  }
  int count_less(int data)
  {
      countlessthan(root,data);
  }

node *countgreaterthan(node *cur,int data)
   {
    if(cur==NULL ) return NULL;
    if(data==cur->data){
      ans+= cur->right_child ;
      return NULL;
    }
    else if (data <cur->data) {
      ans += (cur->_count) + cur->right_child ;
      countgreaterthan(cur->left,data); 
    }
    else
      countgreaterthan(cur->right,data) ;
  }
  int count_great(int data)
  {
      countgreaterthan(root,data);
   
  }



};
 
int main(){
   
    struct tree a;
    struct query q[100010];
    cin >> N >> Q ;
    i = 0 ;
    j = 0 ;
    int size = N+Q ;
    size_of_tree = 0 ;
    while(N--)
    {
      cin >> tree_val ;
      arr[size_of_tree] = tree_val ;
      size_of_tree++;
      q[j].number = tree_val ;
      q[j].ch = 'I' ;
      j++;
    }
    char ch1 ;
    while(Q--)
    {
      cin >> ch1 >> tree_val ;
      if(ch1=='I') {arr[size_of_tree] = tree_val ; size_of_tree++;}
      q[j].number = tree_val ;
      q[j].ch = ch1 ;
      j++;
    }
    sort(arr,arr+size_of_tree) ;
    size_of_tree--;
    cout << size << " " << size_of_tree << endl ;
    a.Buildthistree(0,size_of_tree) ;
    i = 0 ;
    while(size--)
    {
      if(q[i].ch=='I') a.insert2(q[i].number) ; 
      else if(q[i].ch=='U') {
        ans= 0 ;
        a.count_great(q[i].number) ;
        cout << ans << endl ;
      } 
      else if(q[i].ch=='L'){
        ans = 0 ;
        a.count_less(q[i].number) ;
        cout << ans << endl ;
      }
      i++;
    }
   
    return 0;
}
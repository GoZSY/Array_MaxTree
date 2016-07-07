/******************************************************************************
对于数组中的每一个数字，求它的左边第一个比它大的数，求它的右边第一个比它大的数，
两个数中较小的一个的即为它的父节点，如果没有比它大的数，那么它就为根节点，关键在于
如何求得左右比它大的第一个数字中较小的一个
******************************************************************************/
struct Node{  
    int val;  
    Node* left;  
    Node* right;  
    Node(int data):val(data),left(NULL),right(NULL){}  
};  

void getFirstBigNumber(stack<Node*> &sta, map<Node*,Node*> mp)
{
  Node* popVlaue = sta.top();
  sta.pop();
  if(sta.empty())
    mp[popValue] = NULL;
  else
    mp[popValue] = sta.top();
  
}

Node* getMaxtree(vector<int> A)
{
  vector<Node*> v;
  for(int i = 0; i < A.size(); ++i)
    v.push_back(Node(A[i]));
  map<Node*,Node*> leftBig;
  map<Node*,Node*> rightBig;
  stack<Node*> stk;
  for(int i = 0;i < A.size(); ++i)
  {
    Node* temp = v[i];
    while(!stk.empty()&&stk.top().val < temp.val)
    {
      getFirstBigNumber(stk, leftBig);
    }
    stk.push(temp);
  }
  while(!stk.empty())
  {
    getFirstBigNumber(stk, leftBig);
  }
  for(int i = A.size()-1;i >= 0; --i)
  {
    Node* temp = v[i];
    while(!stk.empty()&&stk.top().val < temp.val)
    {
      getFirstBigNumber(stk, rightBig);
    }
    stk.push(temp);
  }
  while(!stk.empty())
  {
    getFirstBigNumber(stk, rightBig);
  }
  Node* head = NULL;
  for(int i = 0 ; i < A.size();++i)
  {
    Node* current = v[i];
    Node* nodeleft = leftBig[current];
    Node* noderight = rightBig[current];
    if(nodeleft == NULL && noderight == NULL)
      head = current;
    else if(nodeleft == NULL)
    {
      if(noderight->left == NULL)
        noderight->left = current;
      else
        noderight->right = current;
    }
    else if(noderight == NULL)
    {
      if(nodeleft->left == NULL)
        nodeleft->left = current;
      else
        nodeleft->right = current;
    }
    else
    {
      Node* parent = nodeleft->val>noderight->val?noderight:nodeleft;
      if(parent->left == NULL)
        parent->left = current;
      else 
        parent->right = current;
    }
  }
  return head;
}

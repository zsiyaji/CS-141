#include <iostream>
using namespace std;


struct Node{
  int data;
  Node *pNext;
};

void display(Node *pHead){
  while( pHead != NULL){
    cout << pHead->data << " ";
    pHead = pHead->pNext;
  }
}


Node* modify(Node *pHead){
  Node *pTemp;
  if(pHead -> pNext == NULL){
    return pHead;
  }
  else{
    pTemp = modify(pHead -> pNext);
    pHead->pNext->pNext = pHead;
    pHead->pNext = NULL;
    // Position B left
    return pTemp;
  }
}


void doit()
{
  int number = 0;
  Node *pHead = NULL;
  Node* pTemp;

  cout <<"Enter numbers, then -1: ";
  while( number != -1) {
    cin >> number;
    if(number != -1) {
      pTemp = new Node;
      pTemp->data = number;
      pTemp->pNext = pHead;
      pHead = pTemp;
    }
  }

  pTemp = pHead;
  pHead = modify( pHead);
  // Position A right
  //pHead->pNext = NULL;
  display( pHead);
}


int main()
{
  doit();
  return 0;
}

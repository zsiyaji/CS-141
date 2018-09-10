#include <iostream>
using namespace std;

struct Node
{
  char name[20];
  int data;
  Node* next;
};

void insert_start(Node* head, int value)
{

  Node *temp=new Node;
  temp->data=value;
  temp->next=head;
  head=temp;
}

void display(Node *head)
{
  Node *temp=new Node;
  temp=head;
  while(temp!=NULL)
  {
    cout<<temp->name<<"\t";
    temp=temp->next;
  }
}

void PrintLL(Node *head)
{
  while (head!=NULL){
    cout<< head->name <<endl;
    head=head->next;
  }
}

Node* addNewPerson(Node* head)
{
  Node* person = new Node;
  cin >> person->name;

  person->next = head;
  head = person;

  return head;
}



int main() {
  Node* head = NULL;
  Node* temp = head;
  int num_ppl;
  cout << "How many people do you want to invite to the party?" << endl;
  cout << "Answer: ";
  cin >> num_ppl;

  for(int arr_i = 0; arr_i < num_ppl; arr_i++){
    cout << "Name: ";
    head = addNewPerson(head);
  }

  /*PrintLL(head);*/
  display(head);
  insert_start(head, 2);
  return 0;
}

#include <iostream>
using namespace std;
struct Node {
   int data;
   struct Node *next;
};
struct Node* head = NULL;
void insertBegin() {
    int newData;
    cin>>newData;
   struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
   newNode->data = newData;
   newNode->next = head;
   head = newNode;
}

void insertLast() {
    int newData;
    cin>>newData;
   struct Node *newNode, *temp; 
   newNode = (struct Node*) malloc(sizeof(struct Node));
   newNode->data = newData; 
   if(head == NULL){
       newNode -> next = NULL;
       head = newNode;
   }
   else {
       temp = head;
       while (temp -> next != NULL) {
            temp = temp -> next;
       }
       temp->next = newNode;  
       newNode->next = NULL;
   }
}

void deleteFirst()  
{  
    struct Node *ptr;  
    if(head == NULL)  
    {  
        cout<<"\nList is empty\n";  
    }  
    else   
    {  
        ptr = head;
        head = ptr->next;
        cout<<"\nNode deleted from the begining\n";
    }  
}

void deleteLast(){
    struct Node *ptr,*ptr1;
    if(head == NULL)  
    {  
        printf("\nlist is empty");
    }
    else if(head -> next == NULL)  
    {  
        head = NULL;
        free(head);
    }
    else  
    {  
        ptr = head;
        while(ptr->next != NULL)
        {  
            ptr1 = ptr;  
            ptr = ptr ->next;
        }
        ptr1->next = NULL;
        free(ptr);
    }
}
void display() {
   struct Node* ptr;
   ptr = head;
   while (ptr != NULL) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
   }
}

void find() {  
    struct Node *ptr;  
    int item,i=0,flag;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        cout<<"\nList is empty\n";  
    }  
    else  
    {   
        cin>>item;
        while (ptr!=NULL)
        {
            if(ptr->data == item)
            {
                cout<<"item found at"<<i+1;
                flag=0;
            }
            else
            {
                flag=1;
            }
            i++;
            ptr = ptr -> next;
        }
        if(flag==1)  
        {  
            cout<<"Item not found";
        }  
    }
}    
int main(){
    int action = 0;
    while(action != 6){
        cout<<"1.Insert at begin\n 2.Insert at end\n 3.Delete First\n 4.Delete Last\n 5.Find\n 6.display";
        cin>>action;
        switch(action){
            case 1: insertBegin();
                    break;
            case 2: insertLast();
                    break;        
            case 3: deleteFirst();
                    break;
            case 4: deleteLast();
                    break;        
            case 5: find();
                    break;
            case 6: display();
                break;        
            }
        }
    return 0;
}
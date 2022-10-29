#include<iostream>

using namespace std;

class Node 
{
    public:
    int data;
    Node* next;
//constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

void insertAthead(Node* &head, int d)
{
    Node* newNode = new Node(d);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node* &tail, int d)
{
    Node* newNode = new Node(d);
    tail->next = newNode;
    tail = newNode;
}

void insertAtPosition(Node* &head, int pos, int d)
{
    if(pos==1)
    {
        insertAthead(head, d);
    }

    else
    {
        Node * newNode = new Node(d);
        Node* prev =head;
        int t  = pos-2;

        while(t--)
        {
            prev = prev->next;
        }

        newNode->next = prev->next;
        prev->next  = newNode;
    }
}

void deleteNode(Node* &head, int target, int pos)
{

    if(head == NULL)
    {
        return;
    }
    Node* temp= head;
    Node* prev = NULL;
    if(target==temp->data && pos==1)
    {
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    else
    {
       while(temp!= NULL && temp->data != target)
       {
        prev  = temp;
        temp= temp->next;
       }

       if(temp==NULL)
       {
        cout<<"Node is not found";
        return;
       }

       prev->next = temp->next;
       temp->next = NULL;
       delete temp;
    }
}

int getLength (Node* &head )
{
    Node* temp= head;
    int len=1;
    while(temp != NULL)
    {
        len++;
        temp= temp->next;
    }
    return len;
}

Node*  reverse(Node* &head )
{

    if(head==NULL)
    {
        cout<<"List is empty";
        return head;
    }

    Node* curr = head;
    Node* prev = NULL;

    while(curr!= NULL)
    {
        Node* forward = curr->next;
        curr->next = prev;

        prev = curr;
        curr = forward;
    }
    return prev;

}

//BY USING RECURRSION
Node* reverseRec(Node* curr, Node* prev)
{
    //base case
    if(curr==NULL)
    {
        return prev;
    }
//we solved one case
    Node* forward = curr->next;
    curr->next = prev;

    //recurssion
    return  reverseRec(forward, curr);
}

Node* getMiddle(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        fast = fast-> next->next;
        slow= slow->next;
    }
    return slow;
}
// for Cheacking LL is circular or not.
bool isCircular(Node* &head)
{
    Node* temp = head;

    while(temp!= NULL)
    {
        if(temp->next==head)
        {
            return true;
        }
        temp=temp->next;
    }
    return false;
}


Node* reverseInK(Node* &head, int k)
{
    if(head==NULL)
    {
        return NULL;
    }

    Node* curr= head;
    Node* next = NULL;
    Node* prev = NULL;
    int count = 0;
    
    //reverse the node;
    while(curr!=NULL && count <k)
    {
        next =curr->next;
        curr->next = prev;
        prev= curr;
        curr = next;
        count++;
    }
//next pointer will get the head of the remaining list
    if(next!=  NULL)
    {
        //recurssion will get ans of the remaining list
        Node* rem = reverseInK(next, k);
        //connect list in step 1 and 3
        head->next = rem;
    }
    //return the entire list
    
    return prev;

}

Node* merge(Node* &head1, Node* &head2)
{
    if(head1==NULL)
    return head2;

    if(head2==NULL)
    return head1;

    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* dummy = new Node(-1);
    Node* tempDummy = dummy;

    while(temp1 != NULL && temp2 != NULL)
    {
        if(temp1->data <= temp2->data)
        {
            tempDummy->next = temp1;
            tempDummy = temp1;
            temp1 = temp1->next;
        }
        else
        {
            tempDummy->next = temp2;
            tempDummy = temp2;
            temp2 = temp2->next;
        }

        
    }

    while(temp1!=NULL)
    {
        tempDummy->next = temp1;
        tempDummy = temp1;
        temp1 = temp1->next;
    }
     while(temp2!=NULL)
    {
        tempDummy->next = temp2;
        tempDummy = temp2;
        temp2 = temp2->next;
    }

    Node* head = dummy->next;
    //delete dummy node
    dummy->next = NULL;
    delete dummy;
    return head;

    
}

int countKFromLast(Node* &head, int k)
{
    //base case
    if(head == NULL)
    return 0;

    int cnt = countKFromLast(head->next, k)+1;
    if(cnt==k)
    cout<<"Kth Node from end is"<<head->data<<endl;

    return cnt;

}
//Detect Loop and delete.
// bool detectLoop(Node* &head)
// {
//     if(head==NULL)
//     {
//         return false;

//     }

//     Node* slow = head;
//     Node* fast = head;

//     while(fast!=NULL && fast->next != NULL)
//     {
//         slow = slow->next;
//         fast = fast->next->next;

//         if(slow==fast)
//         return true;
//     }

//     return false;

// }

Node* detectLoop(Node* &head)
{
    if(head==NULL)
    {
        return NULL;

    }

    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow==fast)
        return slow;
    }

    return NULL;

}

bool detectAndDeleteLoop(Node* &head)
{
    if(head==NULL)
    return false;
    //step1. detect loop
    Node* fast = detectLoop(head);
    //step 2 beginning node
    Node* slow = head;

    while(fast!= slow)
    {
        slow = slow->next;
        fast = fast->next;
    }
// step3 remove the loop.
    Node* beginningNode  = slow;
    Node* temp  = beginningNode;
    while(temp->next != beginningNode )
    {
        temp = temp->next;
    }
    temp->next = NULL;
    return true;
}

void traverse(Node* &head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    Node* b = new Node(3);
    Node* head = b;
    Node* tail= b;
    

insertAtTail(tail,5);
insertAtTail(tail,7);
Node* temp = tail;
insertAtTail(tail,6);
insertAtTail(tail,9);
insertAtTail(tail,2);
tail->next = temp;


// traverse(head);
cout<<detectAndDeleteLoop(head)<<endl;
// insertAtPosition(head, 1,12);
 traverse(head);

// head = reverseInK(head, 3);
// traverse(head);

// deleteNode(head,7 ,2);
// traverse(head);
// cout<<getLength(head)<<endl;

// Node* middle = getMiddle(head);
// cout<<"Middle is at"<<middle->data<<endl;

// // head = reverse(head);
// // traverse(head);
// head->next = head;
// cout<<"Circular or not"<<isCircular(head)<<endl;
// Node* head1  = new Node(1);
// Node* tail1 = head1;
// insertAtTail(tail1,3);

// insertAtTail(tail1,5);
// traverse(head1);
// Node* head2 = new Node(2);
// Node* tail2 = head2;
// insertAtTail(tail2,4);

// insertAtTail(tail2,7);

// insertAtTail(tail2,9);
// insertAtTail(tail2,8);
// traverse(head2);

// head = merge(head1, head2);
// traverse(head);


// countKFromLast(head, 2);
    return 0;
}
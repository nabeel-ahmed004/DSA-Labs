#include "DList.h"
#include <iostream>

using namespace std;

DList::DList()
{
    createDummyHead();
}

DList::~DList()
{
    //Clear The list
    Clear();
    //Delete Dummy Node
    //Write your code between these lines only
    //---------------------------
    delete head;
    //---------------------------
}

// copy constructor
DList::DList(const DList& other)
{
    //Initialize current list
    createDummyHead();
    //Check if other list is empty (if empty do nothing)
    if(other.empty())
        return;
    //Iterate through all the nodes of other list
    //and add all data elements to current list
    Nodeptr other_curr = other.head->next;
    Nodeptr other_head = other.head;

    //Write your code between these lines only
    //---------------------------
    while(other_curr!=other_head)
    {
        addTail(other_curr->data);
        other_curr=other_curr->next;
    }
    //---------------------------
}

// boolean function
bool DList::empty() const
{
    if (head->next == head)
        return true;
    else
        return false;
    // CHECK IF LIST IS EMPTY OR NOT
}

// access head element
int DList::headElement() const
{
    if(!empty())
        return head->next->data;
    cerr<<"List is Empty";
}

// access tail element
int DList::tailElement() const
{
    if(!empty())
        return head->prev->data;
    cerr<<"List is Empty";
}

// access element at specific index
int DList::getAt(int idx)
{
    Nodeptr pos = goToIndex(idx);
    if(pos != NULL)
    {
    //Write your code between these lines only
    //---------------------------
        return pos->data;
    //---------------------------
    }
}

// add to the head
void DList::addHead(int newdata)
{
    //Location to insert Head Node,
    //Between DummyHead and Actual First Node
    Nodeptr curr = head->next;

    //Create New Node
    //Write your code between these lines only
    //---------------------------
    Nodeptr New;
    New = new Node;
    //---------------------------

    //Populate the new created node
    //Write your code between these lines only
    //---------------------------
    New->data=newdata;
    //---------------------------

    //Link the new created node
    //Write your code between these lines only
    //---------------------------
    New->next=curr;
    New->prev=curr->prev;
    curr->prev=New;
    (New->prev)->next=New;
    //---------------------------
}

// delete the head
void DList::delHead()
{
    //Check if list is empty ? Do nothing
    if(empty())
        return;
    //Location to delete Head Node,
    //Just after DummyHead

    Nodeptr curr = head->next;

    //Update references
    //Write your code between these lines only
    //---------------------------

    (curr->prev)->next = curr -> next;
    (curr->next)->prev = curr -> prev;


    //---------------------------

    //Free Node Memory on Heap
    //Write your code between these lines only
    //---------------------------
    delete curr;
    //---------------------------

}

// add to the tail
void DList::addTail(int newdata)
{
    //Location to insert Head Node,
    //Between DummyHead and Actual Last Node
    Nodeptr curr = head;
    //Create New Node
    Nodeptr newnode = new Node;
    //Populate the new created node
    //Write your code between these lines only
    //---------------------------
        newnode->data=newdata;
    //---------------------------

    //Link the new created node
    //Write your code between these lines only
    //---------------------------
        newnode->next=curr;
        newnode->prev=curr->prev;
        curr->prev=newnode;
        (newnode->prev)->next=newnode;
    //---------------------------

}

// delete the head
void DList::delTail()
{
    //Check if list is empty ? Do nothing
    if(empty())
        return;
    //Location to delete Tail Node,
    //Just Before DummyHead
    Nodeptr curr = head->prev;
    //Update references
    //Write your code between these lines only
    //---------------------------
    curr->prev->next=curr->next;
    curr->next->prev=curr->prev;
    //---------------------------

    //Free Node Memory on Heap
    //Write your code between these lines only
    //---------------------------
    delete curr;
    //---------------------------

}

// add to the head
void DList::addAt(int idx, int newdata)
{
    //Get node at current position
    Nodeptr curr = goToIndex(idx);
    if(curr == NULL)    //Index exceed size
        return;

    //Create New Node
    //Write your code between these lines only
    //---------------------------
    Nodeptr newnode = new Node;
    //---------------------------

    //Populate the new created node
    //Write your code between these lines only
    //---------------------------
    newnode->data=newdata;
    //---------------------------

    //Link the new created node
    //Write your code between these lines only
    //---------------------------
    newnode->next=curr;
    newnode->prev=curr->prev;
    curr->prev=newnode;
    newnode->prev->next=newnode;
    //---------------------------

}

// delete the head
void DList::delAt(int idx)
{
    //Get node at current position
    Nodeptr curr = goToIndex(idx);
    if(curr == NULL)    //Index exceed size
        return;

    //Update references
    //Write your code between these lines only
    //---------------------------
    curr->prev->next=curr->next;
    curr->next->prev=curr->prev;
    //---------------------------

    //Free Node Memory on Heap
    //Write your code between these lines only
    //---------------------------
    delete curr;
    //---------------------------


}

// utility function to get length of list
int DList::length() const
{
    //Write your code between these lines only
    //---------------------------
    int i = 0;

    Nodeptr curr = head->next;

    while (curr!=head)
    {
        curr=curr->next;
        i++;
    }

    return i;
    //---------------------------

}

// display the list
void DList::print() const
{
    //Set the starting point of list
    Nodeptr curr = head->next;
    cout << "[";
    //Iterate and display list.
    //Make sure to handle comma ',' separation is correct
    if(!empty()){
        cout << curr->data;
        curr = curr->next;
    }
    while(curr != head){
        cout << ", " << curr->data;
        curr = curr -> next;
    }
    cout << "]" << endl;

}

// Add dummy Head and populate
void DList::createDummyHead()
{
    head = new Node;
    head->next = head;
    head->prev = head;
}

// Clear The List
void DList::Clear()
{
    while(!empty())
        delHead();
}

//Go to specific index and return poiter to node at that position
//Indexing is zero based
Nodeptr DList::goToIndex(int idx)
{
    if(idx > length())
    {
        cerr<<"Error! Given index exceed the size of list";
        return NULL;
    }

    //Iterate up till given index
    Nodeptr curr = head->next;
    //Write your code between these lines only
    //---------------------------
    int i = 0;
    while (i!=idx)
    {
        curr = curr -> next;
        i++;
    }
    //---------------------------
    return curr;
}


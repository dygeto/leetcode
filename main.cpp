#include <iostream>
#include <stdlib.h>


struct node {
    int value;
    node *next;
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
        tail = NULL;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        node *temp = new node;
        for(int i = 0; i < index; i++) {
            temp = temp->next;
            if(temp == NULL)
                return -1;
        }
        return temp->value;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        node *temp = new node;
        temp->value = val;
        temp->next = NULL;
        
        if (head == NULL) {
            head = temp;
            tail = temp;
            temp = NULL;
        }
        else {
            temp->next = head;
            head=temp;
            
        }
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        node *temp = new node;
	node *pre = new node;

        temp->value = val;
        temp->next = NULL;
        
        if (head == NULL) {
            head = temp;
            tail = temp;
            temp = NULL;
        }
        else {

            tail->next = temp;
            tail=temp;


        }
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        node *temp = new node;
        node *pre = new node;
        node *cur = new node;
        temp->value = val;
        temp->next = NULL;
        cur = head;
        for(int i = 0; i < index; i++) {
            pre=cur;
            cur=cur->next;
            if(cur==NULL)
                return;
        }
        if(cur == head)
            head=temp;
        if(cur == tail) {
            tail->next = temp;
	    tail=temp;
        }
	else {
            pre->next = temp;
            temp->next = cur;
	}
        
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        node *temp = new node;
        node *pre = new node;
        node *cur = new node;
        
        cur = head;
        for(int i =0; i < index; i++) {
            pre=cur;
            cur=cur->next;
            if(cur == NULL)
                return;
        }

	if(cur->next == NULL) {
	    tail=pre;
	    pre->next=NULL;
	}
	else {
            pre->next =cur->next;
	}
        delete cur;

    }

    void printList() {
	node *temp = new node;
	temp=head;
	while(temp) {
	std::cout << temp->value << "\n";
	temp=temp->next;
    	}
    }

private:
    node *head, *tail;
};



int main() {
	MyLinkedList myList;
	myList.addAtHead(1);
	myList.addAtTail(3);
	myList.addAtIndex(1,2);
	myList.get(1);
	myList.deleteAtIndex(1);
	myList.get(1);
	myList.deleteAtIndex(5);
	myList.addAtHead(4);
	myList.addAtTail(10);
	myList.deleteAtIndex(2);
	myList.addAtIndex(2,2);
	myList.printList();
	return 1;
}


#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
class DoublleLinkList {
public:
    Node* head;

    DoublleLinkList() {
        head = nullptr;
    }
    void insertatHead(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }


    }
    void insertatTail(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
      
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = nullptr;
        
    }
    void ReverseDoublyList() {
        if (head != nullptr) {
            Node* temp = head;
            while (temp->next != nullptr) {

                temp = temp->next;
            }

            while (temp != nullptr) {
                cout << temp->data << "->";
                temp = temp->prev;
            }
            cout << "Null" << endl;
        }
        else {
            cout << "The list is empty" << endl;
        }

    }
    void CountNodes() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        cout << "The number of nodes are  " << count<<endl;
    }
    bool DeleteByValue(int key) {
       
        if (head == nullptr) {
            cout << "Empty list" << endl;
            return false;
        }

        if (head->data == key) {
            Node* del = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete del;
            return true;
        }
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key) {
                Node* del = temp;
                if (temp->prev != nullptr) {
                    temp->prev->next = temp->next;
                }
                if (temp->next != nullptr) {
                    temp->next->prev = temp->prev;
                }
                delete del;
               
                return true;
            }
            temp = temp->next;
        } 
        return false;
    }
    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "Null" << endl;
    }
    
};
Node* mergeSortedList(Node * &head1,Node* &head2) {
    Node* a1 = head1;
    Node* a2 = head2;
    Node* dm = new Node(-1);
    Node* a3 = dm;
    while (a1!=nullptr&&a2!=nullptr) {
        if (a1->data < a2->data) {
            a3->next = a1;
            a1->prev = a3;
            a1 = a1->next;
        }
        else {
            a3->next = a2;
            a2->prev = a3;
            a2 = a2->next;
            
        }
        a3 = a3->next;
    }
    while (a1 != nullptr) {
        a3->next = a1;
        a1->prev = a3;
        a1 = a1->next;
        a3 = a3->next;
    }
    while (a2 != nullptr) {
        a3->next = a2;
        a2->prev = a3;
        a2 = a2->next;
        a3 = a3->next;
    }
    return dm->next;
}
int main()
{
    DoublleLinkList L,L1,L2;
    L1.insertatTail(5);
    L.insertatTail(6);
    L.insertatTail(7);
    L.insertatTail(10);
    L1.insertatHead(4);
    L.insertatHead(3);
    L.insertatHead(2);
    L1.insertatHead(2);
    L1.insertatHead(1);
    L.DeleteByValue(3);
    L.print();
    L1.print();
    L.ReverseDoublyList();
    L.CountNodes();
    Node* newHead = mergeSortedList(L.head, L1.head);
    L2.head = newHead;
    L2.print();
    return 0;
}


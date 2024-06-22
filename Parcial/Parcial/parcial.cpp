#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node* next;
};

class CircularLinkedList
{
    node* head = NULL;
public:
    void add(int value)
    {
        if (head == NULL)
        {
            head = new node;
            head->data = value;
            head->next = head;
            return;
        }
        if (value < head->data)
        {
            node* temp = new node;
            temp->data = value;
            temp->next = head;            
            node* pass = head;
            for (; pass->next != head; pass = pass->next) {
                ;
            }
            pass->next = temp;
            head = temp;
            return;
        }
        node* current = head;
        for (; current->next != head; current = current->next)
        {
            if (current->next->data > value)
            {
                node* temp = new node;
                temp->data = value;
                temp->next = current->next;
                current->next = temp;
                return;
            }
            
        }
        if (current->next == head)
        {
            node* temp = new node;
            temp->data = value;
            temp->next = current->next;
            current->next = temp;
            return;
        }
        
    }

    void del(int value)
    {
        node*current = head;
        if (head->data == value)
        {
            node* temp = head;
            for (; current->next != head; current = current->next) {
                ;
            }
            current->next = head->next;
            head = head->next;
            delete temp;
            return;
		}
        for (; current->next != head; current = current->next)
        {
            if (current->next->data == value)
            {
                node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
        }
    }

    void print()
    {
        int cont = 0;
        node* ptr = head;
        cout << "head->";
        while (head && cont < 1)
        {
            cout << ptr->data << " -> ";
            ptr = ptr->next;
            if (ptr == head) cont++;
        }
        if (head) cout << ptr->data;
        cout << " <- head \n ";

    }
};

int main()
{
    int ADD[10] = { 2,4,6,8,10,1,3,5,7,9 };
    int DEL[10] = { 9,7,5,3,1,10,8,6,4,2 };
    CircularLinkedList CLL;
    for (int i = 0; i < 10; i++)
    {
        cout << "ADD " << ADD[i] << endl;
        CLL.add(ADD[i]);
        CLL.print();
    }

    for (int i = 0; i < 10; i++)
    {
        cout << "DEL " << DEL[i] << endl;
        CLL.del(DEL[i]);
        CLL.print();
    }
}

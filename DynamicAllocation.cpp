#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkList
{
public:
    Node *head;
    int size;

    LinkList()
    {
        this->head = NULL;
        this->size = -1;
    }

    void InsertAtfront(int data)
    {
        Node *newNode = new Node(data);
        if (this->head == NULL)
        {
            this->head = newNode;
        }
        else
        {
            newNode->next = this->head;
            this->head = newNode;
        }
        this->size++;
    }

    void searchkey(int key)
    {
        cout << endl;
        Node *current = head;
        int position = 0;

        while (current)
        {
            if (current->data == key)
            {
                cout << endl;
                cout << key << " " << "Found the Position is " << " " << position << endl;
                return;
            }
            current = current->next;
            position++;
        }
    }

    void deleteNode(int key)
    {
        if (!head)
            return;

        if (head->data == key)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node *current = head;
        while (current->next && current->next->data != key)
        {
            current = current->next;
        }

        if (current->next)
        {
            Node *temp = current->next;
            current->next = temp->next;
            delete temp;
            cout << key << " " << "Deleting The Value!!!"<<endl;
        }
    }

    void reverse()
    {
        Node *prev = nullptr;
        Node *current = head;

        while (current)
        {
            Node *next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        cout << endl;
        cout << endl;
        cout << "List Reveresed" << endl;
    }
    void displayList()
    {

        Node *temp = this->head;
        cout << "LinkList:- ";

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{

    LinkList list;
    int choice;

    do
    {
        cout << endl;
        cout<<"*********** Dynamic DataStructure ***********"<<endl;
        cout<<"1. Insert at front"<<endl;
        cout<<"2. Search"<<endl;
        cout<<"3. Delete"<<endl;
        cout<<"4. Reverse"<<endl;
        cout<<"5. Display List"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"**********************************************"<<endl;
        cout<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        cout<<endl;

        switch (choice)
        {
        case 1:             
            int data;
            cout << "Enter data to insert at front: ";
            cin >> data;
            list.InsertAtfront(data);
            list.displayList();
            break;

        case 2:
            int serIndex;
            cout << "Enter index to search: ";
            cin >> serIndex;
            list.searchkey(serIndex);
            cout << "After searching: ";
            list.displayList();
            break;

        case 3:
            int delIndex;
            cout << "Enter index to delete: ";
            cin >> delIndex;
            list.deleteNode(delIndex);
            cout << "After Deleting: ";
            list.displayList();
            break;

        case 4:
            list.reverse();
            cout << "After Reversing: ";
            list.displayList();
            break;

        case 5:
            list.displayList();
            break;

        case 0:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again:(" << endl;
            break;
        }
    } while (choice != 0);
    
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
};

ListNode *appendNode(ListNode *&list, int value)
{
    // create a new node
    ListNode *newNode = new ListNode;
    newNode->data = value;
    newNode->next = NULL;

    if (list == NULL)
    {
        list = newNode;
    }
    else
    {
        ListNode *tNode = list;

        while (tNode->next != NULL)
        {
            tNode = tNode->next;
        }
        tNode->next = newNode;
    }
    return list;
}

ListNode *insertAtHead(ListNode *list, int value)
{
    // creating a new node
    ListNode *newNode = new ListNode;
    newNode->data = value;
    newNode->next = NULL;

    if (list == NULL)
    {
        list = newNode;
    }
    else
    {
        newNode->next = list;
        list = newNode;
    }
    return list;
}

void displayList(ListNode *list)
{

    ListNode *tNode = list;

    while (tNode != NULL)
    {
        cout << tNode->data << "->";
        tNode = tNode->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    ListNode *l1 = NULL;

    appendNode(l1, 10);
    appendNode(l1, 20);
    appendNode(l1, 30);

    displayList(l1);

    displayList(insertAtHead(l1, 100));

    return 0;
}
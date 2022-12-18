// 20. Move last element to front of a given Linked List

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
};

void appendNode(ListNode *&list, char value)
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
        ListNode *tNode = list;

        while (tNode->next != NULL)
        {
            tNode = tNode->next;
        }
        tNode->next = newNode;
    }
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

ListNode *moveLastToFront(ListNode *&list)
{
    ListNode *pNode = NULL;
    ListNode *tNode = list;

    while (tNode->next != NULL)
    {
        pNode = tNode;
        tNode = tNode->next;
    }
    pNode->next = NULL;
    tNode->next = list;
    list = tNode;

    return list;
}

int main()
{
    ListNode *l1 = NULL;

    appendNode(l1, 1);
    appendNode(l1, 2);
    appendNode(l1, 3);
    appendNode(l1, 4);
    appendNode(l1, 5);

    displayList(l1);
    displayList(moveLastToFront(l1));

    return 0;
}
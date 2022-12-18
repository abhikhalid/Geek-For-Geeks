// 63. Delete last occurrence of an item from linked list

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
};

void appendNode(ListNode *&list, int value)
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

ListNode *deleteLast(ListNode *&list, int value)
{
    ListNode *pNode = NULL;
    ListNode *tNode = list;

    while (tNode != NULL)
    {
        if (tNode->data == value)
        {
            pNode = tNode;
        }
        tNode = tNode->next;
    }

    tNode = pNode;

    while (tNode->next != NULL)
    {

        swap(tNode->data, tNode->next->data);
        pNode = tNode;
        tNode = tNode->next;
    }
    pNode->next = NULL;
    delete tNode;

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
    appendNode(l1, 4);
    appendNode(l1, 4);

    displayList(l1);

    displayList(deleteLast(l1, 4));

    return 0;
}
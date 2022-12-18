// 64. Delete a Linked List node at a given position

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

ListNode *deleteAtPosition(ListNode *list, int position)
{
    // base case
    if (list == NULL)
        return NULL;

    ListNode *pNode = NULL;
    ListNode *tNode = list;

    int count = 0;

    while (tNode != NULL && count != position)
    {
        count++;
        pNode = tNode;
        tNode = tNode->next;
    }
    if (pNode == NULL)
    {
        list = list->next;
        tNode->next = NULL;
        delete tNode;
    }
    else
    {
        pNode->next = tNode->next;
        delete tNode;
    }

    return list;
}

int main()
{
    ListNode *l1 = NULL;

    appendNode(l1, 8);
    appendNode(l1, 2);
    appendNode(l1, 3);
    appendNode(l1, 1);
    appendNode(l1, 7);

    displayList(l1);

    displayList(deleteAtPosition(l1, 0));

    return 0;
}
// 33. Delete alternate nodes of a Linked List

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

void deleteAlternate(ListNode *list)
{
    ListNode *pNode = list;
    ListNode *tNode = list->next;

    while (pNode != NULL and tNode != NULL)
    {

        pNode->next = tNode->next;
        pNode = tNode->next;
        delete tNode;
        if (pNode != NULL)
        {
            tNode = pNode->next;
        }
    }
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
    deleteAlternate(l1);
    displayList(l1);

    return 0;
}
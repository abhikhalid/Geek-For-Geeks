
// 21. Intersection of two Sorted Linked Lists

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

void reverseAList(ListNode *&list, ListNode *pNode, ListNode *tNode)
{

    if (tNode == NULL)
        return;

    if (tNode->next == NULL)
    {
        list = tNode;
    }

    reverseAList(list, tNode, tNode->next);
    tNode->next = pNode;
    if (pNode)
    {
        pNode->next = NULL;
    }
}

ListNode *reverseList(ListNode *&list)
{

    reverseAList(list, NULL, list);

    return list;
}

// Reverse a linked list by Iterative Method

ListNode *reverseListIteratively(ListNode *&list)
{
    ListNode *pNode = NULL;
    ListNode *next = NULL;
    ListNode *tNode = list;

    while (tNode != NULL)
    {
        next = tNode->next;
        tNode->next = pNode;
        pNode = tNode;
        tNode = next;
    }
    list = pNode;

    return list;
}

int main()
{
    ListNode *l1 = NULL;

    appendNode(l1, 1);
    appendNode(l1, 2);
    appendNode(l1, 3);
    appendNode(l1, 4);

    displayList(l1);
    // displayList(reverseList(l1));
    displayList(reverseListIteratively(l1));

    return 0;
}
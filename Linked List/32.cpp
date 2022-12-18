// 32. Alternate Odd and Even Nodes in a Singly Linked List

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

ListNode *alternateEvenOddList(ListNode *&list)
{
    ListNode *evenStart = NULL;
    ListNode *evenEnd = NULL;

    ListNode *oddStart = NULL;
    ListNode *oddEnd = NULL;

    ListNode *tNode = list;

    while (tNode != NULL)
    {
        if (tNode->data % 2 == 0)
        {
            if (evenStart == NULL)
            {
                evenStart = tNode;
                evenEnd = evenStart;
            }
            else
            {
                evenEnd->next = tNode;
                evenEnd = tNode;
            }
        }
        else
        {
            if (oddStart == NULL)
            {
                oddStart = tNode;
                oddEnd = oddStart;
            }
            else
            {
                oddEnd->next = tNode;
                oddEnd = tNode;
            }
        }

        tNode = tNode->next;
    }
    oddEnd->next = NULL;
    evenEnd->next = NULL;

    ListNode *pNode = oddStart;
    tNode = oddStart->next;

    ListNode *evenTNode = evenStart;

    while (tNode != NULL)
    {
        pNode->next = evenTNode;
        ListNode *t = evenTNode->next;
        evenTNode->next = tNode;
        evenTNode = t;

        pNode = tNode;
        tNode = tNode->next;
    }

    displayList(evenStart);
}

int main()
{
    ListNode *l1 = NULL;

    appendNode(l1, 11);
    appendNode(l1, 20);
    appendNode(l1, 40);
    appendNode(l1, 55);
    appendNode(l1, 77);
    appendNode(l1, 80);

    displayList(l1);

    alternateEvenOddList(l1);

    // displayList(alternateEvenOddList(l1));

    return 0;
}
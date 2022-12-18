
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

ListNode *segregateEvenOdd(ListNode *&list)
{
    ListNode *eventStart = NULL;
    ListNode *evenEnd = NULL;
    ListNode *oddStart = NULL;
    ListNode *oddEnd = NULL;

    ListNode *tNode = list;

    while (tNode != NULL)
    {
        if (tNode->data % 2 == 0)
        {
            if (eventStart == NULL)
            {
                eventStart = tNode;
                evenEnd = eventStart;
            }
            else
            {
                evenEnd->next = tNode;
                evenEnd = evenEnd->next;
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
                oddEnd = oddEnd->next;
            }
        }

        tNode = tNode->next;
    }

    if (oddEnd == NULL || evenEnd == NULL)
        return list;

    evenEnd->next = oddStart;
    oddEnd->next = NULL;
    list = eventStart;

    return list;
}

int main()
{
    ListNode *l1 = NULL;

    appendNode(l1, 17);
    appendNode(l1, 15);
    appendNode(l1, 8);
    appendNode(l1, 12);
    appendNode(l1, 10);
    appendNode(l1, 5);
    appendNode(l1, 4);
    appendNode(l1, 1);
    appendNode(l1, 7);
    appendNode(l1, 6);

    displayList(l1);

    displayList(segregateEvenOdd(l1));

    return 0;
}
// 77. Move all occurrences of an element to end in a linked list

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

ListNode *moveOccurenceToEnd(ListNode *list, int key)
{
    // find the tail of the list

    ListNode *tail = list;
    ListNode *tailHead = NULL;

    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    tailHead = tail;

    ListNode *pNode = NULL;
    ListNode *tNode = list;

    while (tNode != tailHead)
    {
        if (tNode->data == key)
        {
            if (pNode == NULL)
            {
                list = list->next;
                tNode->next = NULL;
                tail->next = tNode;
                tail = tNode;
                tNode = list;
                continue;
            }

            pNode->next = tNode->next;
            tNode->next = NULL;
            tail->next = tNode;
            tail = tNode;
            tNode = pNode->next;
            continue;
        }
        pNode = tNode;
        tNode = tNode->next;
    }

    return list;
}

int main()
{
    // ListNode *l1 = NULL;

    // appendNode(l1, 1);
    // appendNode(l1, 2);
    // appendNode(l1, 2);
    // appendNode(l1, 4);
    // appendNode(l1, 3);

    // displayList(l1);

    ListNode *l1 = NULL;

    appendNode(l1, 6);
    appendNode(l1, 6);
    appendNode(l1, 7);
    appendNode(l1, 6);
    appendNode(l1, 3);
    appendNode(l1, 10);

    displayList(l1);

    displayList(moveOccurenceToEnd(l1, 6));

    return 0;
}
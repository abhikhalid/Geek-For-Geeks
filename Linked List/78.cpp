// 78. Remove all occurrences of duplicates from a sorted Linked List

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

ListNode *removeAllOccurenceOfDuplicate(ListNode *list)
{
    ListNode *pNode = NULL;
    ListNode *tNode = list;

    while (tNode != NULL)
    {
        if (tNode->next != NULL and tNode->data == tNode->next->data)
        {
            int x = tNode->data;

            tNode = tNode->next->next;

            while (tNode != NULL and tNode->data == x)
            {
                tNode = tNode->next;
            }

            if (pNode == NULL)
            {
                list = tNode;
            }
            else
            {
                pNode->next = tNode;
            }
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

    // appendNode(l1, 23);
    // appendNode(l1, 28);
    // appendNode(l1, 28);
    // appendNode(l1, 35);
    // appendNode(l1, 49);
    // appendNode(l1, 49);
    // appendNode(l1, 53);
    // appendNode(l1, 53);

    ListNode *l1 = NULL;

    appendNode(l1, 11);
    appendNode(l1, 11);
    appendNode(l1, 11);
    appendNode(l1, 11);
    appendNode(l1, 11);
    appendNode(l1, 11);
    appendNode(l1, 75);
    appendNode(l1, 75);

    displayList(l1);

    displayList(removeAllOccurenceOfDuplicate(l1));

    return 0;
}
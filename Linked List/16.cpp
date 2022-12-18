// 15. Function to check if a singly linked list is palindrome

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

ListNode *removeDuplicatesFromSortedList(ListNode *&list)
{
    ListNode *pNode = NULL;
    ListNode *tNode = list;

    while (tNode != NULL)
    {
        if (pNode != NULL && pNode->data == tNode->data)
        {
            pNode->next = tNode->next;
            delete tNode;
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
    ListNode *l1 = NULL;

    appendNode(l1, 11);
    appendNode(l1, 11);
    appendNode(l1, 11);
    appendNode(l1, 21);
    appendNode(l1, 43);
    appendNode(l1, 43);

    displayList(l1);

    displayList(removeDuplicatesFromSortedList(l1));

    return 0;
}
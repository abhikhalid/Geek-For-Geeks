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

// iterative approach

bool isIdentical(ListNode *list1, ListNode *list2)
{
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data != list2->data)
            return false;

        list1 = list1->next;
        list2 = list2->next;
    }
    if (list1 != NULL || list2 != NULL)
        return false;
    return true;
}

// recursive approach

bool isListIdentical(ListNode *list1, ListNode *list2)
{
    // base case
    if (list1 == NULL && list2 == NULL)
        return true;

    if ((list1 == NULL and list2 != NULL) or (list1 != NULL and list2 == NULL))
        return false;

    if (list1->data != list2->data)
        return false;

    return isListIdentical(list1->next, list2->next);
}

int main()
{
    ListNode *l1 = NULL;
    ListNode *l2 = NULL;

    appendNode(l1, 1);
    appendNode(l1, 2);
    appendNode(l1, 3);
    appendNode(l1, 4);

    appendNode(l2, 1);
    appendNode(l2, 2);
    appendNode(l2, 3);
    appendNode(l2, 4);
    appendNode(l2, 5);

    if (isListIdentical(l1, l2))
    {
        cout << "Identical" << endl;
    }
    else
    {
        cout << "Not Identical" << endl;
    }

    // displayList(l1);

    return 0;
}
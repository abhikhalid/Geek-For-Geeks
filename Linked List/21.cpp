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

ListNode *getIntersectionOfTwoList(ListNode *l1, ListNode *l2)
{
    // base case
    if (l1 == NULL || l2 == NULL)
        return NULL;

    // creating dummy node
    ListNode *resultList = NULL;

    while (l1 != NULL && l2 != NULL)
    {
        if (l1->data == l2->data)
        {
            appendNode(resultList, l1->data);

            l1 = l1->next;
            l2 = l2->next;
        }
        else if (l1->data < l2->data)
        {
            l1 = l1->next;
        }
        else
        {
            l2 = l2->next;
        }
    }

    displayList(resultList);

    return resultList;
}

ListNode *getIntersectionOfTwoListRecursive(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL || l2 == NULL)
        return NULL;

    if (l1->data < l2->data)
    {
        return getIntersectionOfTwoListRecursive(l1->next, l2);
    }
    else if (l1->data > l2->data)
    {
        return getIntersectionOfTwoListRecursive(l1, l2->next);
    }

    ListNode *resultList = new ListNode;
    resultList->data = l1->data;

    resultList->next = getIntersectionOfTwoListRecursive(l1->next, l2->next);

    return resultList;
}

int main()
{
    ListNode *l1 = NULL;
    ListNode *l2 = NULL;

    appendNode(l1, 1);
    appendNode(l1, 2);
    appendNode(l1, 3);
    appendNode(l1, 4);
    appendNode(l1, 6);

    appendNode(l2, 2);
    appendNode(l2, 4);
    appendNode(l2, 6);
    appendNode(l2, 8);

    displayList(l1);
    displayList(l2);
    displayList(getIntersectionOfTwoListRecursive(l1, l2));
    // getIntersectionOfTwoList(l1, l2);

    return 0;
}
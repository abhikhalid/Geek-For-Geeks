// 86. Merge a linked list into another linked list at alternate positions

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
};

ListNode *appendNode(ListNode *&list, int value)
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

    return list;
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

ListNode *mergeListAlternate(ListNode *list1, ListNode *list2)
{

    ListNode *pNode = list1;
    ListNode *tNode = list1->next;

    while (pNode->next != NULL && list2 != NULL)
    {
        ListNode *toBeMerged = list2;
        list2 = list2->next;
        toBeMerged->next = NULL;

        pNode->next = toBeMerged;
        toBeMerged->next = tNode;

        pNode = tNode;
        tNode = tNode->next;
    }

    if (list2 != NULL)
    {
        ListNode *toBeMerged = list2;
        list2 = list2->next;
        toBeMerged->next = NULL;

        pNode->next = toBeMerged;
    }

    return list1;
}

int main()
{
    // ListNode *l1 = NULL;

    // appendNode(l1, 1);
    // appendNode(l1, 2);
    // appendNode(l1, 3);

    // ListNode *l2 = NULL;

    // appendNode(l2, 4);
    // appendNode(l2, 5);
    // appendNode(l2, 6);
    // appendNode(l2, 7);
    // appendNode(l2, 8);

    // displayList(l1);
    // displayList(l2);

    ListNode *l1 = NULL;

    appendNode(l1, 5);
    appendNode(l1, 7);
    appendNode(l1, 17);
    appendNode(l1, 13);
    appendNode(l1, 11);

    ListNode *l2 = NULL;

    appendNode(l2, 12);
    appendNode(l2, 10);
    appendNode(l2, 2);
    appendNode(l2, 4);
    appendNode(l2, 6);

    displayList(l1);
    displayList(l2);

    displayList(mergeListAlternate(l1, l2));

    return 0;
}
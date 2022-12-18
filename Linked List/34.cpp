// 34. Alternating split of a given Singly Linked List | Set 1

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

void alternateTwoList(ListNode *list)
{
    ListNode *list1Head = NULL;
    ListNode *list1Tail = NULL;

    ListNode *list2Head = NULL;
    ListNode *list2Tail = NULL;

    ListNode *tNode = list;
    int count = 1;

    while (tNode != NULL)
    {
        if (count % 2 == 0)
        {
            if (list2Head == NULL)
            {
                list2Head = tNode;
                list2Tail = list2Head;
            }
            else
            {
                list2Tail->next = tNode;
                list2Tail = tNode;
            }
        }
        else
        {
            if (list1Head == NULL)
            {
                list1Head = tNode;
                list1Tail = list1Head;
            }
            else
            {
                list1Tail->next = tNode;
                list1Tail = tNode;
            }
        }

        count++;
        tNode = tNode->next;
    }

    list1Tail->next = list2Tail->next = NULL;

    displayList(list1Head);
    displayList(list2Head);
}

int main()
{
    ListNode *l1 = NULL;

    appendNode(l1, 0);
    appendNode(l1, 1);
    appendNode(l1, 0);
    appendNode(l1, 1);
    appendNode(l1, 0);
    appendNode(l1, 1);

    displayList(l1);

    alternateTwoList(l1);

    return 0;
}
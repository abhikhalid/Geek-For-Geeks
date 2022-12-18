// 79. Remove every k-th node of the linked list

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

ListNode *removeEveryKthNode(ListNode *&list, int k)
{
    int tempCount = k;

    ListNode *pNode = NULL;
    ListNode *tNode = list;

    while (tNode != NULL)
    {
        tempCount--;

        if (tempCount == 0)
        {
            tempCount = k;

            // delete the head node
            if (pNode == NULL)
            {
                list = list->next;
                tNode->next = NULL;
                delete tNode;
                tNode = list;
                continue;
            }
            else
            {
                pNode->next = tNode->next;
                delete tNode;
                tNode = pNode->next;
                continue;
            }
        }

        pNode = tNode;
        tNode = tNode->next;
    }
    return list;
}

int main()
{
    ListNode *l1 = NULL;

    appendNode(l1, 1);
    appendNode(l1, 2);
    appendNode(l1, 3);
    appendNode(l1, 4);
    appendNode(l1, 5);
    appendNode(l1, 6);
    appendNode(l1, 7);
    appendNode(l1, 8);

    displayList(l1);

    displayList(removeEveryKthNode(l1, 3));

    return 0;
}
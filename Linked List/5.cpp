// Delete a Linked List node at a given position

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

ListNode *deleteAtSpecificPosition(ListNode *&list, int position)
{
    ListNode *pNode = NULL;
    ListNode *tNode = list;

    int count = 0;

    while (tNode != NULL && count != position)
    {
        pNode = tNode;
        tNode = tNode->next;
        count++;
    }
    if (position > count)
    {
        return;
    }
    else if (position == 0)
    {
        list = list->next;
        delete tNode;
    }
    else
    {
        pNode->next = tNode->next;
        delete tNode;
    }

    return list;
}

int main()
{
    ListNode *l1 = NULL;

    appendNode(l1, 10);
    appendNode(l1, 20);
    appendNode(l1, 30);

    displayList(l1);

    displayList(deleteAtSpecificPosition(l1, 2));

    return 0;
}
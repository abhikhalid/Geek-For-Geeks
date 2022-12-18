#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
};

ListNode *appendNode(ListNode *&list, int value)
{
    // create a new node
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

void deleteNode(ListNode *&list, int value)
{

    ListNode *pNode = NULL;
    ListNode *tNode = list;

    while (tNode != NULL && tNode->data != value)
    {
        pNode = tNode;
        tNode = tNode->next;
    }

    // delete head Node
    if (pNode == NULL)
    {
        list = list->next;
        delete tNode;
    }
    else
    {
        pNode->next = tNode->next;
        delete tNode;
    }
}

int main()
{
    ListNode *l1 = NULL;

    appendNode(l1, 10);
    appendNode(l1, 20);
    appendNode(l1, 30);

    displayList(l1);

    return 0;
}
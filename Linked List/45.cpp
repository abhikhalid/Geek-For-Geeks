// 45. Delete N nodes after M nodes of a linked list

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

ListNode *deleteNnodesAfterMnodes(ListNode *&list, int n, int m)
{
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

    displayList(deleteNnodesAfterMnodes(l1, n, m));

    return 0;
}
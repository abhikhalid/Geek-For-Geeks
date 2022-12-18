// 55. Compare two strings represented as linked lists

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    char data;
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

int compareTwoString(ListNode *list1, ListNode *list2)
{
    while (list1 != NULL and list2 != NULL)
    {
        if (list1->data > list2->data)
            return 1;
        else if (list1->data < list2->data)
            return -1;

        list1 = list1->next;
        list2 = list2->next;
    }
    if (list1 == NULL and list2 != NULL)
        return -1;
    else if (list1 != NULL and list2 == NULL)
        return 1;
    else
        return 0;
}

int main()
{
    ListNode *l1 = NULL;

    appendNode(l1, 'g');
    appendNode(l1, 'e');
    appendNode(l1, 'e');
    appendNode(l1, 'k');
    appendNode(l1, 's');
    // appendNode(l1, 'a');

    ListNode *l2 = NULL;

    appendNode(l2, 'g');
    appendNode(l2, 'e');
    appendNode(l2, 'e');
    appendNode(l2, 'k');
    appendNode(l2, 's');
    // appendNode(l2, 'b');

    displayList(l1);
    displayList(l2);

    cout << compareTwoString(l1, l2) << endl;

    return 0;
}
// 88. Delete middle of linked list

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

ListNode *deleteMiddle(ListNode *list)
{
    ListNode *beforeSlow = NULL;
    ListNode *slow = list;
    ListNode *fast = list->next;

    while (fast != NULL)
    {
        fast = fast->next;

        if (fast)
        {
            fast = fast->next;
        }

        beforeSlow = slow;
        slow = slow->next;
    }

    // list has only 1 nodes
    if (beforeSlow == NULL)
        return NULL;

    // when list has only 2 nodes
    if (slow == list)
    {
        list = list->next;
        return list;
    }

    // list has more than 2 nodes
    beforeSlow->next = slow->next;
    delete slow;

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

    displayList(l1);

    displayList(deleteMiddle(l1));

    return 0;
}
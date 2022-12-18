// 17. Remove duplicates from an unsorted linked list

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

ListNode *removeDuplicates(ListNode *&list)
{
    unordered_set<int> seen;

    ListNode *pNode = NULL;
    ListNode *tNode = list;

    while (tNode != NULL)
    {
        // if current element is seen before
        if (seen.find(tNode->data) != seen.end())
        {
            pNode->next = tNode->next;
            delete tNode;
        }
        else
        {
            seen.insert(tNode->data);
            pNode = tNode;
        }

        tNode = pNode->next;
    }

    return list;
}

int main()
{
    ListNode *l1 = NULL;

    appendNode(l1, 12);
    appendNode(l1, 11);
    appendNode(l1, 12);
    appendNode(l1, 21);
    appendNode(l1, 41);
    appendNode(l1, 43);
    appendNode(l1, 21);

    displayList(l1);

    displayList(removeDuplicates(l1));

    return 0;
}
// 85. Merge two sorted lists (in-place)

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

ListNode *mergeList(ListNode *list1, ListNode *list2)
{

    // base case
    if (list1 == NULL or list2 == NULL)
        return NULL;

    // creating a dummy node
    ListNode *resultList = NULL;
    appendNode(resultList, -1);
    
    ListNode *resultListTail = resultList;

    while (list1 != NULL and list2 != NULL)
    {
        if (list1->data < list2->data)
        {
            resultListTail->next = list1;
            resultListTail = list1;
            list1 = list1->next;
        }
        else if (list1->data > list2->data)
        {
            resultListTail->next = list2;
            resultListTail = list2;
            list2 = list2->next;
        }
        else
        {
            resultListTail->next = list1;
            resultListTail = list1;
            list1 = list1->next;
            list2 = list2->next;
        }
    }

    if (list1 == NULL and list2 != NULL)
    {
        while (list2 != NULL)
        {
            resultListTail->next = list2;
            resultListTail = list2;
            list2 = list2->next;
        }
    }
    if (list2 == NULL and list1 != NULL)
    {
        while (list1 != NULL)
        {
            resultListTail->next = list1;
            resultListTail = list1;
            list1 = list1->next;
        }
    }

    resultListTail->next = NULL;

    resultList = resultList->next;

    return resultList;
}

int main()
{
    ListNode *l1 = NULL;

    appendNode(l1, 5);
    appendNode(l1, 10);
    appendNode(l1, 15);

    ListNode *l2 = NULL;

    appendNode(l2, 2);
    appendNode(l2, 3);
    appendNode(l2, 20);

    displayList(l1);
    displayList(l2);

    displayList(mergeList(l1, l2));

    return 0;
}
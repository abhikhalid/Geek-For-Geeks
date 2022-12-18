// 58.Add 1 to a number represented as linked list

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

ListNode *reverseList(ListNode *&list)
{

    ListNode *next = NULL;
    ListNode *pNode = NULL;
    ListNode *tNode = list;

    while (tNode != NULL)
    {
        next = tNode->next;
        tNode->next = pNode;
        pNode = tNode;
        tNode = next;
    }

    list = pNode;

    return list;
}

ListNode *add1ToTheList(ListNode *&list)
{
    ListNode *rList = reverseList(list);

    ListNode *resultList = NULL;

    int carry = 0;
    int add = 1;

    while (rList != NULL)
    {

        appendNode(resultList, ((rList->data + add + carry) % 10));

        carry = (rList->data + 1) / 10;
        add = 0;

        rList = rList->next;
    }

    resultList = reverseList(resultList);

    return resultList;
}

int main()
{
    ListNode *l1 = NULL;

    appendNode(l1, 1);
    appendNode(l1, 9);
    appendNode(l1, 9);
    appendNode(l1, 9);

    displayList(l1);

    // displayList(reverseList(l1));

    // displayList(add1ToTheList(l1));

    displayList(add1ToTheList(l1));

    return 0;
}
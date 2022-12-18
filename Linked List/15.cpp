// 15. Function to check if a singly linked list is palindrome

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

void reverseAList(ListNode *&list, ListNode *pNode, ListNode *tNode)
{
    if (tNode == NULL)
        return;

    if (tNode->next == NULL)
    {
        list = tNode;
    }

    reverseAList(list, tNode, tNode->next);

    if (pNode != NULL)
    {
        tNode->next = pNode;
        pNode->next = NULL;
    }
}

ListNode *reverseList(ListNode *&list)
{

    reverseAList(list, NULL, list);

    return list;
}

ListNode *getAfterMiddle(ListNode *&list)
{
    ListNode *slow = list;
    ListNode *fast = list->next;

    while (fast != NULL && fast->next != NULL)
    {

        fast = fast->next;

        if (fast != NULL)
        {
            fast = fast->next;
        }

        slow = slow->next;
    }
    ListNode *tNode = slow->next;
    slow->next = NULL;

    return tNode;
}

bool isPalindrome(ListNode *list)
{
    ListNode *list2 = getAfterMiddle(list);

    list2 = reverseList(list2);

    displayList(list);
    displayList(list2);

    while (list != NULL && list2 != NULL)
    {
        if (list->data != list2->data)
            return false;
        list = list->next;
        list2 = list2->next;
    }

    return true;
}

int main()
{
    ListNode *l1 = NULL;

    appendNode(l1, 'R');
    appendNode(l1, 'A');
    appendNode(l1, 'D');
    appendNode(l1, 'A');
    appendNode(l1, 'A');
    appendNode(l1, 'R');

    displayList(l1);

    if (isPalindrome(l1))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
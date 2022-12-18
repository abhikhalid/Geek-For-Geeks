// 77. Move all occurrences of an element to end in a linked list

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

// iterative approach
int sumOfLastNnodes(ListNode *list, int n)
{
    int sum = 0;

    ListNode *slow = list;
    ListNode *fast = list;

    int count = 0;

    while (count != n)
    {
        fast = fast->next;
        count++;
    }

    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    while (slow != NULL)
    {
        sum += slow->data;
        slow = slow->next;
    }
    return sum;
}

// recursive approach
void sumOfLastNNodes(ListNode *list, int &n, int &sum)
{
    if (list == NULL)
        return;

    sumOfLastNNodes(list->next, n, sum);

    if (n > 0)
    {
        sum = sum + list->data;
        n--;
    }
}

int sumOfLastN_NodesUtil(ListNode *list, int n)
{
    if (n <= 0)
        return -1;

    int sum = 0;

    sumOfLastNNodes(list, n, sum);

    return sum;
}

// iterative approach with stack
int sumOfLastNnode(ListNode *list, int n)
{
    stack<int> st;
    int sum = 0;

    while (list != NULL)
    {
        st.push(list->data);
        list = list->next;
    }

    while (n != 0)
    {
        sum += st.top();
        st.pop();
        n--;
    }
    return sum;
}

//(Reversing the linked list):

int getSumOfLastNthNode(ListNode *list, int n)
{

    ListNode *prev = NULL;
    ListNode *next = NULL;
    ListNode *current = list;

    int sum = 0;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    list = prev;

    while (list != NULL && n != 0)
    {
        sum += list->data;
        list = list->next;
        n--;
    }
    return sum;
}

int main()
{
    ListNode *l1 = NULL;

    // appendNode(l1, 10);
    // appendNode(l1, 6);
    // appendNode(l1, 8);
    // appendNode(l1, 4);
    // appendNode(l1, 12);

    // displayList(l1);

    // cout << sumOfLastNnodes(l1, 2);

    appendNode(l1, 15);
    appendNode(l1, 7);
    appendNode(l1, 9);
    appendNode(l1, 5);
    appendNode(l1, 16);
    appendNode(l1, 14);

    displayList(l1);

    cout << sumOfLastNnodes(l1, 4) << endl;
    cout << sumOfLastN_NodesUtil(l1, 4) << endl;
    cout << sumOfLastNnode(l1, 4) << endl;
    cout << getSumOfLastNthNode(l1, 4) << endl;

    // displayList(moveOccurenceToEnd(l1, 2));

    return 0;
}
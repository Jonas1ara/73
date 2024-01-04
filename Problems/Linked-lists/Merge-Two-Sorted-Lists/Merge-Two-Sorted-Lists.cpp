﻿#include <iostream>

// Using a part of the merge sort algorithm - Time: O(m + n)

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *a, ListNode *b)
    {
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        head->next = a;

        while (p->next != nullptr && b != nullptr)
        {
            if (p->next->val > b->val)
            {
                ListNode *node = b;
                b = b->next;
                node->next = p->next;
                p->next = node;
            }
            p = p->next;
        }

        if (b != nullptr)
        {
            p->next = b;
        }

        return head->next;
    }
};

void printList(ListNode *node)
{
    std::cout << "[";
    while (node != nullptr)
    {
        std::cout << node->val;
        node = node->next;
        if (node != nullptr)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]";
}

int main()
{
    ListNode *list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode *list2 = new ListNode(1, new ListNode(3, new ListNode(4)));

    std::cout << "Input: list 1 = ";
    printList(list1);

    std::cout << ", list 2 = ";
    printList(list2);
    std::cout << std::endl;

    Solution sol;
    ListNode *mergedList = sol.mergeTwoLists(list1, list2);

    std::cout << "Output: ";
    printList(mergedList);
    std::cout << std::endl;

    delete mergedList;

    return 0;
}

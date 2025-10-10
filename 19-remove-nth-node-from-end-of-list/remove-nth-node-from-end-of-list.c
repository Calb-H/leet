/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 // removes nth node from 1 before the list
 /*
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {

    struct ListNode fake_head = {0, head};
    struct ListNode* prev = &fake_head;

    while (n > 1) {
        if (prev->next)
            prev = prev->next;
        else return head;
        --n;
    }

    if (prev->next) {
        prev->next = prev->next->next;
    }

    return head;
}
*/

// I can't read
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {

    int n_to_end = 1;
    struct ListNode* cur_node = head;
    while (cur_node->next) {
        ++n_to_end;
        cur_node = cur_node->next;
    }

    if (n_to_end < n)
        return head;
    else if (n_to_end == n) {
        return head->next;
    }

    n_to_end -= n; // now represent # of jumps from head to n-from-end node

    struct ListNode fake_head = {0, head};
    cur_node = &fake_head;

    while (n_to_end > 0) {
        if (cur_node->next)
            cur_node = cur_node->next;
        else return head;
        --n_to_end;
    }

    if (cur_node->next) {
        cur_node->next = cur_node->next->next;
    }

    return head;
}

// https://leetcode.com/problems/sort-list/

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        vector<int> arr;
        ListNode* current = head;
        while (current != NULL) {
            arr.push_back(current->val);
            current = current->next;
        }

        // Step 2: Sort the array
        sort(arr.begin(), arr.end());

        // Step 3: Rebuild the sorted linked list
        ListNode* sortedHead = new ListNode(arr[0]);  // First node
        ListNode* sortedCurrent = sortedHead;  // To track the current position in new list

        for (int i = 1; i < arr.size(); ++i) {
            sortedCurrent->next = new ListNode(arr[i]);
            sortedCurrent = sortedCurrent->next;
        }

        return sortedHead;
    }
};

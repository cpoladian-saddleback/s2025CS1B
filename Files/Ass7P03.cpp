struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

DNode* insertAtPosition(DNode* head, int pos, int data) {
    DNode* newNode = new DNode{data, nullptr, nullptr};

    if (pos == 1) {
        newNode->next = head;
        if (head) head->prev = newNode;
        return newNode;
    }

    DNode* current = head;
    for (int i = 1; i < pos - 1 && current; i++) {
        current = current->next;
    }

    if (!current) return head;

    newNode->next = current->next;
    newNode->prev = current;
    if (current->next) current->next->prev = newNode;
    current->next = newNode;

    return head;
}

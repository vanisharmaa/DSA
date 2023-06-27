/*
Ques.
Given a singly linked list of integers and position 'i', delete the node present at the 'i-th' position in the linked list iteratively and recursively.
*/

//Iteratively
Node *deleteNodeRec(Node *head, int pos) {
	if(pos == 0){
		return head->next;
	}
	Node* curr = head->next;
	Node* prev = head;
	pos--;
	while(pos > 0){
		if(curr->next == NULL){
			return head;
		}
		prev = curr;
		curr = curr->next;
		pos--;
	}
	prev->next = curr->next;
	return head;
}

//Recursively
Node *deleteNodeRec(Node *head, int pos) {
	//Write your code here
	if (pos == 0){
		return head->next;
	}
	if(head->next == NULL){
		return head;
	}
	Node* ans = deleteNodeRec(head->next, pos-1);
	head->next = ans;
	return head;
}

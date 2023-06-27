/*
Ques.
Given a singly linked list of integers and position 'i', insert the given node at the 'i-th' position in the linked list iteratively and recursively.
*/

//Iterative approach
Node* InsertNode(Node *head, int pos, Node* newNode)
{
    if (pos == 0){
		newNode->next = head;
		return newNode;
	}
	int curr = pos, prev = pos-1;
	Node* temp = head->next;
	Node* prevTemp = head;
	while(prev > 0){
		prevTemp = temp;
		temp = temp->next;
		if(prevTemp == NULL){
			return head;
		}
		prev--;
	}
	prevTemp -> next = newNode;
	newNode->next = temp;
	return head;
}

//Recursive approach
Node* InsertNode(Node *head, int pos, Node* newNode){
	if(pos == 0){
		newNode->next = head;
		return newNode;
	}
	Node* ans = InsertNode(head->next, pos-1, newNode);
	head->next = ans;
	return head;
}

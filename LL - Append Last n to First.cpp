/*
Ques.
You have been given a singly linked list of integers along with an integer 'N'. Write a function to append the last 'N' nodes towards the front of the singly linked list and returns the new head to the list.
Hint:
Identify how many pointers you require and try traversing them to right places and connect nodes accordingly also don't forget to disconnect what's required else it could create cycles.
*/

/*
1. Take a fast ptr initialised with head and move it n places forward.
2. Move slow ptr and fast ptr one step fwd till fast is at last node.
3. Now slow would be present at the node where division is supposed to happen, so, put temp = slow->next. This would be the new head.
4. Now connect the node where fast is present (initial last node) to initial head.
5. Put NULL after slow ptr to mark the end of the LL and return the new head that is temp.
*/

Node *appendLastNToFirst(Node *head, int n)
{	
	if(n == 0){
		return head;
	}
	Node *slow = head, *fast = head, *temp = head;
	for(int i = 0; i < n; i++){
		if(!fast){ // if n > len of LL
			return head;
		}
		fast = fast->next;
	}
	while(fast->next){
		slow = slow->next;
		fast = fast->next;
	}
	temp = slow->next;
	fast->next = head;
	slow->next = NULL;
	head = temp;
	return head;
}

//SHOWED TLE

// int length(Node* head){
// 	Node* temp = head;
// 	int len = 0;
// 	while(temp != NULL){
// 		len++;
// 		temp=temp->next;
// 	}
// 	return len;
// }
// Node *appendLastNToFirst(Node *head, int n)
// {
//     //Write your code here
// 	if(n == 0){
// 		return head;
// 	}
// 	Node* temp = head;
// 	while(temp->next){
// 		temp = temp->next;
// 	}
// 	cout << "1 " << temp->data << endl;
// 	temp ->next = head;
// 	int len = length(head);
// 	int numNodes = n;
// 	temp = head;
// 	while(--numNodes){
// 		temp = temp->next;
// 	}
// 	cout << "2 " << temp->data << endl;
// 	Node* newHead = temp->next;
// 	temp->next = NULL;
// 	return newHead;
// }

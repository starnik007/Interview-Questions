#include <bits/stdc++.h>
using namespace std;
// linked list
class node
{
public:
	int data;
	node *next;
	node(int k)
	{
		data = k;
		next = NULL;
	}
};
void IAT(node *&head, int p) // Inserting element at the tail
{
	node *n = new node(p);
	if (head == NULL)
	{
		head = n;
		return;
	}
	node *t = head;
	while (t->next != NULL)
	{
		t = t->next;
	}
	t->next = n;
}
void print(node *&head) // for printing the linked list
{
	node *t = head;
	while (t != NULL)
	{
		cout << t->data << " -> ";
		t = t->next;
	}
	cout<<"NULL\n";
}
int leng(node *&head) // for finding the length of the linked list
{
	node *t = head;
	int l = 0;
	while (t != NULL)
	{
		l++;
		t = t->next;
	}
	return l;
}
node *revk(node *&head, int k) // for reversing k nodes
{
	if(k>leng(head)){
		cout<<"k is greater than length of the linked list\n";
		return head;
	}
	node *pre = NULL;
	node *cur = head;
	node *ne;
	int c = 0;
	while (cur != NULL && c < k)
	{
		ne = cur->next;
		cur->next = pre;
		pre = cur;
		cur = ne;
		c++;
	}
	if (ne != NULL)
	{
		head->next = revk(ne, k);
	}
	return pre;
}
int main()
{
	node *head = NULL;
	IAT(head, 1);
	IAT(head, 2);
	IAT(head, 3);
	IAT(head, 4);
	IAT(head, 5);
	IAT(head, 6);
	cout<<"Linked List before reversing k nodes\n";
	print(head);
	node *temp = revk(head, 2);
	cout<<"Linked List after reversing k nodes\n";
	print(temp);
	return 0;
}
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode ( int x ) : val ( x ), next ( NULL ) {}
};

class NumberList {
public:
	NumberList() {
		this->head = NULL;
	}

	NumberList ( ListNode *head ) {
		this->head = head;
	}

	~NumberList() {
		while ( head ) {
			ListNode *node = head->next;
			delete head;
			head = node;
		}
	}

	void traverse() {
		ListNode *node = this->head;
		while ( node ) {
			cout << node->val << '\t';
			node = node->next;
		}
	}

	void addNumber ( int val ) {		//insert from the head of the list
		ListNode *node = new ListNode ( val );
		node->next = this->head;
		this->head = node;
	}

	void setHead ( ListNode *node ) {
		this->head = node;
	}

	ListNode* getHead() {
		return this->head;
	}

	void addTwoNumbers ( ListNode *l1, ListNode *l2 ) {
		ListNode *current = l1;
		int count1 = 0;
		int  count2 = 0;
		int carry = 0;
		while ( current ) {
			count1++;
			current = current->next;
		}
		current = l2;
		while ( current ) {
			count2++;
			current = current->next;
		}
		if ( count1 <= count2 )
			carry = addTwoNumbers ( l1, l2, count2 - count1 );
		else
			carry = addTwoNumbers ( l2, l1, count1 - count2 );
		if ( carry ) {
			ListNode *node = new ListNode ( carry );
			node->next = this->head;
			this->head = node;
		}
	}

private:
	int addTwoNumbers ( ListNode* node1, ListNode* node2, int offset ) {
		int carry = 0;
		int val = 0;
		if ( node2 == NULL )
			return 0;
		else if ( offset ) {
			offset--;
			carry = addTwoNumbers ( node1, node2->next, offset );
			val = node2->val + carry > 9 ? node2->val + carry - 10 : node2->val + carry;
			carry = node2->val + carry > 9 ? 1 : 0;
		} else {
			carry = addTwoNumbers ( node1->next, node2->next, 0 );
			val = node1->val + node2->val + carry > 9 ?
			      node1->val + node2->val + carry - 10 : node1->val + node2->val + carry;
			carry = node1->val + node2->val + carry > 9 ? 1 : 0;
		}
		ListNode *node = new ListNode ( val );
		node->next = this->head;
		this->head = node;
		return carry;
	}

private:
	ListNode *head;
};

int main () {
	NumberList s1;
	s1.addNumber ( 7 );
	//s1.addNumber ( 4 );
	//s1.addNumber ( 2 );
	NumberList s2;
	s2.addNumber ( 4 );
	s2.addNumber ( 6 );
	s2.addNumber ( 5 );
	NumberList s3;
	s3.addTwoNumbers ( s1.getHead(), s2.getHead() );
	s3.traverse();
	return 0;
}

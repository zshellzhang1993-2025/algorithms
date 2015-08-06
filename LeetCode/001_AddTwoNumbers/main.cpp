#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode ( int x ) : val ( x ), next ( NULL ) {}
};

class Solution2 {
public:
	Solution2() {
		this->head = NULL;
	}

	Solution2 ( ListNode *head ) {
		this->head = head;
	}

	~Solution2() {
		while ( head ) {
			ListNode *node = head->next;
			delete head;
			head = node;
		}
	}

	void addNumber ( int val ) {		//insert from the head of the list
		ListNode *node = new ListNode ( val );
		node->next = this->head;
		this->head = node;
	}

	ListNode *addTwoNumbers ( ListNode *l1, ListNode *l2 ) {
		int val = l1->val + l2->val > 9 ? l1->val + l2->val - 10 : l1->val + l2->val;
		int carry = l1->val + l2->val > 9 ? 1 : 0;
		ListNode *adder1 = l1->next;
		ListNode *adder2 = l2->next;
		ListNode *result = new ListNode ( val );
		ListNode *sum = result;
		while ( adder1 != NULL && adder2 != NULL ) {
			val = adder1->val + adder2->val + carry > 9 ? adder1->val + adder2->val + carry - 10 :
			      adder1->val + adder2->val + carry;
			carry = adder1->val + adder2->val + carry > 9 ? 1 : 0;
			ListNode *node = new ListNode ( val );
			sum->next = node;
			sum = node;
			adder1 = adder1->next;
			adder2 = adder2->next;
		}
		while ( adder1 != NULL ) {
			val = adder1->val + carry > 9 ? adder1->val + carry - 10 :
			      adder1->val + carry;
			carry = adder1->val + carry > 9 ? 1 : 0;
			ListNode *node = new ListNode ( val );
			sum->next = node;
			sum = node;
			adder1 = adder1->next;
		}
		while ( adder2 != NULL ) {
			val = adder2->val + carry > 9 ? adder2->val + carry - 10 :
			      adder2->val + carry;
			carry = adder2->val + carry > 9 ? 1 : 0;
			ListNode *node = new ListNode ( val );
			sum->next = node;
			sum = node;
			adder2 = adder2->next;
		}
		if ( carry ) {
			ListNode *node = new ListNode ( carry );
			sum->next = node;
		}
		return result;
	}

public:
	ListNode *head;
};

int main () {
	Solution2 s1;
	s1.addNumber ( 3 );
	//s1.addNumber ( 4 );
	//s1.addNumber ( 2 );
	Solution2 s2;
	s2.addNumber ( 4 );
	s2.addNumber ( 6 );
	s2.addNumber ( 5 );
	Solution2 s3;
	ListNode *result = s3.addTwoNumbers ( s1.head, s2.head );
	while ( result ) {
		cout << result->val << '\t';
		result = result->next;
	}
	return 0;
}

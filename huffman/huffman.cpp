#include <iostream>
#include <queue>

using namespace std;
struct node
{
    char value;
    int frequency;
    struct node *left;
    struct node *right;

    node(int v, int f){
	    value = v;
	    frequency = f;

    }
};

struct compare_frequency 
{
	bool operator()(node *n1, node *n2)
	{
		return n1->frequency < n2->frequency;
	}
};



node *huffman(int char_count, node *node_list[])
{
	priority_queue<node*, vector<node*>, compare_frequency> prio_queue;
	for (int i = 0; i < char_count; i++)
	{
		prio_queue.push(node_list[i]);
	}

	for (int i = 0; i < char_count-2;i++)
	{

		node *x = prio_queue.top();
		prio_queue.pop();
		node *y = prio_queue.top();
		prio_queue.pop();

		node *z = new node(-1, y->frequency + x->frequency);
		z->left = x;
		z->right = y;
		prio_queue.push(z);
	}
	return prio_queue.top();

}

int main(int argc, char const *argv[])
{
	node *a = new node('a', 45);
	node *b = new node('b', 13);
	node *c = new node('c', 12);
	node *d = new node('d', 16);
	node *e = new node('e', 9);
	node *f = new node('f', 5);
	
	int char_count = 6;
	node *node[] = {a, b, c, d, e, f};

	return 0;
}

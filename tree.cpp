#include "tree.h"
#include "list.h"

using namespace std;

struct Tree::Node{
	string creator;
	List list;
	Node * left;
	Node * right;
	Node(const string creator, Node * left = NULL, Node * right = NULL)
		: creator(creator), left(left), right(right){
#if (OBJ_TREE_MESSAGES)
		cout << "Tree::Node[" << this << "]: Node with creator: '" << creator << "' have been created!" << endl;
#endif
	}
	Node(const Node& node)
		:creator(node.creator), list(node.list), left(NULL), right(NULL){
#if (OBJ_TREE_MESSAGES)
		cout << "Tree::Node[" << this << "]: Node with creator: '" << creator << "' have been created by copying!" << endl;
#endif
	}
};

void Tree::printNode(Node * n) const{
	if (n != NULL){
		printNode(n->left);
		cout << "'" << n->creator << "' has " << n->list.get_size() << " posts:" << endl;
		n->list.print();
		printNode(n->right);
	}
}

void Tree::recInsert(Node *n, const Post& post){
	const string creator = post.get_creator();
	if (n != NULL){
		const int x = n->creator.compare(creator);
		if (x > 0){
			if (n->left != NULL)
				recInsert(n->left, post);
			else{
				n->left = new Node(creator);
#if (OBJ_TREE_MESSAGES)
				cout << "Left[" << n->left << "]: A new Tree::Node for creator: " << creator << " has just been created!" << endl;
#endif
				n->left->list.pushFront(post);
			}
		}
		else if (x < 0){
			if (n->right != NULL)
				recInsert(n->right, post);
			else{
				n->right = new Node(creator);
#if (OBJ_TREE_MESSAGES)
				cout << "Right[" << n->right << "]: A new Tree::Node for creator: " << creator << " has just been created!" << endl;
#endif
				n->right->list.pushFront(post);
			}
		}
		else if (x == 0){
#if (OBJ_TREE_MESSAGES)
			cout << "--Node for creator: " << creator << ", have already exists! List::Insert post--" << endl;
#endif
			n->list.pushFront(post);
		}
	}
	else{
		root = new Node(creator);
#if (OBJ_TREE_MESSAGES)
		cout << "Root[" << root << "]: A new Tree::Node for creator: " << creator << " has just been created!" << endl;
#endif
		root->list.pushFront(post);
	}
}

void Tree::recInsert(Node *n, Node * target){
	const string creator = target->creator;
	if (n != NULL && target != NULL){
		const int x = n->creator.compare(creator);
		if (x > 0){
			if (n->left != NULL){
				recInsert(n->left, target);
			}
			else{
				n->left = new Node(*target);
#if (OBJ_TREE_MESSAGES)
				cout << "Left[" << n->left << "]: A new Tree::Node for creator: " << creator << " has just been created!" << endl;
#endif
			}
		}
		else if (x < 0){
			if (n->right != NULL){
				recInsert(n->right, target);
			}
			else{
				n->right = new Node(*target);
#if (OBJ_TREE_MESSAGES)
				cout << "Right[" << n->right << "]: A new Tree::Node for creator: " << creator << " has just been created!" << endl;
#endif
			}
		}
		else if (x == 0){
#if (OBJ_TREE_MESSAGES)
			cout << "--Node for creator: " << creator << ", have already exists! [n->list.append] for " << target->list.get_size() << " posts!" << endl;
#endif
			n->list.append(target->list);
		}
	}
}

void Tree::recMerge(Node * target){
	if (target != NULL){
		recMerge(target->left);
		recMerge(target->right);
		recInsert(this->root, target);
	}
}

void Tree::destroy(Node * node){
	if (node != NULL){
		destroy(node->left);
		destroy(node->right);
		delete node;
	}
}

Tree::Tree(const Thread& thread)
: root(NULL)
{
	const unsigned int posts = thread.get_posts();
	for (unsigned int i = 0; i < posts; i++){
		recInsert(root, thread.get_post(i));
	}
#if (OBJ_TREE_MESSAGES)
	cout << "I create a Tree object!" << endl;
#endif
}

void Tree::enhance(const Tree& tree){
	recMerge(tree.root);
}

void Tree::print() const{
	cout << "\nPrinting of creators alphabetically: " << endl;
	printNode(this->root);
	cout << endl;
}

Tree::~Tree(){
	destroy(root);
#if (OBJ_TREE_MESSAGES)
	cout << "I destroy a Tree object\n" << endl;
#endif
}

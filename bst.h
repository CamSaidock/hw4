#ifndef BST_H
#define BST_H

#include <iostream>
#include <exception>
#include <cstdlib>
#include <utility>

/**
 * A templated class for a Node in a search tree.
 * The getters for parent/left/right are virtual so
 * that they can be overridden for future kinds of
 * search trees, such as Red Black trees, Splay trees,
 * and AVL trees.
 */
template <typename Key, typename Value>
class Node
{
public:
    Node(const Key& key, const Value& value, Node<Key, Value>* parent);
    virtual ~Node();

    const std::pair<const Key, Value>& getItem() const;
    std::pair<const Key, Value>& getItem();
    const Key& getKey() const;
    const Value& getValue() const;
    Value& getValue();

    virtual Node<Key, Value>* getParent() const;
    virtual Node<Key, Value>* getLeft() const;
    virtual Node<Key, Value>* getRight() const;

    void setParent(Node<Key, Value>* parent);
    void setLeft(Node<Key, Value>* left);
    void setRight(Node<Key, Value>* right);
    void setValue(const Value &value);

protected:
    std::pair<const Key, Value> item_;
    Node<Key, Value>* parent_;
    Node<Key, Value>* left_;
    Node<Key, Value>* right_;
};

/*
  -----------------------------------------
  Begin implementations for the Node class.
  -----------------------------------------
*/

/**
* Explicit constructor for a node.
*/
template<typename Key, typename Value>
Node<Key, Value>::Node(const Key& key, const Value& value, Node<Key, Value>* parent) :
    item_(key, value),
    parent_(parent),
    left_(NULL),
    right_(NULL)
{

}

/**
* Destructor, which does not need to do anything since the pointers inside of a node
* are only used as references to existing nodes. The nodes pointed to by parent/left/right
* are freed by the BinarySearchTree.
*/
template<typename Key, typename Value>
Node<Key, Value>::~Node()
{

}

/**
* A const getter for the item.
*/
template<typename Key, typename Value>
const std::pair<const Key, Value>& Node<Key, Value>::getItem() const
{
    return item_;
}

/**
* A non-const getter for the item.
*/
template<typename Key, typename Value>
std::pair<const Key, Value>& Node<Key, Value>::getItem()
{
    return item_;
}

/**
* A const getter for the key.
*/
template<typename Key, typename Value>
const Key& Node<Key, Value>::getKey() const
{
    return item_.first;
}

/**
* A const getter for the value.
*/
template<typename Key, typename Value>
const Value& Node<Key, Value>::getValue() const
{
    return item_.second;
}

/**
* A non-const getter for the value.
*/
template<typename Key, typename Value>
Value& Node<Key, Value>::getValue()
{
    return item_.second;
}

/**
* An implementation of the virtual function for retreiving the parent.
*/
template<typename Key, typename Value>
Node<Key, Value>* Node<Key, Value>::getParent() const
{
    return parent_;
}

/**
* An implementation of the virtual function for retreiving the left child.
*/
template<typename Key, typename Value>
Node<Key, Value>* Node<Key, Value>::getLeft() const
{
    return left_;
}

/**
* An implementation of the virtual function for retreiving the right child.
*/
template<typename Key, typename Value>
Node<Key, Value>* Node<Key, Value>::getRight() const
{
    return right_;
}

/**
* A setter for setting the parent of a node.
*/
template<typename Key, typename Value>
void Node<Key, Value>::setParent(Node<Key, Value>* parent)
{
    parent_ = parent;
}

/**
* A setter for setting the left child of a node.
*/
template<typename Key, typename Value>
void Node<Key, Value>::setLeft(Node<Key, Value>* left)
{
    left_ = left;
}

/**
* A setter for setting the right child of a node.
*/
template<typename Key, typename Value>
void Node<Key, Value>::setRight(Node<Key, Value>* right)
{
    right_ = right;
}

/**
* A setter for the value of a node.
*/
template<typename Key, typename Value>
void Node<Key, Value>::setValue(const Value& value)
{
    item_.second = value;
}

/*
  ---------------------------------------
  End implementations for the Node class.
  ---------------------------------------
*/

/**
* A templated unbalanced binary search tree.
*/
template <typename Key, typename Value>
class BinarySearchTree
{
public:
    BinarySearchTree(); //TODO
    virtual ~BinarySearchTree(); //TODO
    virtual void insert(const std::pair<const Key, Value>& keyValuePair); //TODO
    virtual void remove(const Key& key); //TODO
    void clear(); //TODO
    bool isBalanced() const; //TODO
    void print() const;
    bool empty() const;

    template<typename PPKey, typename PPValue>
    friend void prettyPrintBST(BinarySearchTree<PPKey, PPValue> & tree);
public:
    /**
    * An internal iterator class for traversing the contents of the BST.
    */
    class iterator  // TODO
    {
    public:
        iterator();

        std::pair<const Key,Value>& operator*() const;
        std::pair<const Key,Value>* operator->() const;

        bool operator==(const iterator& rhs) const;
        bool operator!=(const iterator& rhs) const;

        iterator& operator++();

    protected:
        friend class BinarySearchTree<Key, Value>;
        iterator(Node<Key,Value>* ptr);
        Node<Key, Value> *current_;
    };

public:
    iterator begin() const;
    iterator end() const;
    iterator find(const Key& key) const;
    Value& operator[](const Key& key);
    Value const & operator[](const Key& key) const;

protected:
    // Mandatory helper functions
    Node<Key, Value>* internalFind(const Key& k) const; // TODO
    Node<Key, Value> *getSmallestNode() const;  // TODO
    static Node<Key, Value>* predecessor(Node<Key, Value>* current); // TODO
    // Note:  static means these functions don't have a "this" pointer
    //        and instead just use the input argument.

    // Provided helper functions
    virtual void printRoot (Node<Key, Value> *r) const;
    virtual void nodeSwap( Node<Key,Value>* n1, Node<Key,Value>* n2) ;

    // Add helper functions here
    static Node<Key, Value>* successor(Node<Key, Value>* current);

protected:
    Node<Key, Value>* root_;
    // You should not need other data members
};

/*
--------------------------------------------------------------
Begin implementations for the BinarySearchTree::iterator class.
---------------------------------------------------------------
*/

/**
* Explicit constructor that initializes an iterator with a given node pointer.
*/
template<class Key, class Value>
BinarySearchTree<Key, Value>::iterator::iterator(Node<Key,Value> *ptr)
{
  // TODO
	this->current_ = ptr;
}

/**
* A default constructor that initializes the iterator to NULL.
*/
template<class Key, class Value>
BinarySearchTree<Key, Value>::iterator::iterator() 
{
  // TODO
	this->current_ = NULL;
}

/**
* Provides access to the item.
*/
template<class Key, class Value>
std::pair<const Key,Value> &
BinarySearchTree<Key, Value>::iterator::operator*() const
{
  return current_->getItem();
}

/**
* Provides access to the address of the item.
*/
template<class Key, class Value>
std::pair<const Key,Value> *
BinarySearchTree<Key, Value>::iterator::operator->() const
{
    return &(current_->getItem());
}

/**
* Checks if 'this' iterator's internals have the same value
* as 'rhs'
*/
template<class Key, class Value>
bool
BinarySearchTree<Key, Value>::iterator::operator==(
    const BinarySearchTree<Key, Value>::iterator& rhs) const
{
    // TODO
    return (current_ == rhs.current_);
}

/**
* Checks if 'this' iterator's internals have a different value
* as 'rhs'
*/
template<class Key, class Value>
bool
BinarySearchTree<Key, Value>::iterator::operator!=(
    const BinarySearchTree<Key, Value>::iterator& rhs) const
{
    // TODO
    return (current_ != rhs.current_);

}


/**
* Advances the iterator's location using an in-order sequencing
*/
template<class Key, class Value>
typename BinarySearchTree<Key, Value>::iterator&
BinarySearchTree<Key, Value>::iterator::operator++()
{
    // TODO
    current_ = successor(current_);
    return *this;
}


/*
-------------------------------------------------------------
End implementations for the BinarySearchTree::iterator class.
-------------------------------------------------------------
*/

/*
-----------------------------------------------------
Begin implementations for the BinarySearchTree class.
-----------------------------------------------------
*/

/**
* Default constructor for a BinarySearchTree, which sets the root to NULL.
*/
template<class Key, class Value>
BinarySearchTree<Key, Value>::BinarySearchTree() 
{
    // TODO
    this->root_ = NULL;
}

template<typename Key, typename Value>
BinarySearchTree<Key, Value>::~BinarySearchTree()
{
    // TODO
    this->clear();
}

/**
 * Returns true if tree is empty
*/
template<class Key, class Value>
bool BinarySearchTree<Key, Value>::empty() const
{
    return root_ == NULL;
}

template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::print() const
{
    printRoot(root_);
    std::cout << "\n";
}

/**
* Returns an iterator to the "smallest" item in the tree
*/
template<class Key, class Value>
typename BinarySearchTree<Key, Value>::iterator
BinarySearchTree<Key, Value>::begin() const
{
    BinarySearchTree<Key, Value>::iterator begin(getSmallestNode());
    return begin;
}

/**
* Returns an iterator whose value means INVALID
*/
template<class Key, class Value>
typename BinarySearchTree<Key, Value>::iterator
BinarySearchTree<Key, Value>::end() const
{
    BinarySearchTree<Key, Value>::iterator end(NULL);
    return end;
}

/**
* Returns an iterator to the item with the given key, k
* or the end iterator if k does not exist in the tree
*/
template<class Key, class Value>
typename BinarySearchTree<Key, Value>::iterator
BinarySearchTree<Key, Value>::find(const Key & k) const
{
    Node<Key, Value> *curr = internalFind(k);
    BinarySearchTree<Key, Value>::iterator it(curr);
    return it;
}

/**
 * @precondition The key exists in the map
 * Returns the value associated with the key
 */
template<class Key, class Value>
Value& BinarySearchTree<Key, Value>::operator[](const Key& key)
{
    Node<Key, Value> *curr = internalFind(key);
    if(curr == NULL) throw std::out_of_range("Invalid key");
    return curr->getValue();
}
template<class Key, class Value>
Value const & BinarySearchTree<Key, Value>::operator[](const Key& key) const
{
    Node<Key, Value> *curr = internalFind(key);
    if(curr == NULL) throw std::out_of_range("Invalid key");
    return curr->getValue();
}

/**
* An insert method to insert into a Binary Search Tree.
* The tree will not remain balanced when inserting.
* Recall: If key is already in the tree, you should 
* overwrite the current value with the updated value.
*/
template<class Key, class Value>
void BinarySearchTree<Key, Value>::insert(const std::pair<const Key, Value> &keyValuePair)
{
    // TODO
		if(this->root_ == nullptr) { //Root_ doesn't exist, create a new root
			Node<Key, Value>* newRoot = new Node<Key, Value>(keyValuePair.first, keyValuePair.second, nullptr);
			this->root_ = newRoot;
			return;
		}
		
		Node<Key, Value>* findNode = internalFind(keyValuePair.first); //First, check to see if node already exists
		if(findNode != nullptr) {
			findNode->setValue(keyValuePair.second);
			return;
		}
		
		else {
			delete findNode;
			Node<Key, Value>* itr = this->root_;
			Node<Key,Value>* itrParent = this->root_; //Keep track of parent in case itr becomes null

			if(keyValuePair.first < itr->getKey()) { //Check if the key is smaller than itr's key
				if(this->root_->getLeft() != nullptr) { //If root_ contains a left child, search through left subtree
					itr = this->root_->getLeft();
				}
				
				while(itr != nullptr) { //Search through the subtree until itr becomes nullptr
					if(keyValuePair.first < itr->getKey()) { //If key is smaller than itr, continue searching through left subtree
						itrParent = itr;
						itr = itr->getLeft();
					}
					else if(keyValuePair.first > itr->getKey()) { //If key is greater than itr, continue searching through right subtree
						itrParent = itr;
						itr = itr->getRight();
					}
				}
			}

			else if(keyValuePair.first > itr->getKey()) { //Check if the key is greater than itr's key
				if(this->root_->getRight() != nullptr) { //If root_ contains a left child, search through left subtree
					itr = this->root_->getRight();
				}

				while(itr != nullptr) { //Search through the subtree until itr becomes nullptr
					if(keyValuePair.first < itr->getKey()) { //If key is smaller than itr, continue searching through left subtree
						itrParent = itr;
						itr = itr->getLeft();
					}

					else if(keyValuePair.first > itr->getKey()) { //If key is greater than itr, continue searching through right subtree
						itrParent = itr;
						itr = itr->getRight();
					}
				}
			}

			Node<Key, Value>* newNode = new Node<Key, Value>(keyValuePair.first, keyValuePair.second, itrParent);
			//This is where we create the new node based on where itr became null and where itrParent left off.
			if(keyValuePair.first < itrParent->getKey()) { //If key is less than itrParent, then set the new node as itrParent's left child
				itrParent->setLeft(newNode);
			}
			else if(keyValuePair.first > itrParent->getKey()) { //If key is greater than itrParent, then set the new node as itrParent's right child
				itrParent->setRight(newNode);
			}
		}

		return;
}


/**
* A remove method to remove a specific key from a Binary Search Tree.
* Recall: The writeup specifies that if a node has 2 children you
* should swap with the predecessor and then remove.
*/
template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::remove(const Key& key)
{

  Node<Key, Value>* itr = internalFind(key); //Search through tree to find key to be removed

	if(itr == nullptr || this->root_ == nullptr) { //If key doesn't exist or if root_ doesn't exist, return
		return;
	}

	if(itr == this->root_) { //If the Key being removed is the root
		if(itr->getLeft() == nullptr && itr->getRight() == nullptr) { //If the root contains no children, then just delete it and set root_ to nullptr
			delete itr;
			this->root_ = nullptr;
			return;
		}
		else { //If the root contains children, swap it with its predecessor and update root_
			Node<Key, Value>* predecessorNode = predecessor(itr);
			nodeSwap(itr, predecessorNode);
			this->root_ = predecessorNode;
		}
	}

	//Continue through different cases

	if(itr->getLeft() != nullptr && itr->getRight() != nullptr) { //If the node is not a root and contains two children, swap it with its predecessor so it has 0 or 1 children
		Node<Key, Value>* predecessorNode = predecessor(itr);
		nodeSwap(itr, predecessorNode);
	}
	
	if(itr->getLeft() == nullptr && itr->getRight() == nullptr) { //Node is a leaf node and has 0 children
		if(itr->getParent()->getLeft() == itr) { //Node is left child of parent
			itr->getParent()->setLeft(nullptr); //Set parent's left node to null and then delete the left node
			delete itr;
			return;
		}
		else if(itr->getParent()->getRight() == itr) { //Node is right child of parent
			itr->getParent()->setRight(nullptr); //Set parent's right node to null and then delete the right node
			delete itr;
			return;
		}
	}

	else if(itr->getLeft() != nullptr || itr->getRight() != nullptr) { //Node has 1 child
		Node<Key, Value>* itrParent = itr->getParent();

		if(itrParent == nullptr) {
			if(itr->getLeft() == nullptr) {
				itr->getRight()->setParent(nullptr);
				this->root_ = itr->getRight();
				delete itr;
			}
			else if(itr->getRight() == nullptr) {
				itr->getLeft()->setParent(nullptr);
				this->root_ = itr->getLeft();
				delete itr;
			}
		}

		else if(itr->getParent()->getLeft() == itr) { //Node is left child of parent
			if(itr->getLeft() == nullptr) { //Node's child is right child
				itrParent->setLeft(itr->getRight());
				itr->getRight()->setParent(itrParent);
			}
			else if(itr->getRight() == nullptr) { //Node's child is left child
				itrParent->setLeft(itr->getLeft());
				itr->getLeft()->setParent(itrParent);
			}
		}

		else if(itr->getParent()->getRight() == itr) { //Node is right child of parent
			if(itr->getLeft() == nullptr) { //Node's child is right child
				itrParent->setRight(itr->getRight());
				itr->getRight()->setParent(itrParent);
			}
			else if(itr->getRight() == nullptr) { //Node's child is left child
				itrParent->setRight(itr->getLeft());
				itr->getLeft()->setParent(itrParent);
			}
		}
	}
}



template<class Key, class Value>
Node<Key, Value>*
BinarySearchTree<Key, Value>::predecessor(Node<Key, Value>* current)
{
    // TODO
    Node<Key, Value>* itr = current;

		if(current->getLeft() == nullptr && current->getRight() == nullptr) {
			return nullptr;
		}

    if(itr->getLeft() != nullptr) { //Make sure that the current node has a left subtree
        itr = current->getLeft();
				if(itr->getRight() != nullptr){
					while(itr->getRight() != nullptr) {
            itr = itr->getRight();
        	}
				}
        return itr;
    }

		else if(itr->getLeft() == nullptr) {
			Node<Key, Value>* itrParent;
			while(itr->getParent() != nullptr) {
				itrParent = itr->getParent();
				if(itr == itrParent->getRight()) {
					return itrParent;
				}
				itr = itr->getParent();
			}

			return nullptr;
		}

		return itr;

}

template<class Key, class Value>
Node<Key, Value>*
BinarySearchTree<Key, Value>::successor(Node<Key, Value>* current)
{   
    Node<Key, Value>* itr = current;

		if(current->getLeft() == nullptr && current->getRight() == nullptr) {
			return nullptr;
		}
    
    if(current->getRight() != nullptr) { //Make sure that the current node has a right subtree
			itr = current->getRight();
			while(itr->getLeft() != nullptr) {
					itr = itr->getLeft();
			}
			return itr;		
    }

		else if(itr->getRight() == nullptr) {
			itr = current;
			Node<Key, Value>* itrParent;
			while(itr->getParent() != nullptr) {
				itrParent = itr->getParent();
				if(itr == itrParent->getLeft()) {
					return itrParent;
				}
				itr = itr->getParent();
			}
		}

		return itr;
}


/**
* A method to remove all contents of the tree and
* reset the values in the tree for use again.
*/
template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::clear()
{
    // TODO
		while(this->root_ != nullptr) { //Keep removing the root until tree is empty
			remove(this->root_->getKey());
		}


}


/**
* A helper function to find the smallest node in the tree.
*/
template<typename Key, typename Value>
Node<Key, Value>*
BinarySearchTree<Key, Value>::getSmallestNode() const
{
    // TODO
		Node<Key, Value>* itr = this->root_;
		Node<Key,Value>* parent = this->root_; 

		while(itr != nullptr) { //Keep searching through left subtree to find smallest node
			if(itr->getLeft() != nullptr) { //As long as the left node isn't NULL, change parent to current node
				parent = itr;
			}
			itr = itr->getLeft();
		}

		return parent;


}

/**
* Helper function to find a node with given key, k and
* return a pointer to it or NULL if no item with that key
* exists
*/
template<typename Key, typename Value>
Node<Key, Value>* BinarySearchTree<Key, Value>::internalFind(const Key& key) const
{
	Node<Key, Value>* itr = this->root_;

	if(itr == nullptr) { //Empty tree, return NULL
		return nullptr;
	}

	else {
		while(itr != nullptr) {
			if(key == itr->getKey()) { //If node has been found, return the node
				return itr;
			}

			else if(key < itr->getKey()) { //If the node key is less than the iterator's key, search through left subtree
				itr = itr->getLeft();
			}

			else if(key > itr->getKey()) { //If the node key is greater than the iterator's key, search through right subtree
				itr = itr->getRight();
			}
		}
	}

	return itr;
}

/**
 * Return true iff the BST is balanced.
 */
template<typename Key, typename Value>
int calculateHeightIfBalanced(Node<Key,Value>* root) {
	if (root == nullptr) {
		return 0;
	}
		
	int left = calculateHeightIfBalanced(root->getLeft());
	int right = calculateHeightIfBalanced(root->getRight());

	if(left > right) {
		return 1 + left;
	}

	else {
		return 1 + right;
	}

}

template<typename Key, typename Value>
bool checkIfBalanced(Node<Key,Value>* root) {
	if(root == nullptr) { //Base case
		return true;
	}

	int leftHeight = calculateHeightIfBalanced(root->getLeft());
	int rightHeight = calculateHeightIfBalanced(root->getRight());

	if(abs(leftHeight - rightHeight) <= 1 && checkIfBalanced(root->getRight()) && checkIfBalanced(root->getLeft())) {
		return true;
	}

	return false;
}

template<typename Key, typename Value>
bool BinarySearchTree<Key, Value>::isBalanced() const
{
	return checkIfBalanced(this->root_);
}




template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::nodeSwap( Node<Key,Value>* n1, Node<Key,Value>* n2)
{
    if((n1 == n2) || (n1 == NULL) || (n2 == NULL) ) {
        return;
    }
    Node<Key, Value>* n1p = n1->getParent();
    Node<Key, Value>* n1r = n1->getRight();
    Node<Key, Value>* n1lt = n1->getLeft();
    bool n1isLeft = false;
    if(n1p != NULL && (n1 == n1p->getLeft())) n1isLeft = true;
    Node<Key, Value>* n2p = n2->getParent();
    Node<Key, Value>* n2r = n2->getRight();
    Node<Key, Value>* n2lt = n2->getLeft();
    bool n2isLeft = false;
    if(n2p != NULL && (n2 == n2p->getLeft())) n2isLeft = true;


    Node<Key, Value>* temp;
    temp = n1->getParent();
    n1->setParent(n2->getParent());
    n2->setParent(temp);

    temp = n1->getLeft();
    n1->setLeft(n2->getLeft());
    n2->setLeft(temp);

    temp = n1->getRight();
    n1->setRight(n2->getRight());
    n2->setRight(temp);

    if( (n1r != NULL && n1r == n2) ) {
        n2->setRight(n1);
        n1->setParent(n2);
    }
    else if( n2r != NULL && n2r == n1) {
        n1->setRight(n2);
        n2->setParent(n1);

    }
    else if( n1lt != NULL && n1lt == n2) {
        n2->setLeft(n1);
        n1->setParent(n2);

    }
    else if( n2lt != NULL && n2lt == n1) {
        n1->setLeft(n2);
        n2->setParent(n1);

    }


    if(n1p != NULL && n1p != n2) {
        if(n1isLeft) n1p->setLeft(n2);
        else n1p->setRight(n2);
    }
    if(n1r != NULL && n1r != n2) {
        n1r->setParent(n2);
    }
    if(n1lt != NULL && n1lt != n2) {
        n1lt->setParent(n2);
    }

    if(n2p != NULL && n2p != n1) {
        if(n2isLeft) n2p->setLeft(n1);
        else n2p->setRight(n1);
    }
    if(n2r != NULL && n2r != n1) {
        n2r->setParent(n1);
    }
    if(n2lt != NULL && n2lt != n1) {
        n2lt->setParent(n1);
    }


    if(this->root_ == n1) {
        this->root_ = n2;
    }
    else if(this->root_ == n2) {
        this->root_ = n1;
    }

}

/**
 * Lastly, we are providing you with a print function,
   BinarySearchTree::printRoot().
   Just call it with a node to start printing at, e.g:
   this->printRoot(this->root_) // or any other node pointer

   It will print up to 5 levels of the tree rooted at the passed node,
   in ASCII graphics format.
   We hope it will make debugging easier!
  */

// include print function (in its own file because it's fairly long)
#include "print_bst.h"

/*
---------------------------------------------------
End implementations for the BinarySearchTree class.
---------------------------------------------------
*/

#endif
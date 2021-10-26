#include "BinarySearchTree.h"

/**
* Returns true if x is found in the tree.
*/ //xc&&

void BinarySearchTree::printTree(ostream & out) const
{
   return printTree(root, out);
}

/**void BinarySearchTree::printElements(int & min) const
{
   returns printElements(root, min);

   }**/

bool BinarySearchTree::contains( const int & x ) const
{
return contains( x, root );
}
/**
* Insert x into the tree; duplicates are ignored.
*/
void BinarySearchTree::insert( const int & x )
{
insert( x, root );
}
/**
* Remove x from the tree. Nothing is done if x is not found.
*/
void BinarySearchTree::remove( const int & x )
{
remove( x, root );
}

/**
* Internal meythod to test if an item is in a subtree.
* x is item to search for.
* t is the node that roots the subtree.
*/
bool BinarySearchTree::contains( const int & x, BinaryNode *t ) const
{
if( t == nullptr )
return false;
else if( x < t->element )
return contains( x, t->left );
else if( t->element < x )
return contains( x, t->right );
else
return true;
// Match
}

/**
* Internal method to test if an item is in a subtree.
* x is item to search for.
* t is the node that roots the subtree.
*/
/**bool BinarySearchTree::contains( const int & x, BinaryNode *t ) const
{
if( t == nullptr )
return false;
else if( isLessThan( x, t->element ) )

return contains( x, t->left );
else if( isLessThan( t->element, x ) )
return contains( x, t->right );
else
return true;
// Match
}**/

/**
* Internal method to find the smallest item in a subtree t.
* Return node containing the smallest item.
*/
BinarySearchTree::BinaryNode * BinarySearchTree::findMin( BinaryNode *t ) const
{
if( t == nullptr )
return nullptr;
if( t->left == nullptr )
return t;
return findMin( t->left );
}

/**
* Internal method to find the largest item in a subtree t.
* Return node containing the largest item.
*/
BinarySearchTree::BinaryNode * BinarySearchTree::findMax( BinaryNode *t ) const
{
if( t != nullptr )
while( t->right != nullptr )
t = t->right;
return t;
}

/**
* Internal method to insert into a subtree.
* x is the item to insert.
* t is the node that roots the subtree.
* Set the new root of the subtree.
*/
void BinarySearchTree::insert( const int & x, BinaryNode * & t )
{
if( t == nullptr )
t = new BinaryNode{ x, nullptr, nullptr };
else if( x < t->element )
insert( x, t->left );
else if( t->element < x )
insert( x, t->right );
else
; // Duplicate; do nothing
}

/**
* Internal method to remove from a subtree.
* x is the item to remove.
* t is the node that roots the subtree.
* Set the new root of the subtree.
*/

void BinarySearchTree::remove( const int & x, BinaryNode * & t )
{
if( t == nullptr )
return;
// Item not found; do nothing
if( x < t->element )
remove( x, t->left );
else if( t->element < x )
remove( x, t->right );
else if( t->left != nullptr && t->right != nullptr ) // Two children
{
t->element = findMin( t->right )->element;
remove( t->element, t->right );
}
else
{
BinaryNode *oldNode = t;
t = ( t->left != nullptr ) ? t->left : t->right;
delete oldNode;
}
}


/**
* Destructor for the tree
*/
BinarySearchTree::~BinarySearchTree( )
{
makeEmpty( root );
}

/**
* Internal method to make subtree empty.
*/
void BinarySearchTree::makeEmpty( BinaryNode * & t )
{
if( t != nullptr )
{
makeEmpty( t->left );
makeEmpty( t->right );
delete t;
}
t = nullptr;
}

/**
* Copy constructor
*/
BinarySearchTree::BinarySearchTree( const BinarySearchTree & rhs ) : root{ nullptr }
{
root = clone( rhs.root );
}

/**
* Internal method to clone subtree.
*/
BinarySearchTree::BinaryNode * BinarySearchTree::clone( BinaryNode *t ) const
{
if( t == nullptr )
return nullptr;
else
return new BinaryNode{ t->element, clone( t->left ), clone( t->right ) };
}

void BinarySearchTree::printElements(BinaryNode *t, int min)
{
   if( t==nullptr )
      return;
   if (min >= t -> element)
   {
      printElements(t -> right, min);
   }
   else
   {
      printElements( t -> left, min);
      cout << t-> element << " ";
      printTree(t->right, cout);
   }

   
}


void BinarySearchTree::printTree( BinaryNode *t, ostream & out ) const
 {
   if(t == nullptr)
      return;

   if (t->left != nullptr)
      printTree(t->left, cout);
   cout << t-> element << " ";

   if (t->right != nullptr)
      printTree(t->right, cout);
      

} 

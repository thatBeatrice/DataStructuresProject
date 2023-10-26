# DataStructuresProject

A project I made last year for the Data Structures subject. <br />
We had to implement a Search Tree. The nodes had to have a key field and pointers to the parent and children nodes, along with constructors. The following methods had to be implemented: <br />
`INSERT(int key)` - insert a new node with the value of key without creating duplicates <br />
`MAXIM(node* x)/MINIM(node* x)`- return the node with the maximum/minimum value from the subtree with the root x <br />
`SUCCESOR(node* x)`/`PREDECESOR(node* x)`- returns the node that is the successor/predecessor of a given node <br />
`FIND(int key)` - returns a node based on its value <br />
`DELETE(int key)` - deletes a node based on its value <br />
`ERASE(node* x)` - deletes the given node from the tree <br />
`PRINT_TREE(int option)` - based on the option number, prints the tree based on the chosen order <br />
`CONSTRUCT()`- builds a tree from a vector of keys <br />
`EMPTY()` - verifies if the tree is empty of not <br />
`CLEAR()` - deletes all nodes from tree <br />

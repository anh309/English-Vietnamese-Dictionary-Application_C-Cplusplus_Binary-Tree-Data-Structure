
node * minValueNode(struct node* p)
{
    node* current = p;
 
    /* loop down to find the leftmost leaf */
    while (current->pleft != NULL)
        current = current->pleft;
 
    return current;
}
 
// Recursive function to delete a node with given key
// from subtree with given root. It returns root of
// the modified subtree.
node* deleteNode(node* root, _Word data)
{
    // STEP 1: PERFORM STANDARD BST DELETE
 
    if (root == NULL)
        return root;
 
    // If the key to be deleted is smaller than the
    // root's key, then it lies in pleft subtree
    if (strcmp(data.NghiaGoc, root->data.NghiaGoc) < 0)
        root->pleft = deleteNode(root->pleft, data);
 
    // If the key to be deleted is greater than the
    // root's key, then it lies in pright subtree
    else if(strcmp(data.NghiaGoc, root->data.NghiaGoc) > 0)
        root->pright = deleteNode(root->pright, data);
 
    // if key is same as root's key, then This is
    // the node to be deleted
    else
    {
        // node with only one child or no child
        if( (root->pleft == NULL) || (root->pright == NULL) )
        {
            struct node *temp = root->pleft ? root->pleft :
                                             root->pright;
 
            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
             *root = *temp; // Copy the contents of
                            // the non-empty child
            free(temp);
        }
        else
        {
            // node with two children: Get the inorder
            // successor (smallest in the pright subtree)
            node* temp = minValueNode(root->pright);
 
            // Copy the inorder successor's data to this node
            root->data = temp->data;
 
            // Delete the inorder successor
            root->pright = deleteNode(root->pright, temp->data);
        }
    }
 
    // If the tree had only one node then return
    if (root == NULL)
      return root;
 
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(height(root->pleft),
                           height(root->pright));
 
    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
    // check whether this node became unbalanced)
    int balance = getBalance(root);
 
    // If this node becomes unbalanced, then there are 4 cases
 
    // pleft pleft Case
    if (balance > 1 && getBalance(root->pleft) >= 0)
        return rightRotate(root);
 
    // pleft pright Case
    if (balance > 1 && getBalance(root->pleft) < 0)
    {
        root->pleft =  leftRotate(root->pleft);
        return rightRotate(root);
    }
 
    // pright pright Case
    if (balance < -1 && getBalance(root->pright) <= 0)
        return leftRotate(root);
 
    // pright pleft Case
    if (balance < -1 && getBalance(root->pright) > 0)
    {
        root->pright = rightRotate(root->pright);
        return leftRotate(root);
    }
 
    return root;
}

/*
void If2nodes(Nod &a, tree &b){
	if(b->pleft)
		If2nodes(a,b->pleft);
	else{
		a->data = b->data;
		a=b;
		b=b->pright;
	}
}



void XoaNode(tree &r,tree r2){
	if (r != NULL)
	{
		if(r!=r2){
			if (r->pleft != NULL)
				return XoaNode(r->pleft,r2);
			else 
				return XoaNode(r->pright,r2);
		}
	}

	node *p = r;		
	if(r != NULL){
		if(r->pleft==NULL)
			r= r->pright;
		else 
			if (r->pright==NULL)
				r=r->pleft;
			else
				If2nodes(p,r->pright);
		delete(p);
		printf("done!!\n");
	}
	else
		printf("Loi khi xoa!!\n");
	
}

*/
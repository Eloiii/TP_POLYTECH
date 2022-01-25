#define SIZE 8

struct node {
    int value;
    struct node* left;
    struct node* right;
};

static struct node tree;
static struct node A, B, A1, A2, B1, B2;

void init_nodes(void)
{
    /* Node values initialization */
    A.value = 2;
    B.value = 12;
    A1.value = 32;
    A2.value = 43;
    B1.value = 234;
    B2.value = 543;
}

void init_tree(void)
{
    init_nodes();

    /* Tree structure initialization */
    tree.left  = &A;
    tree.right = &B;

    A.left = &A1;
    A.right = &A2;

    B.left = &B1;
    B.right = &B2;
}

/*
 * tree_sum - Compute recursively the sum of all nodes of a given tree
 */
int tree_sum(struct node* n)
{
    int r;

    r = n->value;

    if(n->left != 0) {
        r += tree_sum(n->left);
    }

    if(n->right != 0) {
        r += tree_sum(n->right);
    }

    return r;
}

int main(void)
{
    init_tree();

    return tree_sum(&tree);
}


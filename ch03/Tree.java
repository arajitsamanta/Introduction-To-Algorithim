
//Represent a Tree node.
class Node {

    Node left;
    int data;
    Node right;

    public Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }

}

public class Tree {

    static int depth(Node root) {
        if (root == null) {
            return 0;
        }
        return 1 + max(depth(root.left), depth(root.right));
    }

    static int height(Node root) {
        if (root == null) {
            return -1;
        }
        return 1 + max(height(root.left), height(root.right));
    }

    static int max(int a, int b) {
        return (a > b) ? a : b;
    }

    static void inorder(Node node) {
        if (node == null) {
            return;
        }
        inorder(node.left);
        System.out.print(node.data + " ");
        inorder(node.right);
    }

    static void preorder(Node node) {
        if (node == null) {
            return;
        }
        System.out.print(node.data + " ");
        preorder(node.left);
        preorder(node.right);
    }

    static void postorder(Node node) {
        if (node == null) {
            return;
        }

        postorder(node.left);
        postorder(node.right);
        System.out.print(node.data + " ");
    }

    static boolean isEqual(Node node1, Node node2) {

        if (node1 == null && node2 == null)
            return true;

        if (node1 == null || node2 == null)
            return false;

        return node1.data == node2.data && isEqual(node1.left, node2.left) && isEqual(node1.right, node2.right);
    }

    static boolean isSubtree(Node t, Node s) {

        if (s == null)
            return true;
        if (t == null)
            return false;

        if (isEqual(t, s))
            return true;

        return isSubtree(t.left, s) || isSubtree(t.right, s);
    }

    public static void main(String[] args) {

        // Simple Binary tree
        /*
                5
               /  \
              4    1
             /    /  \
            8   12   10
           / \
          9   7
        */

        // Level 0 - root
        Node root = new Node(5);

        // Level 1 - Set left and right of root.
        root.left = new Node(4);
        root.right = new Node(1);

        // Level 2 - left
        root.left.left = new Node(8);

        // Level 2 - right
        root.right.left = new Node(12);
        root.right.right = new Node(10);

        // level 3 - left
        root.left.left.left = new Node(9);
        root.left.left.right = new Node(7);

        // Maximum depth of root is 4
        assert 4 == depth(root);

        // Height of root is 3
        assert 3 == height(root);
        System.out.println("***** Inorder traversal *****");
        inorder(root);
        System.out.println("\n***** Preorder traversal *****");
        preorder(root);
        System.out.println("\n***** Postorder traversal *****");
        postorder(root);

        //Subtree
        Node subtree=new Node(1);
        subtree.left=new Node(12);
        subtree.right=new Node(10);
        assert true==isSubtree(root,subtree); 

        //Add one more node to make subtree to be false
        subtree.left.right=new Node(6);
        assert true==isSubtree(root,subtree); 
    }

}
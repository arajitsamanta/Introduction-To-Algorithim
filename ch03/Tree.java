
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

    static int  depth(Node root) {
        if (root == null) {
            return 0;
        }
        return 1 + max(depth(root.left), depth(root.right));
    }

    static int  height(Node root) {
        if (root == null) {
            return -1;
        }
        return 1 + max(height(root.left), height(root.right));
    }

    static int max(int a, int b) {
        return (a > b) ? a : b;
    }

    public static void main(String[] args) {
        
        //Simple Binary tree
        /*
                5
               /  \
              4    1
             /    /  \
            8   12   10
           / \ 
          9   7
        */

        //Level 0 - root
        Node root = new Node(5);
        
        //Level 1 - Set left and right of root.
        root.left=new Node(4);
        root.right=new Node(1);

        //Level 2 - left
        root.left.left=new Node(8);

        //Level 2 - right
        root.right.left=new Node(12);
        root.right.right=new Node(10);

        //level 3 - left
        root.left.left.left=new Node(9);
        root.left.left.right=new Node(7);

        //Maximum depth of root is 4
        assert 4 == depth(root);

        //Height of root is 3
        assert 3 == height(root);
        
    }

}
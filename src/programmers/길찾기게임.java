
import java.util.*;

class Solution {
    public static int nodeNum =0;
    public int[][] solution(int[][] nodeinfo) {

        List<TreeNode> tree = new ArrayList<TreeNode>();

        tree = makeTree(tree, nodeinfo);

        Collections.sort(tree, new Comparator<TreeNode>(){
            public int compare(TreeNode n1, TreeNode n2){
                if(n1.y > n2.y){
                    return -1;
                } else if(n1.y<n2.y){
                    return 1;
                } else{ //y가 같을 때 x 비교
                    if(n1.x>n2.x){
                        return -1;
                    }
                    if(n1.x<n2.x){
                        return 1;
                    }else{
                        return 0;
                    }
                }
            }
        });

        TreeNode root = tree.get(0);

        int[][] answer = new int[2][tree.size()];

        for(int i=1;i<tree.size();i++){
            addNode(root, tree.get(i));
        }
        preorder(answer, root);
        nodeNum = 0;
        postorder(answer, root);
        
        return answer;
    }

    void preorder(int[][] arr, TreeNode root){
        if(root!=null){
            arr[0][nodeNum++] = root.getNum();
            preorder(arr, root.left);
            preorder(arr, root.right);
        }
    }

    void postorder(int[][] arr, TreeNode root){
        if(root!=null){
            postorder(arr, root.left);
            postorder(arr, root.right);
            arr[1][nodeNum++] = root.getNum();
        }
    }

    void addNode(TreeNode parent, TreeNode child){
        if(parent.x > child.x){
            if(parent.left==null){
                parent.left = child;
            }else{
                addNode(parent.left, child);
            }
        }else{
            if(parent.right==null){
                parent.right = child;
            }else{
                addNode(parent.right, child);
            }
        }
    }

    private List<TreeNode> makeTree(List<TreeNode> tree, int[][] nodeinfo) {
        for(int i=0;i<nodeinfo.length;i++){
            tree.add(new TreeNode(nodeinfo[i][0], nodeinfo[i][1], i+1));
        }
        return tree;
    }


    public class TreeNode{
        int num;
        int x;
        int y;
        TreeNode left;
        TreeNode right;

        public TreeNode(int x, int y, int num){
            this.x = x;
            this.y = y;
            this.num = num;
        }

        public int getNum(){
            return this.num;
        }
    }
    
}

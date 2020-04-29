import java.util.ArrayList;
import java.util.PriorityQueue;

public class Q004Leetcode642 {

    public class Node {
        Node[] childs;
        int count = 0;
        boolean wordEnd = false;
        String word = "";

        Node() {
            childs = new Node[27];
            count = 0;
        }
    }

    Node root = null;

    public void insert(string str, int count) {
        Node curr = root;
        int n = str.length();
        int idx = 0;

        for (int i = 0; i < n; i++) {
            char ch = str.charAt(i);
            idx = ((ch == ' ') ? 26 : ch - 'a');
            if (curr.childs[idx] == null)
                curr.childs[idx] = new Node();
            curr = curr.childs[idx];
        }
        curr.wordEnd = true;
        curr.count += count;
        curr.word = str;
    }

    public Node search(string word) {
        Node curr = root;
        int n = str.length();
        int idx = 0;

        for (int i = 0; i < n; i++) {
            char ch = str.charAt(i);
            idx = ((ch == ' ') ? 26 : ch - 'a');
            if (curr.chils[i] == null)
                return null;

            curr = curr.next;
        }
        return curr;
    }

    public List<String> allPossibilities(Node node) {

        for (int i = 0; i < 27; i++) {
               
        }
    }

    String prefix;

    public AutocompleteSystem(String[] sentences, int[] times) {
        root=new Node();
        prefix="";

        for(int i=0;i<sentences.length ;i++){
            insert(sentences[i],times[i]);
        }
    }

    public List<String> input(char c) {
        List<String> ans = new ArrayList<>();
        if (ch == '#') {
            insert(prefix, 1);
            prefix = "";
            return ans;
        }

        prefix += ch;
    }

}
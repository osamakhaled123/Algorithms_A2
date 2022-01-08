import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class P7 {

    static class Node {
        int symbol ;
        int freq;
        String code;
        Node childl;
        Node childr;
    }


    static class Huffman {
        int n = 0;
        Vector<Integer> freq = new Vector<>();
        Vector<Integer> chars = new Vector<>();

        static class condition implements Comparator<Node> {
            public int compare(Node x, Node y) {
                return x.freq - y.freq;
            }
        }

        //calculating the frequency
        public void freq(List<Integer> data){
            for (Integer datum : data) {
                if (chars.contains(datum)) {
                    int index = chars.indexOf(datum);
                    freq.setElementAt(freq.get(index) + 1, index);
                } else {
                    chars.add(datum);
                    freq.add(1);
                }
            }
            n= freq.size();
            this.compress();
            if (n > 1){
                System.out.println(count);
            }else{
                System.out.println(0);
            }

        }
        int count =0;
        //assigning binary values to each node
        public void printCode(Node root, String s) {
            if (root == null) return;
            if (root.childl == null && root.childr == null) {
                root.code = s;
                count += s.length()* root.freq;
            } else {
                printCode(root.childl, s + "0");
                printCode(root.childr, s + "1");
            }
        }

        public void compress(){
            PriorityQueue<Node> q = new PriorityQueue<>(n, new condition());
            //creating and adding the nodes to the queue
            for (int i = 0; i < n; i++) {
                Node node = new Node();
                node.symbol = chars.get(i);
                node.freq = freq.get(i);
                node.childl = null;
                node.childr = null;
                q.add(node);
            }
            //creating a node for the root
            Node root = new Node();
            while (q.size() > 1) {
                Node l = q.remove();
                Node r = q.remove();
                Node father = new Node();
                father.freq = l.freq + r.freq;
                father.childl = l;
                father.childr = r;
                root = father;
                q.add(root);
            }
            printCode(root, "");
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int size = Integer.parseInt(input.readLine()) ;
        ArrayList<Integer> data = new ArrayList<>();
        String[] strNums;
        strNums = input.readLine().split(" ");
        for (int i=0; i< size; i++){
            data.add(Integer.parseInt(strNums[i]));
        }
        int queriesNum = Integer.parseInt(input.readLine()) ;
        ArrayList<Integer> queries = new ArrayList<>();
        for (int i =0 ; i< queriesNum*2; i+=2){
            strNums = input.readLine().split(" ");
            queries.add(Integer.parseInt(strNums[0]));
            queries.add(Integer.parseInt(strNums[1]));
        }
        for (int i =0; i< queriesNum*2; i+=2){
            Huffman huffman = new Huffman();
            List<Integer> temp = data.subList(queries.get(i)-1,queries.get(i+1));
            huffman.freq(temp);
        }
    }
}
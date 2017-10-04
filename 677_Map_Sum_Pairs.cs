/* 677. Map Sum Pairs
 * Construct a Trie structure, besides character, children and isLeaf, add subSum recording all chilren's val and parent node
 * when insert(), find the word from head and add add subSum as needed, if the word exist, trace back via parent to correct added subSum
 * when Sum(), return the subSum of target prefix
 */ 

public class MapSum {
    class TrieNode{
        public char c;
        public bool isLeaf;
        public int subSum;
        public TrieNode[] children;
        public TrieNode parent;
        
        public TrieNode(): this(' ') {}
        public TrieNode(char new_c){
            c = ' ';
            isLeaf = false;
            subSum = 0;
            children = new TrieNode[26];
            for(int i = 0; i < 26; ++i){
                children[i] = null;
            }
            parent = null;
        }
        
        public TrieNode subNode(char character){
            return children[character - 'a'];
        }
    }

    private TrieNode head;
    
    /** Initialize your data structure here. */
    public MapSum() {
        head = new TrieNode();
    }
    
    public void Insert(string key, int val) {
        head.subSum += val;
        TrieNode tar = head;
        for(int i = 0; i < key.Length; ++i){
            TrieNode tmp = tar.subNode(key[i]);
            if(tmp == null){
                TrieNode newNode = new TrieNode(key[i]);
                tar.children[key[i] - 'a'] = newNode;
                newNode.parent = tar;
                tar = newNode;
            }else{
                tar = tmp;
            }
            tar.subSum += val;
        }
        if(tar.isLeaf){
            int ori = tar.subSum - val;
            // substract val form root
            while(tar != head){
                tar.subSum -= ori;
                tar = tar.parent;
            }
            head.subSum -= ori;
        }else{
            tar.isLeaf = true;
        }
    }
    
    public int Sum(string prefix) {
        TrieNode tar = head;
        for(int i = 0; i < prefix.Length; ++i){
            tar = tar.subNode(prefix[i]);
            if(tar == null) return 0;
        }
        return tar.subSum;
    }
}

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.Insert(key,val);
 * int param_2 = obj.Sum(prefix);
 */
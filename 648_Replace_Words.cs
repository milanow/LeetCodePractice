/* 648. Replace Words
 * Use a trie structre to store all roots, the root has been optimized via 2 ways:
 * 1. end inserting longer root as insert strings in dictionary
 * 2. stop searching when find no possible root formed
 * After constructing the tree, continuely check each word in the sentence
 */

public class Solution {
    public class Trie{
        bool isRoot = false;
        Trie[] children;
        
        public Trie(){
            children = new Trie[26];
            for(int i = 0; i < 26; ++i){
                children[i] = null;
            }
        }
        
        public void Insert(string word, int idx, int sz){
            isRoot |= idx == sz;
            if(!isRoot){
                if(children[word[idx] - 'a'] == null) children[word[idx] - 'a'] = new Trie();
                children[word[idx] - 'a'].Insert(word, idx+1, sz);
            }
        }
        
        // return int represents the length of word 'replaced' (means it can be original word or a root)
        public int Root(string s, int start, int idx, int sz){
            if(start + idx == sz || s[start+idx] == ' ' || isRoot) return idx;
            if(children[s[start+idx] - 'a'] == null){
                while(start + idx < sz && s[start+idx] != ' ') ++idx;
                return idx;
            }
            return children[s[start+idx] - 'a'].Root(s, start, idx+1, sz);
        }
    }
    
    public string ReplaceWords(IList<string> dict, string sentence) {
        Trie trie = new Trie();
        var res = new StringBuilder("");
        foreach(string s in dict){
            trie.Insert(s, 0, s.Length);
        }
        
        int len = sentence.Length;
        for(int i = 0; i < len;){
            if(sentence[i] == ' ') {
                res.Append(' ');
                ++i;
            }
            int l = trie.Root(sentence, i, 0, len);
            res.Append(sentence.Substring(i, l));
            for(i += l; i < len && sentence[i] != ' '; ++i);
        }
        return res.ToString();
    }
}
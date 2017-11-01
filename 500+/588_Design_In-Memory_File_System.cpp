/* 588. Design In-Memory File System
 * Tire structure to stroe file and directory as a directory system.
 * Note: trie node can represent both file and directory by isFile
 * if the trie node is a file (isFile = true), then its child represents
 * the content of this file (child's isFile = false, but it doesn't matter)
 * A private retrieveAndAdd method is added due to most of APIs are about
 * retrieving and adding new Trie node.
 */

class FileSystem {
    struct Trie{
        bool isFile;
        string name;
        vector<Trie*> children;
        Trie(string _name): name(_name) {
            isFile = false;
        }
    };
    
    Trie* root;
public:
    FileSystem() {
        root = new Trie("");
    }
    
    vector<string> ls(string path) {
        vector<string> res;
        Trie* cur = retriveAndAdd(path);
        if(cur->isFile){
            res.push_back(cur->name);
            return res;
        }
        
        for(auto t: cur->children){
            res.push_back(t->name);
        }
        sort(res.begin(), res.end());
        return res;
    }
    
    void mkdir(string path) {
        retriveAndAdd(path);
    }
    
    void addContentToFile(string filePath, string content) {
        Trie* cur = retriveAndAdd(filePath);
        if(!cur->isFile){
            cur->isFile = true;
            cur->children.push_back(new Trie(content));
        }else{
            (cur->children)[0]->name += content;
        }
    }
    
    string readContentFromFile(string filePath) {
        Trie* cur = retriveAndAdd(filePath);
        return cur->children[0]->name;
    }
    
private:
    Trie* retriveAndAdd(string path){
        Trie* cur = root;
        istringstream iss(path);
        string dir;
        getline(iss, dir, '/');
        while(getline(iss, dir, '/')){
            Trie* child = nullptr;
            for(int i = 0; i < cur->children.size(); ++i){
                if((cur->children)[i]->name == dir){
                    child = (cur->children)[i];
                    break;
                }
            }
            if(!child){
                child = new Trie(dir);
                cur->children.push_back(child);
            }
            cur = child;
        }
        return cur;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem obj = new FileSystem();
 * vector<string> param_1 = obj.ls(path);
 * obj.mkdir(path);
 * obj.addContentToFile(filePath,content);
 * string param_4 = obj.readContentFromFile(filePath);
 */
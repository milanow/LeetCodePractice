/* 604. Design Compressed String Iterator
 * hasNext() can increase the "iterator" by one
 * every time we call next() we should call hasNext first
 * istringstream is used to parse input of character and counter
 */

class StringIterator {
    istringstream iss;
    int cnt;
    char cur_c;
public:
    StringIterator(string compressedString) {
        iss = istringstream(compressedString);
        cnt = 0;
        cur_c = ' ';
    }
    
    char next() {
        if(hasNext()){
            --cnt;
            return cur_c;
        }else{
            return ' ';
        }
    }
    
    bool hasNext() {
        if(cnt == 0){
            iss >> cur_c >> cnt;
        }
        return cnt > 0;
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */
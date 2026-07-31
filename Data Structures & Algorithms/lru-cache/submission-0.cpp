class LRUCache {
public:
    int cap;
    unordered_map<int,int> mpp;
    vector<int> st;  

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end()) 
            return -1;
        for(int i = 0; i < st.size(); i++) {
            if(st[i] == key) {
                st.erase(st.begin() + i);
                break;
            }
        }

        st.push_back(key);
        return mpp[key];
    }
    
    void put(int key, int value) {
        
        if(mpp.find(key) != mpp.end()) {
            for(int i = 0; i < st.size(); i++) {
                if(st[i] == key) {
                    st.erase(st.begin() + i);
                    break;
                }
            }
        }
        else if(st.size() == cap) {
            int lastkey = st[0];
            st.erase(st.begin());
            mpp.erase(lastkey);
        }

        mpp[key] = value;
        st.push_back(key);
    }
};
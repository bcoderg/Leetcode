struct Node {
    int key, val, freq;
    Node* next;
    Node* prev;
    Node(int _key, int _val) {
        key = _key;
        val = _val;
        freq = 1;
    }
};

struct List {
    Node* head;
    Node* tail;
    int size;

    List() {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addNodeAtFront(Node *node) {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }

    void removeNode(Node *delnode) {
        Node* delnext = delnode->next;
        Node* delprev = delnode->prev;
        delnext->prev = delprev;
        delprev->next = delnext;
        size--;
    }
};

class LFUCache {
public:
    map<int , Node*>keyMap;
    map<int , List*>freqListMap;
    int capacity;
    int curSize;
    int minFreq;
    LFUCache(int capacity) {
        this->capacity = capacity;
        curSize = 0;
    }

    //update frequency lists after each operation
    void updateFreqListMap(Node* node) {
        int curFreq = node->freq;
        freqListMap[curFreq]->removeNode(node);

        //if curFreqList empty, update minfreq by 1
        if (curFreq == minFreq && freqListMap[curFreq]->size == 0) {
            minFreq++;
        }

        int nextHighFreq = curFreq + 1;
        node->freq = nextHighFreq;
        List* nextFreqList = new List();
        if (freqListMap.find(nextHighFreq) != freqListMap.end()) {
            nextFreqList = freqListMap[nextHighFreq];
        }
        freqListMap[nextHighFreq] = nextFreqList;
        freqListMap[nextHighFreq]->addNodeAtFront(node);
    }

    int get(int key) {
        if (keyMap.find(key) != keyMap.end()) {
            Node* node = keyMap[key];
            int val = node->val;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }

    void put(int key, int value) {
        //existing element
        if (keyMap.find(key) != keyMap.end()) {
            Node* node = keyMap[key];
            node->val = value;
            updateFreqListMap(node);
        }
        else { //new element
            if (curSize == capacity) { //space full need to delete LFU one
                List* list = freqListMap[minFreq];
                Node* node = list->tail->prev;//least recently used in minFreq list
                keyMap.erase(node->key);
                list->removeNode(node);
                curSize--;
            }
            curSize++; //adding new element so increase size
            minFreq = 1;
            List* list = new List();
            if (freqListMap.find(minFreq) != freqListMap.end()) {
                list = freqListMap[minFreq];
            }
            Node* node = new Node(key, value);
            list->addNodeAtFront(node);
            keyMap[key] = node; //add to keyMap
            freqListMap[minFreq] = list;//update in freqListMap
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
#include <bits/stdc++.h>
using namespace std;

struct trie_node{
    int count, depth;
    unordered_map<char, trie_node*> trie;
    string topic, end;
    vector<trie_node*> *gc;

    trie_node(vector<trie_node*> &garbage_collection, const string& t, int d = 0){
        count = 0;
        end = string();
        topic = t;
        depth = d;
        gc = &garbage_collection;
        gc->push_back(this);
    }

    trie_node(vector<trie_node*> &garbage_collection, const string& t, int d, const string& s){
        count = 1;
        end = s;
        topic = t;
        depth = d;
        gc = &garbage_collection;
        gc->push_back(this);
    }

    void insert(const string& s){
        if(!count){
            count++;
            end = s;
        }else{
            if(depth < end.size() && count == 1){
                trie_node *new_node = new trie_node(*gc, topic, depth+1, end);
                trie.insert(pair<char, trie_node*>(end[depth], new_node));
                end = string();
            }
            count++;
            if(depth < s.size()){
                if(trie.find(s[depth]) == trie.end()){
                    trie_node *new_node = new trie_node(*gc, topic, depth+1, s);
                    trie.insert(pair<char, trie_node*>(s[depth], new_node));
                }else
                    trie.at(s[depth])->insert(s);
            }else
                end = s;    
        }
    }

    void operator+=(trie_node *b){
        if(!count){
            count = b->count;
            depth = b->depth;
            trie = b->trie;
            end = b->end;
        }else{
            if(count == 1 && depth < end.size()){
                trie_node *new_node = new trie_node(*gc, topic, depth+1, end);
                trie.insert(pair<char, trie_node*>(end[depth], new_node));
                end = string();
            }
            if(b->count == 1){
                if(depth < b->end.size()){ 
                    char key = b->end[depth];
                    trie_node *new_node = new trie_node(*gc, topic, depth+1, b->end);
                    if(trie.find(key) != trie.end()){
                        trie_node *node = trie.at(key);
                        if(node->topic != topic){
                            trie_node *new_node = new trie_node(*gc, topic);
                            new_node->count = node->count;
                            new_node->depth = node->depth;
                            new_node->trie = node->trie;
                            new_node->end = node->end;
                            trie[key] = new_node;
                        }
                        *trie.at(key) += new_node;
                    }else{
                        trie.insert(pair<char, trie_node*>(key, new_node)); 
                    }
                }else
                    end = b->end;
            }
            count += b->count;
            for(unordered_map<char, trie_node*>::iterator it = b->trie.begin(); it != b->trie.end(); it++){
                char key = it->first;
                if(trie.find(key) == trie.end()){
                    trie.insert(pair<char, trie_node*>(key, it->second));
                }else{
                    trie_node *node = trie.at(key);
                    if(node->topic != topic){
                        trie_node *new_node = new trie_node(*gc, topic);
                        new_node->count = node->count;
                        new_node->depth = node->depth;
                        new_node->trie = node->trie;
                        new_node->end = node->end;
                        trie[key] = new_node;
                    }
                    *trie.at(key) += it->second;
                }
            }
        }
    }

    int query(const string& str){
        int d = 0, len = str.size();
        trie_node *cur = this;
        while(d < len && cur->trie.find(str[d]) != cur->trie.end()){
            cur = cur->trie.at(str[d]);
            d++;
        }
        if(d == len)
            return cur->count;
        string *curstr = &(cur->end);
        int curlen = curstr->size();
        for(; d < len && d < curlen; d++)
            if(str[d] != (*curstr)[d])
                return 0;
        if(d == len)
            return 1;
        return 0;
    }
};

void clear_garbage(vector<trie_node*>& garbage_collection){
    for(auto node : garbage_collection)
        delete node;
}

int get_number_from_line(){
    int t;
    string tmp;
    getline(cin, tmp);
    stringstream ss(tmp);
    ss >> t;
    return t;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int N, M, K;
    N = get_number_from_line();
    string flat_tree;
    getline(cin, flat_tree);
    M = get_number_from_line();
    
    unordered_map<string, vector<string> > questions;
    while(M--){
        string s, topic, question;
        getline(cin, s);
        stringstream ss(s);
        getline(ss, topic, ':');
        ss.ignore(100000, ' ');
        getline(ss, question);
        questions[topic].push_back(question);
    }

    unordered_map<string, trie_node*> trie(N+5);
    vector<trie_node*> garbage_collection;

    stack<string> flat_tree_traversal;
    stringstream tree(flat_tree);
    while(tree.good()){
        string topic;
        tree >> topic;
        if(topic == ")"){
            queue<trie_node*> aggregate_queue;
            while(!flat_tree_traversal.empty() && flat_tree_traversal.top() != "("){
                aggregate_queue.push(trie.at(flat_tree_traversal.top()));
                flat_tree_traversal.pop();
            }
            if(!flat_tree_traversal.empty())
                flat_tree_traversal.pop();
            if(!flat_tree_traversal.empty())
                topic = flat_tree_traversal.top();
            trie_node *head = trie.at(topic);
            while(!aggregate_queue.empty()){
                *head += aggregate_queue.front();
                aggregate_queue.pop();
            }
        }else{
            flat_tree_traversal.push(topic);
            if(topic != "("){
                trie_node *head = new trie_node(garbage_collection, topic);
                if(questions.find(topic) != questions.end()){
                    vector<string> *topic_questions = &questions.at(topic);
                    int size = topic_questions->size();
                    for(int i = 0; i < size; i++)
                        head->insert((*topic_questions)[i]);
                }
                trie.insert(pair<string, trie_node*>(topic, head));
            }
        }
    }

    K = get_number_from_line();
    while(K--){
        string str, topic, query;
        getline(cin, str);
        stringstream parser(str);
        parser >> topic;
        parser.ignore(100000, ' ');
        getline(parser, query);
        cout << trie.at(topic)->query(query) << endl;
    }

    clear_garbage(garbage_collection);

	return 0;
}

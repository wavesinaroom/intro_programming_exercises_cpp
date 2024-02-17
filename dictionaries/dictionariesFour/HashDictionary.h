#include <iostream>
#include <vector>

template<typename Key, typename Value>
class HashDictionary{
  private:
    std::vector<std::pair<Key, Value>> table;

  public:
    HashDictionary(int size);
    void insert(Key key, Value value);
    Value get(Key key);
    void remove(Key key); 
    friend class Dicset;
};

template<typename Key, typename Value>
HashDictionary<Key, Value>::HashDictionary(int size){
  table.resize(size);
}

template<typename Key, typename Value>
void HashDictionary<Key, Value>::insert(Key key, Value value){
  int index = key % table.size();
  table[index] = std::make_pair(key, value);
}

template<typename Key, typename Value>
Value HashDictionary<Key, Value>::get(Key key){
  int index = key % table.size();
  return table[index].second;
}

template<typename Key, typename Value>
void HashDictionary<Key, Value>::remove(Key key){
  int index = key % table.size();
  table[index] = std::make_pair(NULL, NULL);
}

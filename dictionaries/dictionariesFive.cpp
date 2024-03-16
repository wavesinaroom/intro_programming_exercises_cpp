/* Implement a hash-table, maintaining triples (key1, key2, value) and allowing quick search by the pair of keys and adding of triples*/

#include <iostream>
#include <vector>
#include <string>
#include <list>

template<typename KEY, typename VALUE>
class Data{
  KEY key_one;
  KEY key_two;
  VALUE value;

  public:
    Data():key_one(), key_two(), value(){};
    Data(KEY key_one, KEY key_two, VALUE value){
      this->key_one = key_one;
      this->key_two = key_two;
      this->value = value;
    }
    template<typename K, typename V> friend class HashTable;
};

template<typename KEY, typename VALUE>
class HashTable{
  std::vector<std::list<Data<KEY, VALUE>>> table;
  int getHashKey(Data<KEY, VALUE> data);
  public:
    HashTable(){
      table.resize(16);
    };

    void insert(Data<KEY, VALUE> data){
      int pos = getHashKey(data);
      if(!isDuplicate(data, pos)){
        table[pos].push_back(data);
        return;
      }
      std::cerr<<"Key values are duplicated"<<'\n';
    }

    bool isDuplicate(Data<KEY, VALUE> data, int pos){
      for(auto const & t:table[pos]){
        if(data.key_one == t.key_one){
          if(data.key_two == t.key_two)
            return true;
        }else if(data.key_two == t.key_one){
          if(data.key_one == t.key_two)
            return true;
        }
      }
      return false;
    }
};

template<>
int HashTable<std::string, std::string>::getHashKey(Data<std::string, std::string> data){
  int sum_one = 0, sum_two = 0;
  std::string::iterator it;
  
  for(it = data.key_one.begin(); it!=data.key_one.end(); ++it){
    sum_one += (int)*it;
  }

  for(it = data.key_two.begin(); it!=data.key_two.end(); ++it){
    sum_two += (int)*it;
  }

  return(sum_one+sum_two)% table.size();

}

template<>
int HashTable<std::string, int>::getHashKey(Data<std::string, int> data){
  int sum_one = 0, sum_two = 0;
  std::string::iterator it;

  for(it = data.key_one.begin(); it!=data.key_one.end(); ++it){
    sum_one += (int)*it;
  }

  for(it = data.key_two.begin(); it!=data.key_two.end(); ++it){
    sum_two += (int)*it;
  }

  return(sum_one+sum_two)% table.size();
}

int main(){
  HashTable<std::string, int> hash;
  Data<std::string, int> data("one", "two", 3);
  Data<std::string, int> data_two("two", "three", 4);
  hash.insert(data);
  hash.insert(data_two);
  return 0;
}


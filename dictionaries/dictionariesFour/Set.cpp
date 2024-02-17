/* Implement a DicHashSet<T> class, based on HashDictionary<K, V> class, we discussed in the text above.*/  

/* Implementation methods
 * DONE  bool Add(element) - adding the element to the set and returning false if the element is already present inside the set, otherwise returning true.
 * DONE bool Contains(element) - checks if the set already contains the element passed as an argument. If yes, returns true as a result, otherwise returns false.
 * DONE bool Remove(element) - removes the element from the set. Returns boolean if the element has been present inside the set.
 * DONE void Clear() - removes all the elements from the set.
 * DONE void IntersectWith(Set other) - inside the current set remain only the elements of the intersection of both sets - the result is a set, containing the elements, which are present in both sets at the same time - the set, calling the method and the other, passed as parameter.
 * DONE void UnionWith(Set other) - inside the current set remain only the elements of the sets union - the result is a set, containing the elements of either one or the other, or both sets.
 * DONE bool IsSubsetOf(Set other) - checks if the current set is a subset of the other set. Returns true, if yes and false, if no.
 * DONE bool IsSupersetOf(Set other) - checks if the other set is a subset of the current one. Returns true, if yes and false, if no
 * DONE int Count - a property, which returns the current number of elements inside the set.*/ 

#include <iostream>
#include <vector>
#include "HashDictionary.h"
#include <algorithm>

template<typename Key, typename Value>
class Set{
  private:
    std::vector<HashDictionary<Key, Value>> set;
  public:
    Set();
    bool Add(HashDictionary<Key, Value> &input);
    bool Contains(HashDictionary<Key, Value> input);
    bool Remove(HashDictionary<Key, Value> &input);
    void Clear();
    void IntersectWith(Set other);
    void UnionWith(Set other);
    bool IsSubsetOf(Set other);
    bool IsSupersetOf(Set other);
    int Count();
};

template<typename Key, typename Value>
bool Set<Key, Value>::Add(HashDictionary<Key, Value> &input){
  auto found = std::find(set.begin(), set.end(), input);
  if(found!=set.end())
    return false;
  set.push_back(input);
  return true;
}

template<typename Key, typename Value>
bool Set<Key, Value>::Contains(HashDictionary<Key, Value> input){
  return (std::find(set.begin(), std::find(set.end(), input)!=set.end()));
}

template<typename Key, typename Value>
bool Set<Key, Value>::Remove(HashDictionary<Key, Value> &input){
  auto found = std::find(set.begin(),set.end(), input);
  if(found!=set.end()){
    set.erase(found);
    return true; 
  }
  return false;
}

template<typename Key, typename Value>
void Set<Key, Value>::Clear(){
  set.clear();
}

template<typename Key, typename Value>
void Set<Key, Value>::IntersectWith(Set<Key, Value> other){
  for(auto const & h:set){
    auto found = std::find(other.set.begin(), other.set.end(), h);
    if(found != other.end())
      return;
    set.erase(found);
  }
}

template<typename Key, typename Value>
void Set<Key, Value>::UnionWith(Set<Key, Value> other){
  for(auto const & h:other.set){
    auto found = std::find(set.begin(), set.end(), h);
    if(found == set.end())
      set.push_back(h);
  }
}

template<typename Key, typename Value>
bool Set<Key, Value>::IsSubsetOf(Set<Key, Value> other){
  for(auto const & h:set){
    auto found = std::find(other.set.begin(), other.set.end(), h);    
    if(found == other.set.end())
      return false;
  }
  return true;
}

template<typename Key, typename Value>
bool Set<Key, Value>::IsSupersetOf(Set<Key, Value> other){
  for(auto const & h:other.set){
    auto found = std::find(set.begin(), set.end(), h);
    if(found == set.end())
      return false;
  }
  return true;
}

template<typename Key, typename Value>
int Set<Key, Value>::Count(){
  return set.size();
} 


#include <string>
#include <iostream>
using namespace std;

/*
Class Library File
*/
class Node{
  public:
  void * airport;
  Node * pointer;
  ~Node()
  {
    delete pointer;
  }
};


class LinkedList{
  private:
  Node * headPoint;
  int length;
  public:
  LinkedList()
  {
    length = 0;
    headPoint = nullptr;
  }
  ~LinkedList()
  {
    clear();
  }
  
  int getLength()
  {
    return length;
  }
  
  void clear()
  {
    Node * placehold = headPoint;
    for(int i=0;i<length;i++)
    {
      Node * previous = placehold;
      placehold = placehold->pointer;
      delete previous;
    }
  }
  
  void insert(void * addAirport,int position)
  {
    if(position>length)
    throw "Out of Bounds";
    
    Node * added = new Node();
    added->airport = addAirport;
    if(length == 0 || position == 0)
    {
      added->pointer = headPoint;
      headPoint = added;
    }
    
    else
    {
    Node * current = headPoint;
    Node * previous = new Node();
    for(int i = 0;i<position && current != nullptr;i++)
    {
      previous = current;
      current = current->pointer;
    }
    previous->pointer = added;
    added->pointer = current;
    }
    length++;
  }
  
  void add(void* value)
  {
    insert(value, length);
  }
  
  void* get(int index)
  {
    if(index>=length)
    throw "Out of Bounds";
    Node * spot = headPoint;
    for(int i = 0;i<index;i++)
    {
      spot = spot->pointer;
    }
    return spot->airport;
  }
  
  int size()
  {
    return length;
  }
  
  bool isEmpty()
  {
    if(length == 0)
    return true;
    return false;
  }
  
  bool equals(LinkedList* list)
  {
    if(length == list->size())
    {
      for(int i = 0;i<length;i++)
      {
      if(list->get(i)!=get(i))
      return false;
      }
      return true;
    }
    return false;
  }
  
  void set(void* newAirport, int position)
  {
    if(position>=length)
    throw "Out of Bounds";
    Node * spot = headPoint;
    for(int i = 0;i<position;i++)
    {
      spot = spot->pointer;
    }
    spot->airport = newAirport;
  }
  
  void exchg(int index1, int index2)
  {
    void* store = get(index1);
    set(get(index2),index1);
    set(store,index2);
  }
  
  void remove(int index)
  {
    if(index > length)
    throw "Out of Bounds";
    Node * current = headPoint;
    Node * previous = nullptr;
    for(int i = 0; i<index;i++)
    {
      previous = current;
      current = current->pointer;
    }
    previous->pointer = current -> pointer;
    delete current;
    length--;
  }

  LinkedList subList(int start,int subLength)
  {
    if(start+subLength>=length)
    throw "Out of Bounds";
    LinkedList subList;
    for(int i=0;i<subLength;i++)
    {
      subList.add(get(start+i));
    }
    return subList;
  }

  void swap(int index1, int index2)
  {
    if(index1 >= length || index2 >= length)
    throw "Out of Bounds";
    Node * itself1 = new Node();
    Node * next1 = new Node();
    Node * itself2 = new Node();
    Node * next2 = new Node();
    Node * current = headPoint;
    for(int i = 0;i<=index1 && i<=index2;i++)
    {
    current = current->pointer;
    if(i==index1)
    {
      itself1 = current;
      next1 = current->pointer;
    }
    if(i==index2)
    {
      itself2 = current;
      next2 = current->pointer;
    }
    }
    Node * storage = next1;
    next1=next2;
    next2=storage;
    Node * store = itself1;
    itself1=itself2;
    itself2=store;
  }
    
    /*string toString()
    {
      string returning = "";
      Node * current = headPoint;
      for(int i = 0;i<length;i++)
      {
      current = current->pointer;
      returning += current->airport->toString();
      }
      return returning;
    }*/
  };
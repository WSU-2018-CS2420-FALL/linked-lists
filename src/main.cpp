#include <iostream>
#include "linked_list_adt.h"
using namespace std;

int main(){
  LinkedList<int> nums;
  nums.add(5);
  nums.add(17);
  nums.add(23);

 
 for(int n : nums){
   cout << n << endl;
 }

  nums.remove( 17);
  nums.remove(99);

  nums.print();

  return 0;
}
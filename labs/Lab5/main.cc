#include "list.h"
#include <iostream>


int main() {
    List mylist;
    
    std::cout << "Testing the List Class" << std::endl;
    
    // insert some numbers
    mylist.insert_end(10);
    mylist.print_list();
    mylist.insert_end(20);
    mylist.print_list();
    mylist.insert_end(30);
    mylist.print_list();
    mylist.insert_end(40);
    mylist.print_list();
    mylist.insert_end(50);
    mylist.print_list();
    mylist.insert_end(60);
    mylist.print_list();
    
    // remove
    mylist.remove(20);
    mylist.print_list();
    
    mylist.remove(40);
    mylist.remove(30);
    mylist.print_list();
    
    mylist.remove(10);
    mylist.print_list();
    
    mylist.remove(60);
    mylist.print_list();
    
    mylist.remove(50);
    mylist.print_list();
    
    mylist.remove(100);
    mylist.print_list();
    
}// end main

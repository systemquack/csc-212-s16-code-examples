#include "list.h"
#include <iostream>


int main() {
    List mylist;
    
    std::cout << "Testing the List Class" << std::endl;
    
    mylist.insert_end(10);
    mylist.insert_end(20);
    mylist.insert_end(30);
    
    mylist.print_list();
    
    mylist.insert_end(40);
    
    mylist.print_list();
    
    mylist.insert_end(50);
    
    mylist.print_list();
    
    mylist.insert_end(60);
    
    mylist.print_list();
    
    mylist.remove(60);
    
    mylist.print_list();
    
}// end main

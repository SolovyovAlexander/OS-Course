


#include "LinkedList.h"
int main() {
    insert_node(1);//when list is empty function insert will create list
    insert_node(2);
    insert_node(3);
    insert_node(4);
    insert_node(5);
    delete(2);//delete element in position 2
    print_list();


}

//exercise 2
void buble_sort(int ar[], int size){
    for (int i = 0; i <size-1 ; ++i) {
        for (int j = 0; j <size-1; ++j) {
            if (ar[j]>ar[j+1]){
                int temp=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=temp;
            }
        }
    }
}



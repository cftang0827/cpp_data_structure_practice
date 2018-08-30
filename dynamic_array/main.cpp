#include <iostream>

using namespace std;

class dynamic_array{
    public:
        dynamic_array();
        ~dynamic_array();
        void add(int push_number);
        void remove(int remove_number);
        int get(int index);
        int size();
    private:
        void expand_array();
        void shrink_array();
        int init_capacity;
        int *data;
        int add_capacity;
        int data_counter;
};

dynamic_array::dynamic_array(){
    init_capacity = 5;
    add_capacity = 5;
    data_counter = 0;
    data = new int[init_capacity];
}

dynamic_array::~dynamic_array(){
    delete [] data;
    data_counter = 0;
}

void dynamic_array::add(int push_number){
    if (data_counter < init_capacity){
        data[data_counter] = push_number;
        data_counter += 1;
    }else{
        expand_array();
        data[data_counter] = push_number;
        data_counter += 1;
    }
}

void dynamic_array::expand_array(){
    cout << "expand array" << endl;
    init_capacity = init_capacity + add_capacity;
    int *new_data = new int[init_capacity];
    for (int i = 0; i < data_counter; i++){
        new_data[i] = data[i];
    }
    data = new_data;
}

void dynamic_array::shrink_array(){
    cout << "shrink array" << endl;
    
}

int dynamic_array::get(int index){
    if (index < data_counter){
        return data[index];
    }else{
        cout << "index error" << endl;
        return -1;
    }
}

int dynamic_array::size(){
    return data_counter;
}

void dynamic_array::remove(int remove_number){
    int remove_index = 0;
    for (int i = 0; i < data_counter; i++){
        if (data[i] == remove_number){
            remove_index = i;
        }
    }

    for (int i = remove_index; i < data_counter-1; i++){
        data[i] = data[i+1];
    }

    data_counter = data_counter - 1;


}

int main(){
    dynamic_array test = dynamic_array();
    for (int i = 0; i < 6; i++){
        cout << "insert index: " << i << endl;
        test.add(i);
    }

    cout << "test.size(): " << test.size() << endl;

    for (int i = 0; i < 20; i++){
        cout << "test.get(" << i << "): " << test.get(i) << endl;
    }
}
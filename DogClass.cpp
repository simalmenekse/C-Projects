#include <iostream>
#include <string_view>

class Dog{
    public:
        Dog() = default;
        Dog(std::string_view name_param, std::string_view breed_param, int age_param);
        ~Dog();

        void print_info(){
            std::cout<<"Dog (" << this << ") : [" << name << " breed: " << breed <<" age : " <<*p_age<<std::endl;
        }

        //Setters
        //Chained calles using pointers
        /*Dog* set_dog_name(std::string_view name){
            //name = name;
            this->name = name;
            return this;
        }
        Dog* set_dog_breed(std::string_view breed){
            this->breed = breed;
            return this;
        }
        Dog* set_dog_age(int age){
            *(this -> p_age) = age;
            return this;

        }*/


        //Chained calles using references
        Dog& set_dog_name(std::string_view name){
            //name = name;
            this->name = name;
            return *this;
        }
        Dog& set_dog_breed(std::string_view breed){
            this->breed = breed;
            return *this;
        }
        Dog& set_dog_age(int age){
            *(this -> p_age) = age;
            return *this;

        }



        private:
            std::string name;
            std::string breed;
            int *p_age{nullptr};

};

Dog::Dog(std::string_view name_param, std::string_view breed_param, int age_param){
    name = name_param;
    breed = breed_param;
    p_age = new int;
    *p_age = age_param;

    std::cout<<"Dog constructor called for: "<< name << " at " << this << std::endl;

}

Dog::~Dog(){
    delete p_age;
    std::cout<<"Dog destructor called for: "<< name << " at " << this << std::endl;
}

void some_func(){
    Dog *p_dog = new Dog("Fluffy", "Shepperd", 2);

    delete p_dog; //
}


int main(void){

    Dog dog1("Fluffy", "Shepperd", 2); //Constructor
    dog1.print_info();

    /*
    dog1.set_dog_name("Latte");
    dog1.set_dog_breed("Doberman");
    dog1.set_dog_age(3);*/

    //Chained calles using pointers
    //dog1.set_dog_name("Latte")->set_dog_breed("Doberman")->set_dog_age(4);

    //Chained calles using references
    dog1.set_dog_name("Latte").set_dog_breed("Doberman").set_dog_age(4);
    dog1.print_info();

    std::cout<<"Done"<<std::endl;


    return 0;
}
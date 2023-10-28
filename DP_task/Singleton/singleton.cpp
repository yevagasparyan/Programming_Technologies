#include<iostream>

class Singleton{
    private: 
	static Singleton* instance;
    private: 
	Singleton(){}
	Singleton(const Singleton&) = delete;
	Singleton operator = (const Singleton&) = delete;
    private: 
	int value;
    public: 
    	static Singleton& getInstance(){
    		if(!instance) {
    			instance = new Singleton();
    		}
    		return * instance;
    	}
    public:
    	void setValue(int value){
    		this->value = value;
    	} 
    	void printValue(){
    		std::cout<<"Value = " <<value<<std::endl;
    	}
    	~Singleton(){
    	 	delete instance;
    	 }    
};
Singleton *Singleton::instance = nullptr;


int main(){
	Singleton& obj = Singleton::getInstance();
	
	obj.setValue(10);
	obj.printValue();
	
	obj.setValue(15);
	obj.printValue();

	return 0;
}



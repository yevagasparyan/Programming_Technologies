#include<iostream>

class ChocolateFactory;

class Chocolate{
   public:
  	friend class ChocolateFactory;
   	static ChocolateFactory factory;
   public:
   	void print(){
   		std::cout<<"Eat you choco"<<std::endl;
   	}
   private:
   	Chocolate(float ing1, float ing2){}
};

class ChocolateFactory{
   public:
   	static Chocolate createWhiteChoco(float milk, float cacao){
   		std::cout<<"Created White chocolate"<<std::endl;
   		return {Chocolate(milk*100, cacao*20)};
   	}
   	static Chocolate createDarkChoco(float coffee, float cacao){
   		std::cout<<"Created Dark chocolate"<<std::endl;
   		return {Chocolate(coffee*60, cacao*20)};
   	}
};

int main(){
	Chocolate white_choco = ChocolateFactory::createWhiteChoco(5,5);
	white_choco.print();
	Chocolate dark_choco = ChocolateFactory::createDarkChoco(5,5);
	dark_choco.print();
	return 0;
}

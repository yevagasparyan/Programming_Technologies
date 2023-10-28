#include <iostream>
#include <string>

class Burger{
  public: 
	void set_meat(int meat){
	   std::cout<<"set meat"<<std::endl;
 	   m_meat = meat;
	}
	void set_bread(int bread){
	   std::cout<<"set bread"<<std::endl;
	   m_bread = bread;
	}
	void set_tomato(int tomato){
	   std::cout<<"set tomato"<<std::endl;
	   m_tomato = tomato;
	}	
	void set_cheese(int cheese){
	   std::cout<<"sett cheese"<<std::endl;
	   m_cheese = cheese;
	}
	void display(){
	   std::cout<<"burger is ready!"<<std::endl;
	}
  private: 
	int m_bread;
	int m_tomato;
	int m_cheese;
	int m_meat;
};

class BurgerBuilder {
  public: 
	virtual void build_bread() = 0;
	virtual void build_tomato() = 0;
	virtual void build_meat() = 0;
	virtual void build_cheese() = 0;
	virtual Burger get_burger() = 0;
};

class HamburgerBuilder:public BurgerBuilder{
  public: 
	void build_bread(){
	   burger.set_bread(2);
	}
	void build_tomato(){
	   burger.set_tomato(2);
	}
	void build_meat(){
	   burger.set_meat(2);
	}
	void build_cheese(){

	}
	Burger get_burger(){
	   return burger;
	}

  private: 
	Burger burger;
};		

class CheeseBuilder:public BurgerBuilder{
  public: 
	void build_bread(){
	   burger.set_bread(2);
	}
	void build_tomato(){

	}
	void build_meat(){
	   burger.set_meat(3);
	}
	void build_cheese(){
	   burger.set_cheese(3);
	}
	Burger get_burger(){
	   return burger;
	}

  private: 
	Burger burger;
};	

class BurgerMaker{
  public: 	 
	void make_burger(){
	   burger_builder->build_bread();
           burger_builder->build_tomato();
           burger_builder->build_meat();
           burger_builder->build_cheese();
	}
	Burger get_burger(){
	   return burger_builder->get_burger();
	}
	void set_burger_builder(BurgerBuilder * builder){
	   burger_builder = builder;
	}
  private:	 
	BurgerBuilder * burger_builder;
};

int main(){
   BurgerMaker maker;
 
   CheeseBuilder cheese_builder;
   maker.set_burger_builder(&cheese_builder);
   maker.make_burger();

   HamburgerBuilder ham_builder;
   maker.set_burger_builder(&ham_builder);
   maker.make_burger();

   Burger burger = maker.get_burger();
   burger.display();
   
   return 0;
}



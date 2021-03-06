#ifndef CF_LIVING_H
#define CF_LIVING_H
#include "Entity.h"
#include "Atmosphere.h"
#include<string>
using namespace std;

enum SEX{
	NON = 0,
	MALE = 1,
	FEMALE = 2,
	HERMAPHRODITISM = 3,		//雌雄同体

};

class Living :public Entity{
public:
	Living(vector<Abstract*>* abs_list, int size, int max_age,const char* name, SEX sex);

	~Living(){ delete name_; }

	virtual void die(){														//死亡时被调用。
		cout << name_ << " died just now." << endl;
	}																

	virtual Living* mate_with(Living* another) = 0;								 //交配函数，与另一个生物进行交配，返回所生子代个体的指针

	virtual void breath(Atmosphere* atm) = 0;										 //呼吸函数。调用改变atm二氧化碳和氧气浓度的函数

	virtual void grow() = 0;															//生长函数。随时间增长年龄

	const char* get_name(){ return name_->c_str(); }									//返回存放名字的字符串

	void set_name(const char* new_name);											 //更改生物名字

	virtual void time_pass_by() = 0;

	virtual void when_atmosphere_changed() = 0;

	virtual void update(Abstract* abs, AbstractType type) = 0;

	void set_health_gradient(float new_gradient){ health_gradient_ = new_gradient; }
protected:
	int age_;
	int max_age_;
	float grow_speed_;						//由空气气味浓度影响，是一个系数。在grow()中被使用
	float health_gradient_;					//健康值变化率，由空气微生物浓度影响，是一个系数。在time_pass_by()中被使用，影响健康度变化
	int health_;							 //归0后死亡。
	string* name_;
	SEX sex_;
};


#endif // !CF_ENTITY_H




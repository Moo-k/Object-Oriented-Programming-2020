#ifndef KITCHENAPPLIANCE_H
#define KITCHENAPPLIANCE_H

class KitchenAppliance{
public:
	KitchenAppliance();
	KitchenAppliance(bool inputisElectric);
	virtual bool isElectrical();
protected:
	bool isElectric;
};

#endif

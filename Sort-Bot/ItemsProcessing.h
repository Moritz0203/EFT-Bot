struct PathNameThreshold {
	const char* Path;
	const char* Name;
	const double Threshold;
};

class ItemsProcessing {
	void BarterItemsProcess();

	void cleanUpVectorItemsAmmunition();
	
	void cleanUpVectorItemsBarter();

public:
	void CallAll();

	void AmmunitionProcess();
};
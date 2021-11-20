class ParkingSystem {
public:
    int bigParking;
    int mediumParking;
    int smallParking;
    ParkingSystem(int big, int medium, int small) {
        bigParking = big;
        mediumParking = medium;
        smallParking = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1 && bigParking > 0) {
             bigParking--;
            return true;
        }
        if(carType == 2 && mediumParking > 0) {
            mediumParking--;
            return true;
        }
        if(carType == 3 && smallParking > 0) {
            smallParking--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
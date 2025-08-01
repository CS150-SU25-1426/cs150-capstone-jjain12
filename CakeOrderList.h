#ifndef CAKEORDERLIST_H
#define CAKEORDERLIST_H

#include <vector>
#include "Cake.h"
#include "CakeOrderList.h"

class CakeOrderList {
    private:
    vector<Cake> cakeOrders; 

    public: 
    CakeOrderList() {}
    int size() const;
   
    bool addCakeOrder(Cake cake);
    bool removeCakeOrder(int orderNum);
    bool editCakeOrder(int orderNum);

    bool operator==(const CakeOrderList& other) const;
    friend ostream& operator<<(ostream& os, const CakeOrderList& orderList);

};

#endif
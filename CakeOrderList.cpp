#include "Cake.h"
#include "CakeOrderList.h"

bool CakeOrderList::addCakeOrder(Cake cake) {
    cakeOrders.push_back(cake);
    return true; 
}

bool CakeOrderList::removeCakeOrder(int orderNum) {
    if (orderNum < 0 || orderNum >= cakeOrders.size()) {
        return false; 
    }
    cakeOrders.erase(cakeOrders.begin() + orderNum);
    return true; 
}

bool CakeOrderList::editCakeOrder(int orderNum) {
    cout << "*************************************************************************\n";
    cout << "Would you like to edit order #" << orderNum + 1 << "'s: \n";
    cout << "1) Flavor\n";
    cout << "2) Icing Flavor\n";
    cout << "3) Message\n";
    cout << "4) Filling\n";
    cout << "5) Decor\n";
    cout << "6) Size\n";
    cout << "7) Quantity\n";
    cout << "**************************************************************************\n";
    cout << "Enter your choice (1-7): ";
    int choice;
    cin >> choice;

    cout << endl;

    switch(choice) {
        case 1: {
            string flavor;
            cout << "Enter new flavor: ";
            cin.ignore(); 
            getline(cin, flavor);
            cakeOrders[orderNum].setFlavor(flavor);
            break;
        }
        case 2: {
            string icingFlavor;
            cout << "Enter new icing flavor: ";
            cin.ignore();
            getline(cin, icingFlavor);
            cakeOrders[orderNum].setIcingFlavor(icingFlavor);
            break;
        }
        case 3: {
            string message;
            cout << "Enter new message: ";
            cin.ignore();
            getline(cin, message);
            cakeOrders[orderNum].setMessage(message);
            break;
        }
        case 4: {
            string filling;
            cout << "Enter new filling: ";
            cin.ignore();
            getline(cin, filling);
            cakeOrders[orderNum].setFilling(filling);
            break;
        }
        case 5: {
            string decor;
            cout << "Enter new decor: ";
            cin.ignore();
            getline(cin, decor);
            cakeOrders[orderNum].setDecor(decor);
            break;
        }
        case 6: {
            int size;
            cout << "Enter new size (1-10): ";
            cin.ignore();
            cin >> size;
            cakeOrders[orderNum].setSize(size);
            break;
        }
        case 7: {
            int count;
            cout << "Enter new quantity: ";
            cin.ignore();
            cin >> count;
            cakeOrders[orderNum].setCount(count);
            break;
        }
        default:
            cout << "No changes made.\n";
            return false;
    }
    return true;

}

int CakeOrderList::size() const {return cakeOrders.size(); }

bool CakeOrderList::operator==(const CakeOrderList& other) const {
    return cakeOrders == other.cakeOrders; 
}

ostream& operator<<(ostream& os, const CakeOrderList& orderList) {
    os << "************************************************************************\n";
    os << "Display of Cake Orders: \n";
    os << "************************************************************************\n";
    
    for (int i = 0; i < orderList.cakeOrders.size(); ++i) {
        os << i + 1 << ") \n" << orderList.cakeOrders[i] << "\n";

    }
    return os;
}
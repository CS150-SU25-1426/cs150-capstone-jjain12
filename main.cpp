#include <iostream>
#include <iomanip>

#include "Cake.h"
#include "CakeOrderList.h"

using namespace std;

int main() {

    CakeOrderList orderList;

    //Preset Cakes:
    Cake chocolateCake("Chocolate", "Chocolate Ganache", "Happy Birthday!", "Raspberry Compote", "Sprinkles", 5, 1);
    Cake vanillaCake ("Vanilla", "Buttercream", "Happy Anniversary!", "", "Edible Flowers", 5, 1);
    Cake lemonCake ("Lemon", "Cream Cheese Icing", "Congratulations!", "Blueberry Jam", "Candied Lemons", 5, 1);
    Cake butterscotchCake ("Butterscotch", "Whipped Cream", "Happy Birthday", "Caramel Ganache", "Pecan Crumble", 5, 1);
    Cake pinaColadaCake ("Pina Colada", "Coconut Icing", "Cheers!", "Candied Pineapple", "Toasted Coconut and Umbrella", 5, 1);


    int choice = 0;

	do {
		cout << "************************************************************************\n";
		cout << "**                                                                    **\n";
		cout << "**                          WELCOME TO THE                            **\n";
		cout << "**                        MINI CAKE BAKERY!!                          **\n";
		cout << "**                                                                    **\n";
		cout << "************************************************************************\n";
		cout << "** Please make a choice from the following options:                   **\n";
		cout << "** 1)  Input a Signature Cake Order                                   **\n";
		cout << "** 2)  Input a Custom Cake Order                                      **\n";
		cout << "** 3)  Cancel an order                                                **\n";
        cout << "** 4)  Edit an order                                                  **\n";
        cout << "** 5)  View all orders                                                **\n";
		cout << "** 6)  Exit                                                           **\n";
		cout << "************************************************************************\n";
		cout << ">> ";
		
        cin >> choice;
    
		cin.ignore(); 
        string hold;

		switch (choice) {
        case 1: {
            Cake orderedCake; 
            int cakeChoice;
            cout << "--- Display of Signature Cakes ---\n\n";
            cout << "1) " << chocolateCake << endl;
            cout << "2) " << vanillaCake << endl;
            cout << "3) " << lemonCake << endl;
            cout << "4) " << butterscotchCake << endl;
            cout << "5) " << pinaColadaCake << endl << endl;
            cout << "Choose a Signature Cake (1-5): ";

            cin >> cakeChoice;

            switch(cakeChoice) {
                case 1: orderedCake = chocolateCake; orderList.addCakeOrder(orderedCake); break;
                case 2: orderedCake = vanillaCake; orderList.addCakeOrder(orderedCake); break;
                case 3: orderedCake = lemonCake; orderList.addCakeOrder(orderedCake); break;
                case 4: orderedCake = butterscotchCake; orderList.addCakeOrder(orderedCake); break;
                case 5: orderedCake = pinaColadaCake; orderList.addCakeOrder(orderedCake); break;
                default: cout << "No cake has been chosen, please try again.\n"; break;
            }
            "Thank you for ordering a Signature Cake!\n";
            cout << "The Order Summary is displayed below: \n";
            cout << orderedCake << endl;

            break;

        }

        case 2:{
            string flavor, icingFlavor, filling, decor, message;
            int size, count;
            Cake customCake(flavor, icingFlavor, message, filling, decor, size, count);
            string Cflavor, CicingFlavor, Cmessage, Cfilling, Cdecor;
            int Csize, Ccount;

            cout << "************************************************************************\n";
            cout << "Our available flavors are Chocolate, Vanilla, Lemon, Butterscotch, \nPina Colada, Red Velvet, Black Forest, \"Birthday Cake\", and Mango.\n";
            cout << "************************************************************************\n\nEnter Cake Flavor: ";

            getline(cin, Cflavor);
            customCake.setFlavor(Cflavor);

            cout << "\n************************************************************************\n";
            cout << "Our available icing flavors are: Ganache, Whipped Cream Frosting, \nButtercream, Coconut Cream, and Cream Cheese. \n";
            cout << "************************************************************************\n\nEnter Icing Flavor: ";

            getline(cin, CicingFlavor);
            customCake.setIcingFlavor(CicingFlavor);

            cout << "\n************************************************************************\n";
            cout << "Possible fillings include berry compotes, fruit jams, \ncustard, ganache, and caramel.\n";
            cout << "************************************************************************\n";
            cout << "\nEnter Filling (Press Enter to skip): ";

            getline(cin, Cfilling);
            customCake.setFilling(Cfilling);

            cout << "\n************************************************************************\n";
            cout << "Possible decorations include sprinkles, fruits, icing flowers, \nor cookie/chocolate/nut crumbles.\n";
            cout << "************************************************************************\n";
            cout << "\nEnter Decorations: ";

            getline(cin, Cdecor);
            customCake.setDecor(Cdecor);

            cout << "\n************************************************************************\n";
            cout << "The message to be displayed can be a maximum of 30 characters.\n";
            cout << "************************************************************************\n";
            cout << "\nEnter Message: ";

            getline(cin, Cmessage);
            customCake.setMessage(Cmessage);

            if (Cmessage.length() > 30) {
                cout << "Message is too long. Please enter a message with a maximum of 30 characters.\n";
                continue; 
            }

            cout << "\n************************************************************************\n";
            cout << "We offer cakes between 5 to 7 inches in diameter. ";
            cout << "\n************************************************************************\n";
            cout << "\nEnter Size (inches): ";

            cin >> Csize;
            customCake.setSize(Csize);

            if (customCake.getSize() < 5 || customCake.getSize() > 7) {
                cout << "Invalid size. Please enter a size between 5 and 7 inches.\n";
                continue; // Restart the loop for valid input
            }
            cout << "\n************************************************************************\n";
            cout << "You can order between 1 to 10 cakes at a time.\n";
            cout << "************************************************************************\n";
            cout << "\nEnter Quantity: ";
            
            cin >> Ccount;
            customCake.setCount(Ccount);

            double price = customCake.getPrice();
            
            cout << "\n\nThank you for ordering a Custom Cake!\n";
            cout << "The Order Summary is displayed below: \n";
            cout << customCake << endl;
            cout << endl;
            
            orderList.addCakeOrder(customCake);
            break;
        }

		case 3: {
            int index; 	
            cout << orderList << endl; 
            cout << "\n************************************************************************\n";
            cout << "To cancel an order, please enter the associated order on the inventory.\n";
            cout << "************************************************************************\n";
            cout << "\nEnter inventory number (Enter -1 to cancel): ";

            cin >> index;
            if (index == -1) {
                break; 
            } else if (index > orderList.size() || index < -1) {
                cout << "Invalid order number. Please try again.\n";
            } else {
                if (orderList.removeCakeOrder(index - 1)) {
                    cout << "Order #" << index << " has been successfully cancelled.\n";
                }
            }
            break;
        }

        case 4: {
            int index; 	
            cout << orderList << endl; 
            cout << "\n************************************************************************\n";
            cout << "To modify an order, please enter the associated order on the inventory.\n";
            cout << "************************************************************************\n";
            cout << "\nEnter inventory number  (-1 to cancel): ";

            cin >> index;
            if (index == -1) {
                break; 
            } else if (index > orderList.size() || index < -1) {
                cout << "Invalid order number. Please try again.\n";
            } else {
                orderList.editCakeOrder(index - 1);
                cout << "Order #" << index << " has been successfully modified.\n";
            }
            break;

        }

        case 5: {
            cout << "************************************************************************\n";
            cout << "------------------------Display of all Cake Orders-----------------------\n";
            cout << orderList << endl;
            cout << "************************************************************************\n";
            cout << "Press Enter to continue:";
            getline(cin, hold);
			break;
        }

		case 6:
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";	
        cout << "\nThank you for visiting the Mini Cake Bakery!\nWe will have your cake ready soon!\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
			break;
		}

	} while (choice != 6);

    return 0;
}
#include "menu.h"

menu::menu()
{
	dec = new Dictionary[1];
    //dec[0] = Dictionary();   

}

menu::menu(Dictionary* dec)
{  
    dec = new Dictionary[1];
    this->dec[0] = dec[0];
}




menu::~menu()
{
	delete[] dec;
}

void menu::MainMenu()
{

    int choice;

    cout << "choose a process: " << endl << endl;
    cout << "1. Create dictionary and insert values" << endl;
    cout << "2. add a new definition into the dictionary" << endl;
    cout << "3. Add a new interpretation to an existing definition in the dictionary " << endl;
    cout << "4. Search for a definition in the dictionary" << endl;
    cout << "5. View all settings that have at least one common interpretation" << endl;
    cout << "6. Exit" << endl;

    cin >> choice;
    Definition ad;
    Definition ads;

    String ad1;
    String ad2;
    int i = 0;

    if (choice == 1) {
        cout << "\n Create dictionary and insert values:\n";
        cin >> *dec;
        cout << *dec;
    }

    do {
        cout << endl;
        cout << "choose a new process: " << endl << endl;
        cout << "2. add a new definition into the dictionary" << endl;
        cout << "3. Add a new interpretation to an existing definition in the dictionary " << endl;
        cout << "4. Search for a definition in the dictionary" << endl;
        cout << "5. View all settings that have at least one common interpretation" << endl;
        cout << "6. Exit" << endl;
        cin >> choice;
        int i = 0, j = 0, k = 0;

        switch (choice) {
        case 2:
            getchar();
            cout << "\n add a new definition into the dictionary: \n";
            cin >> ad;
            *dec += ad;
            cout << *dec;
            break;
        case 3:
            getchar();

            cout << "\n Add a new interpretation to an existing definition in the dictionary: \n";
            cin >> ad1;
          ads = Definition (&ad1, 1);
          
          while (!(dec == NULL)) {

              if (dec->operator[](i).equal_word(ads)) {
                  getchar();
                  cout << ads; cout << "123///////////////";
                  cin >> ad1; cout << "123///////////////";

                  dec->operator[](i) += ad1;
                 
              }
             i++;
          }
            
            cout << *dec;

            break;
        case 4:
          getchar();

            cout << "\n Search for a definition in the dictionary: \n";
            cin >> ad1;
            Definition(&ad1, 1) = ad;
            cout << ad;
            while (!dec)
                
            if (dec->operator[](i).equal_word (ad)==true) {
                cout << dec->operator[](i);
                i++;
            }

            

            break;
        case 5:

            cout << "View all settings that have at least one common interpretation";


            break;
        case 6:
            exit(1);
            break;


        }
    } while (choice != 1);

}

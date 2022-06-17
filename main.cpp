//Sami Shaikh
//Mr. Botero
//Githubathon
//6/16/2022
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>
#include <iomanip>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

//declares functions
void secretmenu();

void checkout();

void bakerysetup();

void stocksetup();

void poststocksetup(int stockchoice);

//declares global variables, arrays, and vectors
double price;

vector <int> menuorders;

vector <int> secretmenuorders;

string stocknames[5] = {"Apple", "Amazon", "Alphabet Inc.", "John's Pizza", "Tesla"};

double ogstockprices[5] = {137.00, 109.00, 2228.00, 32.00, 696.00};

double stockprices[5] = {137.00, 109.00, 2228.00, 32.00, 696.00};

//choc. cupcakes / van. cupcakes / muffin / eclair / choc. cake / van. cake
double menuprices[6] = {15.00, 15.00, 13.00, 14.00, 18.00, 17.00};

//velvet cupcakes / brownies / donuts / choc. strawberries
double secretmenuprices[4] = {20.00, 17.00, 10.00, 8.00};

//bakery
int main()
{
  //sets all double output to two decimals
  cout << fixed << setprecision(2);

  cout << "Hello!";

  cout << endl;

  int bakeryvstockchoice;

  cout << "Would you like to head to the bakery (1) or the stocks app (2) ? ";

  //receives user integer input
  cin >> bakeryvstockchoice;

  //if statement
  if(bakeryvstockchoice == 1)
  {
    //calls bakery function
    bakerysetup();
  }
  else if(bakeryvstockchoice == 2)
  {
    //calls stock function
    stocksetup();
  }
  else
  {
    
  }
}

//function
void stocksetup()
{
  cout << "Welcome to the stocks app!  Here you can choose to invest in certain stocks and receive quarterly income!";

  cout << endl;

  int stockchoice;

  //do while loop
  do
  {
    cout << "Choose an option to invest in: ";
  
    cout << endl;

    //for loop
    for(int count = 0; count < 5; count++)
    {
      //finds array length
      int namelength = stocknames[count].size();

      //prints options for investing
      cout << "  " << (count + 1) << ". 1 '" << stocknames[count] << "' Stock" << right << setw(25 - namelength) << "$" << stockprices[count];

      cout << left << endl;
    }

    //receives user input
    cin >> stockchoice;

    //if statement
    if((stockchoice > 5) || (stockchoice < 1))
    {
      cout << "Enter a valid choice next time!";
  
      cout << endl;
    }
    
  }while((stockchoice > 5) || (stockchoice < 1));

  //calls function
  poststocksetup(stockchoice);
}

//function
void poststocksetup(int stockchoice)
{
  //finds random value between -5 and 5 for random stock value change
  double randompercentchange = rand() % 10 + -5;

  randompercentchange = randompercentchange / 10;

  int previousvalue = stockprices[stockchoice - 1];

  //new stock prices
  stockprices[stockchoice - 1] = stockprices[stockchoice - 1] * (1 + (randompercentchange));

  //if statement for if the stock goes up or down
  if(stockprices[stockchoice - 1] < previousvalue)
  {
    cout << "Oh no!  Your stock is losing value (previous value: $" << ogstockprices[stockchoice - 1] << " / value now: $" << stockprices[stockchoice - 1] << ") !";
  }
  else
  {
    cout << "Wow your stocks are gaining value!  You're a good investor (previous value: $" << ogstockprices[stockchoice - 1] << " / value now: $" << stockprices[stockchoice - 1] << ") !";
  }

  cout << endl;
}

//function
void bakerysetup()
{
  cout << "Welcome to the bakery!";

  cout << endl;
  
  int menuchoice;

  //do while loop
  do
  {
    cout << "Menu: ";
  
    cout << endl;

    //concatenates text and array value
    cout << "  1. 6 Chocolate Cupcakes   $" << menuprices[0];
  
    cout << endl;
  
    cout << "  2. 6 Vanilla Cupcakes     $" << menuprices[1];
  
    cout << endl;
  
    cout << "  3. 6 Muffins              $" << menuprices[2];
  
    cout << endl;
  
    cout << "  4. 6 Eclairs              $" << menuprices[3];
  
    cout << endl;
  
    cout << "  5. Chocolate Cake         $" << menuprices[4];
  
    cout << endl;
  
    cout << "  6. Vanilla Cake           $" << menuprices[5];
  
    cout << endl;
  
    cout << "  7. Go to Checkout";

    cout << endl;
  
    cin >> menuchoice;

    //if statement
    if((menuchoice < 7) && (menuchoice >= 1))
    {
      //adds value to vector
      menuorders.push_back(menuchoice);
    }
    else if(menuchoice == 8)
    {
      cout << "Are you sure?  You will not be able to head back (y / n) " ;

      char confirmation;

      cin >> confirmation;

      //if statement
      if((confirmation == 'y') || (confirmation == 'Y'))
      {
        //calls secret menu option
        secretmenu();
      }
    }
    else if(menuchoice == 7)
    {
      //breaks out of loop
      break;
    }
    else
    {
      cout << "Enter a valid input";
    }
  }while(menuchoice != 8);

  //calls checkout function
  checkout();
}

//function
void secretmenu()
{
  cout << "Welcome to the Secret Menu!";

  cout << endl;

  int secretmenuchoice;

  //do while loop
  do
  {
    cout << "Secret Menu: ";
  
    cout << endl;

    //concatenates text with array value
    cout << "  9. 6 Red Velvet Cupcakes               $" << secretmenuprices[0];
  
    cout << endl;
  
    cout << "  10. 6 White Chocolate Chip Brownies    $" << secretmenuprices[1];
  
    cout << endl;
  
    cout << "  11. 6 Assorted Donuts                  $" << secretmenuprices[2];
  
    cout << endl;
  
    cout << "  12. 12 Chocolate Dipped Strawberries   $" << secretmenuprices[3];
  
    cout << endl;
  
    cout << "  13. Go to Checkout";
  
    cout << endl;

    //receives user integer input
    cin >> secretmenuchoice;

    //if statement
    if((secretmenuchoice >= 9) && (secretmenuchoice <= 12))
    {
      secretmenuorders.push_back(secretmenuchoice);
    }
    else if(secretmenuchoice == 13)
    {
      
    }
    else
    {
      cout << "Enter a valid input";
    }
  }while(secretmenuchoice != 13);
}

//funnction
void checkout()
{
  for(int count = 0; count < menuorders.size(); count++)
  {
    //if statement to calculate price
    if(menuorders[count] == 1)
    {
      price = price + menuprices[0];
    }
    else if(menuorders[count] == 2)
    {
      price = price + menuprices[1];
    }
    else if(menuorders[count] == 3)
    {
      price = price + menuprices[2];
    }
    else if(menuorders[count] == 4)
    {
      price = price + menuprices[3];
    }
    else if(menuorders[count] == 4)
    {
      price = price + menuprices[3];
    }
    else if(menuorders[count] == 5)
    {
      price = price + menuprices[4];
    }
  }

  //for loop
  for(int count = 0; count < secretmenuorders.size(); count++)
  {
    //if statement to calculate price
    if(secretmenuorders[count] == 9)
    {
      price = price + secretmenuprices[0];
    }
    else if(secretmenuorders[count] == 10)
    {
      price = price + secretmenuprices[1];
    }
    else if(secretmenuorders[count] == 11)
    {
      price = price + secretmenuprices[2];
    }
    else if(secretmenuorders[count] == 12)
    {
      price = price + secretmenuprices[3];
    }
  }

  //prints subtotal and total with tax
  cout << "Your subtotal: $" << price;

  cout << endl;

  price = price * 1.06625;

  cout << "Your grand total: $" << price;

  cout << endl;

  char couponquestion;

  //coupon inquiry
  cout << "Do you have any coupons to apply (y / n) ? ";

  cin >> couponquestion;

  //do while loop
  do
  {
    //if statement
    if((couponquestion = 'y') || (couponquestion == 'Y'))
    {
      string couponcode;
      
      cout << "Enter coupon code: ";

      //receives string input
      cin >> couponcode;

      //if statement for correct coupon code
      if(couponcode == "redchocolatedonutstrawberries")
      {
        price = price * 0.7;
        
        cout << "Coupon applied for 30% off!  Your price now is $" << price;

        cout << endl;

        //breaks out of loop
        break;
      }
      else
      {
        cout << "Ooh, sorry your coupon didn't go through.  Would you like to try again (y / n) ? ";

        //receives user char input
        cin >> couponquestion;
      }
    }
  }while((couponquestion == 'y') || (couponquestion == 'Y'));
}
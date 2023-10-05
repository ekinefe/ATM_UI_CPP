#include <iostream>
#include <unistd.h> // sleep function

int userPassword = 1234;
float userMoney = 500.0;
int userSelection;
int withdrawalAmount;
int depositAmount;
const char* separator = "--------------------------";

void passwordCheck();
void labels();
void withdraw();
void deposit();
void checkBalance();
void exitProgram();

int main() {
    std::cout << "\n\tATM_UI_C++" << std::endl;
    passwordCheck();
    return 0;
}
void passwordCheck() {
    std::cout << separator << std::endl;
    std::cout << "\nPleas enter your password:\t";
    int password;
    std::cin >> password;
    std::cout << "\n\tVerifying your identity\n";

    if (userPassword == password) {
        std::cout << "\n\tIdentity verification is successful"<<std::endl;
        sleep(2);
        labels();
    } else {
        std::cout << "\n\tYour password is WRONG !!!" << std::endl;
        sleep(3);
        passwordCheck();
    }
}
void labels (){
    std::cout << separator << std::endl;
    std::cout << "Please choose an option:" << std::endl;
    std::cout << "Withdraw.................1" << std::endl;
    std::cout << "Deposit..................2" << std::endl;
    std::cout << "Check Balance............3" << std::endl;
    std::cout << "Exit.....................4" << std::endl;

    std::cin >> userSelection;
    switch (userSelection) {
        case 1:
            sleep(1);
            withdraw();
            break;
        case 2:
            sleep(1);
            deposit();
            break;
        case 3:
            sleep(1);
            checkBalance();
            break;
        case 4:
            sleep(1);
            exitProgram();
            break;
        default:
            std::cout << "Invalid selection. Please choose a valid option." << std::endl;
            labels();
            break;
    }
}
void withdraw(){
    std::cout<<separator<<std::endl;
    std::cout<<"Enter your amount:";
    std::cin>>withdrawalAmount;

    if(withdrawalAmount > userMoney){
        sleep(2);
        std::cout<<"not enough money"<<std::endl;
    }
    else{
        std::cout<<"Your request is being processed..."<<std::endl;
        sleep(withdrawalAmount/75);
        userMoney=(userMoney-withdrawalAmount);
        std::cout << "Remaining amount on your bank account: " << userMoney << std::endl;
        std::cout << "Please take your card." << std::endl << std::endl;
        sleep(2);
        labels();
    }
}
void deposit(){
    std::cout<<separator<<std::endl;
    std::cout<<"Please enter the amount to deposit:";
    std::cin >> depositAmount;
    sleep(depositAmount / 75);
    userMoney += depositAmount;
    std::cout << "New amount on your bank account: " << userMoney << std::endl;
    sleep(2);
    labels();
}
void checkBalance(){
    std::cout << separator << std::endl;
    std::cout << "The amount on your account: " << userMoney << std::endl;
    sleep(2);
    labels();
}
void exitProgram(){
    std::cout << separator << std::endl;
    std::cout << "\n\tPROGRAM IS OVER" << std::endl;
    exit(0);
}
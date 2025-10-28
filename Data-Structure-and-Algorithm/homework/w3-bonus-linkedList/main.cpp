#include "utils/LibrarySystem.hpp"

int main(){
    LibrarySystem lib;
    // implement your logic here

    lib.addMember("seth");
    lib.addMember("reach");
    lib.addMember("omra");

    Member* seth = lib.findMember("seth");
    if(seth) {
        seth->borrowBook("A man who can't be move", "04/04/2025");
        seth->borrowBook("I'm dying alone", "04/05/2025");
        seth->borrowBook("Is it okay to be happy for a little while", "04/06/2025");
    }
    
    Member* reach = lib.findMember("reach");
    if(reach) {
        reach->borrowBook("sl ss ke", "09/04/2025");
        reach->borrowBook("How to drink without getting drunk", "08/05/2025");
    }

    Member* omra = lib.findMember("omra");
    if(omra) {
        omra->borrowBook("A man who can't be move", "04/04/2025");
        omra->borrowBook("you can't get drunk", "04/05/2025");
    }

    lib.displayMemberBooks("seth");
    lib.displayMemberBooks("reach");
    lib.displayMemberBooks("omra");
    lib.displayMemberBooks("sliden");

    if(seth) {
        seth->returnBook("you can't get drunk");
        seth->returnBook("A man who can't be move");
        seth->returnBook("I'm dying alone");
        seth->returnBook("Is it okay to be happy for a little while");
    }

    if(reach) {
        reach->returnBook("sl ss ke");
    }

    lib.displayMemberBooks("seth");
    lib.displayMemberBooks("reach");
    lib.displayMemberBooks("omra");

    return 0;
}
#ifndef LIBRARYSYSTEM_HPP
#define LIBRARYSYSTEM_HPP

#include "Member.hpp"
#include <vector>

using namespace std;

class LibrarySystem{
private:
    vector<Member*> members;

public:
    ~LibrarySystem(){
        for(Member* member: members){
            delete member;
        }
    }

    void addMember(string name){
        members.push_back(new Member(name));
    }

    Member* findMember(string name){
        for(Member* member: members){
            // your code here
            if(member->getName() == name) return member;
        }
        return nullptr;
    }

    void displayMemberBooks(string name){
        Member* member = findMember(name);
        if(member){
            cout<<member->getName() << ":" <<endl;
            member->displayBorrowInfo();
        }else{
            cout<<"Member not found"<<endl;
        }
    }
};


#endif
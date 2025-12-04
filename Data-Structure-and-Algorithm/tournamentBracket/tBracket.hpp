#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Node{
    public:
    Node*left;
    Node* right;
    string name;
    int score;
    int matchId;
    string winner;

    Node(string n , int s, int id){ 
        left=right=nullptr;
        name=n;
        score=s;
        matchId=id;
        winner="?";
    }
};

class tBracket {
private:
    vector<Node* > q;
    Node* root;
    int nextmatchId;

    //random scores
    int randomScores(Node* player) {
        int score = (player->name == "BYE") ? -1 : rand() % 10;
        return score;
    }

    //make the number of participents become the power of 2 (no odd number)
    vector<string> makePowOfTwo(vector<string> players) {
        int nextPow = 1;
        while(nextPow < players.size()) nextPow *= 2;
        
        while(players.size() < nextPow) players.push_back("BYE");
        return players;
    }

    // void insert(vector<string> players) {
    //     players = removePlayer(players);

    //     for(int i = 0; i < players.size(); i++){
    //         Node* leaf = new Node(players[i], )
    //     }
    // }
public:
    tBracket() {
        nextmatchId = 1;
        root = nullptr;
    };


    bool pathToFinal(Node* root, string player, vector<int>& path) {
        if (root==nullptr) return false;

        bool found = false;

        // Search left and right first
        if (pathToFinal(root->left, player, path) || pathToFinal(root->right, player, path)) {
            found = true;
        }

        // If this node is a match where player is winner OR player is in subtree
        if (root->winner == player || found) {
            path.push_back(root->matchId);
            return true;
        }

        return false;
    }
};

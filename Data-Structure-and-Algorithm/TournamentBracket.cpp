#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
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


class TBracket{
    private:
    Node* root;
    queue<Node*> q;
    int matchCounter;
    public:
    TBracket(){
        root=nullptr;
        matchCounter=1;

    }

    vector<string>padPlayer(vector<string>players){  // make it so the size of the players become next power of 2 yeah read it you will understand it
        int n=players.size();
        int nextPow2=pow(2,ceil(log2(n)));
        while(players.size()<nextPow2){
            players.push_back("BYE");
        }

        return players;
    }

    vector<string>insert(vector<string> players){   // push every player to vector for preparing to build a match tree
        players=padPlayer(players);
        for(int i=0;i<players.size();i++){
            int randomScore = (players[i]=="BYE")? -1:rand() % 10;   // makesure players with string BYE get -1 as a score they lose auto
            Node* leaf = new Node(players[i], randomScore,matchCounter++);
            leaf->winner=players[i];
            q.push(leaf);
        }
        return players;
    }

    void buildTree(){
        while(q.size()>1){
            Node* A= q.front();
            q.pop();
            Node* B=q.front();
            q.pop();

           Node* match = new Node("Match",0,matchCounter++);
           match->left=A;
           match->right=B;

          if (A->name == "BYE") {
                match->winner = B->winner;
            } else if (B->name == "BYE") {
                match->winner = A->winner;
            }else {
                if(A->score >  B->score){
                    match->winner= A->winner;
                }else {
                    match->winner=B->winner;
                }
            }
            q.push(match);
        }
        root = q.front(); // hold the pointer to every other loser the last node in the queue 
    }

   

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


 Node* getRoot() { return root; }


void recordResult(Node* root, int matchId, string winnerName) {
        if (!root) return;
        if (root->matchId == matchId) {
            if (root->left && root->right) {
                if (root->left->winner == "?" || root->right->winner == "?")
                    throw runtime_error("Both participants must decide for a winner");
            }
            root->winner = winnerName;
            return;
        }
        recordResult(root->left, matchId, winnerName);
        recordResult(root->right, matchId, winnerName);
    }


 int wouldMeet(Node* root, string p1, string p2, int& round, int depth = 1) {
        if (!root) return -1;
        bool leftHasP1 = contains(root->left, p1);
        bool leftHasP2 = contains(root->left, p2);
        bool rightHasP1 = contains(root->right, p1);
        bool rightHasP2 = contains(root->right, p2);

        if ((leftHasP1 && rightHasP2) || (leftHasP2 && rightHasP1)) {
            round = depth;
            return root->matchId;
        }
        int res = wouldMeet(root->left, p1, p2, round, depth + 1);
        if (res != -1) return res;
        return wouldMeet(root->right, p1, p2, round, depth + 1);
    }

    bool contains(Node* root, string player) {
        if (!root) return false;
        if (root->winner == player || root->name == player) return true;
        return contains(root->left, player) || contains(root->right, player);
    }


 
void printBracket(Node* root) {
    if (!root) return;
    queue<Node*> q1;
    q1.push(root);
    vector<vector<Node*>> rounds;

    while (!q1.empty()) {
        int size = q1.size();
        vector<Node*> currentRound;
        for (int i = 0; i < size; i++) {
            Node* curr = q1.front(); q1.pop();
            currentRound.push_back(curr);
            if (curr->left) q1.push(curr->left);
            if (curr->right) q1.push(curr->right);
        }
        rounds.push_back(currentRound);
    }

    reverse(rounds.begin(), rounds.end());

    cout << "\nBracket:\n";
    int roundNum = 1;
    for (auto &round : rounds) {
        cout << "Round " << roundNum++ << ":\n";
        for (auto *curr : round) {
            cout << "[Match " << curr->matchId << "] ";
            if (!curr->left && !curr->right) {
                cout << curr->name << " (Score: " << curr->score << ")\n";
            } else {
                cout << curr->left->winner << " vs " << curr->right->winner
                     << " | Winner: " << curr->winner << "\n";
            }
        }
        cout << "----\n";
    }
}

};




int main(){

TBracket t1;
    vector<string> players = {"Anna", "Ben", "Chou", "Dara", "Ean", "Faye", "Gita", "Hout"};
    t1.insert(players);
    t1.buildTree();
    t1.printBracket(t1.getRoot());


  vector<int> path;
if (t1.pathToFinal(t1.getRoot(), "Chou", path)) {
    cout << "\nPath to final for Chou: ";
    for (int id : path) cout << id << " ";
    cout << "\n";
} else {
    cout << "Player not found!\n";
}

  

   
    return 0;
}

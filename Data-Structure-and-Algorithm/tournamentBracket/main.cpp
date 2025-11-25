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
            int randomScore = (players[i]=="BYE")? -1:rand() % 100;   // makesure players with string BYE get -1 as a score they lose auto
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

   

void pathToFinal(Node* root, string player, vector<int>& path) {
    if (root==nullptr) return ;

    if(root->winner==player){
        path.push_back(root->matchId);
    }

    if(root->left) pathToFinal(root->left, player, path);
    if(root->right) pathToFinal(root->right, player, path);

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


 
int wouldMeet(Node* root, string p1, string p2, int& round, int depth = 1, int totalRounds = 0) {
    if (root==nullptr) return -1;

    if (totalRounds == 0) {
        // Calculate total rounds once
      totalRounds = ceil(log2(matchCounter)); 
    }

    bool leftHasP1 = contains(root->left, p1);
    bool leftHasP2 = contains(root->left, p2);
    bool rightHasP1 = contains(root->right, p1);
    bool rightHasP2 = contains(root->right, p2);

    if ((leftHasP1 && rightHasP2) || (leftHasP2 && rightHasP1)) {
        round =totalRounds-depth+1; // Convert depth to actual round
        return root->matchId;
    }

    int res = wouldMeet(root->left, p1, p2, round, depth + 1, totalRounds);
    if (res != -1) return res;
    return wouldMeet(root->right, p1, p2, round, depth + 1, totalRounds);
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
    vector<string> players={"seth","hong","Ean","otdg","Hout","Chou","omra","javjit"};
    TBracket t1;
    t1.insert(players);

    t1.buildTree();

    t1.printBracket(t1.getRoot());

    vector<int>Path;

    t1.pathToFinal(t1.getRoot(),"Ean", Path);


    reverse(Path.begin(),Path.end());
    for(auto i : Path){
        cout<<i<<" ";
    }

    cout << endl;       
    
    int round;
    
    cout << t1.wouldMeet(t1.getRoot(), "seth", "otdg", round) << endl;

    return 0;
}
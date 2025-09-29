#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<unordered_set>
using namespace std;

void showResult(vector<vector<string>>& board) {
	system("cls");
    cout <<  "T i c  T a c  T o e  W i t h  A I" << endl << endl;
    cout << "User Symbol: [X]" << endl;
    cout << "AI Symbol: [O]" << endl << endl; 
	
    cout << "     :     :     " << endl;
    cout << "  " << board[0][0] << "  :  " << board[0][1] << "  :  " << board[0][2]<< endl;
    cout << "_____:_____:_____" << endl;
    cout << "     :     :     " << endl;
    cout << "  " << board[1][0] << "  :  " << board[1][1] << "  :  " << board[1][2]<< endl;
    cout << "____ :_____:_____" << endl;
    cout << "     :     :     " << endl;
    cout << "  " << board[2][0] << "  :  " << board[2][1] << "  :  " << board[2][2]<< endl;
    cout << "     :     :     " << endl;
}
void placeTurn(vector<vector<string>>& board, int idx, string symbol) {
    if(idx == 0) board[0][0] = symbol;
    else if(idx == 1) board[0][1] = symbol;
    else if(idx == 2) board[0][2] = symbol;
    else if(idx == 3) board[1][0] = symbol;
    else if(idx == 4) board[1][1] = symbol;
    else if(idx == 5) board[1][2] = symbol;
    else if(idx == 6) board[2][0] = symbol;
    else if(idx == 7) board[2][1] = symbol;
    else if(idx == 8) board[2][2] = symbol;
}
bool checkIfConditionHit(vector<vector<string>>& board, string symbol) {

    if(board[0][0] == symbol && board[0][1] == symbol && board[0][2] == symbol) return true;
    else if(board[1][0] == symbol && board[1][1] == symbol && board[1][2] == symbol) return true;
    else if(board[2][0] == symbol && board[2][1] == symbol && board[2][2] == symbol) return true;

    else if(board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) return true;
    else if(board[0][2] == symbol &&board[1][1] == symbol && board[2][0] == symbol) return true;
    
    else if(board[0][0] == symbol && board[1][0] == symbol && board[2][0] == symbol) return true;
    else if(board[0][1] == symbol && board[1][1] == symbol && board[2][1] == symbol) return true;
    else if(board[0][2] == symbol && board[1][2] == symbol && board[2][2] == symbol) return true;
    
	else return false;
}
void Erase(vector<int> &choices, int val) {
	vector<int> temp;
	for(int i : choices) {
		if(i != val) {
			temp.push_back(i);
		}
	}
	choices.clear();
	for(int i : temp) {
		choices.push_back(i);
	}
}
bool AICanChoose(vector<vector<string>>& board, unordered_set<int>& s, vector<int> &choices) {
	// For Cell (0, 0) -> 0
	if(board[0][0] == "0" && board[0][1] == "O" && board[0][2] == "O" || board[0][0] == "0" && board[1][0] == "O" && board[2][0] == "O" || board[0][0] == "0" && board[1][1] == "O" && board[2][2] == "O") {
		board[0][0] = "O";
		Erase(choices, 0);
		s.erase(0);
		return false;
	}
	// For Cell (0, 1) -> 1
	else if(board[0][0] == "O" && board[0][1] == "1" && board[0][2] == "O" || board[0][1] == "1" && board[1][1] == "O" && board[2][1] == "O") {
		board[0][1] = "O";
		Erase(choices, 1);
		s.erase(1);
		return false;
	}
	// For Cell (0, 2) -> 2
	else if(board[0][0] == "O" && board[0][1] == "O" && board[0][2] == "2" || board[1][1] == "O" && board[2][0] == "O" && board[0][1] == "2" || board[1][2] == "O" && board[2][2] == "O" && board[0][2] == "2") {
		board[0][2] = "O";
		Erase(choices, 2);
		s.erase(2);
		return false;
	}
	// For Cell (1, 0) -> 3
	else if(board[1][0] == "3" && board[1][1] == "O" && board[1][2] == "O" || board[0][0] == "O" && board[1][0] == "3" && board[2][0] == "O") {
		board[1][0] = "O";
		Erase(choices, 3);
		s.erase(3);
		return false;
	}
	// For Cell (1, 1) -> 4
	else if(board[0][1] == "O" && board[1][1] == "4" && board[2][1] == "O" || board[1][0] == "O" && board[1][1] == "4" && board[1][2] == "O" || board[0][0] == "O" && board[1][1] == "4" && board[2][2] == "O" || board[0][2] == "O" && board[1][1] == "4" && board[2][0] == "O") {
		board[1][1] = "O";
		Erase(choices, 4);
		s.erase(4);
		return false;
	}
	// For Cell (1, 2) -> 5
	else if(board[0][2] == "O" && board[1][2] == "5" && board[2][2] == "O" || board[1][0] == "O" && board[1][1] == "O" && board[1][2] == "5") {
		board[1][2] = "O";
		Erase(choices, 5);
		s.erase(5);
		return false;
	}
	// For Cell (2, 0) -> 6
	else if(board[0][0] == "O" && board[1][0] == "O" && board[2][0] == "6" || board[0][2] == "O" && board[1][1] == "O" && board[2][0] == "6" || board[2][0] == "6" && board[2][1] == "O" && board[2][2] == "O") {
		board[2][0] = "O";
		Erase(choices, 6);
		s.erase(6);
		return false;
	}
	// For Cell (2, 1) -> 7
	else if(board[0][1] == "O" && board[1][1] == "O" && board[2][1] == "7" || board[2][0] == "O" && board[2][1] == "7" && board[2][2] == "O") {
		board[2][1] = "O";
		Erase(choices, 7);
		s.erase(7);
		return false;
	}
	// For Cell (2, 2) -> 8
	else if(board[0][0] == "O" && board[1][1] == "O" && board[2][2] == "8" || board[0][2] == "O" && board[1][2] == "O" && board[2][2] == "8" || board[2][0] == "O" && board[2][1] == "O" && board[2][2] == "8") {
		board[2][2] = "O";
		Erase(choices, 8);
		s.erase(8);
		return false;
	}
	return true;
}
bool brainOfAI(vector<vector<string>>& board, unordered_set<int>& s, vector<int> &choices) {
	if(board[0][0] == "X" && board[1][0] == "X" && board[2][0] != "O" && board[2][0] == "6") { 
		board[2][0] = "O";
		s.erase(6);
		Erase(choices, 6);
		return false;
	}
	else if(board[0][0] == "X" && board[1][0] != "O" && board[2][0] == "X" && board[1][0] == "3") {
		board[1][0] = "O"; 
		s.erase(3);
		Erase(choices, 3);
		return false;
	}
	else if(board[0][0] != "O" && board[1][0] == "X" && board[2][0] == "X" && board[0][0] == "0") {
		board[0][0] = "O";
		s.erase(0);
		Erase(choices, 0);
		return false;
	}
	else if(board[0][1] == "1" && board[1][1] == "X" && board[2][1] == "X" && board[0][1] != "O") {
		board[0][1] = "O";
		s.erase(1);
		Erase(choices, 1);
		return false;
	}
	else if(board[0][1] == "X" && board[1][1] == "4" && board[2][1] == "X" && board[1][1] != "O") {
		board[1][1] = "O";
		s.erase(4);
		Erase(choices, 4);
		return false;
	}
	else if(board[0][1] == "X" && board[1][1] == "X" && board[2][1] != "O" && board[2][1] == "7") {
		board[2][1] = "O";
		s.erase(7);
		Erase(choices, 7);
		return false;
	}
	else if(board[0][2] == "X" && board[1][2] == "X" && board[2][2] != "O" && board[2][2] == "8") {
		board[2][2] = "O";
		s.erase(8);
		Erase(choices, 8);
		return false;
	}
	else if(board[0][2] == "X" && board[2][2] == "X" && board[1][2] != "O" && board[1][2] == "5") {
		board[1][2] = "O";
		s.erase(5);
		Erase(choices, 5);
		return false;
	}
	else if(board[0][2] == "2" && board[1][2] == "X" && board[2][2] == "X" && board[0][2] != "O") {
		board[0][2] = "O";
		s.erase(2);
		Erase(choices, 2);
		return false;
	}
	else if(board[0][0] == "X" && board[1][1] == "X" && board[2][2] == "8" && board[2][2] != "O") {
		board[2][2] = "O";
		s.erase(8);
		Erase(choices, 8);
		return false;
	}
	else if(board[0][0] == "0" && board[1][1] == "X" && board[2][2] == "X" && board[0][0] != "O") {
		board[0][0] = "O";
		s.erase(0);
		Erase(choices, 0);
		return false;
	}
	else if(board[0][0] == "X" && board[1][1] == "4" && board[2][2] == "X" && board[1][1] != "O") {
		board[1][1] = "O";
		s.erase(4);
		Erase(choices, 4);
		return false;
	}
	else if(board[0][2] == "X" && board[1][1] == "X" && board[2][0] != "O" && board[2][0] == "6") {
		board[2][0] = "O";
		s.erase(6);
		Erase(choices, 6);
		return false;
	}
	else if(board[0][2] != "O" && board[1][1] == "X" && board[2][0] == "X" && board[0][2] == "2") {
		board[0][2] = "O";
		s.erase(2);
		Erase(choices, 2);
		return false;
	}
	else if(board[0][2] == "X" && board[1][1] != "O" && board[2][0] == "X" && board[1][1] == "4") {
		board[1][1] = "O";
		s.erase(4);
		Erase(choices, 4);
		return false;
	}
	else if(board[0][0] == "X" && board[0][1] == "X" && board[0][2] != "O" && board[0][2] == "2") {
		board[0][2] = "O";
		s.erase(2);
		Erase(choices, 2);
		return false;
	}
	else if(board[0][0] == "X" && board[0][1] != "O" && board[0][2] == "X" && board[0][1] == "1") {
		board[0][1] = "O";
		s.erase(1);
		Erase(choices, 1);
		return false;
	}
	else if(board[0][0] != "O" && board[0][1] == "X" && board[0][2] == "X" && board[0][0] == "1") {
		board[0][0] = "O";
		s.erase(1);
		Erase(choices, 1);
		return false;
	}
	else if(board[1][0] == "X" && board[1][1] == "X" && board[1][2] == "5" && board[1][2] != "O") {
		board[1][2] = "O";
		s.erase(5);
		Erase(choices, 5);
		return false;
	}
	else if(board[1][0] == "X" && board[1][1] != "O" && board[1][2] == "X" && board[1][1] == "5") {
		board[1][1] = "O";
		s.erase(5);
		Erase(choices, 5);
		return false;
	}
	else if(board[1][0] != "O" && board[1][1] == "X" && board[1][2] == "X" && board[1][0] != "4") {
		board[1][0] = "O";
		s.erase(4);
		Erase(choices, 4);
		return false;
	}
	else if(board[2][0] == "X" && board[2][1] == "X" && board[2][2] != "O" && board[2][2] == "8") {
		board[2][2] = "O";
		s.erase(8);
		Erase(choices, 8);
		return false;
	}
	else if(board[2][0] == "X" && board[2][1] != "O" && board[2][2] == "X" && board[2][1] == "7") {
		board[2][1] = "O";
		s.erase(7);
		Erase(choices, 7);
		return false;
	}
	else if(board[2][0] != "O" && board[2][1] == "X" && board[2][2] == "X" && board[2][0] == "6") {
		board[2][0] = "O";
		s.erase(6);
		Erase(choices, 6);
		return false;
	}
	return true;
}

int main() {
    srand(time(0));
    cout << "T i c  T a c  T o e  W i t h  A I" << endl << endl;
    cout << "User Symbol: [X]" << endl;
    cout << "AI Symbol: [O]" << endl << endl;
	
    cout << "     :     :     " << endl;
    cout << "  0  :  1  :  2  " << endl;
    cout << "_____:_____:_____" << endl;
    cout << "     :     :     " << endl;
    cout << "  3  :  4  :  5  " << endl;
    cout << "____ :_____:_____" << endl;
    cout << "     :     :     " << endl;
    cout << "  6  :  7  :  8  " << endl;
    cout << "     :     :     " << endl;
    
    int User;
    int AI; 
    
    vector<vector<string>> board = {
    	{"0", "1", "2"},
    	{"3", "4", "5"},
    	{"6", "7", "8"}
	};
    vector<int> choices  = {0,1,2,3,4,5,6,7,8};
	unordered_set<int> s = {0,1,2,3,4,5,6,7,8};
	float attempts = 4.5;
	
    while(attempts != 0) {
        cout << "User[X] turn: "; 
        cin >> User;
		if(s.find(User) == s.end()) {
			cout << "You Cannot Place Here!" << endl;
			continue;
		}
        attempts -= 0.5;
		
        placeTurn(board, User, "X");
        showResult(board);
		
		if(checkIfConditionHit(board, "X")) {
            cout << "Congrats, You Won The Match!!" << endl;
            return 0;
        }
		Erase(choices, User);
		s.erase(User);
		attempts -= 0.5;
		
		// For AI better Choice
		if(AICanChoose(board, s, choices)) {
			if(brainOfAI(board, s, choices)) {
	        	AI = choices[rand() % choices.size()];						
	        	placeTurn(board, AI, "O");
	        	s.erase(AI);
				Erase(choices, AI); 
			}
		}
		
        showResult(board);

        if(checkIfConditionHit(board, "O")) {
            cout << "OH! You loose the match Against AI try again" << endl << "Good Luck!" << endl;
            return 0;
        }
    }
    
    cout << "Tie!!!" << endl;
}
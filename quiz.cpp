#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Structure for Question
struct Question {
    string question;
    string options[4];
    int correctAnswer;
};

// Structure for User
struct User {
    string name;
    int score;
};

// Comparator for Priority Queue (Max Heap)
struct Compare {
    bool operator()(User a, User b) {
        return a.score < b.score; // higher score = higher priority
    }
};

int main() {
    vector<Question> quiz;

    // Adding Questions
    quiz.push_back({"Capital of India?",
                    {"Delhi", "Mumbai", "Chennai", "Kolkata"},
                    0});

    quiz.push_back({"2 + 2 = ?",
                    {"3", "4", "5", "6"},
                    1});

    quiz.push_back({"Largest planet?",
                    {"Earth", "Mars", "Jupiter", "Saturn"},
                    2});

    // User Input
    string username;
    cout << "Enter your name: ";
    cin >> username;

    int score = 0;

    // Quiz Execution
    for (int i = 0; i < quiz.size(); i++) {
        cout << "\nQ" << i + 1 << ": " << quiz[i].question << endl;

        for (int j = 0; j < 4; j++) {
            cout << j << ". " << quiz[i].options[j] << endl;
        }

        int answer;
        cout << "Enter your answer: ";
        cin >> answer;

        if (answer == quiz[i].correctAnswer) {
            score++;
        }
    }

    cout << "\nYour Score: " << score << "/" << quiz.size() << endl;

    // Ranking System
    priority_queue<User, vector<User>, Compare> leaderboard;

    // Sample Users (for demo ranking)
    leaderboard.push({"Alice", 3});
    leaderboard.push({"Bob", 2});
    leaderboard.push({"Charlie", 1});

    // Current User
    leaderboard.push({username, score});

    cout << "\n🏆 Leaderboard:\n";

    while (!leaderboard.empty()) {
        User u = leaderboard.top();
        cout << u.name << " - " << u.score << endl;
        leaderboard.pop();
    }

    return 0;
}

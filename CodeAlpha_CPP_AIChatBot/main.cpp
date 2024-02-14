#include"AIChatBot.hpp"


int main() {
    // Example usage
    string text = "HAPPY";
    double score = analyze_sentiment(text);
    cout << "Sentiment score: " << score << endl;
    return 0;
}
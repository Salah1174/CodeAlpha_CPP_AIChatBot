#include"AIChatBot.hpp"

double analyze_sentiment(string text) {
    /*
    This function analyzes the sentiment of a given text and returns a score between 0 and 1.
    A score closer to 0 indicates negative sentiment, while a score closer to 1 indicates positive sentiment.

    Parameters:
    text (string): The text to be analyzed

    Returns:
    double: The sentiment score of the text
    */

    //// Convert text to lowercase
    boost::algorithm::to_lower(text);
    // Define positive and negative words
    vector<string> positive_words = { "happy", "love", "great", "amazing", "wonderful" };
    vector<string> negative_words = { "sad", "hate", "terrible", "awful", "disgusting" };

    // Split text into words
    vector<string> words;
    string word = "";
    for (char c : text) {
        if (c == ' ') {
            words.push_back(word);
            word = "";
        }
        else {
            word += c;
        }
    }
    words.push_back(word);

    // Calculate sentiment score
    int positive_count = 0;
    int negative_count = 0;
    for (string w : words) {
        if (find(positive_words.begin(), positive_words.end(), w) != positive_words.end()) {
            positive_count++;
        }
        else if (find(negative_words.begin(), negative_words.end(), w) != negative_words.end()) {
            negative_count++;
        }

    }
    double sentiment_score;
    if ((positive_count != 0) || (negative_count != 0))
    {
        sentiment_score = (double)positive_count / (positive_count + negative_count);
    }
    else
    {
        sentiment_score = -1;
    }

    return sentiment_score;
}

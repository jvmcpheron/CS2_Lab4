#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Paragraph {
private:
    vector<string> words;

public:
    void addWord(const string& word) {
        words.push_back(word);
    }

    vector<string> getWords() const {
        return words;
    }

    bool isEmpty() const {
        return words.empty();
    }
};


class Document {
private:
    Document() {}

    vector<Paragraph> paragraphs;

public:
    Document(string fileName) {
        ifstream myFileStrm(fileName);
        string theLine;

        Paragraph currentParagraph;

        if (myFileStrm.is_open()) {
            vector<string> words;
            while (getline(myFileStrm,theLine,'\n')) {
                istringstream lineStringStrm(theLine);
                string word;
                cout << theLine.size() << endl;
                while (lineStringStrm >> word) {
                    currentParagraph.addWord(word);
                }
                // Rather than printing out the words, store them
                // by paragraphs I highly suggest you implement a
                // Paragraph class to hold the words of a paragraph

                if (theLine.empty() && !currentParagraph.isEmpty()) {
                    paragraphs.push_back(currentParagraph);
                    currentParagraph = Paragraph();  // Start a new paragraph
                }
            }


            if (!currentParagraph.isEmpty()) {
                paragraphs.push_back(currentParagraph);
            }

            myFileStrm.close();
        }
    }
    void prettyPrint() {
        // print out the document, making sure that
        // no line of a paragraph is longer than 80 chars

        for (const Paragraph& paragraph : paragraphs) {
            int lineLength = 0;
            for (const string& word : paragraph.getWords()) {
                if (lineLength + word.length() + 1 <= 80) {
                    if (lineLength > 0) {
                        cout << ' ';
                        lineLength++;
                    }
                    cout << word;
                    lineLength += word.length();
                } else {
                    cout << endl;
                    cout << word;
                    lineLength = word.length();
                }
            }
            cout << endl;
        }
    }

    
};

int main() {
    Document myDoc("GettysburgAddress.txt");
    myDoc.prettyPrint();
    return 0;
}
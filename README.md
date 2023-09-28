# CS2_Lab4

## Introduction
One of the things we often do is manipulate files of text.  I would like you to do some practice on this.  Below is some code to read in a document.  Right now the code divides the document into lines and then the lines into words but it doesn't store them.

I would like you to make the Document structure one that stores a full document broken up into paragraphs that contain words.

Add structure to the code to store the words into paragraphs.  You may assume paragraphs are separated by lines with no characters (empty lines).

In addition to storing the words I want you to then implement the function prettyPrint to print out the words in the file formatted so that all of the words in a paragraph are separated by spaces on lines of at most 80 characters and the last line in a paragraph has a return at the end of it even if the line isn't close to 80 characters.

## The Starting Code
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Document {
private:
    Document() {}
public:
    Document(string fileName) {
        ifstream myFileStrm(fileName);
        string theLine;
        if (myFileStrm.is_open()) {
            vector<string> words;
            while (getline(myFileStrm,theLine,'\n')) {
                istringstream lineStringStrm(theLine);
                string word;
                cout << theLine.size() << endl;
                while (lineStringStrm >> word) {
                    cout << "Word: " << word << endl;
                }
                // Rather than printing out the words, store them
                // by paragraphs I highly suggest you implement a
                // Paragraph class to hold the words of a paragraph
            }
            myFileStrm.close();
        }
    }
    void prettyPrint() {
        // print out the document, making sure that
        // no line of a paragraph is longer than 80 chars
    }
};

int main() {
    Document myDoc("GettysburgAddress.txt");
    myDoc.prettyPrint();
    return 0;
}
## What To Turn In
The submission requirements I'd like you to post from now on is:
1. submit as a .cpp file,
2. put JUST the first and last name of the person submitting the assignment as the name.
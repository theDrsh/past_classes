#include<string>
#include<vector>
#include<iostream>
using namespace std;

int findLength(vector<string> &words);      //This function finds the element of the vector with the longest length.

void padding(vector<string> &words, int maxLength); //This function pads all the words to the same length

void horizontal(vector<string> &words);  //This function will print the elements of the vector across the screen left to right

void inverted(vector<string> &words, int maxLength);    //This fucntion will print the words from bottom to top.

void vertical(vector<string> &words, int maxLength);    //This function will print the words from top to bottom

void reverse(vector<string> &words);    //This function prints words from left to right
                                        //IN ALL FUNCTIONS i REFERENCES THE POSITION WITHIN VECTOR(ELEMENT NUMBER) AND j REFERS TO CHAR NUMBER
int main()
{
   
    int maxLength = 0;
    vector<string> words;
    string input;
    while(input != "quit")
    {
        cin >> input;
        if(input != "quit") //Makes sure that "quit" isn't written to the vector
        {
            words.push_back(input);     //writes input to the vector
        }
    }
    maxLength = findLength(words);
    padding(words,maxLength);
    vertical(words, maxLength); 
    inverted(words, maxLength);
    horizontal(words);
    reverse(words);
    return 0;
}

int findLength(vector<string> &words)
{
    int maxLength = 0;
    for(int i = 0; i < words.size(); i++)
    {
        if(words[i].length() > maxLength)   //compares each element to the previous to check for max length
        {
            maxLength = words[i].length();
        }
    }
    return maxLength;
}

void padding(vector<string> &words, int maxLength)
{ 
    int lengthDiff = 0;
    for(int i = 0; i< words.size(); i++)    //writes whitespace to fill shorter words
        {
            lengthDiff = maxLength - words[i].length();
            string padding (lengthDiff, ' ');
            words[i] += padding;
        }      
}

void horizontal(vector<string> &words)
{
    string horizontalWord;
    int wordLength = 0;
    for(int i = 0; i < words.size(); i++)   //writes words horizontally and adds a space between letters except for last letter
    {   
        wordLength = words[i].length();
        for(int j = 0; j<wordLength; j++)
        {
            horizontalWord += words[i][j];
            if(j<(wordLength - 1))
            {
                horizontalWord += ' ';
            }
        }
        cout << horizontalWord << endl;
        horizontalWord.erase();
    }
    cout << endl;
}

void inverted(vector<string> &words, int maxLength)
{
    string inverted;
    int elements = 0;
    elements = words.size();
    for(int j = 0; j < maxLength; j++)  //writes words bottom to top and makes sure there are spaces between     
    {                                   //each letter but not after last letter of each element

        for(int i = 0; i < elements; i++)
        {
            inverted += words[i][(maxLength-1) - j];
            if(i<words.size()-1)
                inverted += ' ';
        }
        cout<< inverted << endl;
        inverted.erase();
    }
    cout << endl;
}

void vertical(vector<string> &words, int maxLength)
{
    string vertical;
    for(int j = 0; j < maxLength; j++)  //Writes from top to bottom
    {
        for(int i = 0; i < words.size(); i++)
        {
            vertical += words[i][j];
            if(i<words.size()-1)
                vertical += ' ';
        }
        cout<< vertical << endl;
        vertical.erase();
    }
    cout<< endl;
}
void reverse(vector<string> &words)
{
    int wordLength = 0;
    string reverseWord;
    for(int i = 0; i < words.size(); i++)   //writes left to right
    {
        wordLength = words[i].length();
        for(int j = 0; j < wordLength; j++)
        {
            reverseWord += words[i][(wordLength - 1) - j];
            if(j < (wordLength-1))
            {
                reverseWord += ' ';
            }
        }
            cout << reverseWord << endl;
            reverseWord.erase();
     }
}

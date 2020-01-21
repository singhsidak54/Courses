#include<bits/stdc++.h>
using namespace std;
#define N 10

/*
Crossword Problem

CodingNinjas has provided a crossword of 10*10 grid. The grid contains '+' or '-' as its cell values. Now, you are also provided with a word list that needs to placed accurately in the grid. Cells marked with '-' are to be filled with word list.
For example, The following is an example for the input crossword grid and the word list.
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV

Output for the given input should be:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA

Note: We have provided such test cases that there is only one solution for the given input.

Input format:
The first 10 lines of input contain crossword. Each of 10 lines has a character array of size 10. Input characters are either '+' or '-'.
The next line of input contains the word list, in which each word is separated by ';'. 

Output format:
Print the crossword grid, after placing the words of word list in '-' cells.  
*/

void printCrossword(char crossword[N][N])
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout<<crossword[i][j];
        }
        cout<<endl;
    }
}

bool isValidVertical(char crossword[N][N],int row,int col,string word)
{
    int count = 0;

    while(row < N && (crossword[row][col] == '-' || crossword[row][col] == word[count]))
    {
        count++;
        row++;
    }
    
    int len = word.size();
    
    if(count == len)
        return true;
    
    else
        return false;
}

bool isValidHorizontal(char crossword[N][N],int row,int col,string word)
{
    int count = 0;
    
    while(col < N && (crossword[row][col] == '-' || crossword[row][col] == word[count]))
    {
        count++;
        col++;
    }
    
    int len = word.size();
    if(count == len)
        return true;
    
    else
        return false;
}

void setVertical(char crossword[N][N],int row,int col,string word,bool temp[],int len)
{
    for(int i=0;i<len;i++)
    {
        if(crossword[i+row][col] == '-')
        {
            crossword[i+row][col] = word[i];
            temp[i] = true;
        }
    }
}

void setHorizontal(char crossword[N][N],int row,int col,string word,bool temp[],int len)
{
    for(int i=0;i<len;i++)
    {
        if(crossword[row][i+col] == '-')
        {
            crossword[row][i+col] = word[i];
            temp[i] = true;
        }
    }
}

void resetVertical(char crossword[N][N],int row,int col,bool temp[],int len)
{
    for(int i=0; i<len; i++)
    {
        if(temp[i])
            crossword[i+row][col] = '-';
    }
}

void resetHorizontal(char crossword[N][N],int row,int col,bool temp[],int len)
{
    for(int i=0; i<len; i++)
    {
        if(temp[i])
            crossword[row][i + col] = '-';
    }
}
bool solveCrossword(char crossword[N][N],string words[],int index,int n)
{
    if(index == n)
    {
        printCrossword(crossword);
        return true;
    }
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(crossword[i][j] == '-' || crossword[i][j] == words[index][0])
            {
                if(isValidVertical(crossword,i,j,words[index]))
                {
                    int len = words[index].size();
                    bool temp[len];
                    setVertical(crossword,i,j,words[index],temp,len);
                    if(!solveCrossword(crossword,words,index + 1,n))
                    {
                        resetVertical(crossword,i,j,temp,len);
                    }
                    else
                        return true;
                }
                
                if(isValidHorizontal(crossword,i,j,words[index]))
                {
                    int len = words[index].size();
                    bool temp[len];
                    setHorizontal(crossword,i,j,words[index],temp,len);
                    if(!solveCrossword(crossword,words,index + 1,n))
                    {
                        resetHorizontal(crossword,i,j,temp,len);
                    }
                    else
                        return true;                       
                }   
            }
        }
    }
                   
    return false;
}
int main() {

	char crossword[10][10];
    
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
            cin>>crossword[i][j];
    
    
    string wordList;
    cin>>wordList;
    
    int n = 1;
    for(int i=0; i<wordList.size(); i++)
        if(wordList[i] == ';')
            n++;
    
    
    string words[n];
    int j=0;
    string temp = "";
    for(int i=0; i<wordList.size(); i++)
    {
        if(wordList[i] == ';')
        {
            words[j] = temp;
            temp = "";
            j++;
        }
        else
        {
            temp += wordList[i];
        }
    }
    words[j] = temp;
    solveCrossword(crossword,words,0,n);
}

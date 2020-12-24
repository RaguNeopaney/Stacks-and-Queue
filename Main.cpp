
#include <iostream>
#include "Queue.h"
#include "Stack.h"
#include <fstream>
#include <string>

using namespace std;


int main() {
    queue<char>* All = new queue<char>(5);
    stack<char>* Bll = new stack<char>(5);
    string fileName,full_file, text_from_file;
    fstream data;
    cout << "Enter a file name: ";
    cin >> fileName;
    full_file = fileName + ".txt";
    data.open(full_file, ios::in);                      // Tries to open the file file
    if (data.fail()) {
        do                                            // if the file fails to open this code block will executes and ask user to enter file name until right file name is provided
        {
            cout << "Unable to open the file. (enter file name without the extension)" << endl;
            cout << "Enter a file name: ";
            cin >> fileName;
            full_file = fileName + ".txt";
            data.open(full_file, ios::in);
        } while (data.fail());
        // rest of the codes goes here once the file open successfully
        getline(data, text_from_file);                              // This will get the line from the text file and stores it in the string text_from_file
        data.close();                                               // close the file after the data are imported successfully
        int length = text_from_file.length();
        queue<char>* All = new queue<char>(length);                 // both the queue and stack array are given the length of the string (total number of charactes in the strings)
        stack<char>* Bll = new stack<char>(length);
    }
    // use this if the files open successfully the first time 
    else                                                       // if successful it moves here and continues
    {
        getline(data, text_from_file);                               // This will get the line from the text file and stores it in the string text_from_file
        data.close();                                               // close the file after the data are imported successfully
        int length = text_from_file.length();
        queue<char>* All = new queue<char>(length);                 // both the queue and stack array are given the length of the string (total number of charactes in the strings)
        stack<char>* Bll = new stack<char>(length);

        try
        {   
            for (int i = 0; i < length; i++)
            {
                if (text_from_file[i] != ' ')
                {
                    Bll->push(text_from_file[i]);
                }
                else
                {
                    while (Bll->isempty() == false) 
                    {
                        All->enqueue(*(Bll->top()));
                        Bll->pop();
                        cout << *(All->dequeue());
                    }
                    cout << " ";
                }
            }
            while (Bll->isempty() == false) {
                All->enqueue(*(Bll->top()));
                Bll->pop();
                cout << *(All->dequeue());

            }
        
        }
        
        catch (stack<char>::fullerror)
        {
            cout << "ERROR: Cannot add more to a stack.Stack is full.\n stack overflow\n";
        }
        catch (stack<char>::emtyerror)
        {
            cout << "ERROR: Cannot pop from a empty stack. \nStack underflow \n";
        }
        catch (stack<char>::toperror)
        {
            cout << "ERROR: There are no item in the stack. \n";
        }

        /*
            These are the error handler for queues
        */
        catch (queue<char>::enqueError)
        {
            cout << "ERROR: Cannot Enqeue the queue is full. Queue overflow \n";
        }
        catch (queue<char>::dequeError)
        {
            cout << "ERROR: Cannot dequeue from the queue. Queue is empty. Queue underflow \n";
        }
        catch (queue<char>::pekError)
        {
            cout << "ERROR: Cannot peek into a empty queue. \n";
        }
    }

}

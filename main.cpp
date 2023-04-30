#include <iostream>
//#include <fstream>

#include "Headers/Units.h"
#include "Headers/Board.h"

using namespace std;

/*void tokenize(string s, string del = " ")
{
    int start, end = -1 * del.size();
    do
    {
        start = end + del.size();
        end = s.find(del, start);
        cout << s.substr(start, end - start) << endl;
    } while (end != -1);
};*/

int main()
{
    string mediator = "D:\\Users\\trane\\CLionProjects\\untitled\\text.txt";
    //cin>>mediator;
    Board board(mediator);


    return 0;
}
#include "Huffman.h"
#include <windows.h>
void setConsoleColor(WORD c) // Coloring the output
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
int main() {

    int i = 0;
    while (i < 20) {
        // the array of characters to read in the text file 
        vector<char> arr;
        // the name of the text file to be read in
        string filename = "testingFiles/inText";
        filename += to_string(i);
        filename += ".txt";
       
        ifstream inData(filename);

        if (inData.is_open())
        {
            int i = 0;
            char c;

            while (inData.get(c)) {
                arr.push_back(c);
                i++;}

            setConsoleColor(46);
            cout << setw(60) << "FILENAME: " << filename << endl;
            setConsoleColor(7);
            Huffman(arr, filename);
            inData.clear();
            int uncompressed = get_file_size(filename);
            int compressed = get_file_size(filename + "Compressed.txt");
            cout << "\nThe size of the REGULAR file before is: " << uncompressed << " bytes";
            cout << "\nThe size of the COMPRESSED file after is: " << compressed << " bytes";
            cout << "\nThe Ratio of the compression is: " << (float)compressed / uncompressed * 100 << "%";
            setConsoleColor(50);
            cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
            setConsoleColor(7); 
            inData.close();
        }
        else cout << "\nUnable to open file\n";
        i++;
    }
    return 0;
}

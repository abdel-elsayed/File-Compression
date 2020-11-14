#include "Huffman.h"

int main() {

    vector<char> arr;
  
    ifstream inData("inText.txt");
    if (inData.is_open())
    {
        int i = 0;
        char c;
        while (inData.get(c))
        {
            arr.push_back(c);
            i++;
        }
        inData.close();
    }
    else cout << "Unable to open file";

    buildHuffmanTree(arr);

    return 0;
}
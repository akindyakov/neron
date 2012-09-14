#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main()
{
    srand(time(NULL));
    for (int i = 0; i < 50; ++i)
    {
         int in = rand();
         cout << "rand = " << in << endl;
    }
    ifstream in("/home/alexander/Dropbox/neron/algo_test/ran_generation/random_generation/dxsdk_aug2006.exe", ios::in|ios::binary);
    if (!in)
    {
      cout << "Not a file";
    }
    char ch;
    while(in)
    {
      in.get(ch);
      if (in) cout << (int)ch << endl;
    }
    cout << "Hello world!" << endl;
    return 0;
}

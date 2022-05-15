#include <iostream>
#include <string>
#include <vector>

bool isAnagram(std::string s1, std::string s2);

int main()
{
    std::string s = "cat";
    std::string t = "tac";
    std::cout << "s and t are: "<< isAnagram(s, t);

    return isAnagram(s, t);

}

bool isAnagram(std::string s1, std::string s2)
{
    std::vector<int> charsCount(26, 0);
    for (char letter: s1)
    {
        if (letter != ' ')
        {
            ++charsCount[letter - 'a'];
        }
    }

    for (char letter: s2)
    {
        if (letter != ' ')
        {
            if (--charsCount[letter - 'a'] < 0)
            {
                return false;
            }
        }
    }
    for (int count: charsCount)
    {
        if (count > 0)
        {
            return false;
        }
    }
    return true;

}


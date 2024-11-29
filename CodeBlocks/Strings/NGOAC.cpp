#include <bits/stdc++.h>

std::string Check(std::string str);


std::string str;

int main()
{
    getline(std::cin, str);

    std::cout << Check(str);
}

std::string Check(std::string str)
{
    int openLength = 0;
    int pos;

    int closeLength = 0;

    bool check = true;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != '(' && str[i] != ')')
        {
            return "KHONG HOP LE";
        }

        
        
        if (check == true)
        {
            if (str[i] == '(')
            {
                openLength += 1;
                pos = i;
                check = false;
            }
        }
        
        else
        {
            if (str[i] == ')')
            {
                while (str[i] == ')')
                {
                    closeLength += 1;
                    i += 1;

                    if (str[i] != '(' && str[i] != ')')
                    {
                        if(i < str.length())
                        {
                            return "KHONG HOP LE";
                        }
                    }
                }

                if (closeLength != openLength)
                {
                    return "KHONG DUNG";
                }

                i += openLength;
                openLength = 1;
                check = true;
            }
            else
            {
                openLength += 1;
            }
        }
    }


    if (str.length() > 1 || str.length() == 0)
    {
        return "DUNG";
    }
    else
    {
        return "KHONG DUNG";
    }
}
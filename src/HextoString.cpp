#include <iostream>

static int IntFromHex(unsigned char *pChars)
{
    int Hi;     //   高位
    int Lo;     //   低位
    int Result; //   结果

    Hi = pChars[0];
    if ('0' <= Hi && Hi <= '9')
    {
        Hi -= '0';
    }
    else if ('a' <= Hi && Hi <= 'f')
    {
        Hi -= ('a' - 10);
    }
    else if ('A' <= Hi && Hi <= 'F')
    {
        Hi -= ('A' - 10);
    }

    Lo = pChars[1];
    if ('0' <= Lo && Lo <= '9')
    {
        Lo -= '0';
    }
    else if ('a' <= Lo && Lo <= 'f')
    {
        Lo -= ('a' - 10);
    }
    else if ('A' <= Lo && Lo <= 'F')
    {
        Lo -= ('A' - 10);
    }
    Result = Lo + (16 * Hi);
    return Result;
}

std::string GetStringFromHexFromat(const std::string &sKey)
{
    std::string ret;
    int len = sKey.length() / 2;
    for (int i = 0; i < len; i++)
    {
        ret += IntFromHex((unsigned char *)sKey.substr(i * 2, 2).c_str());
    }
    return ret;
}

int main()
{
    std::cout << GetStringFromHexFromat("e4bda0e79c8be588b0e79a84e698afe4b880e69da1e6b58be8af95e5ad97e7aca6e4b8b2e59096efbc81") << std::endl;
}
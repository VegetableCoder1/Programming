/*
翻转字符串中的单词
"the sky is blue" ==> "blue is sky the"
"  hello world!  " ==> "world! hello"
"a good   example" ==> "example good a"

c++ 标准库并不提供split方法
利用STL自己实现split 函数
split()方法：输入一个字符串，一个分隔符字符串(可包含多个分隔符)，返回一个字符串向量
vector<string> split(const string &s, const string &seperator);

*/

#include <bits/stdc++.h>
using namespace std;
string reverseWords(string s);
vector<string> split(const string &s, const string &seperator);
int main()
{
    string s = "..hello.*world.*!";
    cout<<reverseWords(s)<<endl;
}
vector<string> split(const string &s, const string &seperator)
{
    vector<string> result;
    typedef string::size_type string_size;
    string_size i = 0;

    while (i != s.size())
    {
        //找到字符串中首个不等于分隔符的字母；
        int flag = 0;
        while (i != s.size() && flag == 0)
        {
            flag = 1;
            for (string_size x = 0; x < seperator.size(); ++x)
                if (s[i] == seperator[x])
                {
                    ++i;
                    flag = 0;
                    break;
                }
        }

        //找到又一个分隔符，将两个分隔符之间的字符串取出；
        flag = 0;
        string_size j = i;
        while (j != s.size() && flag == 0)
        {
            for (string_size x = 0; x < seperator.size(); ++x)
                if (s[j] == seperator[x])
                {
                    flag = 1;
                    break;
                }
            if (flag == 0)
                ++j;
        }
        if (i != j)
        {
            result.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    return result;
}
string reverseWords(string s)
{
    if(s.size() == 0 || s == "" || s.find_first_not_of(' ') == s.npos) return s;
    vector<string> words = split(s, ".*");
    string ans = "";
    for (int i = words.size() - 1; i >= 0; i--)
    {
        ans += words[i];
        ans += " ";
    }
    ans.pop_back();
    return ans;
}
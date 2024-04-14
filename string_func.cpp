#include "string_func.h"

// wstring to string
inline std::string wstring2utf8string(const std::wstring &str)
{
    static std::wstring_convert<std::codecvt_utf8<wchar_t>> strCnv;
    return strCnv.to_bytes(str);
}

// string to wstring
inline std::wstring utf8string2wstring(const std::string &str)
{
    static std::wstring_convert<std::codecvt_utf8<wchar_t>> strCnv;
    return strCnv.from_bytes(str);
}

inline std::wstring String2wstring(const std::string& str, const std::string& locale)
{
    typedef std::codecvt_byname<wchar_t, char, std::mbstate_t> F;
    std::wstring_convert<F> strCnv(new F(locale));
    return strCnv.from_bytes(str);
}

inline std::wstring StrToWstr(std::string str)
{
    if (str.length() == 0)
        return L"";
    return String2wstring(str, "zh-CN");
}

int splitString(const std::string &str, const char split, std::vector<std::string> &res)
{
    if (str == "")
    {
        return -1;
    }
    std::string &&strs = str + split;
    size_t pos = strs.find(split);

    while (pos != std::string::npos)
    {
        res.emplace_back(strs.substr(0, pos));
        strs = move(strs.substr(pos + 1, strs.size()));
        pos = strs.find(split);
    }
    return 0;
}

int splitString(const std::string &str, const std::string &sp, std::vector<std::string> &vecdst)
{
    std::string str_tmp = str;
    if (str.size() < 1 || sp.size() < 1)
    {
        return -1;
    }
    size_t pos = str_tmp.find(sp);
    while (pos != std::string::npos)
    {
        std::string str_sub = str_tmp.substr(0, pos);
        if (!str_sub.empty())
        {
            vecdst.push_back(str_sub);
            str_tmp = str_tmp.substr(pos + 1, str_tmp.size());
        }
        pos = str_tmp.find(sp);
        if (pos == std::string::npos)
        {
            if (!str_tmp.empty())
            {
                vecdst.push_back(str_tmp);
            }
            break;
        }
    }
    return 0;
}

std::string replaceString(const std::string &str, const std::string &str_find, const std::string &str_replace)
{
    std::string str_tmp = str;
    if (str.size() < 1 || str_find.size() < 1)
    {
        return str_tmp;
    }

    size_t pos = str_tmp.find(str_find);
    while (pos != std::string::npos)
    {
        str_tmp.replace(pos, str_find.length(), str_replace);

        size_t pos_t = pos + str_replace.length();
        std::string str_sub = str_tmp.substr(pos_t, str_tmp.length() - pos_t);

        size_t pos_tt = str_sub.find(str_find);
        if (std::string::npos != pos_tt)
        {
            pos = pos_t + str_sub.find(str_find);
        }
        else
        {
            pos = std::string::npos;
        }
    }
    return str_tmp;
}
bool startsWith(const std::string &str, const std::string &prefix)
{
    if (str.size() < prefix.size())
    {
        return false;
    }
    return str.substr(0, prefix.size()) == prefix;
}
bool endsWith(const std::string &str, const std::string &suffix)
{
    if (str.size() < suffix.size())
    {
        return false;
    }
    return str.substr(str.size() - suffix.size()) == suffix;
}

std::string joinString(const std::vector<std::string> &tokens, const std::string &delimiter)
{
    std::string result;
    for (size_t i = 0; i < tokens.size(); ++i) {
        result += tokens[i];
        if (i < tokens.size() - 1) {
            result += delimiter;
        }
    }
    return result;
}

std::wstring joinString(const std::vector<std::wstring>& tokens, const std::wstring& delimiter) {
    std::wstring result;
    for (size_t i = 0; i < tokens.size(); ++i) {
        result += tokens[i];
        if (i < tokens.size() - 1) {
            result += delimiter;
        }
    }
    return result;
}

static bool isStripChar(const char& ch) {
	return stripChar.find(ch) != std::string::npos;
}

//std::wstring stripString(const std::wstring &text)
//{
//    std::wstring ret = text;
//    if (ret.empty())
//        return ret;
//    size_t pos = 0;
//    while (pos < ret.size() && isStripChar(utf8string2wstring(ret[pos])))
//        pos++;
//    if (pos != 0)
//        ret = ret.substr(pos, ret.size() - pos);
//    pos = ret.size() - 1;
//    while (pos != (size_t)-1 && isStripChar(utf8string2wstring(ret[pos])))
//        pos--;
//    return ret.substr(0, pos + 1);
//}
std::string stripString(const std::string &text)
{
    std::string ret = text;
    if (ret.empty())
        return ret;
    size_t pos = 0;
    while (pos < ret.size() && isStripChar(ret[pos]))
        pos++;
    if (pos != 0)
        ret = ret.substr(pos, ret.size() - pos);
    pos = ret.size() - 1;
    while (pos != (size_t)-1 && isStripChar(ret[pos]))
        pos--;
    return ret.substr(0, pos + 1);
}
std::string toUpper(const std::string& str) 
{
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

std::string toLower(const std::string& str) 
{
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

bool isChineseChar(const wchar_t &ch)
{
    if ((ch >= 0x4E00 && ch <= 0x9FFF) ||
        (ch >= 0x3400 && ch <= 0x4DBF) ||
        (ch >= 0x20000 && ch <= 0x2A6DF) ||
        (ch >= 0x2A700 && ch <= 0x2B73F) ||
        (ch >= 0x2B740 && ch <= 0x2B81F) ||
        (ch >= 0x2B820 && ch <= 0x2CEAF) ||
        (ch >= 0xF900 && ch <= 0xFAFF) ||
        (ch >= 0x2F800 && ch <= 0x2FA1F))
        return true;
    return false;
}

bool isChineseChar(const char &ch)
{
    unsigned int code = static_cast<unsigned int>(ch);
    if ((code >= 0x4E00 && code <= 0x9FFF) ||
        (code >= 0x3400 && code <= 0x4DBF) ||
        (code >= 0x20000 && code <= 0x2A6DF) ||
        (code >= 0x2A700 && code <= 0x2B73F) ||
        (code >= 0x2B740 && code <= 0x2B81F) ||
        (code >= 0x2B820 && code <= 0x2CEAF) ||
        (code >= 0xF900 && code <= 0xFAFF) ||
        (code >= 0x2F800 && code <= 0x2FA1F))
        return true;
    return false;
}
#pragma once 
#include <string>
#include <locale>
#include <codecvt>
#include <vector>
#include <algorithm>
#include <cwchar>



const std::string stripChar = " \t\n\r\v\f";
// wstring to string
inline std::string wstring2utf8string(const std::wstring& str);
 
// string to wstring 
inline std::wstring utf8string2wstring(const std::string& str);
int  splitString(const std::string& str, const char split, std::vector<std::string>& res);
int splitString(const std::string& str, const std::string& sp, std::vector<std::string>& vecdst);
std::string replaceString(const std::string& str, const std::string& str_find, const std::string& str_replace);

bool startsWith(const std::string& str, const std::string& prefix);
bool endsWith(const std::string& str, const std::string& suffix);
std::string joinString(const std::vector<std::string>& tokens, const std::string& delimiter);
std::wstring joinString(const std::vector<std::wstring>& tokens, const std::wstring& delimiter);
//std::wstring stripString(const std::wstring &text);
std::string stripString(const std::string &text);
std::string toUpper(const std::string& str) ;
std::string toLower(const std::string& str);
bool isChineseChar(const wchar_t& ch);
bool isChineseChar(const char& ch);
#pragma once
#include<iostream>
#include<map>
#include<fstream>
#include<string>
#include<cstdlib>
#include<vector>
#include <sstream>
#define L int
#define IdW float
#define GmId float
class lookupTableGmOverId
{
public:
    lookupTableGmOverId();
    ~lookupTableGmOverId();
    std::map<L, std::map<IdW, GmId>> getCSVMap();
    void toCsvMapString();
    void readCSVFile();
private:
    std::map<L,std::map<IdW, GmId>> csvMap;
};


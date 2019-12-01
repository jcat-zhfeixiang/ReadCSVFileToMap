#include "lookupTableGmOverId.h"

lookupTableGmOverId::lookupTableGmOverId()
{
    
}

lookupTableGmOverId::~lookupTableGmOverId()
{

}

std::map<L, std::map<IdW, GmId>> lookupTableGmOverId::getCSVMap()
{
    return this->csvMap;
}

void lookupTableGmOverId::toCsvMapString()
{
    std::map<L, std::map<IdW, GmId>>::iterator iterCsvMap;
    std::map<IdW, GmId>::iterator iterCsv;
    iterCsvMap = csvMap.begin();
    for (iterCsvMap;iterCsvMap!=csvMap.end();iterCsvMap++)
    {
        std::cout << "L: " << iterCsvMap->first << std::endl;
        iterCsv = (iterCsvMap->second).begin();
        for (iterCsv;iterCsv!= (iterCsvMap->second).end();iterCsv++)
        {
            std::cout << iterCsv->first << "," << iterCsv->second << std::endl;
        }
    }
    return;
}

void lookupTableGmOverId::readCSVFile()
{
    const std::string filePath = "./data/";
    for (size_t i = 1; i <= 10; i++)
    {
        std::map<IdW, GmId> csv;
        std::string fileName = filePath + std::to_string(i) + ".2.csv";
        //std::cout << fileName << std::endl;
        std::ifstream csvFile(fileName, std::ios::in); //打开文件
        if (!csvFile) {
            std::cerr << "Failed to open file" << fileName << std::endl;
            exit(1); //退出应用程序
        }
        else
        {       //一个向量，用来保存从文件中读取的一行数据，并把数据进行分组（2个）。
                std::vector<std::string> vect;
                std::string _oneLine; //从文件中读取的一行数据，保存在这个string中

                //开始读取
                while (std::getline(csvFile , _oneLine))
                {
                    
                    std::istringstream ReadLine(_oneLine);
                    std::string _oneLines;
                    float key, value;
                    //对一行数据进行分组（以“,”为分界符）
                    //例如（4.33E-05,30.43439611），4.33E-05存到vect[0]中，30.43439611存到vect[1]中。
                    while (std::getline(ReadLine , _oneLines , ','))
                    {
                        vect.push_back(_oneLines);
                    }
                    //数据格式转换，字符串转float
                    std::istringstream iiskey(vect[0]);
                    std::istringstream iisvalue(vect[1]);
                    vect.clear();
                    iiskey >> key;
                    iisvalue >> value;
                    //把数据保存到map中
                    csv.insert(std::pair<IdW , GmId>(key,value));
                }
                csvMap.insert(std::pair<L, std::map<IdW, GmId>>(i, csv));     
        }
    }
    
}

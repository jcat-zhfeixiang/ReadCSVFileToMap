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
        std::ifstream csvFile(fileName, std::ios::in); //���ļ�
        if (!csvFile) {
            std::cerr << "Failed to open file" << fileName << std::endl;
            exit(1); //�˳�Ӧ�ó���
        }
        else
        {       //һ������������������ļ��ж�ȡ��һ�����ݣ��������ݽ��з��飨2������
                std::vector<std::string> vect;
                std::string _oneLine; //���ļ��ж�ȡ��һ�����ݣ����������string��

                //��ʼ��ȡ
                while (std::getline(csvFile , _oneLine))
                {
                    
                    std::istringstream ReadLine(_oneLine);
                    std::string _oneLines;
                    float key, value;
                    //��һ�����ݽ��з��飨�ԡ�,��Ϊ�ֽ����
                    //���磨4.33E-05,30.43439611����4.33E-05�浽vect[0]�У�30.43439611�浽vect[1]�С�
                    while (std::getline(ReadLine , _oneLines , ','))
                    {
                        vect.push_back(_oneLines);
                    }
                    //���ݸ�ʽת�����ַ���תfloat
                    std::istringstream iiskey(vect[0]);
                    std::istringstream iisvalue(vect[1]);
                    vect.clear();
                    iiskey >> key;
                    iisvalue >> value;
                    //�����ݱ��浽map��
                    csv.insert(std::pair<IdW , GmId>(key,value));
                }
                csvMap.insert(std::pair<L, std::map<IdW, GmId>>(i, csv));     
        }
    }
    
}

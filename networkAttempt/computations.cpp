#include "computations.h"
#include <bitset>
#include <vector>
#include <QVariant>

computations::computations(QString inputIP, QString userClass)
{
    localIP = inputIP;
    subnet= userClass;
    validInput = is_valid(localIP);
}
//Check if the dec is between 0 && 255
bool computations::withinRange(int dec)
{
    //return((dec> 255 || dec <0) ? false: true);
    if(dec>255 || dec < 0)
        return false;
    return true;
}


bool computations::checkInput()
{
    return validInput;
}

//make sure the user input is valid
bool computations::is_valid(QString input)
{
    QString temp;
    int count = 0;
    bool validate = true;
    for(auto c: input)
    {
        if(c =='.' || c==' ' || temp.size() >=3){
            validate=withinRange(temp.toInt());
            temp="";
            if(c == '.')
            {
                count++;
            }
        }
        else{
            temp += c;
        }
        if(!validate)
               return false;
    }
    if(count != 3)
    {
     return false;
    }
    return true;
}



int computations::qstringToInt(QString dec)
{
    return dec.toInt();
}



std::vector<int> computations::populate(QString adress)
{
    std::vector<int> out;
    QString temp;
    for(auto c: adress)
    {
        if(c =='.' || c==' ' || temp.size() >=3){
            out.push_back(temp.toInt());
            temp="";
        }
        else{
            temp += c;
        }
    }
    return out;
}


void computations::outputString(std::vector<int> &vec)
{
    for(auto it = vec.begin(); it < vec.end(); it++)
    {
        QVariant var(*it);
        output +=var.toString();
        if(it !=  (vec.end()-1))
        {
            output+='.';
        }
    }
//    for(auto a: vec)
//    {
//       QVariant var(a);
//       output += var.toString();

//    }
}


void computations::compute()
{

    std::vector<int> ip_byte = populate(localIP);
    std::vector<int> subnet_byte = populate(subnet);
    std::vector<int> hostIP;
    for(int i= 0 ; i < 4 ; i++)
    {
       hostIP.push_back(ip_byte[i] & subnet_byte[i]);
    }
    outputString(hostIP);
}

QString computations::hostIP()
{
    return output;
}

//
// Created by Mahone on 2022/1/18.
//

//第一行是一个IP地址，
//
//第二行是一个IP地址和对应的IP子网掩码
//问题：给出一个网段，该网段的地址都属于黑名单，验证其他ip地址是否属于黑名单

/**
 * 对于一个CIDR的ip地址，怎么得到子网掩码？
 * 可以得到CIDR中的网络号位数netCount，然后：
 * int mask = 0xFFFFFFFF << (32 - netCount);
 *
*/
#include <utility>

#include "include/headers.h"

/**
     * @param network 黑名单网段
     * @param maskIp 扫描ip
     * @return
     */

vector<int> split(const string str,const char &del) {
    stringstream ss(str);
    string temp;
    vector<int> ret;
    while (getline(ss, temp, del)) {
        ret.push_back(stoi(temp));
    }
    return ret;
}

bool IPFilter(const string& network,string maskIp){
    vector<int> ips = split(std::move(maskIp), '.');
    if (ips.size()!=4) return false;
    uint32_t ip = ips[0] << 24 | ips[1] << 16 | ips[2] << 8 | ips[3];
    int pos = network.find('/');
    string tmp = network.substr(0, pos);
    vector<int> networks = split(tmp, '.');
    uint32_t network_ip = networks[0] << 24 | networks[1] << 16 | networks[2] << 8 | networks[3];
    uint32_t net_count = stoi(network.substr(pos + 1 , network.size()- pos - 1));
    uint32_t mask = 0xFFFFFFFF << (32 - net_count);
    return (ip & mask) == (network_ip & mask);
}




int main(){
    bool isBlack = IPFilter("192.168.13.3/24", "192.168.12.3");
    if(isBlack){
        cout << "黑名单"<< endl;
    }else{
        cout << "不是"<< endl;
    }


}


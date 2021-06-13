
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;




int main() {
    //import java.util.*;
    //
    //public class ForTest {
    //public static int main(String[] args) {
    //        Scanner sc = new Scanner(System.in);
    //        String input = sc.nextLine();
    //        if (!input.contains("o")) {
    //            System.out.println(input.length());
    //            return 0;
    //        }
    //        String[] split = input.split("o");
    //        if(split.length==0){
    //            Boolean isEven =input.length()%2 ==0;
    //            if (isEven){
    //                System.out.println(input.length());
    //            }else {
    //                System.out.println(input.length()-1);
    //            }
    //            return 0;
    //        }
    //        Boolean isEven = split.length % 2 == 0;
    //        if (isEven) {
    //            List<Integer> lenList = new ArrayList<>();
    //            for (String str : split) {
    //                lenList.add(str.length());
    //            }
    //            Collections.sort(lenList);
    //            int length = 0;
    //            for (int i = 1; i <= lenList.size() - 1; i++) {
    //                length += lenList.get(i);
    //            }
    //            length += lenList.size() - 2;17
    //            System.out.println(length);
    //        } else {
    //            System.out.println(input.length());
    //        }
    //        return 0;
    //    }
    //}
    string s;
    getline(cin, s);
    string flag="o";
    int pos=0,last=0;
    vector<string> strList;
    while((pos=s.find(flag,pos))!=string::npos)
    {
        strList.emplace_back(s.substr(last, pos+1 - last));
        pos++;
        last = pos;
    }
    if (strList.size() % 2 == 0) {
        cout << s.size()<< endl;
        return s.size();
    }
    if (last != s.size()-1&&!s.empty()) {
        strList.emplace_back(s.substr(last, s.size() - 1) + strList[0]);
    }

    vector<int> lenList;
    for (int i = 0; i < strList.size(); ++i) {
        lenList.emplace_back(strList[i].size());
    }
    sort(lenList.begin(), lenList.end());
    int ans = 0;
    for (int i = 1; i < lenList.size(); ++i) {
        ans += lenList[i];
    }
    ans += (lenList[0] - 1);
    cout <<"---"<< ans<< endl;
    return ans;







    return 0;
}

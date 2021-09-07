//
// Created by Mahone on 2021/9/1.
//

/**
 * http://tingyun.site/2018/04/26/%E7%BA%A6%E7%91%9F%E5%A4%AB%E7%8E%AF%E9%97%AE%E9%A2%98%E8%AF%A6%E8%A7%A3/
 */


/**
 *在一间房间总共有n个人（下标0～n-1），只能有最后一个人活命
 *所有人围成一圈
 *顺时针报数，每次报到q的人将被杀掉
 *被杀掉的人将从房间内被移走
 *然后从被杀掉的下一个人重新报数，继续报q，再清除，直到剩余一人
 *
 *
*/

int main() {
    int n,m;   //n 总人数  m 杀第几个.
    cin >> n >> m;
    //从0开始计数
    int result = 0;
    for(int i = 2; i <= n; i++){
        result = (result + m) % i;
    }
    cout<<"result = "<<result + 1 <<endl;  //默认从 0 开始  +1从1开始
    return 0;

}
/**< ��������������
����һ���������飬�ж������������������ֵ����Сֵ�Ĳ�ֵ������num�����������Ƹ������꣩�ĸ�����
��������ָԭ����������������±��ϵ�Ԫ����ɵ����飩

�����⣺����ÿ��Ԫ�أ��ٱ����Ե�ǰԪ��Ϊ�׵����������飬�ٱ����������ҵ����е����ֵ����Сֵ���ж�
���Ƿ��ꡣ����Ȼ���ַ�����ʱ�临�Ӷ�Ϊo(N^3)�������ʹ�����ֵ���½ṹ������ʵ��O(N)����Ľ⡣

���ʹ��L��R����ָ��ָ������������±꣬��L��R����ߡ���L~R��һ��������ʱ�������Ƶ�����L��ͷ�ĳ���
������R-L+1�����������鶼��ꣻ��L~R��һ�����鲻���ʱ������L���������ٸ�λ�û���R���������ٸ�λ�ã�
L~R���ǲ���ꡣ

O(N)�Ľ��Ӧ���㷨�ǣ�L��R����0��ʼ��R�������ƶ���Rÿ����һ��λ�þ�ʹ�����ֵ���½ṹ����Сֵ���½ṹ
��¼һ��L~R֮������ֵ����Сֵ���±꣬��R�ƶ������������һ��λ��L~R�Ͳ������ʱֹͣ����ʱ�Ե�ǰL��ͷ
�ĳ��Ȳ�����R-L+1�������鶼��ꣻȻ��L����һ��λ�ã�ͬʱ����һ�����ֵ����Сֵ���½ṹ��L-1�±�����ˣ���
������R��R�������һ��λ��L~R�Ͳ������ֹͣ��ÿ����Rһ��Ҳ�������Сֵ���½ṹ��������ֱ��L��������βԪ��
Ϊֹ����ÿ��Rֹͣʱ��R-L+1�������ۼ���������O(N)�Ľ⣬��ΪL��R��ֻ�����ƶ�������ÿ��Rֹͣʱ����L��ͷ�Ĵ��
�Ӵ�������ֱ��ͨ��R-L+1���㣬����ʱ�临�ӶȾ��ǽ����������һ�鼴O(N)��
*/

/**< �õ������������ֵ��Сֵ���� */
#include<iostream>
#include<deque>
#include<vector>
using namespace std;

int getNum_ok_subArr(vector<int> arr, int num)
{
    deque<int> max_num;//�洢���ֵ
    deque<int> min_num;//�洢��Сֵ
    max_num.push_back(0);
    min_num.push_back(0);
    int R = 0;
    int L = 0;
    int res = 0;
    while(L < arr.size())
    {
        while(R < arr.size()-1)
        {
            //�������ֵ
            while(!max_num.empty() && arr[max_num.front()] < arr[R+1])
                max_num.pop_back();
            max_num.push_back(R+1);
            //������Сֵ
            while(!min_num.empty() && arr[min_num.front()] > arr[R+1])
                min_num.pop_back();
            min_num.push_back(R+1);

            if(max_num.front() - min_num.front() > num)
                break;
            R++;
        }

        res += (R - L + 1);
        if(max_num.front() == L)   //��ʱ��ߵ���
            max_num.pop_front();
        if(min_num.front() == L)
            min_num.pop_front();

        L++;
    }
    return res;
}
void Test()
{
    vector<int> v;


    v = {1, 2,3,5};
    cout<<getNum_ok_subArr(v,3);//10
}

int main()
{
    Test();
    return 0;
}

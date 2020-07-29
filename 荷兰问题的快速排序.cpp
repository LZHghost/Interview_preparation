/** \brief ���ں�����������ʵ�ֵĿ���
 *
 * \param �Ƚ�һ�¾��������ʹ�ú�����������Ľ���ľ�������
 *        ���ѷ��֣�����һ��partition��ȥ��һ�����ϵ�Ԫ�أ�����arr[endIndex]�����򣩣�
          ��ǰ��ÿ��partitionֻ��ȥ��һ��Ԫ�أ������ȥ���൱�ڰ��ţ����򣩺��˶�ӦԪ�ص�λ�á�
          ��˺��߱Ⱦ���������ţ������Ż�����ֻ�ǳ���ʱ���ڵ��Ż���ʵ���ϵ�Ч�ʻ���Ҫ������״��
          ���������ΪO(nlogn)��������ΪO(n^2)����
 * \param
 *
 */
#include<iostream>
#include<vector>
using namespace std;

class sort_imporve_classical_quick{
public:
    vector<int> imporve_partition(vector<int>&arr,int pos_begin,int pos_end);
    void imporve_sortquick(vector<int>&arr,int pos_begin,int pos_end);
};

vector<int> sort_imporve_classical_quick::imporve_partition(vector<int>& arr,int pos_begin,int pos_end)
{
    vector<int> range(2,0);
    int small = pos_begin-1 , great = pos_end+1;
    int i = pos_begin;
    while(i <= pos_end -1 )
    {
        if(arr[i]<arr[pos_end])
        {
            std::swap(arr[++small],arr[i++]);
        }

        else if (arr[i]>arr[pos_end]) std::swap(arr[--great],arr[i]);
        else i++;
    }
    for(auto item : arr) cout<<" " << item <<" ";
            cout<<endl;
    cout<<endl<< small << " "<< great<<endl;
    range[0] = small;
    range[1] = great;
    return range;
}
void sort_imporve_classical_quick::imporve_sortquick(vector<int>&arr,int pos_begin,int pos_end)
{
   // std::cout<<std::endl<<"--������������Ľ����ľ������-"<<std::endl;
    if(pos_begin > pos_end) return ;
    vector<int>range = imporve_partition(arr,pos_begin,pos_end);
    imporve_sortquick(arr,pos_begin,range[0]);
    imporve_sortquick(arr,range[1],pos_end);
}

int main()
{
    sort_imporve_classical_quick obj;
    vector<int> nums = {5,7,6,3,2,1,11,4};
    obj.imporve_sortquick(nums,0,nums.size()-1);
    for(int i = 0; i < nums.size() ; i++)
        cout<<" "<<nums[i] ;
    return 0;
}

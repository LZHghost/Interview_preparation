//</code
/** \brief �鲢���������
 *
 * \param int merge(int arr[],int helpArr[], int startIndex, int midIndex,int endIndex);
 * \param int mergeSort(int arr[],int helpArr[], int startIndex, int endIndex);
 * \return
 *
 */
#include<iostream>
#include<vector>
using namespace std;
class sort_merger{
public:
    void merge(vector<int>& arr,vector<int>& helpArr, int startIndex, int midIndex,int endIndex);
    void mergeSort(vector<int>& arr,vector<int>& helpArr, int startIndex, int endIndex);

};
void sort_merger::merge(vector<int>& arr,vector<int>& helpArr, int startIndex, int midIndex,int endIndex)
{

    int L = startIndex, R = midIndex + 1, i = startIndex;
    int res=0;
    while (L <= midIndex && R <= endIndex ) { //ֻҪû��ָ��ûԽ�����αȽ�
        res += arr[L] < arr[R] ? arr[L] * (endIndex - R + 1) : 0;
        helpArr[i++] = arr[L] < arr[R] ? arr[L++] : arr[R++];
    }
    while (L != midIndex + 1) {
        helpArr[i++] = arr[L++];
    }
    while (R != endIndex + 1) {
        helpArr[i++] = arr[R++];
    }
    for (i = startIndex; i <= endIndex; i++) {
        arr[i] = helpArr[i];
    }

}
void sort_merger::mergeSort(vector<int>& arr,vector<int>& helpArr, int startIndex, int endIndex)
{
    int midIndex;
    if (startIndex < endIndex) {  //��������ֻ��һ��Ԫ��ʱ�����ٽ��д��ӹ���
        midIndex = startIndex + ((endIndex - startIndex) >> 1);       //�ҵ��м��λ��
               mergeSort(arr, helpArr, startIndex, midIndex) ;        //����벿������
               mergeSort(arr, helpArr, midIndex + 1, endIndex) ;     //���Ұ벿������
               merge(arr, helpArr, startIndex, midIndex, endIndex);  //ʹ��������
    }

}
int main()
{
    sort_merger obj;
    vector<int> nums = {5,7,6,3,2,1,11,13,4};
    vector<int> helpnums(nums.size()); //Ҫ��ʼ��
    obj.mergeSort(nums,helpnums,0,nums.size()-1);
    for(int i = 0; i < nums.size() ; i++)
        cout<<" "<<nums[i] ;
    return 0;
}

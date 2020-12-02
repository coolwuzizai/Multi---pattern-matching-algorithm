#include<vector>
#include<iostream>
#include<algorithm>
#include<ctime>
using namespace std;
//定义稀有字母数组
//char Rarenum[26] = { };
//int m_g[26] = { 788,156,268,389,1268,256,187,573,707,10,60,394,244,706,776,186,9,594,634,978,280,102,214,16,202,6 };
double m_g[26] = {0.0788,0.0156,0.0268,0.0389,0.1268,0.0256,0.0187,0.0573,0.0707,0.0010,0.0060,0.0394,0.0244,0.0706,0.0776,0.0186,0.0009,0.0594,0.0634,0.0978,0.0280,0.0102,0.0214,0.0016,0.0202,0.0006};//26个字母的概率
typedef struct rect {
	char m;//字符
	int num;//字符出现次数
	double g=0;//概率
	vector<int> w;//出现的位置信息
};
//预处理模式串p
vector <rect> vec;
//输入模式串p，和p的长度，返回结构体rect
rect Pre_RBM(char*p,int p_length) 
{
	//char q[p_length][p_length] = { 0 };
	
	rect rect2;
	rect2.m = p[0];
	rect2.g = m_g[int(p[0]) - 97];
	rect2.num = 1;
	rect2.w.push_back(0);
	vec.push_back(rect2);
	for (int i = 1; i < p_length; i++) 
	{
		rect rect1;
		int result = 0;
		for (int j = 0; j < vec.size(); j++)
		{
			if (p[i] == vec[j].m)
			{



				vec[j].num += 1;
				vec[j].g *= m_g[p[i] - 97];
				vec[j].w.push_back(i);
				result = 1;
		

			}
		}
			if(result==0){
				rect1.m = p[i];
				rect1.g= m_g[p[i]- 97];
				
				
				rect1.num = 1;
				
				rect1.w.push_back(i);
				vec.push_back(rect1);
				
				
			}
		}
	
	int tmp = 0;
	double g_ =vec[0].g;
	for (int i = 0; i < vec.size(); i++) 
	{
		//计算概率最小的
	
		//输出当前值
		//cout << vec[i].m << endl;
		//cout << vec[i].g << endl;
	
		
		
		
		
		 if (g_ > vec[i].g) 
		 {
			 g_= vec[i].g;
			 tmp = i;
		 }

	}
	//printf("%c\n", vec[tmp].m);
	//cout<< vec[tmp].m<<endl;
	//cout << vec[tmp].g << endl;
	//cout << temp << endl;
	//cout << vec[tmp].w.size() << endl;
	
	return vec[tmp];
	//vector<int>().swap(nums); //或者nums.swap(vector<int> ())
}
int main()
{
	clock_t start, end;
	start = clock();
	char *test = "xsddajzj";
	int m = 8;
	rect result=Pre_RBM(test, m);
	
	char *T = "abcdabcdxxsddajsdkzddxsddamzkaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	int n = 85;
	//来查找模式串中概率最小的字符
	vector<int> Tp;
	int j = 0;//概率最小字符个数
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			if (T[k] == result.m) 
			{
				j++;
			}
			else {

			}

		}
		
	}
	end = clock();
	double endtime = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "Total time:" << endtime << endl;		//s为单位
	cout << "Total time:" << endtime * 1000 << "ms" << endl;	//ms为单位
	cout << result.m << endl;
	cout << result.g << endl;
	cout << result.num << endl;
	for (std::vector<int>::iterator m = result.w.begin(); m != result.w.end(); m++)    //用迭代器的方式输出容器对象的值
	{
		cout << *m << endl;

	}
	vector<rect>().swap(vec);

	system("pause");
}
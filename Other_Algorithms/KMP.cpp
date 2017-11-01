/* KMP algorithm */

#include <vector>
#include <iostream>
#include <string>

using namespace std;

int isSubstr(string, string);
int main(int argc, char const *argv[])
{
	/* code */
	string h = "dasffasdjafnm";
	string n = "asd";
	cout << isSubstr(h, n) << endl;
	return 0;
}

void calculateNextArray(string, vector<int>&);
int isSubstr(string haystack, string needle){
	int i = 0;
	int j = 0;
	int hlen = haystack.length();
	int nlen = needle.length();
	vector<int> next(nlen, -1);
	calculateNextArray(needle, next);

	if(hlen < nlen) return -1;
	while(i < hlen && j < nlen){
		if(j == -1 || haystack[i] == needle[j]){
			i++;
			j++;
		}else{
			j = next[j];
		}
	}

	if(j == nlen) return i-j;
	else return -1;
}

void calculateNextArray(string str, vector<int>& next){
	// i is postfix, j is prefix
	int i = 0;
	int j = -1;
	int len = next.size();
	while(i < len - 1){
		if(j == -1 || str[i] == str[j]){
			++i;
			++j;
			if(str[i] != str[j]){
				next[i] = j;
			}else{
				next[j] = next[j];
			}
		}else{
			j = next[j];
		}
	}
}
#include <iostream>
using namespace std;
#include <fstream>
#include <vector>
#include <set>
int a, b, c;
set<int> L;
void da(vector<int>& div){
	int k = 1;
	div.push_back(k);
	while (k != a){
		if (a % k == 0 && k >= b){
			div.push_back(k);
		}
		k++;
	}
	div.push_back(a);
}
vector<int> la(vector<int> s){
	vector<int> l;
	for (int i = 0; i < s.size(); i++){
		if (s[i] <= c){
			l.push_back(s[i]);
		}
	}	
	return l;
}

void find_all_div_between(vector<int>& div){
	if (b == 1) b = 2;
		for (int i = b; i <= c; i++){
			if (a % i == 0) div.push_back(i);
		}
}

bool isinL(int x){
	if (L.find(x) != L.end()) return true;
	return false;
}

int min(vector<int>& div, int * d, int num){
	int minimum = d[0];
	for (int i = 0; i <= num; i++){
		if ((div[num + 1] % div[i] == 0) && isinL(div[num + 1] / div[i]))
		if (d[i] < minimum) minimum = d[i];
	}
	return minimum;
}


int main(){
	ifstream input("input.txt");
	ofstream output("output.txt");
	vector<int> div;

	int  *d, n;
	input >> a >> b >> c;
	if (a < b || c < b || a < 2 || a > 1000000000 || c > 1000000 || b < 1 || (b == 1 && c == 1)){
		output << -1;
		input.close();
		output.close();
		return 0;
	}
	if (b <= a && c >= a){
		output << 1;
		input.close();
		output.close();
		return 0;
	}
	da(div);
	n = div.size();
	d = new int[n]();
	for (int i = 0; div[i] <= c; i++){
		if (div[i] >= b){
			L.insert(div[i]);
			d[i] = 1;
		}
	}
	
	
	for (int j = 0; j < n; j++){
		d[j] = min(div, d, j - 1) + 1 ;
	}
	/*
	find_all_div_between(div, a, b, c);
	int last = div.size() - 1;
	while (a != 1 && last >= 0){
		if (a % div[last] == 0) {
			a /= div[last];
			count++;
		}
		else last -= 1;
	}

	if (last < 0) output << -1;
	else output << count;
	*/

	output << d[n - 1];

	input.close();
	output.close();
	return 0;
}
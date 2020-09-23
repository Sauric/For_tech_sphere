
#include <iostream>
#include <fstream>
#include <vector> 
#include <string>
#include <sstream>

using namespace std;
string toLower_s(const string s){
    string result;
    for (int i = 0; i < s.size(); i ++){
        result += tolower(s[i]);    
    }
    return result;
}
string toUpper_s(const string s){
    string result;
    for (int i = 0; i < s.size(); i ++){
        result += toupper(s[i]);    
    }
    return result;
}
string change_s (const string s, const char a, const char b){
    string result;
    for (int i = 0; i < s.size(); i ++){
        if (s[i] == a)
            result += b;
        else
            result += s[i];     
    }
    return result;
}
vector<string> separetor (const string s){
    vector<string> res;
    int i = 0;
    string temp = "";
    while (true){
        if ((s[i] == ' ' && s[i + 1] == ' ' && s[i + 2] == ' ' && s[i + 3] == ' ')|| i >= s.size()){
            res.push_back(temp);
            temp = "";
            // cout << i << endl;.
            if (i >= s.size())
                break;
            i += 3;
            continue;
        }
        temp += s[i];
        // cout << i << "= i;s[i] =" << s[i] << s.size() << endl;
        i++;
    }
        

    return res;
}
void printer(vector<vector<string>> ff){
    for(int i = 0; i < ff.size(); i++){
        for(int j = 0; j < ff[i].size(); j++)
            cout << ff[i][j] << " ";
        cout << endl;
    }
}   

int main(){
    ifstream file ("file.txt");
    string s, s2;
    vector<string> res;
    vector<vector<string>> whole_file;
    while (getline(file, s)){
        res.clear(); 
        res = separetor(s);
      
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << "    ";
        cout<< endl;
    }
    int N;
    while (getline(cin,s)){
        stringstream ss (s);
        ss >> N; ss >> s;
        cout <<"\nN = "<< N <<" s[1] = "<< s[1] << endl;
        if (s[1] == 'u'){
            for (int i = 0; i < whole_file.size(); i++)
                whole_file[i][N] = toLower_s(whole_file[i][N]);
            printer(whole_file);
        }
    }

    return 1;
}

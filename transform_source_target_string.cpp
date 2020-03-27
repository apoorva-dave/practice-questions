#import <iostream>
#import <string>
#import <vector>

using namespace std;

vector<string> diffBetweenTwoStrings(const string& source, const string& target)
{
  int m = source.length();
  int n = target.length();
  vector <string> res;
	int dp[m+1][n+1];
  for(int i=0; i<=n; i++)
    dp[0][i] = i;
  for(int i=0; i<=m; i++)
    dp[i][0] = i;
  for(int i=1; i<=m; i++)
  {
    for(int j=1; j<=n; j++)
    {
      if(source[i-1] == target[j-1])
      {
        dp[i][j] = dp[i-1][j-1];
        //res.push_back(string(1, source[i-1]));
      }
      else
      {
        dp[i][j] = 1 + min(dp[i][j-1],dp[i-1][j]);
      }
    }
  }
  
  
  cout<<dp[m][n];
  
  int i=m, j=n;
  while(i>0 && j>0)
  {
    if(source[i-1] == target[j-1])
    {
      res.push_back(string(1,source[i-1]));
      i--;j--;
    }
    else 
    {
      if(dp[i-1][j] < dp[i][j-1])
      {
        res.push_back("-"+string(1,source[i-1]));
        i--; 
      }
      else
      {
          res.push_back("+"+string(1,target[j-1]));
        j--;
      } 
    }
  }
  reverse(res.begin(), res.end());
  return res;
}

int main() 
{
	return 0;
}

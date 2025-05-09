using namespace std;
long long solve(string &s)
{
    s = " " + s;
    long long prefixSum[s.length()] = {0}, sum = 0;
    int cnt[3] = {0};
    for (int i = 1; i < s.length(); ++i)
    {
        int digit = s[i] - '0';
        sum += digit;
        prefixSum[i] = prefixSum[i - 1] + digit;
        cnt[prefixSum[i] % 3]++;
    }
    long long res = 0;
    for (int i = 1; i < s.length(); ++i)
    {
        res += cnt[(sum + prefixSum[i - 1]) % 3];
        cnt[prefixSum[i] % 3]--;
    }
    if (sum % 3 != 0)
    {
        res--;
    }
    return res;
}
int main()
{
    freopen("CAU3.INP", "r", stdin);
    freopen("CAU3.OUT", "w", stdout);
    ios::syncwithstdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    cout << solve(s);
    return 0;
}
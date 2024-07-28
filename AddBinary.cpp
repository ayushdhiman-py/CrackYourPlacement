class Solution {
public:
    string addBinary(string a, string b) {
        int c = 0;
        string res = "";

        int i = a.size() - 1;
        int j = b.size() - 1;

        while (i >= 0 || j >= 0) {
            int sum = c;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            res += (sum % 2) + '0';
            c = sum / 2;
        }
        if (c != 0) res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};

// gives tle
int countSetBits(int n) {
    //Write your code here abhinay bir
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int temp = i;
        while (temp) {
            // cout<<"i is:"<<i<<endl;
            if (temp & 1)ans += 1;
            temp = temp >> 1;
        }
        // cout<<"ans is:"<<ans<<endl;
    } return ans;
}

// learnt from pepcoding
int code(int n) {
    if (n == 0)return 0; // for code(n=2) it is : 1*(2^(1-1)) + (2-2+1) + code(2-2);
    if (n == 1)return 1;
    // find 2^n which is less than equal to 2^n, so now wht will u do..............
    // go till msb nd find leftmost 1
    int temp = n;
    int ind = 0;
    int l_ind_1;
    while (temp) {
        if (temp & 1)l_ind_1 = ind;
        ind += 1; temp = temp >> 1;
    }
    int aux = 1 << (l_ind_1);
    return  ( (l_ind_1) * (1 << (l_ind_1 - 1))  + ( n - aux + 1) + code(n - aux) );

}

int countSetBits(int n) {
    //Write your code here abhinay bir
    int ans = 0;
    return code(n);
}
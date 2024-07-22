class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        
        sort(a.begin(),a.end());
		
		long long start = 0,end =0;
		long long mind = LONG_LONG_MAX;
		
		for(long long i=0;i+m-1<n;i++)
		{
			long long diff = a[i+m-1] - a[i];
			if(mind>diff)
			{
				mind = diff;
				start = i;
				end = i+m-1;
			}
		}
		return a[end]-a[start];
            
    }
};
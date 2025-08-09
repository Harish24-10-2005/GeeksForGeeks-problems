class Solution {
  private: 
    int cnt = 0;
    void merge(int l,int m,int h,vector<int>&a)
    {
        
        // for(int j=m+1;j<=h;j++){
        //     for(int i=m;i>=l;i--){
        //         if(a[i]<=a[j]){
        //             break;
        //         }
        //         cnt++;
        //     }
        // }
        int i = l;
        int j = m+1;
        vector<int>temp;
        while(i<=m && j<=h)
        {
            if(a[i] <= a[j])
            {
                temp.push_back(a[i]);
                i++;
            }
            else 
            {
                cnt+=(m-i + 1);
                temp.push_back(a[j]);
                j++;
            }
        }
        while(i<=m)
        {
            temp.push_back(a[i]);
            i++;
        }
        while(j<=h)
        {
            temp.push_back(a[j]);
            j++;
        }
        for(int i=l;i<=h;i++)
        {
            a[i] = temp[i-l];
            // cout<<a[l]
        }
    }
    void ms(int l,int h,vector<int>&a)
    {
        if(l>=h) return;
        int m = l+((h-l)/2);
        // cout<<"l ->"<<l<<" m->"<<m<<" h->"<<h<<endl;
        ms(l,m,a);
        ms(m+1,h,a);
        merge(l,m,h,a);
    }
  public:
    int inversionCount(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        ms(0,n-1,arr);
        // for(int i=0;i<arr.size();i++)cout<< arr[i]<<" ";
        return cnt;
    }
};
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, n=nums.size(), h=n-1,  mid=l+(h-l)/2, in=0;
        while(l<=h)
        {
            mid=l+(h-l)/2;
            int x=(mid-1+n)%n, y=(mid+1)%n;
            if(nums[mid]<nums[x] && nums[mid]<nums[y])
            {
                in=mid;
                break;
            }
            else if(nums[mid]>=nums[n-1])
            {
                l=mid+1;
            }
            else
            {
                h=mid-1;
            }
        }
        if(target>nums[n-1])
        {
            l=0, h=in-1;
        }
        else
        {
            l=in, h=n-1;
        }
        while(l<=h)
        {
            mid=l+(h-l)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                l=mid+1;
            else
                h=mid-1;
        }
        return -1;
        
    }
};

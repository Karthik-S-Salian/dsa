impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let mut sum =nums[0];
        let mut maxsum=sum;

        for i in 1..nums.len(){
            sum = sum.max(0)+nums[i];
            maxsum = maxsum.max(sum);
        }
        maxsum
    }
}

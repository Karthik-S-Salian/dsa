impl Solution {
    pub fn product_except_self(nums: Vec<i32>) -> Vec<i32> {
        let mut prvs= 1;
        let len =nums.len();
        let mut products= vec![0;len];
        let mut i =0;

        while i<len {
            products[i] = prvs;
            prvs*=nums[i];
            i+=1;
        }

        prvs=1;

        while i>0 {
            i-=1;
            products[i] *= prvs;
            prvs*=nums[i];
        }

        products

    }
}
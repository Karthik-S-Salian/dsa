use std::collections::HashSet;

impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        let mut uniques: HashSet<i32> = HashSet::with_capacity(nums.len());

        //nums.iter().any(|&num| !uniques.insert(num))

       for num in nums{
           if !uniques.insert(num){
               return true;
           }
       }
        false
    }
}

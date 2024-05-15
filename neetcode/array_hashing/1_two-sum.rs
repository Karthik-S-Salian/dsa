use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut prvs:HashMap<i32, usize> = HashMap::new();

        for (i, num) in nums.iter().enumerate() {
            match prvs.get(num){
                Some(j)=>{
                    return vec![i as i32,*j as i32];
                },
                None=>{
                    prvs.insert(target-num,i);
                }
            }
        }

        vec![0,0]
    }
}
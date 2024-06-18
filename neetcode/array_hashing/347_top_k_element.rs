use std::collections::HashMap;
impl Solution {


pub fn top_k_frequent(nums: Vec<i32>, k: i32) -> Vec<i32> {
    let mut counts = HashMap::new();
    let mut freq: Vec<Vec<i32>> = vec![Vec::new(); nums.len()];

    for num in nums {
        counts.insert(num, counts.get(&num).unwrap_or(&0) + 1);
    }

    for (&key, &count) in &counts {
        freq[count-1].push(key);
    }

    let mut result = Vec::with_capacity(k as usize);
    for list in freq.iter().rev() {
        for &item in list {
            result.push(item);
            if (result.len() == k as usize) {
                return result;
            }
        }
    }

    unreachable!();
}

}

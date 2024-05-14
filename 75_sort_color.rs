impl Solution {
    pub fn sort_colors(nums: &mut Vec<i32>) {
        let mut counts = vec![0; 3];

        nums.iter().for_each(|&num| {
            counts[num as usize] += 1;
        });

        let mut k = 0;
        for (color, &count) in counts.iter().enumerate() {
            for _ in 0..count {
                nums[k] = color as i32;
                k += 1;
            }
        }
    }
}
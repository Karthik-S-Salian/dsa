impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        if s.len() != t.len() {
            return false;
        }

        let mut counts: Vec<i32> = vec![0; 26];

        s.into_bytes().iter().for_each(|&x| {
            counts[(x - b'a') as usize] += 1;
        });

        !t.into_bytes().iter().any(|&x| {
            let index = (x - b'a') as usize;
            counts[index] -= 1;
            counts[index] < 0
        })
    }
}

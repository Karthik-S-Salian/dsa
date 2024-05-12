impl Solution {
    pub fn count_and_say(n: i32) -> String {
        if n == 1 {
            return String::from("1");
        }

        let binding = Self::count_and_say(n - 1);
        let chunk = binding.as_bytes();
        let mut result = String::new();

        let mut prvs = chunk[0];
        let mut count = 1;

        for i in 1..chunk.len() {
            if prvs == chunk[i] {
                count += 1;
            } else {
                result.push_str(count.to_string().as_str());
                result.push(prvs as char);
                count = 1;
            }
            prvs = chunk[i];
        }

        result.push_str(count.to_string().as_str());
        result.push(prvs as char);
        return result;
    }
}

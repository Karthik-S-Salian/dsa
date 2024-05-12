impl Solution {
    pub fn asteroid_collision2(state: Vec<i32>) -> Vec<i32> {
        let mut stack: Vec<i32> = Vec::with_capacity(state.len());

        let mut i = 0;

        while i < state.len() {
            let current = state[i];
            match stack.pop() {
                None => {
                    stack.push(current);
                    i += 1;
                }
                Some(val) => {
                    if current < 0 && val>0 {
                        if current.abs() < val.abs() {
                            stack.push(val);
                            i += 1;
                        } else if current.abs() == val.abs() {
                            i += 1;
                        }
                    } else {
                        stack.push(val);
                        stack.push(current);
                        i += 1;
                    }
                }
            }
        }

        return stack;
    }


    pub fn asteroid_collision(state: Vec<i32>) -> Vec<i32> {
        let mut stack: Vec<i32> = Vec::with_capacity(state.len());
        let mut i = 0;

        while i < state.len() {
            let current = state[i];

            if stack.is_empty(){
                stack.push(current);
                i += 1;
            }else{
                let val = stack[stack.len()-1];
                if current < 0 && val>0 {
                    if current.abs() < val.abs() {
                        i += 1;
                    } else if current.abs() == val.abs() {
                        stack.pop();
                        i += 1;
                    }else{
                        stack.pop();
                    }
                } else {
                    stack.push(current);
                    i += 1;
                }
            }
        }

        return stack;
    }
}
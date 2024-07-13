impl Solution {
    pub fn daily_temperatures(temperatures: Vec<i32>) -> Vec<i32> {
        let mut sol: Vec<i32>= vec![0;temperatures.len()];
        
        let mut j:usize;

        for i in (0..temperatures.len()-1).rev(){
            if temperatures[i]<temperatures[i+1]{
                sol[i] = 1;
            }else{
                j = sol[i+1] as usize;
                while temperatures[i+j]<=temperatures[i]{
                    if sol[i+j]==0 {
                        j=0;
                        break;
                    }
                    j +=sol[i+j] as usize;
                }
                sol[i] = j as i32;
            }
        }
        sol
    }
}
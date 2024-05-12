fn asteroid_collision(asteroids: Vec<i32>) -> Vec<i32> {
    let mut stack:Vec<i32>= Vec::with_capacity(asteroids.len());

    let i=1;
    stack.push(asteroids[0])
    while i<astroids.len(){
        let current = asteroids[i];
        let top = stack.pop();

        if current^top<0 {
            if current.abs()>top.abs(){
                stack.push(current);
            }
            else if current.abs()<top.abs(){
                stack.push(top);
            }
        }else{
            stack.push(current);
            i+=1;
        }
    }
}


fn main(){
    
}
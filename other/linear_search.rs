

fn linear_search(array: &[i32],key:i32){
    for i in 0..array.len(){
        if key == array[i]{
            println!("{} fond at position {}",key,i+1);
            return;
        }
    }
    println!("{} is not found in the array",key);
}


fn main(){
    let array:[i32;5]=[5,4,2,3,1];
    linear_search(&array,4);
}
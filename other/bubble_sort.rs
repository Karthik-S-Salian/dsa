
fn bubble_sort(array:&mut[i32]){
    
    for i in 0..array.len()-1{
        for j in 0..array.len()-i-1{
            if array[j+1] < array[j]{
                let temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

fn main() {
    let mut array: [i32; 5] = [5,4,3,2,1];
    bubble_sort(&mut array);
    println!("sorted = {:?}",array);
    
}
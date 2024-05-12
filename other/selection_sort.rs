
fn sort(array: &mut[i32]){
    for i in 0..array.len(){
        let mut min = array[i];
        let mut pos = i;
        for j in i+1..array.len(){
            if array[j]<min{
                min = array[j];
                pos=j;
            }
        }
        array[pos] = array[i];
        array[i] = min;
    }
}


fn main(){
    let mut array:[i32;5]=[5,4,2,3,1];
    sort(&mut array);
    println!("{:?}",array);
}

fn clockwise(array: &mut[i32],shift:usize){
    let size = array.len();
    if size==0 {return};
    for i in 0..shift{
        let mut prvs = array[(2*size-shift+i)%size];
        let mut j = i;
        while j < size {
            let temp = array[j];
            array[j] = prvs;
            prvs = temp;
            j+=shift;
        }
    }
}


fn main(){
    let mut array:[i32;5]=[5,4,2,3,1];
    clockwise(&mut array,3);
    println!("{:?}",array);
}
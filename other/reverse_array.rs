fn main(){
    const SIZE :usize= 5;
    let mut arr:[i32;SIZE] = [1,2,3,4,5];

    let mid= SIZE/2;

    for i in 0..mid{
        let temp = arr[i];
        arr[i] = arr[SIZE-i-1];
        arr[SIZE-i-1] = temp;
    }

    println!("{:?}",arr);
}
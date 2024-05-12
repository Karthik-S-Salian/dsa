

fn main(){
    let len:i16 = 5;
    let mut prvs = 0;
    for i in 1..=len{
        for j in i..=len{
            prvs = prvs*10+j;
            println!("{}",prvs);
        }
        prvs=0;
    }
}
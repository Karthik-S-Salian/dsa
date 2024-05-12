
fn binary_search(array:&[i32],key:i32)-> Option<usize>{
    let mut beg:usize = 0;
    let mut end:usize = array.len();
    
    while beg<=end {
    
        let mid:usize = beg+(end-beg)/2;
        
        if array[mid]==key {
            return Some(mid);
        }else if array[mid]>key{
            end = mid-1;
        }else{
            beg = mid+1;
        }
    }
    return None;
}

fn main() {
    let array: [i32; 5] = [1, 2, 3, 4, 5];
    let result = binary_search(&array,3);
    match result {
            None => {
                println!("key doesnot exists");
            },
            Some(i) => {
                println!("key exists at {}",i+1);
            },
        }
}
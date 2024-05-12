fn ceaser_chiper(text: &str,shift:u8)->String{
    let mut result = String::new();
    for c in text.as_bytes() {
            let base:u8 = if c.is_ascii_uppercase(){b'A'} else {b'a'};
            let offset:u8 = *c as u8 - base;
            let shift_char = (offset+shift)%26 + base;
            result.push(shift_char as char);
    }

    return result;
}

fn main(){
    let s1: &str = "xyz";
    ceaser_chiper(s1,3);
    println!("{}",ceaser_chiper(s1,3))
}
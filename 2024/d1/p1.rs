use std;
use std::io;
use std::result::Result::{Ok};

fn main() -> io::Result<()>{
    let mut buffer = String::new();
    let mut left : Vec<i32> = vec![];
    let mut right : Vec<i32> = vec![];

    loop{
        let result = io::stdin().read_line(&mut buffer)?;
        if result == 0{
            break;
        }
        let nums: Vec<i32> = buffer
            .split_whitespace()
            .map(|s| s.parse().expect("invalid"))
            .collect();
        
        buffer.clear();
        left.push(nums[0]);
        right.push(nums[1]);   
    }
    left.sort();
    right.sort();

    let mut r:i32 = 0;

    let mut i = 0;
    while i < left.len(){
        r += (left[i] - right[i]).abs();
        i+=1;
    }
    println!("{}", r);
    Ok(())
}
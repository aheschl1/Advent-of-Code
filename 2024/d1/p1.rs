use std;
use std::io;
use std::result::Result::{Ok};
use std::io::BufRead;

fn main() -> io::Result<()>{
    let mut left : Vec<i32> = vec![];
    let mut right : Vec<i32> = vec![];
    let lock = io::stdin().lock();

    for line in lock.lines(){
        let line = line?;
        let nums: Vec<i32> = line
            .split_whitespace()
            .map(|s| s.parse().expect("invalid"))
            .collect();

        if let [a,b] = nums[..]{
            left.push(a);
            right.push(b);  
        }
    }
    left.sort_unstable();
    right.sort_unstable();

    let r:i32 = left
        .iter()
        .zip(&right)
        .map(|(a,b)| (a-b).abs())
        .sum();

    println!("{}", r);
    Ok(())
}
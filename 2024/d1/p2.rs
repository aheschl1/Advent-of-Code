use std;
use std::io;
use std::io::BufRead;
use std::result::Result::{Ok};
use std::collections::HashMap;

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
        left.push(nums[0]);
        right.push(nums[1]);   
    }

    let mut maps = HashMap::new();
    for &elem in &right{
        *maps.entry(elem).or_insert(0) += 1;
    }

    let r:i32 = left
        .iter()
        .map(|&target| target*maps.get(&target).unwrap_or(&0))
        .sum();

    println!("{}", r);
    Ok(())
}
use std;
use std::io;
use std::io::BufRead;

fn check(line: & String) -> i32{
    let nums: Vec<i32> = line
        .trim()
        .split_whitespace()
        .map(|c| c.parse().expect("error"))
        .collect();
    let increasing = nums[0] < nums[1];
    let mut result = true;
    for i in 0..nums.len()-1{
        result = result && match nums[i+1] - nums[i]{
            1|2|3 => increasing,
            -1|-2|-3 => !increasing,
            _ => false
        };
    }

    if result {1} else {0}
}

fn main() -> io::Result<()>{
    let lock = io::stdin().lock();
    let mut result:i32 = 0;
    for line in lock.lines(){
        let line = line.expect("dw");
        result += check(&line);
    }
    println!("{}", result);
    Ok(())
}
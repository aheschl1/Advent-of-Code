use std;
use std::io;
use std::io::BufRead;

/**
 * A bit messy but it works
 * n
 */
fn check(line: & String) -> i32{
    let nums: Vec<i32> = line
        .trim()
        .split_whitespace()
        .map(|c| c.parse().expect("error"))
        .collect();

    let mut result = true;
    for increasing in [true, false]{
        result = true;
        let mut tolerance = true;
        let mut i = 0;
        while i < nums.len()-1{
            let mut inner = match nums[i+1] - nums[i]{
                1|2|3 => increasing,
                -1|-2|-3 => !increasing,
                _ => false
            };
            if !inner && tolerance {
                // what if i didn't exist?
                tolerance = false;
                if i == nums.len() - 2{
                    inner = true;
                }else{
                    if i == 0{
                        // make sure this guys isnt the issue either
                        inner = match nums[i+2] - nums[i+1]{
                            1|2|3 => increasing,
                            -1|-2|-3 => !increasing,
                            _ => false
                        };
                    }
                    inner = inner | match nums[i+2] - nums[i]{
                        1|2|3 => increasing,
                        -1|-2|-3 => !increasing,
                        _ => false
                    };
                    i+=1;
                }
            }
            result = result && inner;
            i += 1;
        }
        if result {break;}
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
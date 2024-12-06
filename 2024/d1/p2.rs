use std;
use std::io;
use std::result::Result::{Ok};
use std::collections::HashMap;

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

    let mut r:i32 = 0;
    let mut i: usize = 0;
    let mut maps = HashMap::new();
    while i < left.len(){
        let target:i32 = left[i];
        if maps.contains_key(&target){
            match maps.get(&target){
                Some(v) => r+=target*v,
                None => r+=0
            };
            continue;
        }
        let mut c = 0;
        for elem in &right{
            if *elem == target{
                c+=1;
            }
        }
        maps.insert(target, c);
        r += target * c;
        i+=1;
    }
    println!("{}", r);
    Ok(())
}
use std;
use std::fs;

fn main() {
    let mut content = fs::read_to_string("/home/andrewheschl/Documents/Advent of Code/2024/d3/in.txt")
        .expect("File IO error");

    let mut mul_idx = content.find("mul");
    let mut dont_idx = content.find("don't()").unwrap_or(content.len());
    let mut answer = 0;
    while mul_idx.unwrap_or(content.len()) < content.len(){
        if dont_idx < mul_idx.unwrap_or(content.len()){
            content = content[dont_idx+7..].to_string();
            mul_idx = content.find("mul");
            let do_idx = content.find("do()");
            if do_idx.unwrap_or(content.len()) == content.len(){
                // cant start again
                break;
            }
            // go here
            content = content[do_idx.unwrap_or(content.len())+4..].to_string();
            dont_idx = content.find("don't()").unwrap_or(content.len());
            mul_idx = content.find("mul");
            continue;
        }
        let start_idx = mul_idx.unwrap_or(content.len())+3;
        let mut end_idx = start_idx+3;
        let mut stage = 0;
        let mut buffer = String::new();
        let mut first_num = -1;
        let mut second_num = -1;
        for (i, &character) in content[start_idx..].as_bytes().iter().enumerate(){
            let mut breakout = false;
            let ok:bool = match stage{
                0 => {
                    // expect the (
                    if character != '(' as u8 {false} else{stage+=1;true}
                },
                1|2 => {
                    // expect a #
                    if character > '9' as u8 || character < '0' as u8{
                        if (stage == 1 && character == ',' as u8) || (stage == 2 && character == ')' as u8){
                            if stage == 1{
                                first_num = buffer.parse().expect(":(");
                                buffer.clear();
                            }else{
                                second_num = buffer.parse().expect(":(");
                            }
                            stage+=1; 
                            true
                        }else {false}
                    }else{buffer.push(character as char);true}
                },
                _ => {
                    // finished!
                    end_idx = start_idx + i;
                    breakout = true;
                    true
                },
            };
            if breakout{
                // success and done a chunk!
                answer += first_num*second_num;
                break;
            }
            if !ok{
                break;
            }
        }

        content = content[end_idx..].to_string();
        mul_idx = content.find("mul");
        dont_idx = content.find("don't()").unwrap_or(content.len());
    }
    println!("{answer}");
}

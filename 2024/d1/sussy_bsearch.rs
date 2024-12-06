/**
 * Didn't read the question correctly and made bsearch for practice
 */

fn bsearch<T: PartialOrd>(array:&Vec<T>, target:T, left:i32, right:i32)->bool {
    if (left > right ) || (right==array.len()as i32){
        return false
    }
    let mid: usize = (left + (right-left)/2) as usize;
    println!("{}", mid);
    if array[mid] == target{
        return true
    }else if array[mid] > target{
        // left
        return bsearch(array, target, left, mid as i32 -1);
    }else{
        return bsearch(array, target, mid as i32 +1, right);
    }
}
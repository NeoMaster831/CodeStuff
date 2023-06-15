fn read_integers() -> Vec<i64> {
    
    let stdin = std::io::stdin();
    let mut inp = String::new();
    stdin.read_line(&mut inp).unwrap();

    let mut ret: Vec<i64> = vec![];
    for sliced in inp.trim().split(' ').collect::<Vec<&str>>() {
        ret.push(sliced.parse::<i64>().unwrap());
    }
    ret

}

fn main() {
    let inp = read_integers();
    let a = inp[0]; let b = inp[1];
    println!("{}", a + b);
}
fn main() {

    let age = 18;
    let judgement = match age {
        1..=8 => "femboy????",
        9..=16 => "loli's are bad, you pervert.",
        17..=20 => "ok i see, your taste is little suspicious",
        21..=50 => "Congratulations! You are just a normal person!",
        _ => "what",
    };

    println!("{}", judgement);
}
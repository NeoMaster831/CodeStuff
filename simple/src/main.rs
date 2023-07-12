use std::time::{SystemTime, UNIX_EPOCH, Duration};     
use std::collections::HashMap;

fn max(left: i32, right: i32) -> i32 {
    if left > right { return left }
    right
}

fn make_rand(start: u32, end: u32) -> u32 {   
   
    let epoc = SystemTime::now().duration_since(UNIX_EPOCH).unwrap();
    let mut seed = epoc.as_millis() as u32;

    seed ^= seed << 13;
    seed ^= seed >> 17;
    seed ^= seed << 5;
    return seed % (end - start + 1) + start;

}

struct GenshinGacha {
    guaranteed: bool,
    stack: i32,
    four_star_stack: i32,
    got_four_stars: i32,
    got_three_stars: i32,
    spent: i32,
    primogems: i32,
    characters: HashMap<String, i32>,
}

impl GenshinGacha {

    fn purchase_primo(&mut self, how_many: i32) {
        self.spent += how_many;
        self.primogems += match how_many {
            119000 => 6480 + 1600,
            65000 => 3280 + 600,
            37000 => 1980 + 260,
            19000 => 980 + 110,
            5900 => 300 + 30,
            1200 => 60,
            _ => 0
        }
    }

    fn add_primo(&mut self, how_many: i32) {
        self.primogems += how_many;
    }

    fn gacha(&mut self, how_many: i32) {

        if how_many == 0 {
            return ()
        }
        self.primogems -= 160;
        self.four_star_stack += 1;
        self.stack += 1;
        let preresult = make_rand(1, 1000); // 0.6% 확률 계산
        if preresult <= 6 + max(0, (self.stack as i32 - 73) * 60) as u32 {

            self.four_star_stack = 0;
            self.stack = 0;
            
            let realres = make_rand(0, 1);
            if realres <= 0 + self.guaranteed as u32 { // Sangonomiya Kokomi
                
                self.characters.insert(String::from("Sangonomiya Kokomi"), 
                self.characters.get(&String::from("Sangonomiya Kokomi")).unwrap_or(&0) + 1);
                print!("★★★★★ Sangonomiya Kokomi\n");
                
                self.guaranteed = false;

            } else {

                let the_other = ["Tighnari", "Mona", "Jean", "Keqing", "Qiqi", "Diluc", "Dehya"];

                let otherresult = make_rand(0, the_other.len() as u32 - 1);
                self.characters.insert(String::from(the_other[otherresult as usize]), 
                self.characters.get(&String::from(the_other[otherresult as usize])).unwrap_or(&0) + 1);
                print!("★★★★★ {}\n", the_other[otherresult as usize]);

                self.guaranteed = true;
            }
        }
        else if preresult <= 51 + max(0,(self.four_star_stack as i32 - 8) * 510) as u32 {
            self.four_star_stack = 0;
            self.got_four_stars += 1;
            print!("★★★★ 4 Star\n");
        }
        else {
            self.got_three_stars += 1;
            print!("★★★ 3 Star\n");
        }
        std::thread::sleep(Duration::from_millis(20));
        self.gacha(how_many - 1);

    }

    fn new() -> Self {
        GenshinGacha {
            guaranteed: false,
            stack: 0,
            four_star_stack: 0,
            got_four_stars: 0,
            got_three_stars: 0,
            spent: 0,
            primogems: 0,
            characters: HashMap::new(),
        }
    }

    fn print_self(&self) {
        print!("Spent: {} KRW\nCurrent Primogems: {}\nGotten 3 stars: {}\nGotten 4 stars: {}\nGotten 5 stars: {:?}, Current Stack: {}, Four Star Stack: {}\nNext 5 star is Kokomi-chan?: {:?}\n",
                self.spent, self.primogems, self.got_three_stars, self.got_four_stars, self.characters, self.stack, self.four_star_stack, self.guaranteed);
    }
}

fn main() {
    let mut manager = GenshinGacha::new();

    let stdin = std::io::stdin();

    loop {
        let mut inp = String::new();
        stdin.read_line(&mut inp).unwrap();
        

        match inp.as_str().trim() {
            "purchase" => manager.purchase_primo(119000),
            "add" => manager.add_primo(16000),
            "gacha" => manager.gacha(10),
            "print" => manager.print_self(),
            "exit" => break,
            _ => println!("Please input something good"),
        }
    }
}
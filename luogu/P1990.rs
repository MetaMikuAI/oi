fn main() {
    let n = {
        let mut s = String::new();
        std::io::stdin().read_line(&mut s).unwrap();
        let mut iter = s.split_whitespace();
        let n: i32 = iter.next().unwrap().parse().unwrap();
        n
    };

    let mut a: i32 = 1;
    let mut b: i32 = 2;
    let mut c: i32 = 5;
    let mut d: i32;

    if n == 1 {
        println!("1");
        return;
    }

    if n == 2 {
        println!("2");
        return;
    }
    
    if n == 3 {
        println!("5");
        return;
    }

    for _i in 4..=n {
        d = (a + c * 2) % 10000;
        a = b;
        b = c;
        c = d;
    }
    println!("{}", c);
}

/*
P1990 覆盖墙壁
普及/提高-

不是很懂，看题解说有神奇的 dp[i] = dp[i-1] * 2 + dp[i-3]
验证后也确实如此

Check 1: 10AC

MetaMiku 20251114 15:37
*/
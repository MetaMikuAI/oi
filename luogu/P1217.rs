fn is_prime(x: i32) -> bool {
    let mut n: i32 = 2;
    while n * n <= x {
        if x % n == 0 {
            return false;
        }
        n += 1;
    }
    return true;
}

fn check_and_print(a: i32, b: i32, x: i32) {
    if a <= x && x <= b && is_prime(x) {
        println!("{}", x);
    }
}

fn main() {
    let (a, b) = {
        let mut s = String::new();
        std::io::stdin().read_line(&mut s).unwrap();
        let mut iter = s.split_whitespace();
        let a: i32 = iter.next().unwrap().parse().unwrap();
        let b: i32 = iter.next().unwrap().parse().unwrap();
        (a, b)
    };


    // 回文 a
    for d1 in 1..=9 {
        let x: i32 = d1;
        check_and_print(a, b, x);
    }

    if b < 10 {
        return;
    }

    // 回文 aa
    for d1 in 1..=9 {
        let x: i32 = 11 * d1;
        check_and_print(a, b, x);
    }

    if b < 100 {
        return;
    }

    // 回文 aba
    for d1 in 1..=9 {
        for d2 in 0..=9 {
            let x: i32 = 101 * d1 + 10 * d2;
            check_and_print(a, b, x);
        }
    }

    if b < 1000 {
        return;
    }

    // 回文 abba
    for d1 in 1..=9 {
        for d2 in 0..=9 {
            let x: i32 = 1001 * d1 + 110 * d2;
            check_and_print(a, b, x);
        }
    }

    if b < 10000 {
        return;
    }

    // 回文 abcba
    for d1 in 1..=9 {
        for d2 in 0..=9 {
            for d3 in 0..=9 {
                let x: i32 = 10001 * d1 + 1010 * d2 + 100 * d3;
                check_and_print(a, b, x);
            }
        }
    }

    if b < 100000 {
        return;
    }
    
    // 回文 abccba
    for d1 in 1..=9 {
        for d2 in 0..=9 {
            for d3 in 0..=9 {
                let x: i32 = 100001 * d1 + 10010 * d2 + 1100 * d3;
                check_and_print(a, b, x);
            }
        }
    }

    if b < 1000000 {
        return;
    }

    // 回文 abcdcba
    for d1 in 1..=9 {
        for d2 in 0..=9 {
            for d3 in 0..=9 {
                for d4 in 0..=9 {
                    let x: i32 = 1000001 * d1 + 100010 * d2 + 10100 * d3 + 1000 * d4;
                    check_and_print(a, b, x);
                }
            }
        }
    }

    if b < 10000000 {
        return;
    }

    // 回文 abcddcba
    for d1 in 1..=9 {
        for d2 in 0..=9 {
            for d3 in 0..=9 {
                for d4 in 0..=9 {
                    let x: i32 = 10000001 * d1 + 1000010 * d2 + 100100 * d3 + 11000 * d4;
                    check_and_print(a, b, x);
                }
            }
        }
    }
}


/*
P1217 [USACO1.5] 回文质数 Prime Palindromes
普及-

看起来挺简单的，当 rust 练手了

并不简单，这回文数太抽象了

Check 1: 9AC

MetaMiku 20251108 00:38
*/
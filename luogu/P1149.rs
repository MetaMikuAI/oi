use std::io;


fn calc_cost(x: i32) -> i32 {
    let mut x = x;
    let cost_list: [i32; 10] = [6, 2, 5, 5, 4, 5, 6, 3, 7, 6];
    let mut cost = 0;
    if x == 0 {
        cost += cost_list[0];
    }
    while x > 0 {
        let x_l = (x % 10) as usize;
        cost += cost_list[x_l];
        x /= 10;
    }
    return cost;
}


fn main() {
    let n: i32 = {
        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();
        let parts: Vec<i32> = input
            .trim()
            .split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect();
        parts[0]
    };

    let n: i32 = n - 4; // `+` `=`

    let mut count = 0;

    
    for a in 0..=999 {
        for b in a..=999 {
            let c = a + b;
            if calc_cost(a) + calc_cost(b) + calc_cost(c) == n {
                count += 1;
                // println!("{} + {} = {}", a, b, c);
                if a != b {
                    count += 1;
                }
            }
        }
    }

    println!("{}", count);
}

/* 
P1149 [NOIP 2008 提高组] 火柴棒等式
普及-

rrrrrust

Check 1: 2AC 3WA
哎呀我想简单了

Check 2: 5AC

MetaMiku 20251108 01:28
*/

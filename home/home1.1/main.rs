use std::io;

fn main() {
    loop {
        println!("Please enter the list of numbers separated by spaces:");

        let mut list = String::new();
        io::stdin().read_line(&mut list)
            .expect("Failed to read line");

        if list.trim().is_empty() {
            println!("Input is empty");
            continue;
        }

        let mut numbers = Vec::new();
        let mut has_negative = false;
        let mut largest_negative: Option<f64> = None;
        let mut valid_input = true;
        for i in list.split_whitespace() {
            match i.trim().parse::<f64>() {
                Ok(number) => {
                    if number < 0.0 {
                        has_negative = true;
                        if largest_negative.is_none() || number > largest_negative.unwrap() {
                            largest_negative = Some(number);
                        }
                    }
                    numbers.push(number);
                },
                Err(_) => {
                    println!("Input should have only numbers, also use only dots for non-integer numbers");
                    valid_input = false;
                    break; 
                }
            }
        }

        if valid_input {
            if has_negative {
                println!("The largest negative number is: {:?}", largest_negative.unwrap());
            } else {
                println!("No negative numbers found in the list.");
            }
        }

        println!("Do you want to continue? (y/n)");
        let mut choice = String::new();
        io::stdin().read_line(&mut choice)
            .expect("Failed to read line");
        
        let choice = choice.trim().to_lowercase();
        if choice != "y" {
            println!("Bye!");
            break;
        }
    }
}


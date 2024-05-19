use std::io;

fn main() {
    loop {
        println!("Please enter the list of numbers separated by spaces:");

        let mut input_list = String::new();
        io::stdin().read_line(&mut input_list)
            .expect("Failed to read line");

        if input_list.trim().is_empty() {
            println!("Input is empty");
            continue;
        }

        let mut numbers = Vec::new();
        let mut has_negative = false;
        let mut largest_negative: Option<f64> = None;
        let mut valid_input = true;
        for num_str in input_list.split_whitespace() {
            match num_str.trim().parse::<f64>() {
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
        let mut restart_choice = String::new();
        io::stdin().read_line(&mut restart_choice)
            .expect("Failed to read line");
        
        let restart_choice = restart_choice.trim().to_lowercase();
        if restart_choice != "y" {
            println!("Bye!");
            break;
        }
    }
}


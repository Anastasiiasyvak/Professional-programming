use std::io;

fn main() {
    loop {
        println!("Please enter the list of numbers separated by spaces:");

        // for some variables we can use better names like input_list instead of just list here
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
        // It is better to use built-in tools of the language to process the data - consider list.split_whitespace().filter_map( ). and other tools to easily filter out all invalid data and non-negative values.
        // It will make your code more readable and maintainable as every for loop and nested if-else block makes reading of the code harder as a reader should understand all the potential flows.
        // Of course we can't avoid nested if and for statements completely but if we already have a good way to describe our intentions shortly then let's use it. 
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
        // for some variables we can use better names like restart_choise or rerun_choise or restart instead of just choise here
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


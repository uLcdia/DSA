#[derive(Debug, Clone)]
struct Tower(Vec<u32>);

fn move_disk(from: &mut Tower, to: &mut Tower) {
    let disk = from.0.pop().expect("Cannot move from empty tower");
    to.0.push(disk);
}

fn hanoi(num_disks: u32, source: &mut Tower, auxiliary: &mut Tower, destination: &mut Tower) {
    if num_disks == 1 {
        move_disk(source, destination);
    } else {
        hanoi(num_disks - 1, source, destination, auxiliary);
        move_disk(source, destination);
        hanoi(num_disks - 1, auxiliary, source, destination);
    }
}

fn create_tower(num_disks: u32) -> Tower {
    let mut disks = Vec::new();
    for i in (1..=num_disks).rev() {
        disks.push(i);
    }
    Tower(disks)
}

fn main() {
    let num_disks = 32;

    // No timers inside the rust code.  The timing will be done externally.
    let mut source = create_tower(num_disks);
    let mut auxiliary = Tower(Vec::new());
    let mut destination = Tower(Vec::new());
    hanoi(num_disks, &mut source, &mut auxiliary, &mut destination);


    // Check correctness (optional, but good for debugging larger problems)
    assert!(source.0.is_empty());
    assert!(auxiliary.0.is_empty());
    assert_eq!(destination.0.len() as u32, num_disks);
    for i in 0..num_disks {
        assert_eq!(destination.0[i as usize], num_disks - i);
    }

}

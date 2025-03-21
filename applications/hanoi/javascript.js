function moveDisk(from, to) {
  const disk = from.pop();
  to.push(disk);
}

function hanoi(numDisks, source, auxiliary, destination) {
  if (numDisks === 1) {
    moveDisk(source, destination);
  } else {
    hanoi(numDisks - 1, source, destination, auxiliary);
    moveDisk(source, destination);
    hanoi(numDisks - 1, auxiliary, source, destination);
  }
}

function createTower(numDisks) {
  const tower = [];
  for (let i = numDisks; i >= 1; i--) {
    tower.push(i);
  }
  return tower;
}

function main() {
  const numDisks = 32;

  const source = createTower(numDisks);
  const auxiliary = [];
  const destination = [];

  hanoi(numDisks, source, auxiliary, destination);

  // Correctness check (optional, but recommended)
  if (source.length !== 0 || auxiliary.length !== 0 || destination.length !== numDisks) {
    console.error("Error: Towers not in correct state.");
    return; // Or throw an error
  }
  for (let i = 0; i < numDisks; i++) {
    if (destination[i] !== numDisks - i) {
        console.error("Error: Disk order is incorrect")
        return
    }
  }

}

main();
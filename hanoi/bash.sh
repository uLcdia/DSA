#!/bin/bash

# Function to simulate moving a disk (no actual disk movement, just counting)
move_disk() {
  : # Do nothing (empty command)
}

# Recursive Hanoi function
hanoi() {
  local num_disks=$1
  local source=$2
  local auxiliary=$3
  local destination=$4

  if (( num_disks == 1 )); then
    move_disk
  else
    hanoi "$((num_disks - 1))" "$source" "$destination" "$auxiliary"
    move_disk
    hanoi "$((num_disks - 1))" "$auxiliary" "$source" "$destination"
  fi
}

# Main execution
num_disks=32

# Create "towers" (represented by integers, no actual data structure)
source=1
auxiliary=2
destination=3

# Call the hanoi function
hanoi "$num_disks" "$source" "$auxiliary" "$destination"

exit 0
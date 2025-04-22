import subprocess
import time
import os
from typing import List, Tuple

class CPPTester:
    def __init__(self, cpp_file: str, test_cases: List[Tuple[str, str]]):
        """
        Initialize the tester with the C++ file and test cases.

        Args:
            cpp_file (str): Path to the C++ source file
            test_cases (List[Tuple[str, str]]): List of (input, expected_output) pairs
        """
        self.cpp_file = cpp_file
        self.test_cases = test_cases
        self.executable = "a.out"  # Default output name for g++
        self.compile_command = f"g++ {cpp_file} -o {self.executable}"
        self.passed_tests = 0
        self.failed_tests = 0

    def compile_cpp(self) -> bool:
        """
        Compile the C++ program using g++.

        Returns:
            bool: True if compilation successful, False otherwise
        """
        try:
            result = subprocess.run(self.compile_command, shell=True,
                                  text=True, capture_output=True)
            if result.returncode != 0:
                print("Compilation Failed!")
                print(result.stderr)
                return False
            print("Compilation Successful!")
            return True
        except Exception as e:
            print(f"Compilation Error: {e}")
            return False

    def run_test_case(self, input_data: str, expected_output: str, test_number: int) -> Tuple[bool, float]:
        """
        Run a single test case and measure execution time.

        Args:
            input_data (str): Input for the test case
            expected_output (str): Expected output for the test case
            test_number (int): Test case number for reporting

        Returns:
            Tuple[bool, float]: (Test passed or not, Time taken in seconds)
        """
        try:
            start_time = time.time()
            process = subprocess.run(f"./{self.executable}", shell=True,
                                   input=input_data, text=True,
                                   capture_output=True, timeout=5)
            end_time = time.time()

            execution_time = end_time - start_time
            # Split outputs into lines and strip trailing whitespace from each line
            actual_lines = [line.rstrip() for line in process.stdout.splitlines()]
            expected_lines = [line.rstrip() for line in expected_output.splitlines()]

            # Join lines back for comparison and printing (optional, but good for output)
            actual_output_processed = "\n".join(actual_lines)
            expected_output_processed = "\n".join(expected_lines)


            if actual_lines == expected_lines:
                print(f"Test Case {test_number}: PASSED (Time: {execution_time:.4f} seconds)")
                return True, execution_time
            else:
                print(f"Test Case {test_number}: FAILED (Time: {execution_time:.4f} seconds)")
                print(f"Expected Output:\n{expected_output_processed}")
                print(f"Actual Output:\n{actual_output_processed}")
                # Optionally print original outputs if needed for debugging
                # print(f"Original Expected Output:\n{expected_output}")
                # print(f"Original Actual Output:\n{process.stdout}")
                return False, execution_time
        except subprocess.TimeoutExpired:
            print(f"Test Case {test_number}: FAILED (Timeout after 5 seconds)")
            return False, 0.0
        except Exception as e:
            print(f"Test Case {test_number}: FAILED (Error: {e})")
            return False, 0.0

    def run_all_tests(self) -> None:
        """
        Run all test cases and display summary.
        """
        if not self.compile_cpp():
            return

        total_time = 0.0
        self.passed_tests = 0
        self.failed_tests = 0

        print("\nRunning Test Cases...\n")
        for i, (input_data, expected_output) in enumerate(self.test_cases, 1):
            passed, exec_time = self.run_test_case(input_data, expected_output, i)
            if passed:
                self.passed_tests += 1
            else:
                self.failed_tests += 1
            total_time += exec_time

        print("\nTest Summary:")
        print(f"Total Test Cases: {len(self.test_cases)}")
        print(f"Passed: {self.passed_tests}")
        print(f"Failed: {self.failed_tests}")
        print(f"Total Execution Time: {total_time:.4f} seconds")

    def cleanup(self) -> None:
        """
        Remove the compiled executable file.
        """
        if os.path.exists(self.executable):
            os.remove(self.executable)
            print("Cleaned up executable file.")

def main():
    # Example test cases: List of (input, expected_output) pairs
    test_cases = [
        ("15", "1 2 3 4 5\n4 5 6\n7 8"),  # Example test case 1
       # ("3\n10 20 30\n", "10 20 30"),    # Example test case 2
       # ("2\n100 200\n", "100 200"),      # Example test case 3
    ]

    # Path to your C++ file
    cpp_file = "./02/6/2.cpp"

    # Create tester instance and run tests
    tester = CPPTester(cpp_file, test_cases)
    tester.run_all_tests()
    tester.cleanup()

if __name__ == "__main__":
    main()

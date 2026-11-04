// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract StudentData {

    struct Student {
        string name;
        uint age;
        string className;
        uint rollNumber;
    }

    Student[] public students;

    // Add student
    function addStudent(
        string memory name,
        uint age,
        string memory className,
        uint rollNumber
    ) public {
        students.push(Student(name, age, className, rollNumber));
    }

    // Get student details
    function getStudent(uint index)
        public view returns (string memory, uint, string memory, uint)
    {
        require(index < students.length, "Invalid index");

        Student memory s = students[index];

        return (s.name, s.age, s.className, s.rollNumber);
    }

    // Get total students
    function getTotalStudents() public view returns (uint) {
        return students.length;
    }

    // Accept plain Ether transfers
    receive() external payable {}

    // Handle unmatched function calls
    fallback() external payable {}

    // Get contract balance
    function getContractBalance() public view returns (uint) {
        return address(this).balance;
    }
}
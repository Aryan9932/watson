// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract BankAccount {

    address public owner;
    uint256 public balance;

    constructor() {
        owner = msg.sender;
    }

    // Deposit money
    function deposit() public payable {
        require(msg.value > 0, "Invalid amount");

        balance += msg.value;
    }

    // Withdraw money
    function withdraw(uint256 amount) public {
        require(msg.sender == owner, "Not the owner");
        require(amount > 0, "Invalid amount");
        require(amount <= balance, "Insufficient balance");

        balance -= amount;

        payable(owner).transfer(amount);
    }

    // Display balance
    function getBalance() public view returns (uint256) {
        return balance;
    }
}
#!/bin/bash

FILE="addressbook.txt"

createAddressBook() {
    if [ -e "$FILE" ]; then
        echo "Address book already exists."
    else
        touch "$FILE"
        echo "Address book created."
    fi
}

viewAddressBook() {
    if [ ! -s "$FILE" ]; then
        echo "Address book is empty or does not exist."
    else
        echo "---- Address Book ----"
        cat "$FILE"
    fi
}

insertRecord() {
    echo "Enter record in format: LastName,FirstName,Email,Phone"
    read record
    echo "$record" >> "$FILE"
    echo "Record inserted."
}

deleteRecord() {
    if [ ! -s "$FILE" ]; then
        echo "Address book is empty or does not exist."
        return
    fi

    echo "Enter a search string (e.g. name or email) to find the record to delete:"
    read search
    matches=$(grep -n "$search" "$FILE")

    if [ -z "$matches" ]; then
        echo "No matching records found."
        return
    fi

    echo "$matches"
    echo "Enter line number to delete:"
    read line
    sed -i "${line}d" "$FILE"
    echo "Record deleted."
}

modifyRecord() {
    if [ ! -s "$FILE" ]; then
        echo "Address book is empty or does not exist."
        return
    fi

    echo "Enter a search string (e.g. name or email) to find the record to modify:"
    read search
    matches=$(grep -n "$search" "$FILE")

    if [ -z "$matches" ]; then
        echo "No matching records found."
        return
    fi

    echo "$matches"
    echo "Enter line number to modify:"
    read line
    echo "Enter new record (LastName,FirstName,Email,Phone):"
    read newRecord
    sed -i "${line}s/.*/$newRecord/" "$FILE"
    echo "Record modified."
}

exitProgram() {
    echo "Exiting... Goodbye!"
    exit 0
}

while true; do
    echo "=============================="
    echo "     Address Book Menu"
    echo "=============================="
    echo "1. Create Address Book"
    echo "2. View Address Book"
    echo "3. Insert a Record"
    echo "4. Delete a Record"
    echo "5. Modify a Record"
    echo "6. Exit"
    echo "=============================="
    echo -n "Enter your choice: "
    read choice

    case $choice in
        1) createAddressBook ;;
        2) viewAddressBook ;;
        3) insertRecord ;;
        4) deleteRecord ;;
        5) modifyRecord ;;
        6) exitProgram ;;
        *) echo "Invalid choice. Please select 1-6." ;;
    esac
done

: '
4️⃣ Give execution permission:
   chmod +x addressbook.sh

5️⃣ Run the script:
   ./addressbook.sh
   (or)
   bash addressbook.sh
------------------------------------------------------------
📘 SHELL SCRIPT DOCUMENTATION — ADDRESS BOOK MANAGEMENT SYSTEM
------------------------------------------------------------

🔹 SCRIPT PURPOSE:
   This shell script provides a simple **menu-driven Address Book System**
   that allows users to perform CRUD operations (Create, Read, Update, Delete)
   on a text file named **addressbook.txt**.

   The address book stores records in the format:
       LastName,FirstName,Email,Phone

------------------------------------------------------------
⚙️ LOGIC / ALGORITHM USED:

1️⃣ **File Setup**
   - The script uses a text file (`addressbook.txt`) as the database.
   - If the file doesn’t exist, it can be created using the “Create Address Book” option.

2️⃣ **Menu System (Infinite Loop)**
   - The `while true` loop continuously displays a menu with options 1–6.
   - The user selects an option, and the corresponding function is called using a `case` statement.

3️⃣ **Function Descriptions**

   ➤ **createAddressBook()**
      - Checks if `addressbook.txt` exists.
      - If not, creates the file using `touch`.
      - Displays confirmation message.

   ➤ **viewAddressBook()**
      - Displays the entire address book contents using `cat`.
      - Checks if the file exists and is not empty using `[ -s "$FILE" ]`.

   ➤ **insertRecord()**
      - Prompts user to enter details in format:
          LastName,FirstName,Email,Phone
      - Appends the record to the file using `>>`.

   ➤ **deleteRecord()**
      - Searches for a specific keyword (name or email) using `grep -n` (with line numbers).
      - Displays matching lines.
      - Prompts user to enter the line number to delete.
      - Deletes that line using `sed -i "${line}d"`.

   ➤ **modifyRecord()**
      - Searches for a record using `grep -n`.
      - Displays all matching records.
      - User selects a line number to modify.
      - Prompts for a new record (same format).
      - Updates the selected line using `sed -i "${line}s/.*/$newRecord/"`.

   ➤ **exitProgram()**
      - Prints an exit message and terminates the script using `exit 0`.

4️⃣ **Error Handling**
   - Checks if the file exists and is not empty before delete/modify/view.
   - Ensures that only valid choices (1–6) are accepted.

------------------------------------------------------------
📊 EXAMPLE EXECUTION:

Example Run:
---------------
$ bash addressbook.sh

==============================
     Address Book Menu
==============================
1. Create Address Book
2. View Address Book
3. Insert a Record
4. Delete a Record
5. Modify a Record
6. Exit
==============================
Enter your choice: 1
Address book created.

Enter your choice: 3
Enter record in format: LastName,FirstName,Email,Phone
Doe,John,john.doe@example.com,9876543210
Record inserted.

Enter your choice: 2
---- Address Book ----
Doe,John,john.doe@example.com,9876543210

Enter your choice: 4
Enter a search string (e.g. name or email) to find the record to delete:
John
1:Doe,John,john.doe@example.com,9876543210
Enter line number to delete:
1
Record deleted.

Enter your choice: 6
Exiting... Goodbye!

------------------------------------------------------------
✅ SUMMARY:
   ➤ Script Type: Menu-driven Bash Script
   ➤ File Used: addressbook.txt
   ➤ Features:
       • Create address book file
       • View records
       • Insert new record
       • Delete specific record
       • Modify existing record
   ➤ Key Commands Used:
       touch, cat, grep, sed, read, case, if-else
------------------------------------------------------------
'

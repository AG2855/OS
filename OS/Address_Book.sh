#!/bin/bash

# Set default file location in your Documents folder
FILE="$HOME/Documents/addressbook.txt"

# Function to create the address book
createAddressBook() {
  # Ensure Documents folder exists
  mkdir -p "$HOME/Documents"

  if [ -e "$FILE" ]; then
    echo "Address book already exists at: $FILE"
  else
    touch "$FILE"
    echo "Address book created at: $FILE"
  fi
}

# Function to view all records
viewAddressBook() {
  if [ ! -s "$FILE" ]; then
    echo "Address book is empty or does not exist."
  else
    echo "---- Address Book ----"
    nl -ba -w3 -s". " "$FILE"
  fi
}

# Function to insert a new record
insertRecord() {
  echo "Enter record in format: LastName,FirstName,Email,Phone"
  read -r record
  if [ -z "$record" ]; then
    echo "Empty record — nothing inserted."
    return
  fi
  printf '%s\n' "$record" >> "$FILE"
  echo "Record inserted successfully."
}

# Function to delete a record by line number
deleteRecord() {
  if [ ! -s "$FILE" ]; then
    echo "Address book is empty or does not exist."
    return
  fi
  echo "Enter a search string (name or email) to find the record to delete:"
  read -r search
  matches=$(grep -ni -- "$search" "$FILE")
  if [ -z "$matches" ]; then
    echo "No matching records found."
    return
  fi
  echo "Matching records:"
  echo "$matches"
  echo "Enter line number to delete:"
  read -r line
  if ! [[ "$line" =~ ^[0-9]+$ ]]; then
    echo "Invalid line number."
    return
  fi
  cp "$FILE" "${FILE}.bak"
  sed -i "${line}d" "$FILE"
  echo "Record deleted. Backup saved as ${FILE}.bak"
}

# Function to modify a record by line number
modifyRecord() {
  if [ ! -s "$FILE" ]; then
    echo "Address book is empty or does not exist."
    return
  fi
  echo "Enter a search string (name or email) to find the record to modify:"
  read -r search
  matches=$(grep -ni -- "$search" "$FILE")
  if [ -z "$matches" ]; then
    echo "No matching records found."
    return
  fi
  echo "Matching records:"
  echo "$matches"
  echo "Enter line number to modify:"
  read -r line
  echo "Enter new record (LastName,FirstName,Email,Phone):"
  read -r newRecord
  if [ -z "$newRecord" ]; then
    echo "Empty input — modification cancelled."
    return
  fi
  cp "$FILE" "${FILE}.bak"
  sed -i "${line}s/.*/$newRecord/" "$FILE"
  echo "Record modified. Backup saved as ${FILE}.bak"
}

# Exit function
exitProgram() {
  echo "Exiting... Goodbye!"
  exit 0
}

# Main menu loop
while true; do
  echo "=============================="
  echo "       Address Book Menu"
  echo "=============================="
  echo "1. Create Address Book"
  echo "2. View Address Book"
  echo "3. Insert a Record"
  echo "4. Delete a Record"
  echo "5. Modify a Record"
  echo "6. Exit"
  echo "=============================="
  echo -n "Enter your choice: "
  read -r choice
  case $choice in
    1) createAddressBook ;;
    2) viewAddressBook ;;
    3) insertRecord ;;
    4) deleteRecord ;;
    5) modifyRecord ;;
    6) exitProgram ;;
    *) echo "Invalid choice. Please select 1-6." ;;
  esac
  echo ""  # Blank line for readability
done

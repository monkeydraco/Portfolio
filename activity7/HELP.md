# Line Editor Help Documentation

Welcome to the Advanced Line Editor! Below are the supported terminal commands and their usage syntax, including extra credit features.

## Supported Commands

* **`p` (Display)**
  * **Description:** Displays all current lines with their line numbers.
  * **Example:** `cmd> p`

* **`i <line_number> <text>` (Insert Line)**
  * **Description:** Inserts a new line of text at a specific index, shifting existing lines down.
  * **Example:** `cmd> i 1 Hello World`

* **`d <line_number>` (Delete Line)**
  * **Description:** Removes a line at a specific index, shifting subsequent lines up.
  * **Example:** `cmd> d 1`

* **`u` (Undo Last Action - BONUS)**
  * **Description:** Reverses the most recent insert or delete operation.
  * **Example:** `cmd> u`

* **`f <keyword>` (Search - BONUS)**
  * **Description:** Finds and reports which line numbers contain a given word or phrase.
  * **Example:** `cmd> f World`

* **`s <filename>` (Save File)**
  * **Description:** Writes the current in-memory document to a text file.
  * **Example:** `cmd> s notes.txt`

* **`l <filename>` (Load File)**
  * **Description:** Reads a text file into the editor memory.
  * **Example:** `cmd> l notes.txt`

* **`q` (Quit)**
  * **Description:** Exits the line editor.   
  * **Example:** `cmd> q`
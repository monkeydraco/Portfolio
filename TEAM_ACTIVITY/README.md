# Advanced Command-Line Line Editor in C

## Team Details & Functional Contributions
* **TANMAYI M** (R25EF285)
  * **Modules Developed:** Document display handler (`display_document`), File I/O operations (`save_file`, `load_file`), and the core terminal command-line parsing loop (`main`).
* **TARUN S MUDHOL** (R25EF288)
  * **Modules Developed:** Line insertion logic (`insert_line`) with automated index shifting, memory boundary protection, and syntax validation.
* **PRAJWAL S NAIK** (R25EF189)
  * **Modules Developed:** Line deletion logic (`delete_line`), Undo transaction system (`undo_last_action`), and Keyword search implementation (`search_keyword`).

---

## Architecture & Technical Design (How It Is Built)

### 1. Data Structure Choice: 2D Static Array
Instead of dynamic linked lists (which introduce pointer complexity and potential memory leaks under strict time constraints), this editor utilizes a fixed-size 2D character array:

`char lines[MAX_LINES][MAX_LEN];`

* **Trade-off & Justification:** 
  * *Pros:* Extremely fast, predictable memory layout, zero dependency on heap memory management (`malloc`/`free`), and highly stable for a bounded 2-hour terminal project.
  * *Cons:* Fixed capacity (`MAX_LINES = 100`, `MAX_LEN = 256`), meaning the document holds up to 100 lines. This trade-off was intentionally chosen to guarantee clean compilation and zero segmentation faults during evaluation.

### 2. Core Operational Logic
* **Insertion & Deletion Shifting:** When a line is inserted at a specific index, all subsequent lines to the end of the document are shifted downward using `strcpy()` within a reverse loop. Deleting a line shifts subsequent lines upward to keep text contiguous in memory.
* **Command Parsing Loop:** The program operates through an interactive REPL (Read-Eval-Print Loop) inside `main()`, reading string tokens via `scanf()` and dispatching control flow using standard `strcmp()` checks. Input buffer flushing (`getchar()`) prevents synchronization issues between numeric inputs and text entry.

### 3. Bonus Architecture (Undo & Search)
* **Single-Level Undo Engine:** Managed via state tracking variables (`last_action`, `undo_line_num`, `undo_text`). When an insert or delete occurs, prior line state/metadata is safely cached. Triggering `u` calls the inverse operation natively without infinite recursion overhead.
* **Pattern Matching:** The search module (`f`) scans the array linearly using standard library string routines (`strstr`), reporting matches instantly alongside line numbers.

---

## Features Implemented
* **Core Features:** 
  1. Insert a Line (`i`)
  2. Delete a Line (`d`)
  3. Display Document (`p`)
  4. Save / Load File (`s` / `l`)
* **Bonus Features (Extra Credit):** 
  1. Undo Last Action (`u`)
  2. Keyword Search (`f`)

---

## Compilation and Execution Instructions

### 1. Compile the code using GCC
Open your terminal inside the project directory and run:

`gcc line_editor.c`

### 2. Run the Editor
Execute the compiled binary directly from your terminal:

`./a.out`

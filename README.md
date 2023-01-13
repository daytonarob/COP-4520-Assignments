# COP-4520-Assignments

## How to run this program

⚠️ This only works for **Windows** systems. ⚠️

Simply download the provided `.exe`* file provided in [x64/Release/](https://github.com/GameDevSlate/COP-4520-Assignments/tree/master/x64/Release) (or you can click the link, and download once inside the page). Once downloaded, you can simply click on the file to start the program.

### Command-line arguments

If you are going to run the program from a **windows** terminal, firstly, when you are inside the terminal and already in the directory of where the `.exe`* file is, you start by typing:

```
 .\COP-4520-Assignments.exe

```

You can simply press the ENTER key after that, and the program will start with no issues. If you want to immediately start at a particular assignment you type a space, *then* the **number** of the assignment you want to access. So, if you wanted to access assignment 1, you would type:

```
.\COP-4520-Assignments.exe 1
```

If you type a number outside the range of 1 to whatever the latest assignment due is, the program will default to using the assignment's menu inside the program.

---

\* ⚠️ The `.exe` was compiled for **64-bit** systems only. ⚠️

## Compiling Binaries

⚠️ This project was coded using **ISO C++ 20 standard (/std:c++20)**, since it is the most stable at the moment. ⚠️

### Visual Studio

⚠️ This only works if you have the *Visual Studio*, **not** Visual Studio Code. ⚠️

Simply download the whole project and click on the `.sln` (solution) file, once Visual Studio opens, run the program.

🛑 Set the build configuration to be **Release** if you want similar results to the provided `.exe` file.

### No IDE's, on a terminal

You only have to download the `src` folder, since that is what contains all source files require to run this program; from there, use your compiler of choice (g++, clang, etc.) and run its proper commands, note that I do not know the order of sequence all the files have to be in when typing the compile command.

---

❗Might try to add makefiles at some point, but do not count on it.

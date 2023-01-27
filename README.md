# COP-4520-Assignments

## Building the Project

⚠️ This project was coded using **ISO C++ 20 standard (/std:c++20)**, since it is the most stable at the moment. ⚠️

**You need to have CMake installed.**

In your terminal of choice, type the following command:

If you are using a single configuration generator (Ninja/Unix-Makefiles) you must specify the CMAKE_BUILD_TYPE. **This will most likely be the case.**

```
cmake -S . -B <build directory>/ -D CMAKE_BUILD_TYPE=Release 
cmake --build <build directory>/
```

---

For multi-configuration generators it's slightly different (Ninja Multi-Config, Visual Studio).

```
cmake -S . -B <build directory>
cmake --build <build directory> --config Release
```

I lot ouf people like to name the build directory `out/build` or `build`, but this is up to you.

### Running the Project
Inside of the *build directory* there are two ways you can run the program on a terminal depending on your operating system:

#### Windows

```
COP-4520-Assignments.exe
```

#### Linux

```
./COP-4520-Assignments
```

### Command-Line Arguments

There is only one command line argument so far in this project, and it is simply a way to start at a project immeditely, simply type the assignment number after the run command. So, if you wanted to run the program and immediately start at assignment one in Linux, you would type:

```
./COP-4520-Assignments 1
```

Otherwise, you could simply use the terminal GUI that I made for accessing assignments🙂.

## Reports on Each Assignment

Each assignment report is written in Markdown so it can be easily read from inside github. They can be found in [COP-4520-Assignments/COP-4520-Assignments/src/Assignment_Reports/](https://github.com/GameDevSlate/COP-4520-Assignments/tree/master/COP-4520-Assignments/src/Assignment_Reports) (or you can click on the link).

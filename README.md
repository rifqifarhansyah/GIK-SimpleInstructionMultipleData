# **Garuda Ilmu Komputer** - Weekly Task
<h2 align="center">
  Simple Instruction Multiple Data (SIMD)<br/>
</h2>
<hr>

## Table of Contents
1. [General Info](#general-information)
2. [Creator Info](#creator-information)
3. [Features](#features)
4. [Technologies Used](#technologies-used)
5. [Setup](#setup)
6. [Usage](#usage)
7. [Screenshots](#screenshots)
7. [Structure](#structure)
8. [Project Status](#project-status)
9. [Room for Improvement](#room-for-improvement)
10. [Acknowledgements](#acknowledgements)
11. [Contact](#contact)

<a name="general-information"></a>

## General Information
A simple program that utilize the `SIMD` concept to accelerate the search process. This program will prove that the `SIMD` concept is faster than the normal search process (`scalar`). The parameter of the comparison is the `time` that is needed to search the query. The result of the program is gained by using device with `11th Gen Intel(R) COre(TM) i7-1165G7 @ 2.80GHz` processor and `8192MB` RAM.

<a name="creator-information"></a>

## Creator Information

| Nama                        | NIM      | E-Mail                      |
| --------------------------- | -------- | --------------------------- |
| Mohammad Rifqi Farhansyah   | 13521166 | 13521166@std.stei.itb.ac.id |

<a name="features"></a>

## Features
- This program will first ask the user to input the number of data (`n`) that will be used in the program.
- Then, the program will ask user to input a `sequence of n data`. The data must separated by `space`.
- After that, the program will ask user to input query `q` that will be used in the program.
- Finally, the program will output the result of the search process, that contains the `time` was needed to search the query and the `index` of the data that is the query.

<a name="technologies-used"></a>

## Technologies Used
- MingGw-W64 version 8.1.0

> Note: The version of the libraries above is the version that we used in this project. You can use the latest version of the libraries.

<a name="setup"></a>

## Setup
1. Download the MingW-W64 from [here](https://sourceforge.net/projects/mingw-w64/files/).
2. Install the MingW-W64.

<a name="usage"></a>

## Usage
1. Open the terminal in the project directory.
2. `cd output` and then `main.exe` to run the program.
3. Complete all of the input that is asked by the program.
4. The program will print out all of the result

<a name="screenshots"></a>

## Screenshots
<p>
  <img src="/image/SS1.png/">
  <p>Figure 1. Database</p>
  <nl>
  <img src="/image/SS2.png/">
  <p>Figure 2. Query</p>
  <nl>
  <img src="/image/SS3.png/">
  <p>Figure 3. Result</p>
  <nl>
</p>

<a name="structure"></a>

## Structure
```bash
│   Doc.docx
│   file.txt
│   main.cpp
│   print_number.py
│   README.md
│
├───.vscode
│       settings.json
│
├───image
│       SS1.png
│       SS2.png
│       SS3.png
│
└───output
        main.exe
```

<a name="project-status">

## Project Status
Project is: _complete_

<a name="room-for-improvement">

## Room for Improvement
Room for Improvement:
- Accelerate the search process.
- Improvement in the `time` that is needed to search the query to be more precise.

<a name="acknowledgements">

## Acknowledgements
- Thanks To Allah SWT

<a name="contact"></a>

## Contact
<h4 align="center">
  Contact Me : mrifki193@gmail.com<br/>
  2023
</h4>
<hr>

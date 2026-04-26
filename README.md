# Project README

## Overview
The project is a graphical application that visualizes the Collatz Conjecture using custom graphics libraries. It supports Linux, Windows, and WebAssembly builds.

## Features
- Visualize the Collatz Conjecture in real-time.
- Adjust the depth of the sequence with keyboard controls (E key to update, S to decrease depth, E to increase depth).
- Supports multiple build targets: Linux, Windows, and WebAssembly.

## Project Structure
```
Gui_CollatzConjecture/
├── build/              # .exe files produced by Main.c for different platforms
├── bin/                # .so or .dll files produced by *.c in libs
├── libs/               # *.c files for generating *.so/.dll in bin
├── lib/                # custom library files for the project
├── code/               # scripts from custom languages like .rex, .ll, .omml
├── data/               # data files like .txt or dumped files
├── assets/             # image and sound files
├── src/                # source code
│   ├── Main.c          # Entry point file
│   └── *.h             # standalone header-based C-files, without *.c implementing it
├── Makefile.linux      # Linux build configuration
├── Makefile.windows    # Windows build configuration
├── Makefile.wine       # Wine (Linux cross compile for Windows) build configuration
├── Makefile.web        # Emscripten (WebAssembly) build configuration
└── README.md           # This file
├── LICENSE               # License file
└── .gitignore            # Git ignore file
```

### Prerequisites
- C/C++ Compiler and Debugger: GCC, Clang.
- Make utility.
- Standard development tools.
- Libraries needed for specific projects:
  - Linux: X11, PNG, JPEG libraries.
  - Windows: WINAPI (user32, gdi32, winmm).
  - WebAssembly: Emscripten.

## Build & Run
### Linux
```sh
cd Gui_CollatzConjecture/
make -f Makefile.linux all
```

### Windows
```sh
cd Gui_CollatzConjecture/
make -f Makefile.windows all
```

### WebAssembly (Emscripten)
```sh
cd Gui_CollatzConjecture/
make -f Makefile.web all
emrun --no_browser --port 8080 build/index.html
```

### Clean Rebuild
```sh
make -f Makefile.linux clean
make -f Makefile.linux all
```
or for other platforms:
```sh
make -f Makefile.windows clean
make -f Makefile.windows all

make -f Makefile.wine clean
make -f Makefile.wine all

make -f Makefile.web clean
make -f Makefile.web all
```

### Build Options
- `all`: build output.
- `do`: build + exe output.
- `clean`: Remove build artifacts.

Always execute with `make`:
```sh
make -f Makefile.(os) exe
```
Replace `(os)` with the target platform (linux, windows, wine, web).
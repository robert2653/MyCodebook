1. install vscode & msys2, check desktop path of vscode
2. open mingw64, not ucrt64, "pacman -S --needed base-devel mingw-w64-x86_64-toolchain"
3. add C:\\msys64\\mingw64\\bin to environment path
4. (re)open vscode, install C/C++, run, choose g++
5. open settings -> compiler -> add compilerPath "C:\\msys64\\mingw64\\bin\\g++.exe"
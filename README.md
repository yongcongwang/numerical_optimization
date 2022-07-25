# Numerical Optimization in Robotics

This is the code repo for homework of the course [Numerical Optimization in Robotics](https://www.shenlanxueyuan.com/my/course/490).

## Environment

### Os

```Bash
                   -`                    wyc@arch 
                  .o+`                   -------- 
                 `ooo/                   OS: Arch Linux x86_64 
                `+oooo:                  Host: XPS 15 7590 
               `+oooooo:                 Kernel: 5.18.11-arch1-1 
               -+oooooo+:                Uptime: 1 day, 4 hours, 5 mins 
             `/:-:++oooo+:               Packages: 613 (pacman) 
            `/++++/+++++++:              Shell: bash 5.1.16 
           `/++++++++++++++:             Resolution: 3840x2160 
          `/+++ooooooooooooo/`           DE: i3-with-shmlog 
         ./ooosssso++osssssso+`          WM: i3 
        .oossssso-````/ossssss+`         Theme: Adwaita [GTK3] 
       -osssssso.      :ssssssso.        Icons: Adwaita [GTK3] 
      :osssssss/        osssso+++.       Terminal: xterm 
     /ossssssss/        +ssssooo/-       CPU: Intel i7-9750H (12) @ 4.500GHz 
   `/ossssso+/:-        -:/+osssso+-     GPU: NVIDIA GeForce GTX 1650 Mobile / Max-Q 
  `+sso+:-`                 `.-/+oso:    GPU: Intel CoffeeLake-H GT2 [UHD Graphics 630] 
 `++:.                           `-/+/   Memory: 3735MiB / 15628MiB 
 .`                                 `/
```

### OpenCV

OpenCV [install](https://docs.opencv.org/4.x/d7/d9f/tutorial_linux_install.html):

```Bash
wget -O opencv.zip https://github.com/opencv/opencv/archive/4.x.zip
unzip opencv.zip
mkdir -p build && cd build
cmake  ../opencv-4.x
make -j10
sudo make install
```

### Eigen

- [Eigen](https://eigen.tuxfamily.org/index.php?title=Main_Page), it's in `extern` folder.

### Compiler

- g++ 12.1.0

## Build

Build all works with the command:

```Bash
bash scripts/build.sh
```

## Run

Executables are generated in the path `build/apps/work[n]`(`n` can be `0 - 5`), run with:

```Bash
./build/apps/work0/work
```

## Results

[work0](docs/work0.md)


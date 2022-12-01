# Quadratic root finder

Almost the single most overkill version of a quadratic root finder I could
think of. I could also add the quadratic functions to a polynomial struct
with function pointers (_i.e._, as methods) to make this unnecessarily object
oriented, but that might be best left to the user as an exercise.

You will note that I include [Doxygen](https://doxygen.nl/)-style
documentation and it is tooled for
the usual gcc/cmake workflow. It's aching to use github actions as a build
system.

I made this as a reference program to highlight a bunch of common `C` ideas.
There are preprocessor macros, static functions, standard librarys,
command line arguments, etc. etc.

## Build Instructions

Since this is intended as a simple reference for undergraduate students, I
intended this to be built and used in your favorite \*nix flavor. These
instructions will cover installing, building, and running the program
in [Debian](https://www.debian.org/) on Windows via [WSL](#install-wsl).
You could achieve the same in Windows
with [mingw](https://www.mingw-w64.org/), or even easier to do it on a native
[Linux](https://ubuntu.com/download) device or macOS.

<a name="install-wsl"></a>

## Installing WSL if you are using Windows

Consult the
[official install docs](https://learn.microsoft.com/en-us/windows/wsl/install)
if you run into trouble.

First, fire open Command Prompt (search for it in your Start menu) or PowerShell,
or even better, Terminal, and install debian via wsl

```bash
wsl --install -d Debian
```

Alternatively, try out ubuntu if you prefer the bleeding edge

```bash
wsl --install -d Debian
```

## Installing the build tools and such

Assuming you are staring at a Debian-based Linux prompt, you should probably
get up to date

```bash
sudo apt update
sudo apt upgrade -y
```

and now install all the magic sauce

```bash
sudo install git cmake vim
```

If you like Visual Studio Code instead of vim (heathen) then you can install on
native Debian-based via `snap` with

```bash
sudo snap install --classic code
```

or follow the [instructions](https://code.visualstudio.com/docs/setup/linux)
to install via apt (I prefer it this way).
If you are using WSL, there are
[instructions](https://code.visualstudio.com/docs/remote/wsl)
for that too.

## Building the code

Now that you are all set up, and assuming you have
[generated an SSH key](https://docs.github.com/en/authentication/connecting-to-github-with-ssh/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent) and
[added it to your github account](https://docs.github.com/en/authentication/connecting-to-github-with-ssh/adding-a-new-ssh-key-to-your-github-account),
first clone the repo

```bash
git clone git@github.com:jacobw56/quadratic_formula.git
```

then make a build folder and build it

```bash
cd quadratic_formula
mkdir build
cd build
cmake ..
make
```

Now try it out!

```bash
./quadratic_formula -A=2.34 -B=7 -C=-4.51
```

or

```bash
./quadratic_formula --help
```

## [sfml-examples](https://github.com/matgat/sfml-examples.git)
A collection of (goofy?) examples written while
inspecting [SFML library](https://www.sfml-dev.org)

_________________________________________________________________________
## pan-zoom-resize
Setting a scene where is possible modify the view with the mouse:
Left click drag: Pan
Mouse wheel: Zoom in/out
Window resize: Increase area without loosing the current pan/zoom


_________________________________________________________________________
## color
Extending `sf::Color` adding hue/saturation/luminance capabilities


_________________________________________________________________________
## Build

### linux

```sh
# pacman -S sfml
$ git clone https://github.com/matgat/sfml-examples
$ cd sfml-examples
$ clang++ -std=c++20 -O3 -Wall -Wextra -Wpedantic -Wconversion -Wfatal-errors -lsfml-graphics -lsfml-window -lsfml-system "color/main.cpp" -o "color"
```

> [!TIP]
> Install the dependency `sfml` using
> your package manager:
>
> ```sh
> $ sudo pacman -S sfml
> ```
>
> or
>
> ```sh
> $ sudo apt install -y libsfml-dev
> ```


### Windows

> [!TIP]
> Install the dependency `sfml` using `vcpkg`:
>
> ```bat
> > git clone https://github.com/Microsoft/vcpkg.git
> > cd .\vcpkg
> > .\bootstrap-vcpkg.bat -disableMetrics
> > .\vcpkg integrate install
> > .\vcpkg install sfml:x64-windows
> ```
>
> To just update the `vcpkg` libraries:
>
> ```bat
> > cd .\vcpkg
> > git pull
> > .\bootstrap-vcpkg.bat -disableMetrics
> > .\vcpkg upgrade --no-dry-run
> ```

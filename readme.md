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
```
# pacman -S sfml
$ git clone https://github.com/matgat/sfml-examples
$ cd sfml-examples
$ clang++ -std=c++2b -O3 -Wall -Wextra -Wpedantic -Wconversion -Wfatal-errors -lsfml-graphics -lsfml-window -lsfml-system "color/main.cpp" -o "color"
```
On windows, using Visual Studio, the `sfml` library
dependency can be conveniently handled with `vcpkg`:
```
> git clone https://github.com/Microsoft/vcpkg.git
> .\vcpkg\bootstrap-vcpkg.bat -disableMetrics
> .\vcpkg\vcpkg integrate install
> .\vcpkg\vcpkg install fmt:x64-windows
```

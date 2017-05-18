# libnolimits 1.0.0-beta
A NoLimits Roller Coaster 1 and 2 Library written in C++, which provides functionality to manipulate and create NoLimits 2 Parks or NoLimits 1 Tracks programmatically.

## Important

This library is still beta. There is no documentation nor unit tests yet, but planned for the stable release. If you like to contribute, feel free to beta test this library, especially by opening, saving and comparing an existing park in NoLimits 2 with this library.

All non working features are listed below.

# Getting started
## Requirements
* [zlib](http://zlib.net/) >= 1.2.7
* [glm](http://zlib.net/) >= 0.9.8

## Installation
Clone this repository on your local machine and follow the usual [cmake](https://cmake.org/) procedure.

```
cmake .
make
make install
```

# Documentation

Documentation is not written yet. It´s still in progress.

~~Here it is: https://geforcefan.github.io/libnolimits/~~

## Examples

There is a basic example in this repository, which will be compiled during the ``cmake`` build process. There will be more examples in the feature. Feel free to ask for specific examples.

## Opening and reading park information from a *.nl2park

```c++
#include <iostream>
#include <libnolimits.h>
...
NoLimits::NoLimits2::Park *park = new NoLimits::NoLimits2::Park("Hydra.nl2park");

std::cout << "Author: " << park->getInfo()->getAuthor() << std::endl;
std::cout << "Description: " << park->getInfo()->getDescription() << std::endl;

std::cout << "Terrain height at [20, 50]: " << park->getTerrain()->getHeightAtVertex(20, 50) << std::endl;
...
park->getInfo()->setAuthor("Ercan Akyürek"); 
park->save("HydraClone.nl2park");
...
```

## Features
### NoLimits 2 Park (*.nl2park)
#### Available chunks

- [x] Info
  - [x] Weather
  - [x] Sky
- [x] Terrain
  - [x] Water
  - [x] Layers
  - [x] Layer intensities on terrain
  - [x] Terrain height data
- [x] Scenery
- [x] Coaster
  - [x] Tracks
    - [x] Vertices
    - [x] Segments
    - [x] Sections
      - [x] Brake
      - [x] Lift
      - [x] Station
      - [x] Storage
      - [x] Transport
    - [x] Separators
    - [x] Triggers
    - [x] Roll points
    - [x] 4D parameters
    - [ ] Special tracks (switch and transfer table)
  - [x] Trains
    - [x] Cars
  - [x] Custom Friction
  - [x] Track / Train / Car Colors
  - [x] Scripts
  - [x] Mode
  - [x] Sections
  - [x] Resource files
  - [x] Supports
    - [x] Beams
    - [x] Free Nodes
    - [x] Beam Nodes
    - [x] Rail Nodes
    - [x] Support Nodes
    - [x] Footers
    - [ ] Prefabs
     
### NoLimits 1 Park (*.nltrack)
#### Available chunks

- [ ] Info
- [ ] Terrain
  - [ ] Terrain height data
- [ ] Environment
- [ ] Train
  - [ ] Cars
- [ ] Track
  - [ ] Vertices
  - [ ] Sections
      - [ ] Brake
      - [ ] Lift
      - [ ] Station
      - [ ] Transport
  - [ ] Catwalks
- [ ] Supports
  - [ ] Rail Nodes
  - [ ] Free Nodes
  - [ ] Beam
  - [ ] Footers
- [ ] Train
- [ ] Scenery

### Version independent features
 
- [x] Setting and getting terrain heights at a given XY point
- [ ] Track interpolation, getting the matrix at a given distance on track
- [ ] "NL2 Spline export" conform CSV generation
- [x] Creating or modifiying existing tracks

# Contribution

Feel free to fork this project, implement features, improve the code quality, fixing bugs, etc. Just request a push, the core team will review the code and decide whether it will merged to the master branch or not.

# Core team

- Ercan "geforcefan" Akyürek, [GitHub](https://github.com/geforcefan/) | [eMail](mailto:ercan.akyuerek@gmail.com)

# License information 

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

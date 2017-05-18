# libnolimits 0.1 alpha
A NoLimits Roller Coaster 1 and 2 Library written in C++, which provides functionality to manipulate and create NoLimits 2 Parks or NoLimits 1 Tracks programmatically.

# Getting started
## Requirements
* [zlib](http://zlib.net/) >= 1.2.7

## Installation
Clone this repository on your local machine and follow the usual make procedure on unix like environments

```
./configure
make
make install
```

# Documentation

Here it is: https://geforcefan.github.io/libnolimits/

# Examples

## Opening and reading park information from a *.nl2park

```c++
#include <libnolimits/libnolimits.h>
...
NoLimits::NL2::Park *park = new NoLimits::NL2::Park("Hydra.nl2park");

std::cout << "Author: " park->getInfo()->getAuthor() << std::endl;
std::cout << "Description: " park->getInfo()->getDescription() << std::endl;

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
  - [ ] Layer intensities on terrain
- [ ] Scenery
- [x] Coaster
  - [x] Tracks
    - [x] Vertices
    - [x] Segments
    - [x] Sections
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
    - [x] Free Nodes
    - [x] Beam Nodes
    - [x] Rail Nodes
    - [x] Footers
     
### Version independent features
 
- [x] Setting and getting terrain heights at a given XY point
- [ ] Track interpolation, getting the matrix at a given distance on track
- [ ] "NL2 Spline export" conform CSV generation
- [ ] Creating or modifiying existing tracks

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

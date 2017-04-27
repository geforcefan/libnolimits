# libnolimits
A NoLimits Roller Coaster 1 and 2 Library written in C++, which provides functionality to manipulate and create NoLimits 2 Parks or NoLimits 1 Track programmatically.

# Getting started
## Requirements
* [zlib](http://zlib.net/) >= 1.2.7

## Installing libnolimits
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
...
NoLimits::NL2::Park *park = new NoLimits::NL2::Park("Hydra.nl2park");

std::cout << "Author: " park->getInfo()->getAuthor() << std::endl;
std::cout << "Description: " park->getInfo()->getDescription() << std::endl;

std::cout << "Terrain height at [20, 50]: " << park->getTerrain()->getHeightAtVertex(20, 50) << std::endl;
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

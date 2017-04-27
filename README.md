# libnolimits
A NoLimits Roller Coaster 1 and 2 Library written in C++, which provides functionality to manipulate and create NoLimits 2 Parks or NoLimits 1 Track programmatically.

## Features
### NoLimits 2 Park (*.nl2park)

* Full covarage of all available chunks
  * Info
    * Weather
    * Sky
  * Terrain
    * Water
    * Layers
  * Scenery
  * Coaster
    * Tracks / Special tracks (switch and transfer table)
      * Vertices
      * Segments
      * Sections
      * Separators
      * Triggers
      * Roll points
      * 4D parameters
    * Trains
    * Cars
    * Custom Friction
    * Track / Train / Car Colors
    * Scripts
    * Mode
    * Sections
    * Resource files
    * Supports
      * Free Nodes
      * Beam Nodes
      * Rail Nodes
      * Footers
     
### Version independed features
 
* Setting and getting terrain heights at a given XY point
* Track interpolation, getting the matrix at a given distance on track
* "NL2 Spline export" conform CSV generation
* Creating or modifiying existing tracks

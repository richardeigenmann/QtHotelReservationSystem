# Installation on Windows

Get and install vcpkg

Then run `vcpkg.exe integrate install mongo-cxx-driver:x64-windows` this drags in many boot libraries.

use `vcpkg.exe list` to see the installed packages

Then do `vcpkg.exe integrate install` to make the package available to all users.

Open the `QtHotelReservationSystem.pro` project file and adjust the location of the `vcpkg` directory.

Now open QtCreator and open the Project by opening the `QtHotelReservationSystem.pro` file.

Good luck!

# Installation on Windows

Get and install vcpkg

Then run `vcpkg.exe install mongo-cxx-driver:x64-windows` this drags in many boot libraries.

use `vcpkg.exe list` to see the installed packages

Then do `vcpkg.exe integrate install` to make the package available to all users.

Open the `QtHotelReservationSystem.pro` project file and adjust the location of the `vcpkg` directory.

Now open QtCreator and open the Project by opening the `QtHotelReservationSystem.pro` file.

Build the project.

Open a console and cd to the build... directory where the `QtHotelReservationSystem.exe` file was created.

You now need to add the shared .dll libraries with the special QT tool:

`c:\Qt\5.11.1\msvc2017_64\bin\windeployqt.exe .`

and

```
copy c:\Users\Richa\Documents\vcpkg\packages\mongo-cxx-driver_x64-windows\bin\mongocxx.dll .
copy c:\Users\Richa\Documents\vcpkg\packages\mongo-cxx-driver_x64-windows\bin\bsoncxx.dll .
copy c:\Users\Richa\Documents\vcpkg\packages\libbson_x64-windows\bin\libbson-1.0.dll .
copy c:\Users\Richa\Documents\vcpkg\packages\mongo-c-driver_x64-windows\bin\libmongoc-1.0.dll .
```

Good luck!

# PCS 2024 - Exercises

Repository for the course PCS laboratories.

## Instructions

Software `QtCreator` shall be installed on the machine with `CMake` support with version >= 3.20.
To install `QtCreator` follow the instructions given by the professor.

Then, 3rd party libraries shall be installed.
Follow the instructions before moving to the exercises.

### 3rd_party_libraries installations

To install the 3rd party libraries the following step shall be performed:

* Go to the main folder `<main>` that contains the folder `3rd_party_libraries`;
* Create a folder `<main>/externals` in which the libraries will be installed;
* Open `QtCreator` and open a new project selecting `<main>/3rd_party_libraries/CMakeLists.txt`; 
* Select the `Release` configuration and browse to the folder `<main>/externals`;
* Press the `Configure Project` button and build the project.

If the build is successful the folder `<main>/externals/Main_Install` is created with all the 3rd libraries inside of it.

### Exercises build

Once all the 3rd party libraries are successfully installed then each exercise can be compiled successfully.
The following steps shall be performed:

* Go to the exercise folder `<main>/<Example>`;
* Create a folder `<main>/<Example>/Debug` in which the exercise will be compiled in `Debug` configuration;
* Open `QtCreator` and open a new project selecting `<main>/<Example>/CMakeLists.txt`;
* Select the `Debug` configuration and browse to the folder `<main>/<Example>/Debug`;
* Press the `Configure Project` button and build the project.

If the build is successful the folder `<main>/<Example>/Debug` will contain the executable program.

**NB**: for the `Release` configuration the same steps shall be performed replacing the word `Debug` on the instructions.


# starshipgen

[![Build](https://github.com/VoxelStorm-Ltd/starshipgen/actions/workflows/cmake-single-platform.yml/badge.svg)](https://github.com/VoxelStorm-Ltd/starshipgen/actions/workflows/cmake-single-platform.yml)

`starshipgen` is a C++ command-line starship and civilisation generator.

## Requirements

- A C++11-compatible compiler
- CMake 3.16 or newer
- Boost.Random headers and the Boost.Program_options library

## Build

Configure and build an optimized executable from the repository root:

```sh
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel
```

For a debug build, use `-DCMAKE_BUILD_TYPE=Debug` instead. With a multi-config
generator, select the configuration when building, for example:

```sh
cmake --build build --config Release --parallel
```

## Run

With a single-config generator, run:

```sh
./build/starshipgen --civ-seed 7009 --ship-seed 0
```

Multi-config generators place the executable in a configuration subdirectory,
such as `build/Release/starshipgen`.

Both seed options are optional. Any omitted seed is selected randomly and
printed when the program starts. Run `starshipgen --help` to list the available
options.

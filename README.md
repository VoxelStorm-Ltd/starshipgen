# starshipgen

`starshipgen` is a C++ command-line starship and civilisation generator.

## Requirements

- A C++11-compatible compiler
- CMake 3.16 or newer
- Boost headers (including Boost.Random)

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
./build/starshipgen
```

Multi-config generators place the executable in a configuration subdirectory,
such as `build/Release/starshipgen`.

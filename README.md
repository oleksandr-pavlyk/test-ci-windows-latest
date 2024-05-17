# Test conda build on windows-2022 runner

This repository compares run of sample project on windows-2019 and windows-2022 runners
in GitHub Actions CI.

This repo first builds stand-alone C/C++ CMake project which succeds in both runners.
It then proceeds to build Python native extension which is also cmake-based. This step
succeds in windows-2019, but fails in windows-2022


In windows-2019:
   - stand-alone cmake:
      - "C:/Program Files (x86)/Microsoft Visual Studio/2019/Enterprise/VC/Tools/MSVC/14.29.30133/bin/Hostx64/x64/cl.exe"
   - cmake in "conda build"
      - "C:/Program Files (x86)/Microsoft Visual Studio/2019/Enterprise/VC/Tools/MSVC/14.29.30133/bin/Hostx64/x64/cl.exe"

In windows-2022:
   - stand-alone cmake:
      - "C:/Program Files/Microsoft Visual Studio/2022/Enterprise/VC/Tools/MSVC/14.39.33519/bin/Hostx64/x64/cl.exe"
   - cmake in "conda build"
      - FAILS

conda-build selects compiler from a selection specified by conda-forge package https://github.com/conda-forge/vc-feedstock
The latest supported redistributable is 14.38.33130 per

https://github.com/conda-forge/vc-feedstock/blob/main/.ci_support/win_64_cl_version19.38.33130cross_t_hb91178803b.yaml

Since this version is absent from the container, the build fails.

There can be two resolutions to this conundrum:
   1. Updated vc-feedstock
   2. Install needed version into the runner

The right choice is delegated to maintainers of these.
# Description

This repository contains the **registers address** definition of the **DinFox** nodes.

# Dependencies

The driver relies on:

* An external `types.h` header file defining the **standard C types** of the targeted MCU.
* The **UNA library** provided in the [una-lib](https://github.com/Ludovic-Lesur/una-lib) repository.

Here is the versions compatibility table:

| **dinfox-registers** | **una-lib** |
|:---:|:---:|
| [sw7.3](https://github.com/Ludovic-Lesur/dinfox-registers/releases/tag/sw7.3) | >= [sw4.2](https://github.com/Ludovic-Lesur/una-lib/releases/tag/sw4.2) |
| [sw7.2](https://github.com/Ludovic-Lesur/dinfox-registers/releases/tag/sw7.2) | >= [sw4.2](https://github.com/Ludovic-Lesur/una-lib/releases/tag/sw4.2) |
| [sw7.1](https://github.com/Ludovic-Lesur/dinfox-registers/releases/tag/sw7.1) | >= [sw4.2](https://github.com/Ludovic-Lesur/una-lib/releases/tag/sw4.2) |
| [sw7.0](https://github.com/Ludovic-Lesur/dinfox-registers/releases/tag/sw7.0) | >= [sw4.2](https://github.com/Ludovic-Lesur/una-lib/releases/tag/sw4.2) |
| [sw6.0](https://github.com/Ludovic-Lesur/dinfox-registers/releases/tag/sw6.0) | >= [sw4.2](https://github.com/Ludovic-Lesur/una-lib/releases/tag/sw4.2) |
| [sw5.0](https://github.com/Ludovic-Lesur/dinfox-registers/releases/tag/sw5.0) | [sw4.0](https://github.com/Ludovic-Lesur/una-lib/releases/tag/sw4.0) to [sw4.1](https://github.com/Ludovic-Lesur/una-lib/releases/tag/sw4.1) |
| [sw4.0](https://github.com/Ludovic-Lesur/dinfox-registers/releases/tag/sw4.0) | [sw4.0](https://github.com/Ludovic-Lesur/una-lib/releases/tag/sw4.0) to [sw4.1](https://github.com/Ludovic-Lesur/una-lib/releases/tag/sw4.1) |
| [sw3.1](https://github.com/Ludovic-Lesur/dinfox-registers/releases/tag/sw3.1) | [sw2.2](https://github.com/Ludovic-Lesur/una-lib/releases/tag/sw2.2) to [sw3.1](https://github.com/Ludovic-Lesur/una-lib/releases/tag/sw3.1) |
| [sw3.0](https://github.com/Ludovic-Lesur/dinfox-registers/releases/tag/sw3.0) | [sw2.2](https://github.com/Ludovic-Lesur/una-lib/releases/tag/sw2.2) to [sw3.1](https://github.com/Ludovic-Lesur/una-lib/releases/tag/sw3.1) |
| [sw2.0](https://github.com/Ludovic-Lesur/dinfox-registers/releases/tag/sw2.0) | [sw2.2](https://github.com/Ludovic-Lesur/una-lib/releases/tag/sw2.2) to [sw3.1](https://github.com/Ludovic-Lesur/una-lib/releases/tag/sw3.1) |
| [sw1.0](https://github.com/Ludovic-Lesur/dinfox-registers/releases/tag/sw1.0) | [sw2.2](https://github.com/Ludovic-Lesur/una-lib/releases/tag/sw2.2) to [sw3.1](https://github.com/Ludovic-Lesur/una-lib/releases/tag/sw3.1) |

# Compilation flags

| **Flag name** | **Value** | **Description** |
|:---:|:---:|:---:|
| `DINFOX_REGISTERS_DISABLE_FLAGS_FILE` | `defined` / `undefined` | Disable the `dinfox_registers_flags.h` header file inclusion when compilation flags are given in the project settings or by command line. |
| `DINFOX_REGISTERS_DEFAULT_TIMEOUT_MS` | `<value>` | Default registers access timeout in milliseconds. |

# Build

A static library can be compiled by command line with `cmake`.

```bash
mkdir build
cd build
cmake -DCMAKE_TOOLCHAIN_FILE="<toolchain_file_path>" \
      -DTOOLCHAIN_PATH="<arm-none-eabi-gcc_path>" \
      -DTYPES_PATH="<types_file_path>" \
      -DUNA_LIB_PATH="<una-lib_path>" \
      -DEMBEDDED_UTILS_PATH="<embedded-utils_path>" \
      -DDINFOX_REGISTERS_DEFAULT_TIMEOUT_MS=200 \
      -G "Unix Makefiles" ..
make all
```

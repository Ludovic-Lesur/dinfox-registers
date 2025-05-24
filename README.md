# Description

This repository contains the **registers address** definition of the **DinFox** nodes.

# Dependencies

The driver relies on:

* An external `types.h` header file defining the **standard C types** of the targeted MCU.
* The **UNA library** provided in the [una-lib](https://github.com/Ludovic-Lesur/una-lib) repository.

Here is the versions compatibility table:

| **dinfox-registers** | **una-lib** |
|:---:|:---:|
| [sw2.0](https://github.com/Ludovic-Lesur/dinfox-registers/releases/tag/sw2.0) | >= [sw2.2](https://github.com/Ludovic-Lesur/una-lib/releases/tag/sw2.2) |
| [sw1.0](https://github.com/Ludovic-Lesur/dinfox-registers/releases/tag/sw1.0) | >= [sw2.2](https://github.com/Ludovic-Lesur/una-lib/releases/tag/sw2.2) |

# Compilation flags

| **Flag name** | **Value** | **Description** |
|:---:|:---:|:---:|
| `DINFOX_REGISTERS_DISABLE_FLAGS_FILE` | `defined` / `undefined` | Disable the `dinfox_registers_flags.h` header file inclusion when compilation flags are given in the project settings or by command line. |
| `DINFOX_REGISTERS_DEFAULT_TIMEOUT_MS` | `<value>` | Default registers access timeout in milliseconds. |
| `DINFOX_REGISTERS_ACCESS` | `defined` / `undefined` | Enable register access definitions. |
| `DINFOX_REGISTERS_ACCESS_TIMEOUT` | `defined` / `undefined` | Enable register access timeout definitions. |
| `DINFOX_REGISTERS_ERROR_VALUE` | `defined` / `undefined` | Enable register error values definitions. |

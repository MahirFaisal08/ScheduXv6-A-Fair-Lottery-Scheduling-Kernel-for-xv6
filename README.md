# ScheduXv6 – A Fair Lottery Scheduling Kernel for xv6  
![Language](https://img.shields.io/badge/language-C-blue)  
![Platform](https://img.shields.io/badge/platform-xv6--riscv-lightgrey)  
![License](https://img.shields.io/badge/license-MIT-green)  
![Status](https://img.shields.io/badge/status-stable-success)  

---

## Overview  

**ScheduXv6** is a modified xv6 kernel that implements **lottery scheduling**,  
a probabilistic CPU allocation mechanism ensuring **fairness among processes**.  

Unlike traditional round-robin scheduling, this system assigns each process  
a certain number of **tickets**, where each CPU scheduling decision is made  
through a **random lottery draw** — the higher the number of tickets,  
the greater the chance of CPU time.  

---

## Objectives  

- Implement a **fair and probabilistic scheduling algorithm**  
- Maintain **process proportionality** based on assigned tickets  
- Preserve **kernel stability and simplicity**  
- Provide an **interactive test program** to verify fair distribution  

---

## Core Features  

- **Lottery Scheduling:** Processes receive CPU time proportional to their tickets  
- **Dynamic Ticket Assignment:** Each process can hold a different number of tickets  
- **Randomized Fairness:** Uses kernel-level pseudo-random generator  
- **Process Fairness Visualization:** Test tool to observe real-time fairness  
- **Backward Compatibility:** Works seamlessly with xv6 system calls and process management  

---

## Implementation Details  

- **Kernel Modules Modified:**  
  `proc.c`, `proc.h`, `rand.c`, `rand.h`, and `sysproc.c`  

- **New System Call Added:**  
  `settickets(int n)` → allows a process to set its ticket count  

- **Random Number Generator:**  
  Implemented in `rand.c` using a linear congruential generator for fairness  

- **Scheduler Modification:**  
  Updated `scheduler()` loop in `proc.c` to perform random lottery draws  
  based on the total ticket pool at runtime  

---

## Build & Run Instructions  

Follow these steps to **compile and run ScheduXv6** on your system:  

### Clone the Repository  
```bash
git clone https://github.com/MahirFaisal08/ScheduXv6-A-Fair-Lottery-Scheduling-Kernel-for-xv6.git
cd ScheduXv6-A-Fair-Lottery-Scheduling-Kernel-for-xv6
```
---
## Build & Run Instructions  

Follow these steps to **compile and run ScheduXv6** on your system:  

---

### Prerequisites  

Make sure the following are installed:  

- `riscv64-unknown-elf-gcc` toolchain  
- `qemu` emulator  
- `make` and `gcc`  
- `WSL` or `Linux terminal` (for Windows users)  

> **Note:** On Windows, xv6 must be run inside **WSL** with RISC-V tools installed.  

---

### Build the Kernel  

```bash
make clean
make qemu
```
---

### Run the Lottery Scheduler Test  

Once xv6 is running inside QEMU:  
```bash
$ test_scheduler
```
---
## Also test multiple processes with different ticket counts:
```bash
$ test_scheduler 10 &
$ test_scheduler 5 &
$ test_scheduler 2 &
```
## Exit the Emulator
```bash
Ctrl + A → X
```
## Rebuild if Needed
```bash
make clean
make qemu
```
---

## 🧾 Testing & Validation  

To verify **proportional CPU allocation fairness** in the lottery scheduler:

1. Launch **3–4 instances** of `test_scheduler`, each with a different ticket count.  
2. Observe that the **round count** of each process increases **in proportion to its ticket count**.  
3. Over time, these ratios **converge**, confirming fair and unbiased scheduling behavior.  

---

## Future Improvements

- 🔹 Add **multi-core scheduling support** for CPU > 1  
- 🔹 Implement **dynamic ticket redistribution**  
- 🔹 Extend algorithm for **weighted I/O-bound processes**  
- 🔹 Add **visualization module** for scheduling outcomes  
- 🔹 Explore **hybrid (lottery + stride) scheduling** for finer fairness

---

## Author

**Name:** Md. Mahir Faisal  
**Project:** ScheduXv6 – A Fair Lottery Scheduling Kernel for xv6  
**Language:** `C` *(Kernel-level Programming)*  
**Platform:** `xv6-riscv`

---

## License

This project is licensed under the **MIT License** –  
you are free to use, modify, and distribute this software with proper credit.  

For details, see the LICENSE file in this repository  
or visit the official [MIT License page](https://opensource.org/licenses/MIT).

---

## 🏫 Acknowledgment

This project is based on **xv6-riscv** by [MIT PDOS](https://github.com/mit-pdos/xv6-riscv),  
used and modified under the **MIT License** for **educational and research purposes**.

---

⭐ **Star this repo** if you found it helpful!  
📫 For queries, issues, or collaborations — contact **[Md. Mahir Faisal](https://github.com/MahirFaisal08)**  

---

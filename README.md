# Digital-Bank-Account-Ledger
# Bank Account Management System

A modular Microproject developed in C Language to track, control, and process operational data records for multiple user bank accounts. The source code uses separate functional files to maintain clear, clean, and beginner-friendly structure.

---

## Project Requirements Implemented

This project fully implements all core bookkeeping and technical assignment parameters:
* **Dynamic Array Records:** Uses structured data definitions to capture initial baseline input values for custom user arrays (struct UserAccount client_list[MAX_RECORDS]).
* **Search-Based Adjustments:** Performs sequential verification loops matching specific account IDs to process daily deposit changes.
* **Transaction Safe Limits:** Features defensive validation rules that automatically block and deny cash withdrawals if client funding is insufficient.
* **Targeted Growth Updates:** Loops across structured data indices to scale existing capital values based on exact category rules (4% for savings and 2% for current types).
* **Extreme Balance Audits:** Scans through array limits to calculate and extract accounts containing the absolute highest and lowest cash funds.
* **Low Fund Warnings:** Runs dedicated counters to aggregate active system flags when available balances collapse beneath the critical ₹1000 standard constraint.

---

## Architecture Layout

The system divides functions across dedicated individual script layers to keep logic decoupled and manageable:
* main.c - The primary automation router hosting the central console user interaction loop.
* bank.h & bank.c - Defines primary structure properties and populates initial user account entries.
* cash.h & cash.c - Checks transaction limits, handles adjustments, and calculates annual growth distributions.
* summary.h & summary.c - Tracks analytic boundary checks to log account extremes and balance alarms.

---

## Compilation and Execution Guide

To deploy and execute this application inside a standard workspace terminal, run the following commands sequentially:

```bash
gcc main.c bank.c cash.c summary.c -o bank_app
./bank_app
```

## Hospital Management System

### Overview
- Text-based C program that manages doctors, patients, appointments, and billing for a small clinic or hospital.
- Data is persisted across sessions in plain-text files (`doctors.txt`, `patients.txt`, `appointments.txt`, `bills.txt`). The executable expects these files in the parent directory of the `main.c` source folder, i.e. `Hospital-Management-System-main/`.

### Features by Role
- **Admin** (`admin123` password): add/view doctors, add/view patients, review appointments and bills.
- **Doctor** (login with doctor ID assigned on creation): review personal appointments, mark them completed by issuing prescriptions, and trigger automatic billing.
- **Patient**: self-register, book appointments with any doctor, and review personal bills.

### Building the Program
- **Prerequisites**: C compiler such as GCC (MinGW-w64 on Windows) or Clang.
- **Compile** (from the `Hospital-Management-System-main/Hospital-Management-System-main` directory):
  ```
  gcc main.c -o hms
  ```
- On success, `hms` (or `hms.exe` on Windows) is generated alongside `main.c`.

### Running the Program
- Ensure the data files exist one level up from the executable. Empty files can be created if running for the first time:
  ```
  cd ..
  type nul > doctors.txt
  type nul > patients.txt
  type nul > appointments.txt
  type nul > bills.txt
  ```
- Launch the executable from the `Hospital-Management-System-main/Hospital-Management-System-main` directory so the relative paths resolve:
  ```
  ./hms      # Linux/macOS
  .\hms.exe # Windows PowerShell
  ```

### Data Management Notes
- IDs are auto-generated: doctors start at 1000, patients at 2000, appointments at 3000, bills at 4000.
- Appointments default to `Scheduled`; completing an appointment via the doctor menu updates it to `Completed` and adds an unpaid bill for the patient.
- Bills remain `Unpaid` until you manually edit the text file or extend the program with payment handling.

### Extending the Program
- Add persistence for prescriptions (currently printed only to stdout).
- Implement payment status updates and receipt printing.
- Harden input handling (e.g., validation, overflow protection) and switch to binary or database storage for larger deployments.


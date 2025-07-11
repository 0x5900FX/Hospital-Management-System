# Hospital-Management-System


A C-based console application for managing hospital operations, developed using CLion.

```
Features

Role-based access control (Admin, Doctor, Patient)

Doctor management (add/view doctors)

Patient management (register/view patients)

Appointment scheduling

Billing system

Data persistence using text files
```
Requirements

- CLion IDE or any C compiler (gcc recommended)

- CMake 3.20+

- C11 Standard


## Installation 

Clone the repo

`git clone https://github.com/0x5900FX/Hospital-Management-System.git`

Open project in `Clion`.
    
`Build` the project.

`Run` the executable.

```
Usage
The system provides three main interfaces:

Admin Interface
1. Add/view doctors

2. View all patients

3. View appointments

4. Access billing records

Doctor Interface
1. View assigned appointments

2. Prescribe medicine

3. Update appointment status

Patient Interface
1. Register new account

2. Book appointments

3. View medical bills


Default admin credentials:

Username: admin

Password: admin123

```



````
Data Storage
The system stores data in four text files in the project directory:

doctors.txt - Doctor records

patients.txt - Patient records

appointments.txt - Appointment details

bills.txt - Billing information

Project Structure
main.c - Contains core program logic

CMakeLists.txt - Build configuration

Data files - Generated automatically on first run

````
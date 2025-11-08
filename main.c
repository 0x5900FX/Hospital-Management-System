#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure definitions
typedef struct {
    int id;
    char name[50];
    char specialization[50];
    char contact[15];
} Doctor;

typedef struct {
    int id;
    char name[50];
    int age;
    char gender;
    char contact[15];
    char medicalHistory[200];
} Patient;

typedef struct {
    int appointmentId;
    int patientId;
    int doctorId;
    char date[20];
    char time[10];
    char status[20]; // Scheduled, Completed, Cancelled
} Appointment;

typedef struct {
    int billId;
    int patientId;
    float amount;
    char date[20];
    char status[20]; // Paid, Unpaid
} Bill;

// Global variables
Doctor doctors[100];
Patient patients[1000];
Appointment appointments[500];
Bill bills[500];

int doctorCount = 0;
int patientCount = 0;
int appointmentCount = 0;
int billCount = 0;

// Function prototypes
void loadData();
void saveData();
void adminMenu();
void doctorMenu();
void patientMenu();
void addDoctor();
void viewDoctors();
void addPatient();
void viewPatients();
void bookAppointment();
void viewAppointments();
void prescribeMedicine(int doctorId);
void generateBill(int patientId, float amount);

void viewDoctorAppointments(int doctorId);
void viewPatientBill();
void viewBills();

int main() {
    loadData();

    int choice;

    printf("==========================================\n");
    printf("   HOSPITAL MANAGEMENT SYSTEM (HMS v1.0)  \n");
    printf("==========================================\n\n");

    while(1) {
        printf("\nSelect Role:\n");
        printf("1. Admin\n");
        printf("2. Doctor\n");
        printf("3. Patient\n");
        printf("4. Exit System\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                adminMenu();
                break;
            case 2:
                doctorMenu();
                break;
            case 3:
                patientMenu();
                break;
            case 4:
                saveData();
                printf("Data saved. Exiting system.\n");
                exit(0);
            default:
                printf("Invalid selection. Try again.\n");
        }
    }

    return 0;
}
//did

void loadData() {
    FILE *file;

    // Load doctors
    file = fopen("../doctors.txt", "r");
    if (file != NULL) {
        doctorCount = 0;
        while(fscanf(file, "%d|%[^|]|%[^|]|%[^\n]\n",
              &doctors[doctorCount].id,
              doctors[doctorCount].name,
              doctors[doctorCount].specialization,
              doctors[doctorCount].contact) == 4) {
            doctorCount++;
            if(doctorCount >= 100) break;
        }
        fclose(file);
    }

    // Load patients
    file = fopen("../patients.txt", "r");
    if (file != NULL) {
        patientCount = 0;
        while(fscanf(file, "%d|%[^|]|%d|%c|%[^|]|%[^\n]\n",
              &patients[patientCount].id,
              patients[patientCount].name,
              &patients[patientCount].age,
              &patients[patientCount].gender,
              patients[patientCount].contact,
              patients[patientCount].medicalHistory) == 6) {
            patientCount++;
            if(patientCount >= 1000) break;
        }
        fclose(file);
    }

    // Load appointments
    file = fopen("../appointments.txt", "r");
    if (file != NULL) {
        appointmentCount = 0;
        while(fscanf(file, "%d|%d|%d|%[^|]|%[^|]|%[^\n]\n",
              &appointments[appointmentCount].appointmentId,
              &appointments[appointmentCount].patientId,
              &appointments[appointmentCount].doctorId,
              appointments[appointmentCount].date,
              appointments[appointmentCount].time,
              appointments[appointmentCount].status) == 6) {
            appointmentCount++;
            if(appointmentCount >= 500) break;
        }
        fclose(file);
    }

    // Load bills
    file = fopen("../bills.txt", "r");
    if (file != NULL) {
        billCount = 0;
        while(fscanf(file, "%d|%d|%f|%[^|]|%[^\n]\n",
              &bills[billCount].billId,
              &bills[billCount].patientId,
              &bills[billCount].amount,
              bills[billCount].date,
              bills[billCount].status) == 5) {
            billCount++;
            if(billCount >= 500) break;
        }
        fclose(file);
    }
}

void saveData() {
    FILE *file;

    // Save doctors
    file = fopen("../doctors.txt", "w");
    if (file != NULL) {
        for(int i = 0; i < doctorCount; i++) {
            fprintf(file, "%d|%s|%s|%s\n",
                doctors[i].id,
                doctors[i].name,
                doctors[i].specialization,
                doctors[i].contact);
        }
        fclose(file);
    }

    // Save patients
    file = fopen("../patients.txt", "w");
    if (file != NULL) {
        for(int i = 0; i < patientCount; i++) {
            fprintf(file, "%d|%s|%d|%c|%s|%s\n",
                patients[i].id,
                patients[i].name,
                patients[i].age,
                patients[i].gender,
                patients[i].contact,
                patients[i].medicalHistory);
        }
        fclose(file);
    }

    // Save appointments
    file = fopen("../appointments.txt", "w");
    if (file != NULL) {
        for(int i = 0; i < appointmentCount; i++) {
            fprintf(file, "%d|%d|%d|%s|%s|%s\n",
                appointments[i].appointmentId,
                appointments[i].patientId,
                appointments[i].doctorId,
                appointments[i].date,
                appointments[i].time,
                appointments[i].status);
        }
        fclose(file);
    }

    // Save bills
    file = fopen("../bills.txt", "w");
    if (file != NULL) {
        for(int i = 0; i < billCount; i++) {
            fprintf(file, "%d|%d|%.2f|%s|%s\n",
                bills[i].billId,
                bills[i].patientId,
                bills[i].amount,
                bills[i].date,
                bills[i].status);
        }
        fclose(file);
    }

    printf("\nData saved to text files in current directory:\n");
    printf("- doctors.txt\n- patients.txt\n- appointments.txt\n- bills.txt\n");
}
void adminMenu() {
    int choice;
    char password[20];

    printf("\nEnter admin password: ");
    scanf("%s", password);

    if(strcmp(password, "admin123") != 0) {
        printf("Invalid password!\n");
        return;
    }

    while(1) {
        printf("\n[ADMIN PANEL]\n");
        printf("1. Add Doctor\n");
        printf("2. View Doctors\n");
        printf("3. Add Patient\n");
        printf("4. View Patients\n");
        printf("5. View Appointments\n");
        printf("6. View Bills\n");
        printf("7. Return to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addDoctor();
                break;
            case 2:
                viewDoctors();
                break;
            case 3:
                addPatient();
                break;
            case 4:
                viewPatients();
                break;
            case 5:
                viewAppointments();
                break;
            case 6:
                viewBills();
                break;
            case 7:
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}

void doctorMenu() {
    int id, found = 0;
    printf("\nEnter your doctor ID: ");
    scanf("%d", &id);

    // Check if doctor exists
    for(int i = 0; i < doctorCount; i++) {
        if(doctors[i].id == id) {
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("Doctor ID not found!\n");
        return;
    }

    int choice;
    while(1) {
        printf("\n[DOCTOR PANEL - ID: %d]\n", id);
        printf("1. View My Appointments\n");
        printf("2. Prescribe Medicine\n");
        printf("3. Return to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                viewDoctorAppointments(id);
                break;
            case 2:
                prescribeMedicine(id);
                break;
            case 3:
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}

void patientMenu() {
    int choice;
    while(1) {
        printf("\n[PATIENT PANEL]\n");
        printf("1. Register\n");
        printf("2. Book Appointment\n");
        printf("3. View Bill\n");
        printf("4. Return to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addPatient();
                break;
            case 2:
                bookAppointment();
                break;
            case 3:
                viewPatientBill();
                break;
            case 4:
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}

void addDoctor() {
    if (doctorCount >= 100) {
        printf("Maximum doctor capacity reached!\n");
        return;
    }

    Doctor d;
    printf("\nEnter Doctor Details:\n");
    d.id = 1000 + doctorCount; // Auto-generated ID

    printf("Name: ");
    scanf(" %[^\n]", d.name);

    printf("Specialization: ");
    scanf(" %[^\n]", d.specialization);

    printf("Contact Number: ");
    scanf(" %s", d.contact);

    doctors[doctorCount++] = d;
    printf("Doctor added successfully! ID: %d\n", d.id);
}

void viewDoctors() {
    printf("\n%-5s %-20s %-20s %-15s\n", "ID", "Name", "Specialization", "Contact");
    printf("----------------------------------------------------\n");

    for (int i = 0; i < doctorCount; i++) {
        printf("%-5d %-20s %-20s %-15s\n",
               doctors[i].id, doctors[i].name,
               doctors[i].specialization, doctors[i].contact);
    }

    printf("\nTotal Doctors: %d\n", doctorCount);
}

void addPatient() {
    if (patientCount >= 1000) {
        printf("Maximum patient capacity reached!\n");
        return;
    }

    Patient p;
    printf("\nEnter Patient Details:\n");
    p.id = 2000 + patientCount; // Auto-generated ID

    printf("Name: ");
    scanf(" %[^\n]", p.name);

    printf("Age: ");
    scanf("%d", &p.age);

    printf("Gender (M/F/O): ");
    scanf(" %c", &p.gender);

    printf("Contact Number: ");
    scanf(" %s", p.contact);

    printf("Medical History: ");
    scanf(" %[^\n]", p.medicalHistory);

    patients[patientCount++] = p;
    printf("Patient added successfully! ID: %d\n", p.id);
}

void viewPatients() {
    printf("\n%-5s %-20s %-5s %-5s %-15s\n", "ID", "Name", "Age", "Gen", "Contact");
    printf("------------------------------------------------\n");

    for (int i = 0; i < patientCount; i++) {
        printf("%-5d %-20s %-5d %-5c %-15s\n",
               patients[i].id, patients[i].name,
               patients[i].age, patients[i].gender, patients[i].contact);
    }

    printf("\nTotal Patients: %d\n", patientCount);
}
void bookAppointment() {
    if (appointmentCount >= 500) {
        printf("Maximum appointments reached!\n");
        return;
    }

    Appointment a;
    int patientId, doctorId;
    int patientFound = 0, doctorFound = 0;

    printf("\nEnter Patient ID: ");
    scanf("%d", &patientId);

    // Check patient exists
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == patientId) {
            patientFound = 1;
            break;
        }
    }

    if (!patientFound) {
        printf("Patient ID not found!\n");
        return;
    }

    viewDoctors();
    printf("\nEnter Doctor ID: ");
    scanf("%d", &doctorId);

    // Check doctor exists
    for (int i = 0; i < doctorCount; i++) {
        if (doctors[i].id == doctorId) {
            doctorFound = 1;
            break;
        }
    }

    if (!doctorFound) {
        printf("Doctor ID not found!\n");
        return;
    }

    a.appointmentId = 3000 + appointmentCount;
    a.patientId = patientId;
    a.doctorId = doctorId;

    printf("Enter Date (DD-MM-YYYY): ");
    scanf(" %s", a.date);

    printf("Enter Time (HH:MM): ");
    scanf(" %s", a.time);

    strcpy(a.status, "Scheduled");

    appointments[appointmentCount++] = a;
    printf("Appointment booked successfully! ID: %d\n", a.appointmentId);
}

void viewAppointments() {
    printf("\n%-10s %-10s %-10s %-12s %-8s %-12s\n",
           "Appt ID", "Patient", "Doctor", "Date", "Time", "Status");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < appointmentCount; i++) {
        printf("%-10d %-10d %-10d %-12s %-8s %-12s\n",
               appointments[i].appointmentId,
               appointments[i].patientId,
               appointments[i].doctorId,
               appointments[i].date,
               appointments[i].time,
               appointments[i].status);
    }

    printf("\nTotal Appointments: %d\n", appointmentCount);
}

void viewDoctorAppointments(int doctorId) {
    printf("\nYour Appointments:\n");
    printf("%-10s %-10s %-12s %-8s %-12s\n",
           "Appt ID", "Patient", "Date", "Time", "Status");
    printf("------------------------------------------------\n");

    for (int i = 0; i < appointmentCount; i++) {
        if (appointments[i].doctorId == doctorId) {
            printf("%-10d %-10d %-12s %-8s %-12s\n",
                   appointments[i].appointmentId,
                   appointments[i].patientId,
                   appointments[i].date,
                   appointments[i].time,
                   appointments[i].status);
        }
    }
}

void prescribeMedicine(int doctorId) {
    int appointmentId;
    char medicine[100], dosage[50];

    printf("\nEnter Appointment ID to prescribe for: ");
    scanf("%d", &appointmentId);

    int found = 0;
    for (int i = 0; i < appointmentCount; i++) {
        if (appointments[i].appointmentId == appointmentId &&
            appointments[i].doctorId == doctorId) {
            found = 1;

            printf("Enter Medicine Name: ");
            scanf(" %[^\n]", medicine);

            printf("Enter Dosage: ");
            scanf(" %[^\n]", dosage);

            // In a real system, you would save this prescription
            printf("\nPrescription created for Appointment %d:\n", appointmentId);
            printf("Medicine: %s\n", medicine);
            printf("Dosage: %s\n", dosage);

            // Mark appointment as completed
            strcpy(appointments[i].status, "Completed");

            // Generate a bill automatically
            generateBill(appointments[i].patientId, 500.0); // Sample amount
            break;
        }
    }

    if (!found) {
        printf("Appointment not found or not assigned to you!\n");
    }
}

void generateBill(int patientId, float amount) {
    if (billCount >= 500) {
        printf("Cannot generate more bills!\n");
        return;
    }

    Bill b;
    b.billId = 4000 + billCount;
    b.patientId = patientId;
    b.amount = amount;

    // Get current date
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(b.date, "%02d-%02d-%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    strcpy(b.status, "Unpaid");

    bills[billCount++] = b;
    printf("Bill generated successfully! ID: %d, Amount: %.2f\n", b.billId, b.amount);
}

void viewBills() {
    printf("\n%-8s %-10s %-10s %-12s %-10s\n",
           "Bill ID", "Patient", "Amount", "Date", "Status");
    printf("------------------------------------------------\n");

    for (int i = 0; i < billCount; i++) {
        printf("%-8d %-10d %-10.2f %-12s %-10s\n",
               bills[i].billId,
               bills[i].patientId,
               bills[i].amount,
               bills[i].date,
               bills[i].status);
    }
}

void viewPatientBill() {
    int patientId;
    printf("\nEnter your Patient ID: ");
    scanf("%d", &patientId);

    printf("\nYour Bills:\n");
    printf("%-8s %-10s %-12s %-10s\n", "Bill ID", "Amount", "Date", "Status");
    printf("----------------------------------------\n");

    int found = 0;
    for (int i = 0; i < billCount; i++) {
        if (bills[i].patientId == patientId) {
            printf("%-8d %-10.2f %-12s %-10s\n",
                   bills[i].billId,
                   bills[i].amount,
                   bills[i].date,
                   bills[i].status);
            found = 1;
        }
    }

    if (!found) {
        printf("No bills found for this patient.\n");
    }
}


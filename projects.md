# PROJECT PROPOSAL

## GENERAL INFORMATION
1. **Name of the Institution:** Greenwood Institute of Technology
2. **Project Title:** Hospital Management System (HMS v1.0)
3. **Team Members (with Roll Numbers):**
   - Priya Sharma (CSE/20/074)
   - Aarav Mehta (CSE/20/051)
   - Neha Kulkarni (CSE/20/089)

## APPROVAL CERTIFICATE
This is to certify that the project proposal entitled "Hospital Management System (HMS v1.0)" submitted by Priya Sharma, Aarav Mehta, and Neha Kulkarni of Greenwood Institute of Technology has been reviewed and is hereby approved for fulfillment of the partial requirements of the Bachelor of Technology (Computer Science & Engineering) final year project. The students are authorized to proceed with the scope of work as detailed in this document under the supervision of Prof. K. R. Iyer.

---

## PROJECT DETAILS

### Project Title
Hospital Management System (HMS v1.0)

### Executive Summary
The Hospital Management System (HMS v1.0) is a lightweight, menu-driven C application designed to digitize essential operations of a mid-sized clinic. The system manages doctor profiles, patient records, appointment scheduling, and billing in a single interface, with persistent storage handled through structured flat files. The project demonstrates how even small healthcare facilities can streamline administrative workflows, maintain consistent records, and reduce manual errors without investing in expensive proprietary software.

### Background
India's Tier-II cities continue to experience rapid population growth while public healthcare infrastructure remains stretched. Many private clinics still rely on paper-based registers that are error-prone, hard to audit, and vulnerable to loss. Digitizing routine processes—such as patient registration, appointment allocation, and billing—improves efficiency, data reliability, and patient satisfaction. The HMS v1.0 focuses on the workflow of a typical urban clinic serving a mixed socio-economic demographic, aiming to make digital record-keeping accessible at minimal cost.

### Literature Review
- Ahmed, S., & Rao, B. (2021). *Design of Lightweight Hospital Management Systems for Rural Clinics*. Journal of Healthcare Informatics, 9(2), 55-62.
- Bansal, R. (2020). *Comparative Study of Electronic Medical Record Implementations in Small Practices*. International Journal of Medical Systems, 14(3), 101-109.
- Existing open-source HMS solutions (OpenMRS, HospitalRun) were reviewed to understand architectural choices, complexity levels, and hardware demands. The project narrows the feature set to core administrative functions so that it remains deployable on basic desktop hardware without network dependencies.

### Scope of the Work
- Implement a console-based interface for three user roles: Admin, Doctor, and Patient.
- Provide CRUD (Create, Read, Update, Delete) operations for doctors and patients.
- Allow patients to self-register and book appointments with available doctors.
- Enable doctors to review their schedules, record prescriptions, and auto-trigger billing.
- Persist records to plain-text files to support offline usage and easy backups.

### Project Objectives
- **Digital Records:** Maintain structured doctor, patient, appointment, and billing records (Measurable: ≥100 doctors, ≥1000 patients, ≥500 appointments supported).
- **Role-based Access:** Separate admin, doctor, and patient workflows to avoid accidental data modification (Realistic completion by mid-term evaluation).
- **Operational Efficiency:** Reduce appointment booking and billing time by at least 40% compared to manual registers (Simple observation-based study during trials).
- **Deployment Readiness:** Deliver an executable and documentation that can be deployed on Windows and Linux systems by April 2026 (Time Bound).

### Feasibility Study
- **Cost:** Uses free and open-source tools (GCC/Clang). Existing lab computers suffice.
- **Technology & Equipment:** Implemented in ANSI C with standard libraries—no proprietary dependencies.
- **Academic Knowledge:** Aligns with curriculum topics (Data Structures, File Handling, Software Engineering).
- **Time:** Six-month timeline with weekly milestones; considered achievable within two academic semesters.

### Methodology
1. **Requirement Gathering:** Interviews with local clinic staff to understand day-to-day tasks and pain points.
2. **System Design:** Drafted flow diagrams for each user role; defined data structures for storage.
3. **Implementation:** Built modules iteratively (doctor management, patient management, appointment scheduling, billing) using modular C functions.
4. **Testing:** Performed unit testing for critical functions and scenario-based testing for end-to-end workflows.
5. **Evaluation:** Gathered feedback from mock users; refined data validation and reporting features.
6. **Documentation:** Prepared user manual, installation guide, and final presentation.

Anticipated issues such as inconsistent data entry are mitigated with input validation and auto-generated IDs. File corruption risks are reduced with periodic backups and defensive programming (e.g., array bounds checks).

### Limitations
- Console interface limits accessibility for non-technical staff.
- Lacks integration with diagnostic or pharmacy modules.
- No built-in network synchronization; runs on a single machine.
- Billing module does not currently process payments or receipts.

### Project Schedule

| Phase | Tasks | Duration (Weeks) | Timeframe |
| --- | --- | --- | --- |
| Requirement Analysis | Stakeholder interviews, finalize scope | 2 | Jan 6 – Jan 19, 2026 |
| System Design | Data modeling, interface mock-ups | 2 | Jan 20 – Feb 2, 2026 |
| Implementation Cycle I | Doctor & patient modules | 3 | Feb 3 – Feb 23, 2026 |
| Implementation Cycle II | Appointments & billing modules | 3 | Feb 24 – Mar 16, 2026 |
| Testing & Validation | Unit tests, user walkthroughs | 2 | Mar 17 – Mar 30, 2026 |
| Documentation & Presentation | Report, slides, rehearsal | 2 | Mar 31 – Apr 13, 2026 |

*Gantt-style representation is provided in Appendix A of the final report for visual tracking.*

### Conclusion
The Hospital Management System (HMS v1.0) aims to demonstrate how structured software engineering practices can transform routine healthcare administration. By focusing on realistic constraints—offline operation, limited hardware, and basic training—the project delivers a deployable solution suitable for small clinics. Completion of this project will not only benefit local healthcare providers but also strengthen the team’s proficiency in designing and implementing real-world software solutions.


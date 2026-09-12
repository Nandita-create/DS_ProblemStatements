/* -----------------------------
   SAMPLE DATA
----------------------------- */
const API_URL = "http://localhost:8080";

async function testBackend() {

    try {

        const response = await fetch(`${API_URL}/api/test`);

        const data = await response.text();

        console.log(data);

        document.getElementById("backendStatus").innerText = data;

    } catch (error) {

        console.error(error);

        document.getElementById("backendStatus").innerText =
            "Backend not connected";

    }
}

testBackend();

let patients = [
    {
        patientID: 101,
        name: "Rahul Sharma",
        age: 35,
        gender: "Male",
        bloodGroup: "B+",
        department: "Cardiology",
        doctorID: 501
    },

    {
        patientID: 102,
        name: "Priya Patil",
        age: 28,
        gender: "Female",
        bloodGroup: "O+",
        department: "Neurology",
        doctorID: 502
    },

    {
        patientID: 103,
        name: "Amit Joshi",
        age: 45,
        gender: "Male",
        bloodGroup: "A+",
        department: "Orthopedics",
        doctorID: 503
    }
];


let appointments = [
    {
        appointmentID: 1,
        patientID: 101,
        doctorID: 501,
        time: "10:00 AM"
    },

    {
        appointmentID: 2,
        patientID: 102,
        doctorID: 502,
        time: "10:30 AM"
    }
];


let emergencyPatients = [

    {
        patientID: 103,
        severity: 5,
        arrivalTime: 9
    },

    {
        patientID: 102,
        severity: 3,
        arrivalTime: 10
    }

];


/* -----------------------------
   NAVIGATION
----------------------------- */

function showSection(sectionID) {

    let sections =
        document.querySelectorAll(".section");

    sections.forEach(section => {
        section.classList.remove("active");
    });

    document
        .getElementById(sectionID)
        .classList.add("active");

    if (sectionID === "patients")
        loadPatients();

    if (sectionID === "appointments")
        loadAppointments();

    if (sectionID === "emergency")
        loadEmergency();

    if (sectionID === "dashboard")
        loadDashboard();
}


/* -----------------------------
   PATIENT MANAGEMENT
----------------------------- */

function loadPatients() {

    let table =
        document.getElementById("patientTable");

    table.innerHTML = "";

    patients.forEach(patient => {

        let row = `
            <tr>
                <td>${patient.patientID}</td>
                <td>${patient.name}</td>
                <td>${patient.age}</td>
                <td>${patient.gender}</td>
                <td>${patient.bloodGroup}</td>
                <td>${patient.department}</td>
                <td>${patient.doctorID}</td>
            </tr>
        `;

        table.innerHTML += row;
    });

    document.getElementById("patientCount")
        .innerText = patients.length;
}


function searchPatient() {

    let id =
        Number(document.getElementById("patientSearch").value);

    let patient =
        patients.find(p => p.patientID === id);

    let table =
        document.getElementById("patientTable");

    table.innerHTML = "";

    if (!patient) {

        table.innerHTML = `
            <tr>
                <td colspan="7">
                    Patient not found.
                </td>
            </tr>
        `;

        return;
    }

    table.innerHTML = `
        <tr>
            <td>${patient.patientID}</td>
            <td>${patient.name}</td>
            <td>${patient.age}</td>
            <td>${patient.gender}</td>
            <td>${patient.bloodGroup}</td>
            <td>${patient.department}</td>
            <td>${patient.doctorID}</td>
        </tr>
    `;
}


/* -----------------------------
   ADD PATIENT
----------------------------- */

function openPatientForm() {

    document.getElementById("patientModal")
        .style.display = "flex";
}


function closePatientForm() {

    document.getElementById("patientModal")
        .style.display = "none";
}


function addPatient(event) {

    event.preventDefault();

    let patient = {

        patientID:
            Number(
                document.getElementById("newPatientID").value
            ),

        name:
            document.getElementById("newPatientName").value,

        age:
            Number(
                document.getElementById("newPatientAge").value
            ),

        gender:
            document.getElementById("newPatientGender").value,

        bloodGroup:
            document.getElementById("newPatientBlood").value,

        department:
            document.getElementById("newPatientDepartment").value,

        doctorID:
            Number(
                document.getElementById("newPatientDoctor").value
            )
    };


    patients.push(patient);

    closePatientForm();

    document.querySelector("form").reset();

    loadPatients();

    alert("Patient added successfully.");
}


/* -----------------------------
   OPD QUEUE
----------------------------- */

function loadAppointments() {

    let container =
        document.getElementById("appointmentQueue");

    container.innerHTML = "";

    appointments.forEach((appointment, index) => {

        container.innerHTML += `

            <div class="queue-item">

                <div>

                    <strong>
                        Patient ID:
                        ${appointment.patientID}
                    </strong>

                    Appointment:
                    ${appointment.appointmentID}

                </div>

                <div>

                    Doctor:
                    ${appointment.doctorID}

                    <br>

                    ${appointment.time}

                </div>

            </div>

        `;
    });


    document.getElementById("queueCount")
        .innerText = appointments.length;


    if (appointments.length > 0) {

        document.getElementById("nextPatient")
            .innerText =
            appointments[0].patientID;

    } else {

        document.getElementById("nextPatient")
            .innerText = "-";
    }
}


function attendAppointment() {

    if (appointments.length === 0) {

        alert("OPD queue is empty.");

        return;
    }

    let appointment =
        appointments.shift();

    alert(
        "Attending Patient ID: "
        + appointment.patientID
    );

    loadAppointments();
}


function addAppointment() {

    let patientID =
        Number(
            prompt("Enter Patient ID:")
        );

    if (!patientID)
        return;


    let appointment = {

        appointmentID:
            appointments.length + 1,

        patientID:
            patientID,

        doctorID:
            501,

        time:
            "11:00 AM"
    };


    appointments.push(appointment);

    loadAppointments();
}


/* -----------------------------
   EMERGENCY QUEUE
----------------------------- */

function loadEmergency() {

    let container =
        document.getElementById("emergencyQueue");

    container.innerHTML = "";


    /*
       Sort according to severity.

       This is currently being done
       by JavaScript only for UI.

       Later this will be handled
       by your C++ EmergencyQueue.
    */

    emergencyPatients.sort(
        (a, b) => b.severity - a.severity
    );


    emergencyPatients.forEach(patient => {

        container.innerHTML += `

            <div class="queue-item">

                <div>

                    <strong>
                        Patient ID:
                        ${patient.patientID}
                    </strong>

                    Arrival:
                    ${patient.arrivalTime}

                </div>

                <div>

                    Severity:
                    <strong>
                        ${patient.severity}
                    </strong>

                </div>

            </div>

        `;
    });


    document.getElementById("emergencyCount")
        .innerText = emergencyPatients.length;
}


function treatEmergency() {

    if (emergencyPatients.length === 0) {

        alert("Emergency queue is empty.");

        return;
    }


    let patient =
        emergencyPatients.shift();


    alert(
        "Treating Patient ID: "
        + patient.patientID
        + "\nSeverity: "
        + patient.severity
    );


    loadEmergency();
}


function addEmergency() {

    let patientID =
        Number(
            prompt("Enter Patient ID:")
        );

    if (!patientID)
        return;


    let severity =
        Number(
            prompt("Enter severity (1-5):")
        );


    if (severity < 1 || severity > 5) {

        alert("Severity must be between 1 and 5.");

        return;
    }


    emergencyPatients.push({

        patientID: patientID,

        severity: severity,

        arrivalTime:
            new Date().getHours()

    });


    loadEmergency();
}


/* -----------------------------
   MEDICAL HISTORY
----------------------------- */

function showHistory() {

    let patientID =
        Number(
            document.getElementById(
                "historyPatientID"
            ).value
        );


    let patient =
        patients.find(
            p => p.patientID === patientID
        );


    let container =
        document.getElementById(
            "historyContainer"
        );


    if (!patient) {

        container.innerHTML = `
            <p class="empty-message">
                Patient not found.
            </p>
        `;

        return;
    }


    /*
       Temporary sample records.

       Later these will come
       from MedicalHistory in C++.
    */

    container.innerHTML = `

        <div class="queue-item">

            <div>

                <strong>
                    05 September 2026
                </strong>

                Diagnosis:
                Fever

                <br>

                Prescription:
                Paracetamol

            </div>

            <div>
                Doctor ID: ${patient.doctorID}
            </div>

        </div>


        <div class="queue-item">

            <div>

                <strong>
                    20 August 2026
                </strong>

                Diagnosis:
                Routine Checkup

                <br>

                Prescription:
                None

            </div>

            <div>
                Doctor ID: ${patient.doctorID}
            </div>

        </div>

    `;
}


/* -----------------------------
   DASHBOARD
----------------------------- */

function loadDashboard() {

    document.getElementById("patientCount")
        .innerText = patients.length;

    document.getElementById("appointmentCount")
        .innerText = appointments.length;

    document.getElementById("emergencyCount")
        .innerText = emergencyPatients.length;


    let table =
        document.getElementById("recentPatients");

    table.innerHTML = "";


    patients.slice(0, 5).forEach(patient => {

        table.innerHTML += `

            <tr>

                <td>${patient.patientID}</td>

                <td>${patient.name}</td>

                <td>${patient.department}</td>

                <td>${patient.doctorID}</td>

            </tr>

        `;
    });


    let emergency =
        document.getElementById(
            "dashboardEmergency"
        );

    emergency.innerHTML = "";


    emergencyPatients
        .slice()
        .sort(
            (a, b) =>
                b.severity - a.severity
        )
        .forEach(patient => {

            emergency.innerHTML += `

                <div class="queue-item">

                    <strong>
                        Patient ${patient.patientID}
                    </strong>

                    <span>
                        Severity ${patient.severity}
                    </span>

                </div>

            `;
        });
}


/* -----------------------------
   INITIAL LOAD
----------------------------- */

loadDashboard();
loadPatients();
loadAppointments();
loadEmergency();
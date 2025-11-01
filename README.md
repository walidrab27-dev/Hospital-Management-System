# 🏥 Hospital Management System

A simple yet powerful **Hospital Management System** built in **C++**, implementing **Object-Oriented Programming (OOP)** principles such as encapsulation, abstraction, and modular design.  
It allows managing patients, doctors, and their relationships — with data persistence using text files.

---

## 🛠️ Badges

![Build](https://img.shields.io/badge/build-passing-brightgreen?style=flat-square)
![Language](https://img.shields.io/badge/language-C++17-blue?style=flat-square)
![License](https://img.shields.io/badge/license-MIT-yellow?style=flat-square)
![Status](https://img.shields.io/badge/status-active-success?style=flat-square)
![Contributions](https://img.shields.io/badge/contributions-welcome-orange?style=flat-square)

---

## 🚀 Features

✅ **Add New Patients**  
✅ **Display All Patients**  
✅ **Search for Patients** by name or ID  
✅ **Assign Doctors** to Patients  
✅ **Delete Patient Records**  
✅ **Save & Load Data** automatically (from `patients.txt` and `doctors.txt`)  
✅ **Colorful Console Output** for better readability  

---

## 🧠 Object-Oriented Design

| Class | Responsibility |
|--------|----------------|
| `Patient` | Stores patient info (ID, name, age, gender, disease, assigned doctor) |
| `Doctor` | Stores doctor info (ID, name, specialty, age) |
| `HospitalSystem` | Core manager that handles all CRUD operations and data persistence |

---

## 🗂️ Project Structure

```
HospitalSystem/
│
├── main.cpp
├── Patient.h
├── Patient.cpp
├── Doctor.h
├── Doctor.cpp
├── HospitalSystem.h
├── HospitalSystem.cpp
├── patients.txt
├── doctors.txt
└── README.md
```

---

## 💻 How to Run

### ▶️ Using g++
```bash
g++ main.cpp Patient.cpp Doctor.cpp HospitalSystem.cpp -o hospital
./hospital
```

### 🧱 Using Code::Blocks / Visual Studio
1. Create a new C++ project  
2. Add all `.cpp` and `.h` files  
3. Build and run the project  

---

## 🎨 Console Colors

The system uses **ANSI Escape Codes** for colorful outputs:

```cpp
cout << "\033[1;32mPatient added successfully!\033[0m\n";  // Green (Success)
cout << "\033[1;31mPatient deleted!\033[0m\n";             // Red (Delete)
cout << "\033[1;36mData saved successfully!\033[0m\n";     // Cyan (Info)
```

> Works perfectly on Linux, macOS, and modern Windows terminals.

---

## 🧩 Future Improvements

- 🕓 **Appointments System** (schedule doctor–patient meetings)  
- 💰 **Billing System** (track payments)  
- 🔐 **Admin Authentication**  
- 🧾 **CSV / Database Integration** (replace text files)  
- 🖥️ **Graphical User Interface (Qt or C#)**  
<!-- --- -->
## 🤝 Contributing

Contributions are always welcome!  
If you'd like to improve the project:

1. **Fork** this repository  
2. **Create a new branch** (`git checkout -b feature/new-feature`)  
3. **Commit your changes** (`git commit -m 'Add a new feature'`)  
4. **Push to your branch** (`git push origin feature/new-feature`)  
5. **Open a Pull Request**
> 💡 Make sure to follow clean code principles and comment your changes clearly.

## 👨‍💻 Author

**Walid Rabei**  
💼 *Computer Science Student / C++ Developer*  
📧 walidrab27@gmail.com  
🌐 [[https://github.com/walidrab27-dev]](https://github.com/walidrab27-dev)

---

## 🏗️ Technologies Used
- **C++17**
- **OOP Principles**
- **File Handling (fstream)**
- **Vectors & Classes**
- **ANSI Color Codes**

---

## 🪄 License
This project is open-source under the **MIT License**.  
Feel free to fork, modify, and improve it!  

---

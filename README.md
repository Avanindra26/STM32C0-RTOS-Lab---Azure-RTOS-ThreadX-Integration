# STM32C0 RTOS Lab – Azure RTOS ThreadX Integration
This project is based STM32C0, where I integrated Azure RTOS ThreadX into an STM32 project using STM32CubeIDE. The goal is to introduce real-time multithreading with ThreadX on STM32C0 microcontrollers.



________________________________________
🔷 STM32C0 RTOS Lab – Azure RTOS ThreadX Integration
This project is based on Lab 08 of the STM32C0 Workshop series, where I demonstrate how to integrate Azure RTOS ThreadX into an STM32 project using STM32CubeIDE. The goal is to introduce real-time multithreading with ThreadX on STM32C0 microcontrollers.
🎥 Video Tutorial: Watch on YouTube
________________________________________
✨ Key Features
•	🧵 Integration of Azure RTOS ThreadX (via STM32CubeMX)
•	🔁 Multiple threads (tasks) running concurrently
•	🔦 LED blinking using ThreadX thread and sleep API
•	🎯 Real-time thread scheduling and cooperative multitasking
•	💡 Clean starting point for building ThreadX-based applications
________________________________________
📁 Project Structure
STM32C0_ThreadX_Lab/
├── Core/
│   ├── Inc/
│   │   ├── main.h
│   │   └── app_threadx.h...
│   └── Src/
│       ├── main.c
│       ├── app_threadx.c
│     
├── ThreadX/
│   ├── tx_user.h
│   └── tx_initialize_low_level.S
├── Drivers/
│   └── ...
├── STM32C0_ThreadX_Lab.ioc
├── .project
├── .cproject
└── README.md
________________________________________
🛠️ Requirements
✅ Hardware
•	STM32C0 board (e.g., NUCLEO-C031C6)
✅ Software
•	STM32CubeIDE
•	STM32CubeMX
•	STM32Cube MCU Package for STM32C0 Series
•	Azure RTOS ThreadX middleware (enabled via CubeMX)
________________________________________
🚀 Getting Started
1.	Clone this repository:
2.	Open the .ioc file in STM32CubeIDE to load the project configuration.
3.	Build the project inside CubeIDE.
4.	Connect your STM32C0 board via USB (ST-Link).
5.	Flash and run the application. The LED should blink using the ThreadX thread.________________________________________
📊 Debugging & Analysis
•	Enable RTOS-aware debugging in STM32CubeIDE.
•	Use breakpoints inside threads to observe task switching.
•	Monitor CPU load and stack usage for each thread.
•	ThreadX is deterministic—useful for real-time applications like motor control, sensing, etc.
________________________________________
📚 Resources
•	Azure RTOS ThreadX Documentation
•	STM32CubeIDE
•	STM32C0 Series Overview
•	ThreadX on GitHub
________________________________________
🛡 License
This project is licensed under the MIT License. See the LICENSE file for details.
________________________________________
🤝 Contributing
Feel free to fork this project, experiment with other ThreadX features (e.g., message queues, mutexes), and open pull requests. Contributions are welcome!


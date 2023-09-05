<h1 align="center">Hi 👋, I'm Osama Moussa</h1>
<h3 align="center">A passionate Embedded developer from Egypt</h3>

- 📫 How to reach me **osama.yassin.moussa@gmail.com**

<h3 align="left">Connect with me:</h3>
<p align="left">
<a href="https://linkedin.com/in/https://www.linkedin.com/in/osama-moussa-b9b175187/" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/linked-in-alt.svg" alt="https://www.linkedin.com/in/osama-moussa-b9b175187/" height="30" width="40" /></a>
</p>

<h3 align="left">Languages and Tools:</h3>
<p align="left"> <a href="https://www.cprogramming.com/" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/c/c-original.svg" alt="c" width="40" height="40"/> </a> <a href="https://www.w3schools.com/cpp/" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/cplusplus/cplusplus-original.svg" alt="cplusplus" width="40" height="40"/> </a> <a href="https://www.python.org" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/python/python-original.svg" alt="python" width="40" height="40"/> </a> <a href="https://www.qt.io/" target="_blank" rel="noreferrer"> <img src="https://upload.wikimedia.org/wikipedia/commons/0/0b/Qt_logo_2016.svg" alt="qt" width="40" height="40"/> </a> </p>

# Smart_Home_Project_Version_2 
A modified Version of Smart_Home_Project(https://github.com/OsamaMoussa/Smart_Home_Project.git)<br><br>
The Project Consists of two Atmega32 Microcontrollers one in a Control Room that Receives commands from a mobile device via Bluetooth and transmits these commands to the other Microcontroller which is located in a Smart Room via SPI communication protocol and shows the commands on a LCD. The Atmega32 located in the smart room controls the Light, the Fan, and the Door of the room an reads the Temperature of the Room and shows it on the LCD.<br><br>
In this Version the Room Controller can send data back to the control room and can be shown on the Control room LCD. For Example the temperature sensed in room_1 can be shown on the LCDs of both the room and the control room.<br><br>
Also The Fan's Motor in this Version is Controlled by Timer2, and the Door's Servo is controled by Timer1 (The motor and the servo in the previous Version were both controlled by Timer1 which caused some issues).  

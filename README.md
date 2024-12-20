# Cul-de-Sac Crook

## Introduction

**Cul-de-Sac Crook** is a simulation game built to model a neighborhood and the activities of its residents. Users can engage in a variety of actions, from exploring the neighborhood and tracking residents to committing robberies and evading capture. The project leverages core data structures and algorithms to provide a functional, interactive experience with features like movement monitoring, crime detection, and leaderboards.

---

## Features

### 1. **Neighborhood Map Representation**

- Represents the neighborhood as a graph with nodes for houses and paths as edges.
- File handling is used to load graph data.
- Tracks traversal and resident locations.

### 2. **Resident Tracking**

- Tracks residents using queues and their predefined routes.
- Logs financial statuses and recent movements.

### 3. **Movement Monitoring**

- Observes deviations from usual resident routes.
- Generates alerts for suspicious behavior.

### 4. **Alert System**

- Maintains a stack of recent unresolved alerts.
- Pushes alerts with details such as location, incident type, and residents involved.

### 5. **Crime Detection**

- Detects and logs robbery incidents.
- Tracks stolen wealth and flags frequent or unusual activities.

### 6. **User Interaction**

- Allows users to control residents’ movements and commit crimes.
- Monitors actions and provides notifications.

### 7. **Diary**

- Enables users to document notes on houses and residents.
- Updates dynamically during gameplay.

### 8. **Escape System**

- Engages users in a typing-based minigame to evade capture.

### 9. **Leaderboard**

- Tracks top players by loot level.
- Uses file handling for persistence across sessions.

---

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/Cul-de-Sac-Crook.git
   ```
2. Navigate to the project directory:
   ```bash
   cd Cul-de-Sac-Crook
   ```
3. Run the main script:
   ```bash
   g++ main.cpp -o main -lwinmm
   ./main
   ```

---

## Usage

### Starting the Game

- Run the main script to load the neighborhood map and initialize the system.
- Create a new user or select an existing one.

### Core Gameplay

- **Explore the Neighborhood:** Navigate through nodes representing houses and locations.
- **Track Residents:** Observe and log resident movements.
- **Commit Crimes:** Rob houses based on weapon levels and planned targets.
- **Evade Capture:** Complete typing challenges to escape the police.
- **Track Progress:** View your loot level and rank on the leaderboard.

---

## Technical Details

### **Data Structures Used**

| Feature             | Data Structure      | Complexity |
| ------------------- | ------------------- | ---------- |
| Neighborhood Map    | Graph               | O(V + E)   |
| Resident Tracking   | Queue (Linked List) | O(n)       |
| Movement Monitoring | Queue               | O(n)       |
| Alert System        | Stack               | O(n^2)     |
| Crime Detection     | Arrays, AVL Trees   | O(log n)   |
| Leaderboard         | Hashmaps            | O(1)       |
| Diary               | Linked List         | O(n)       |
| Escape System       | Typing Minigame     | O(1)       |

---

## Contributing

We welcome contributions to improve Cul-de-Sac Crook! To contribute:

1. Fork the repository.
2. Create a new branch:
   ```bash
   git checkout -b feature-name
   ```
3. Commit your changes:
   ```bash
   git commit -m "Add your message here"
   ```
4. Push to your fork:
   ```bash
   git push origin feature-name
   ```
5. Open a pull request on GitHub.

---

## License

This project is licensed under the [MIT License](LICENSE).

---

## Authors

- **Abdullah Ejaz Janjua** (2023038)
- **Muhammad Ahmad Amjad** (2023361)

---

Enjoy playing **Cul-de-Sac Crook** and feel free to contribute or report any issues!


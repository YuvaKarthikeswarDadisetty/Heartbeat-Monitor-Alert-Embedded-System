# Quick Start

## If you only want to reproduce the validated project

1. Open Wokwi.
2. Open the project:
   https://wokwi.com/projects/472602638056250369
3. Verify the circuit and run it.
4. Use `simulation/HeartbeatMonitor_Wokwi.ino`.
5. Test:
   - 75.0 → NORMAL
   - 40.0 → LOW
   - 120.0 → HIGH
6. Keep the screenshots in `screenshots/`.

## GitHub

After verifying the repository:

```bash
git init
git add .
git commit -m "Initialize Wokwi heartbeat monitor project"
git branch -M main
git remote add origin https://github.com/YOUR_USERNAME/Heartbeat-Monitor-Alert-Embedded-System.git
git push -u origin main
```

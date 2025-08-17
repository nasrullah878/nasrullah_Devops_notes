import cv2
import time
import os

# Load Haar Cascade face detector from OpenCV
face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + "haarcascade_frontalface_default.xml")

# Open webcam
cap = cv2.VideoCapture(0)

if not cap.isOpened():
    print("Cannot access webcam.")
    exit()

# Timer for face absence
face_missing_start = None
shutdown_threshold = 15  # seconds

print("✅ Monitoring... (will shutdown if no face is detected for 15 seconds)")

try:
    while True:
        ret, frame = cap.read()
        if not ret:
            break

        # Convert to grayscale
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

        # Detect faces
        faces = face_cascade.detectMultiScale(gray, 1.1, 4)

        if len(faces) > 0:
            # Face detected
            print("👤 Face detected.")
            face_missing_start = None  # reset timer
        else:
            # No face detected
            if face_missing_start is None:
                face_missing_start = time.time()
            else:
                elapsed = time.time() - face_missing_start
                print(f"⏳ No face for {int(elapsed)}s...")
                if elapsed >= shutdown_threshold:
                    print("❌ Face not detected. Shutting down...")
                    os.system("sudo shutdown -h now")
                    break

        # Wait a short time before next check
        time.sleep(1)

except KeyboardInterrupt:
    print("⏹️ Script interrupted.")

finally:
    cap.release()
    cv2.destroyAllWindows()

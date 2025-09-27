import cv2
import numpy as np
import time

def detect_motion(prev_frame, frame, motion_interval, lights_change_time, red_light):
    gray_prev_frame = cv2.cvtColor(prev_frame, cv2.COLOR_BGR2GRAY)
    gray_prev_frame = cv2.GaussianBlur(gray_prev_frame, (21, 21), 0)

    gray_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    gray_frame = cv2.GaussianBlur(gray_frame, (21, 21), 0)

    frame_diff = cv2.absdiff(gray_prev_frame, gray_frame)
    
    _, thresh = cv2.threshold(frame_diff, 30, 255, cv2.THRESH_BINARY)
    
    kernel = np.ones((5, 5), np.uint8)
    thresh = cv2.dilate(thresh, kernel, iterations=2)


    motions_pixels = np.sum(thresh) // 255
    total_pixels = thresh.size
    motion_ratio = motions_pixels / total_pixels
    
    motion_threshold = 0.001
    current_time = time.time()
    result = frame.copy()

    if current_time - lights_change_time >= motion_interval:
        red_light = True if not red_light else False
        lights_change_time = current_time
        

        

    if red_light:
        cv2.circle(result, (100, 200), 30, (0, 0, 255), -1)

        if motion_ratio > motion_threshold:
            cv2.putText(result, 'MOTION DETECTED', (10, 100), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)
        else:
            cv2.putText(result, 'NO MOTION', (10, 100), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
    else:
        cv2.circle(result, (100, 200), 30, (0, 255, 0), -1)
    return result, red_light, lights_change_time



cap = cv2.VideoCapture(0)

ret, prev_frame = cap.read()
if not ret:
    print("Frame reading error occurs")
    exit()

motion_interval = int(input("Input Lights interval"))

lights_change_time = time.time()
red_light = False


while True:

    ret, frame = cap.read()
    if not ret:
        break

   
    result, red_light, lights_change_time= detect_motion(prev_frame, frame, motion_interval, lights_change_time, red_light)

    cv2.imshow("frame", result)

    
    prev_frame = frame.copy()
    
    

    if(cv2.waitKey(10) == 27):
        break
cv2.destroyAllWindows()
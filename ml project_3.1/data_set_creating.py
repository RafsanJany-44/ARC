#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Sep 16 00:57:15 2020

@author: rafsan
"""

import cv2


def DataSetFor(expression):

    
    with open(expression+".txt",'r') as f:
        images = [line.strip() for line in f]
    for image in images:
        loadedImage = cv2.imread("images/"+image)
        cv2.imwrite("facial_expressions/"+expression+"/"+image,loadedImage)
    print("done writing for"+expression)
    print()
    
    
    face_detector = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
    
    # For each Emotion, enter one numeric face id
    face_id = input('\n Enter Emotion id for '+expression+' end press <return> ==>  ')
    
    count = 0
    
    for image in images:
        img = cv2.imread("facial_expressions/"+expression+"/"+image)
        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        faces = face_detector.detectMultiScale(gray, 1.3, 5)
    
        for (x,y,w,h) in faces:
    
            cv2.rectangle(img, (x,y), (x+w,y+h), (255,0,0), 2)     
            count += 1
    
            # Save the captured image into the datasets folder
            cv2.imwrite("dataset/six_t." + str(face_id) + '.' + str(count) + ".jpg", gray[y:y+h,x:x+w])
    
    print("\n Done creating face data for "+expression)
    print("--------------------------------------------")

DataSetFor("happy")

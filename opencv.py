import cv2
import numpy as np
def nothing(x):
    pass
cap=cv2.VideoCapture(0)
#cv2.namedWindow("Image",cv2.WINDOW_NORMAL)
#cv2.namedWindow("Image_blur",cv2.WINDOW_NORMAL)
cv2.namedWindow("Image_blur_lab",cv2.WINDOW_NORMAL)
#cv2.namedWindow("Image_blur_lab_masked",cv2.WINDOW_NORMAL)
cv2.namedWindow("Image_final",cv2.WINDOW_NORMAL)
cv2.createTrackbar("ll","Image_blur_lab",0,255,nothing)
cv2.createTrackbar("al","Image_blur_lab",0,255,nothing)
cv2.createTrackbar("bl","Image_blur_lab",0,255,nothing)
cv2.createTrackbar("lu","Image_blur_lab",0,255,nothing)
cv2.createTrackbar("au","Image_blur_lab",0,255,nothing)
cv2.createTrackbar("bu","Image_blur_lab",0,255,nothing)
while True:
    __,frame=cap.read()
    #cv2.imshow("Image",frame)
    blur=cv2.GaussianBlur(frame,(21,21),0)
    lab=cv2.cvtColor(blur,cv2.COLOR_BGR2LAB)
    #cv2.imshow("Image_blur",blur)
    ll=cv2.getTrackbarPos("ll","Image_blur_lab")
    al=cv2.getTrackbarPos("al","Image_blur_lab")
    bl=cv2.getTrackbarPos("bl","Image_blur_lab")
    lu=cv2.getTrackbarPos("lu","Image_blur_lab")
    au=cv2.getTrackbarPos("au","Image_blur_lab")
    bu=cv2.getTrackbarPos("bu","Image_blur_lab")
    low_limit=np.array([ll,al,bl],dtype=np.uint8)
    up_limit=np.array([lu,au,bu],dtype=np.uint8)
    mask_binary=cv2.inRange(lab,low_limit,up_limit)
    _,contours,hierarchy=cv2.findContours(mask_binary,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)
    if len(contours)!=0:
        c=max(contours,key=cv2.contourArea)
        M=cv2.moments(c)
        area=M['m00']
        x=M['m10']/area
        y=M['m01']/area
        print(x,y)
        cv2.drawContours(frame,[c],-1,(0,0,255),3)
    #mask_bitand=cv2.bitwise_and(frame,frame,mask=mask_binary)
    cv2.imshow("Image_blur_lab",mask_binary)
    cv2.imshow("Image_final",frame)
    #cv2.imshow("Image_blur_lab_masked",mask_bitand)
    k=cv2.waitKey(1)
    if k==27:
        break
import numpy as np
import cv2 as cv
import os


# //ImageTransform(py) -> core (CPP) OUTPUT -> Build Image(py)


# Extracting image Data to use later
img = cv.imread("images.jpg")
height, width, channels = img.shape
img_list = img.tolist()
print(type(img))
print("Image Dimensions Before Transform",img.ndim)
print(img.shape)
print(f"\n")



# reading cpp transformed image
with open('output.txt', 'r+') as fin:
    data = fin.read().splitlines(True)
    fin.truncate(0)
    fin.writelines(data[1:])
# print(type(data))
    
with open('middle.txt', 'w') as fout:
    fout.writelines(str(data))

print(f"\n")
print(type(data))
arr = np.array(data)
print("Dimensions : " , arr.ndim)
print("Length of Numpy Array  : ",len(arr))
print("Length of first element in array : ",len(arr[0]))
print("Shape of the numpy array : ",arr.shape)
print(type(arr[0]))
print(f"\n")


#  Convert to 2D Array and add to main nd Array


# Phase 1 : Preparation of 3D Array 
#  Remove "*3" if the image does not have parameter cv.IMREAD_GRAYSCALE in cv.imread() functions
main_Image = np.zeros((height,width*3,3))
print("Before height : ",height)
print("Before width : ",width)
print("Before channels : ",channels)
print(f"\n")

print("After height : ",height)
print("After width : ",width*3," (",width,") * 3")
print("After channels : ",channels)
print("Dimensions : " , main_Image.ndim)
print(" Shape : ",main_Image.shape)


# creating a main_image_list which will be converted to ndArray(passed to openCv) later to show image
main_image_list = []


#Reference 
# Convert string to list (int)
# list_2 = [int(i) for i in arr[0].split() if i.isdigit()]
# # print(list_2)       
# npArray2 = np.array(list_2).reshape(width,3) 
# # Create a list after reShape 
# list2 = npArray2.tolist()
# print(list2);
# main_image_list.append(list2)
# print("1D Main Image size is : ",len(main_image_list))
# print("2D Main Image element(another list) size is : ",len(main_image_list[0]))
# print("3D Main Image element inside another element(another list) size is : ",len(main_image_list[0][1]))
# print("First element is : ", main_image_list[0][1][0])

for ele in arr:
        list_2 = [int(i) for i in arr[0].split() if i.isdigit()]
        npArray2 = np.array(list_2).reshape(width,3)
        list2 = npArray2.tolist()
        main_image_list.append(list2)

# print("1D Main Image size is : ",len(main_image_list))
# print("2D Main Image element(another list) size is : ",len(main_image_list[0]))
# print("3D Main Image element inside another element(another list) size is : ",len(main_image_list[0][1]))
# print("First element is : ", main_image_list[0][0][0])

# Convert List to Numpy nd-Array to 
updated_image_matrix = np.array(main_image_list)


# cv.imwrite('updated_image.jpg', updated_image_matrix)
# cv.imshow("image", updated_image_matrix)












# img = cv.imread("images.jpg")
# img_list = img.tolist()
# print(type(img))
# print(img.ndim)
# print(img.shape)

# file_matrx = open("test.txt","w")
# file_matrx.write(str(img_list))
# file_matrx.close()

# cv.imwrite('/output/output-img.jpg', img)
# cv.imshow("image", img)
# cv.waitKey()

# LINKS 
# https://www.rapidtables.com/web/color/RGB_Color.html
# https://note.nkmk.me/en/python-numpy-ndarray-ndim-shape-size/
# https://stackoverflow.com/questions/26681756/how-to-convert-a-python-numpy-array-to-an-rgb-image-with-opencv-2-4
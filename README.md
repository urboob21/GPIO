# GPIO
General Purpose Input/Output
I.Mode 

1. INPUT
  - Floating: cấu hình thả nổi 
  
  ![image](https://user-images.githubusercontent.com/118428350/216987872-4944280f-d60c-4623-8069-c820b03789ee.png)
  
    - sử dụng với peripheral tiêu thụ dòng vd: bus I2C
  - Pull up/Pull down:
  
  ![image](https://user-images.githubusercontent.com/118428350/216988754-a02f8bc0-0995-4d06-9dfd-c9c5b6acc738.png)

    - cấu hình có trở kéo lên hoặc xuống, giá trị trạng thái của INPUT xác định cụ thể là 0 or 1 (0V or 5V)

2. OUTPUT
  - Open drain: 

![image](https://user-images.githubusercontent.com/118428350/216990066-45c7da64-9025-4cf1-a4b5-e4776b2dcaac.png)

    - khi C = 1 NMOS dẫn OUTPUT dẫn VSS, khi C=0 thì OUTPUT không xác định
    - thường kết hợp với trở kéo ngoài
  - Push-Pull:
    
    ![image](https://user-images.githubusercontent.com/118428350/216990595-eae992c1-7d85-4aab-917b-e4c204a10e97.png)

    - C=0/1 PMOS/NMOS dẫn, OUTPUT = VCC/GND
  
  


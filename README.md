# GPIO
**General Purpose Input/Output**<br>
I.Mode <br>
1. INPUT
  - Floating: cấu hình thả nổi <br>
  ![image](https://user-images.githubusercontent.com/118428350/216987872-4944280f-d60c-4623-8069-c820b03789ee.png)<br>
    - sử dụng với peripheral tiêu thụ dòng vd: bus I2C
  - Pull up/Pull down:<br>
  ![image](https://user-images.githubusercontent.com/118428350/216988754-a02f8bc0-0995-4d06-9dfd-c9c5b6acc738.png)<br>
    - cấu hình có trở kéo lên hoặc xuống, giá trị trạng thái của INPUT xác định cụ thể là 0 or 1 (0V or 5V)<br>
2. OUTPUT
  - Open drain: <br>
![image](https://user-images.githubusercontent.com/118428350/216990066-45c7da64-9025-4cf1-a4b5-e4776b2dcaac.png)<br>
    - khi C = 1 NMOS dẫn OUTPUT dẫn VSS, khi C=0 thì OUTPUT không xác định
    - thường kết hợp với trở kéo ngoài
  - Push-Pull:<br>
    ![image](https://user-images.githubusercontent.com/118428350/216990595-eae992c1-7d85-4aab-917b-e4c204a10e97.png)<br>
    - C=0/1 PMOS/NMOS dẫn, OUTPUT = VCC/GND<br>


II. Something <br>
1. Sink/Source<br>
  - sink: lấy dòng ra từ vđk
  - source: lấy nguồn ngoài, dòng đi vào vđk<br>
2. Delay<br>
  - NOP: lênh as không làm gì 
  - Dutycycle : chu kỳ máy là thời gian cần thiết để thực hiện lênh<br>
                              T=12/F<br>
  - Các cách để tạo delay:
    - C1: dùng lệnh NOP -> rất nhiều
    - C2: dùng timer
    - C3: dùng while,for,.. -> tính chính xác không cao và thực nghiệm để hiệu chỉnh

3. Switch bounce/bauns/<br>
![image](https://user-images.githubusercontent.com/118428350/216993268-a11184bb-cc66-4eb7-b5e9-99cde1c2901b.png)<br>
    -> xử lý hiện tượng dội phím -> nhấn 1 lần lại thực hiện nhiều lần -> saii -> xử lý **Debounce**<br>
   - C1: phần cứng dùng tụ nối song song
   - C2: code xử lý đọc lại giá trị sau 20ms
        - if (= ?) //phím được nhấn<br>
            {<br>
              delay(20ms)<br>
                if(= ?) //kiểm tra lại nút nhấn <br>
                do something<br>
            }<br>

4. External interrupt <br>
![image](https://user-images.githubusercontent.com/118428350/217842227-1f73ee79-703b-46cf-a62a-fa220e719c25.png)<br>

B1: Enable ngắt toàn cục : EA=1; <br>
B2: Enable ngắt EXTI0/1 ~ P3.2 P3.3 <br>
B3: Viết hàm ngắt:  void name_isr() interrupt ? {} <br>
![image](https://user-images.githubusercontent.com/118428350/217842723-2cd059a0-54ea-442c-9142-ee616ebe00f3.png)

5. Timers 8051
- Thạch anh ngoại qua bộ chia /12 dùng cho timer.
- Có 2 bộ timers 16bit : TH1|TL1 và TH0|TL0.
a. Các thanh ghi 
#TMOD: Gate|C/T|M1|M0|Gate|C/T|M1|M0
             Timer1  |   Timer0
- Gate=0 cho phép timer khi INT0/INT1 = 1 và TR0/TR1 = 1.
- Gate=1 cho phép timer khi TR0/TR1 = 1. <br>
        ![image](https://user-images.githubusercontent.com/118428350/217852723-be899b4d-970e-4b71-aa0e-9e9e33ac7f40.png)<br>



  
  


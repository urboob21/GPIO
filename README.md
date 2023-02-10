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
- C/T: counter or timer<br>
- M1M0: mode 0: 13bit<br>
        mode 1: 16bit<br>
        mode 2: 8 bit tự động nạp lại<br>
        mode 3: ...<br>
#TCON: TF1|TR1|TF0|TR0|IE1|IT1|IE0|IT0<br>
TF: cờ tràn timer<br>
TR: chạy/dừng timer<br>
IE: ngắt ngoài xãy ra/đang xử lý<br>
ITx = 1, ngắt xảy ra trên INTx khi có xung sườn xuống<br>
ITx = 0, ngắt xảy ra trên INTx khi mức thấp xãy ra<br>

b. Mode 0<br>
3 bits cao của TLx=000;<br>
13bits -> 0-> 2^13-1 = 8191<br>

#Tính giá tri nạp<br>
12Mhz -> 1Mhz -> 1MC=1us<br>
-> 1ms -> 1000mc<br>
(max - count) +1 + thời gian trễ hàm = (8191-1000)+1+10 =0x1C22=0001 1100 0010 0010<br>
THx= 1110 0001<br>
TLX= 0000 0010<br>
 ***=> THx = BỎ 3 BIT ĐẦU - 8 bit TIẾP THEO, TLx = 000 + 5 bit cuối<br>
  
 #Các bước cấu hình<br>
  chọn bộ timer 1 or 0<br>
 B1: Gate=0 .(không dùng ngắt ngoài - chân int)<br>
     C/T=0 - timer<br>
     M1M0=00: mode 0<br>
 B2:Nạp giá trị cho THx,TLx<br>
 B3: set TRx để bắt đầu chạy time<br>
 B4: check TFx để biết khi nào timer tràn ( đếm xong)<br>
 B5: clear TRx để dừng timer, xóa cờ báo tràn TFx<br>

![image](https://user-images.githubusercontent.com/118428350/217998116-9e3f83f6-a39a-4824-b6ef-eb0636a8dc20.png)

 ->ưu diểm của delay dùng timer: tối ưu CPU thay vì thực hiện các lệnh vô nghĩa và trong thời gian timer chạy thì có thể thực hiện các công việc khác.<br>
 

    



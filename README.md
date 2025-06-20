# PackSwing
### 탈부착형 종이팩 자동 분리수거 모듈 (Detachable Automated Sorting Module for Paper Cartons)

 탈부착형 종이팩 자동 분리수거 모듈(이하 PackSwing)은 뚜껑 형식의 모듈로 다양한 쓰레기통에 범용적으로 적용하여 일반팩과 멸균팩을 자동으로 분리해주는 모듈입니다. 본 프로토타입에서는 전문 센서 등을 사용하기보다는 BreadBoard와 아두이노, 그리고 시중에 판매되는 보편화된 금속 센서를 활용하여 대략적으로 기능을 확인할 수 있는 정도로 제작해보았습니다. 

💡  **PackSwing**은 일반팩과 멸균팩을 구분하는 차이점인 알루미늄 막의 존재 유무를 활용하여 일반팩과 멸균팩을 자동으로 분리해줍니다. 이러한 로직을 구현하는 아두이노 코드가 하단에 제공되어있습니다.

The Detachable Paper Carton Automatic Sorting Module (hereafter referred to as PackSwing) is a module designed to be universally compatible with various trash bins, automatically sorting between regular paper cartons and aseptic cartons. In this prototype, instead of using specialized sensors, we utilized a breadboard, an Arduino, and commonly available metal sensors to build a simplified version that demonstrates the basic functionality.

💡 **PackSwing** automatically sorts regular and aseptic cartons by detecting the presence or absence of an aluminum layer—a key distinguishing feature between the two types. The Arduino code implementing this logic is provided below.

<img src="./assets/Module.png" alt="Module" width="500"/><img src="./assets/ModuleWithTrashBin.png" alt="Module with Trash Bin" width="500"/>


## 프로젝트 개요 (Project Overview)

- **목적(Purpose)**
    - 이 솔루션은 **멸균팩과 일반팩을 자동으로 분리할 수 있는 기능**을 제공합니다.
    - 기존의 일반 종이류 쓰레기통에서 무작위적으로 버려지고 있는 **멸균팩과 일반팩, 종이의 혼합배출**을 해결하여 종이팩의 재활용률을 높일 수 있습니다.
    - 기존의 IoT 수거함은 AI 딥러닝을 활용하여 사용하는 전력이 많고 크기가 크다는 문제점이 있었는데, 분류 알고리즘을 간단히 하여 **사용전력과 크기를 모두 줄여** 환경적인 측면에서도, 범용성에도 큰 장점이 있습니다.
    - This solution provides the ability to automatically separate aseptic and regular paper cartons.
    - It addresses the issue of **mixed disposal of aseptic cartons, regular cartons, and paper** in conventional paper recycling bins, thereby improving the overall recycling rate of paper cartons.
    - While conventional IoT-based collection systems often rely on AI deep learning, which requires high power consumption and large physical size, PackSwing simplifies the classification algorithm to significantly **reduce both power usage and device size**, making it more environmentally friendly and widely applicable.

- **주요 기능(Key Features)**
    1. **멸균팩, 일반팩 인식**: 사용자는 멸균팩, 일반팩을 구분하지 않고 쓰레기통에 올려둡니다. 이때, PackSwing은 물체가 올라왔다는 것을 인식합니다.
    2. **멸균팩, 일반팩 구분**: 멸균팩의 경우 금속 인식 센서에 의해 금속이 인식되고, 일반팩의 경우 금속 인식 센서는 반응하지 않습니다.
    3. **분리 배출**: 금속 인식 센서가 반응하면(멸균팩) 시계방향으로, 반응하지 않으면(일반팩) 시계 반대방향으로 각각 90도 회전하며 종이팩을 분리 배출합니다.

    <ol start="1">
    <li><b>Aseptic vs. Regular Carton Detection</b>: 
    Users place both aseptic and regular carton into the bin without distinguishing between them. At this point, PackSwing detects that an object has been placed.
    </li><li><b>Aseptic vs. Regular Carton Identification</b>: 
    If it's a aseptic carton, the metal detection sensor detects aluminum layer in an aseptic carton. If it's a regular carton, the metal sensor does not respond.
    </li><li><b>Sorting and Disposal</b>: 
    If metal is detected (aseptic carton), PackSwing rotates 90 degrees clockwise. If not (regular carton), it rotates 90 degrees counterclockwise to sort and dispose of the cartons accordingly.
    </li>
    </li>
    </ol>
    
- **아두이노 코드(Arduino Code)**
[Arduino Code](./ArduinoCode.ino)


- **회로도 및 부품(Circuit Diagram & Electronic components)**
<img src="./assets/CircuitDiagram.png" alt="CircuitDiagram" width="800"/>

1. 아두이노 호환보드(Arduino UNO R3)
2. 브레드보드(Breadboard)
3. 배터리(Battery)
4. 금속인식센서(DIY Kit Metal Detector)(Model: ICstation)
5. 적외선 거리측정 센서(Infrared Distance Sensor)(Model: 2Y0A02)
6. 모터(Motor)(Model: MG995)
7. 전선(Line): VCC(RED), GND(Black), SIG(Orange)
    
## 프로젝트 결과 (Project Outcomes)

### 데모 영상 (Demo Video)
[Demo Video Link](./assets/DemoVideo.mp4)

  **View raw (Sorry about that, but we can’t show files that are this big right now.)** 와 같은 텍스트가 뜰 수 있지만, **View raw** 를 클릭하면 영상을 다운받을 수 있습니다.
  
  You may see a message like **View raw (Sorry about that, but we can’t show files that are this big right now.)**, but you can still download the video by clicking **View raw**.

### 특징 및 장점 (Features & Benefits)
- **사전 지식 불필요:** 멸균팩과 일반팩을 분리 배출해야한다는 **사전 지식이 없이도** 어려움없이 분리배출할 수 있도록 도와줍니다.
- **간단한 사용:** 기존 IoT 수거함에서 필요했던 바코드 확인, 미리 해두어야하는 세척 과정 등의 불필요한 과정없이, 그냥 쓰레기통에 던지듯이 던져도 자동으로 분리 배출되므로 사용법이 아주 간단합니다.
- **탈부착 가능:** 크기가 컸던 기존 IoT 종이팩 수거함과는 달리 **뚜껑형태로 탈부착이 가능하여** 일반 쓰레기통 위에 올려두는 방식으로도 종이팩 분리 배출이 가능해집니다.
- **저비용 생산/설치:** 기존 IoT 수거함과는 달리 **전력 사용량** 관점에서도 설치에 필요한 비용이 매우 저렴하고, 생산하는데 들어가는 **부품 비용**도 매우 저렴합니다.
- **No Prior Knowledge Required**: Users can separate aseptic and regular cartons without needing any prior knowledge.
- **Simple to Use**: Unlike traditional IoT carton bins that require barcode scanning or pre-washing, this system allows users to simply toss in cartons like regular trash bins.
- **Attachable/Detachable Design**: Unlike bulky existing IoT bins, this system is designed as a detachable lid, making it easy to place on top of regular trash bins.
- **Low-Cost Production & Installation**: Compared to conventional IoT bins, this system is significantly cheaper to produce and install, both in terms of power consumption and component costs.


## 기대 효과 (Expected Benefits)


### 영향 (Impact)

- **인식 개선의 효과**: 수거함의 존재 자체만으로도 멸균팩과 일반팩을 **분리해야한다는 사실을 인지**할 수 있습니다.
- **혼합 배출 방지**: 종이팩을 분리배출할 수 있는 시스템을 다중이용시설에 제공함으로써 종이팩의 **혼합 배출을 방지**하고, 종이팩의 **재활용률을 높이는 것에 기여**할 수 있습니다.
- **정부 정책의 변화 유도**: 종이팩 분리배출의 수요가 높아지게 되면, 그에 맞춰 종이팩 분리배출 **사후 처리에 대한 정책적 변화를 유도**할 수 있게 되어 전체적인 선순환에 기여해볼 수 있을 것이라고 기대됩니다.
- **Improved Awareness**: The presence of the collection bin helps users recognize the need to separate aseptic and regular cartons.
- **Prevention of Mixed Disposal**: By providing a system for carton separation in public spaces, we can prevent the mixed disposal of cartons and contribute to increasing the recycling rate.
- **Policy Change Encouragement**: As demand for carton separation grows, it may encourage policy changes regarding post-disposal processing, contributing to a broader positive cycle.


### 확장 가능성 (Scalability)

- **모듈 길이조절 기능 추가**: 길이가 조절 가능하도록 하면 다양한 쓰레기통 크기에 맞추어 설치할 수 있어 **범용성**을 더욱 확장시킬 수 있습니다.
- **배출 여부 확인 가능한 소리 기능 추가**: 배출이 올바르게 완료되면 멸균팩으로 분리되었는지, 일반팩으로 분리되었는지 알려줄 수 있는 스피커를 추가하여 **인식 개선**을 더욱 효과적으로 할 수 있습니다.
- **Add Adjustable Module Length**: Making the length adjustable allows the system to be installed in trash bins of various sizes, greatly enhancing its **versatility**.
- **Add Sound Notification for Disposal Status**: Adding a speaker that notifies **whether the item was sorted** as an aseptic or regular carton after disposal can significantly improve user **awareness and feedback.**


## 설치 및 실행 방법 (Installation & Execution)

**1. 위의 회로도를 참고하여 회로도를 완성(Complete the circuit with reference to the schematic above)**  
**2. 위의 이미지를 참고하여 쓰레기통 틀 제작(Build the trash bin frame based on the image above)**  
**3. 회전판 및 틀에 아두이노 보드, Breadboard, Battery, Motor 부착(Attach the Arduino board, breadboard, battery, and motor to the rotating plate and frame)**  
**4. 아두이노 코드를 아두이노 보드에 업로드하여 코드 실행(Upload the Arduino code to the Arduino board and run the program)**: [Arduino Code](./ArduinoCode.ino)

## 팀 소개 (Team Introduction)

### 팀원 (Team Members)
- **강소현 (SoHyun Kang)**: 기획자, 디자이너, 프로토타입 제작자 (Planner, Designer, Developer)  
  ✉️ Mail: kangsobee@yonsei.ac.kr | Github: [kkangsso](https://github.com/kkangsso)
- **강승원 (Seungwon Kang)**: 기획자, 개발자, 프로토타입 제작자 (Planner, Lead Developer)  
  ✉️ Mail: swkang7263@yonsei.ac.kr | GitHub: [Seungwon511](https://github.com/Seungwon511)
- **김윤서 (Yoonseo Kim)**: 기획자 (Planner)  
  ✉️ Mail: lemonashley@naver.com | Github: [yoonseo05](https://github.com/yoonseo05)
- **서은빈 (Eunbin Seo)**: 기획자, 프로토타입 제작자, 발표자 (Planner, Developer, Presenter)  
  ✉️ Mail: seoeunbin609@gmail.com | Github: [BBI-BI](https://github.com/BBI-BI)  
- **신예진 (YeJin Shin)**: 기획자, 디자이너 (Planner, Designer)    
  ✉️ Mail: yj2003@yonsei.ac.kr  | Github: [yeding20](https://github.com/yeding20)  
- **이재동 (Jaedong Lee)**: 기획자, 프로토타입 제작자(Planner, Developer)  
  ✉️ Mail: dlwoehd456@gmail.com | Github: [JaeD456](https://github.com/JaeD456)

### 펠로우 및 멘토 (Fellow & Mentor)
- **Fellow : 리필리 대표 김재원 펠로우님** : [Organization Website](https://refeely.com/?NaPm=ct%3Dmc4u8on4%7Cci%3Dcheckout%7Ctr%3Dds%7Ctrx%3Dnull%7Chk%3Debeb1ae28552287fbdc64ef2c2414941f8e9e62f)
- **Mentor : 카카오 김채현 멘토님** : Mail(charlotte.chk@kakaocorp.com)


## 개발 환경 (Development Environment)

### Hardware (Embedded)
 - **Platform**: Arduino UNO R3 Compatible Board (CH340, USB-C Type)
 - **Language**: C++
 - **IDE**: Arduino IDE
 - **Libraries**: Servo.h
 - **Toolchain**: AVR-GCC (via Arduino IDE)
 - **Communication**: Serial (via USB-C), Digital/Analog I/O

### 협업 및 커뮤니케이션
- **일정 관리:** 매주 화요일마다 회의를 진행하면서 진행상황 Notion에 기록. 각자 작업 현황은 카톡으로 주기적으로 확인
- **Schedule Management:** We hold weekly meetings every Tuesday and record our progress on Notion. Each member's work status is regularly checked via KakaoTalk.


## 연관 자료 (Related Resources)
- [최종 발표 자료 링크 (Final Presentation Materials)](./assets/FinalPresentation.pdf)
- [펠로우 조직 사이트 (Fellow Organization Website)](https://refeely.com/?NaPm=ct%3Dmc4u8on4%7Cci%3Dcheckout%7Ctr%3Dds%7Ctrx%3Dnull%7Chk%3Debeb1ae28552287fbdc64ef2c2414941f8e9e62f)

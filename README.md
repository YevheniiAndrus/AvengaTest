# AvengaTest

Application consists of several modules: <br>
  1. FrameLoader - to load consequentially frames from video file
  2. BlackBox - represents black box algorithm. Accept frame from vide and produce generated metadata.
  3. UI - subsystem to renderer metadata
  4. ExternalDrive - to flush metadata to external storage
  
To run it effedtively multithreading has been used with pub/sub protocol. <br>
Boost signals were choosen since they are thread safe. <br>
After getting each frame new thread is running. It accepts single frame from video and runs worker. <br>
Worker triggers generating metadata and the run UI and ExternalDrive subsystems. <br>
They are accept generated metadata and do their work. <br>
Interactor class was used to orchestrate all these subsystems.

Steps to build and run solution:
  1. Boost and OpenCV are required. Instructions are here: <br>
     OpenCV (https://docs.opencv.org/3.4/d7/d9f/tutorial_linux_install.html) <br>
     Boost - ```sudo apt-get install libboost-all-dev```
     
  2. Clone repository <br>
     ```git clone git@github.com:YevheniiAndrus/AvengaTest.git```
     
  3. Prepare build: <br>
     ```mkdir build``` <br>
     ```cd build``` <br>
     ```cmake ..``` <br>
     ```make``` <br>
 
  4. Run application
     ```./AvengaTest <path_to_file> (you can use file from repo)```
     
     
Testing can be done with unit tests (GoogleTest for example) to test each component separately
as well as running the whole application using different video files.
Also, we can test interaction of any components between themselves.

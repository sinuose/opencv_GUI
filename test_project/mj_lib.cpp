
// ------------------------------------------------------------------
//  Author: Martin Jasinski
//      mj_Lib.cpp
//
// ------------------------------------------------------------------


#include "mj_lib.h"

// ------------------------------------------------------------------
//This function Opens the Camera
// ------------------------------------------------------------------
int mj_Webcam(int state)
{
    if (state == 1)
    {
        cout << "Camera ON";

        VideoCapture cap(0);
        if (!cap.isOpened()) {
            cout << "Error initializing video camera!" << endl;
            return -1;
        }

        char* windowName = "Webcam Feed";
        namedWindow(windowName, WINDOW_AUTOSIZE);

        while (1)
        {

            Mat frame;
            bool bSuccess = cap.read(frame);

            if (!bSuccess) {
                cout << "Error reading frame from camera feed" << endl;
                break;
            }

            imshow(windowName, frame);
            switch (waitKey(10)) {
            case 27:
                return 0;
            }
        }
    }

    return 0;
}

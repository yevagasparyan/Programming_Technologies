#include <iostream>

class AudioPlayer {
public:
    void playAudio() {
        std::cout << "Playing audio" << std::endl;
    }

    void stopAudio() {
        std::cout << "Stopping audio" << std::endl;
    }
};

class VideoPlayer {
public:
    void playVideo() {
        std::cout << "Playing video" << std::endl;
    }

    void stopVideo() {
        std::cout << "Stopping video" << std::endl;
    }
};

class Display {
public:
    void showImage() {
        std::cout << "Displaying image" << std::endl;
    }

    void hideImage() {
        std::cout << "Hiding image" << std::endl;
    }
};

class MultimediaFacade {
private:
    AudioPlayer audioPlayer;
    VideoPlayer videoPlayer;
    Display display;

public:
    void play() {
        audioPlayer.playAudio();
        videoPlayer.playVideo();
        display.showImage();
    }

    void stop() {
        audioPlayer.stopAudio();
        videoPlayer.stopVideo();
        display.hideImage();
    }
};

int main() {
    MultimediaFacade multimediaFacade;

    std::cout << "Start multimedia system:" << std::endl;
    multimediaFacade.play();

    std::cout << "\nStop multimedia system:" << std::endl;
    multimediaFacade.stop();

    return 0;
}


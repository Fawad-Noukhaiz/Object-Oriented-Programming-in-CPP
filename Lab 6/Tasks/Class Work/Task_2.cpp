#include<bits/stdc++.h>

using namespace std;

class Media_File{
    protected:
        string Path;
        int size;

    public:
        Media_File(){

        }

        Media_File(string Path1, int size1){
            Path = Path1;
            size = size1;
        }

        void Play(){
            cout << "Playing..." << endl;
        }

        void Stop(){
            cout << "Stopping..." << endl;
        }
};

class Visual_Media : virtual public Media_File {
    protected:
        int width;
        int height;

    public:
        Visual_Media(){}

        Visual_Media(int height1, int width1){
            height = height1;
            width = width1;
        }
};

class Audio_Media : virtual public Media_File {
    protected:
        int Sample_Rate;

    public:
        Audio_Media(){}

        Audio_Media(int Sample_Rate1){
            Sample_Rate = Sample_Rate1;
        }
};

class Video_File : public Audio_Media, public Visual_Media {
    public:
        Video_File(string Path, int size1, int width, int height, int Sample_rate){
            Media_File(Path,size1);
            Visual_Media(height,width);
            Audio_Media(Sample_Rate);
        }
};

int main() {
    Media_File A("file.mp3", 500);
    A.Play();
    A.Stop();

    Video_File video("movie.mp4", 1024, 1920, 1080, 44100);
    video.Play();
    video.Stop();

    return 0;
}
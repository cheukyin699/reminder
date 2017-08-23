#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

#include <sstream>

int main(int argc, char** argv) {
    std::stringstream ss;
    for (int i = 1; i < argc; ++i) {
        ss << argv[i] << "\n";
    }
    std::string res = ss.str();
    Fl_Window* w = new Fl_Window(500, 500, "Reminder");
    Fl_Box* text = new Fl_Box(0, 0, 500, 500, res.c_str());
    w->end();

    text->labelsize(32);
    w->show();

    return Fl::run();
}

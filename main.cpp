#define QT_NO_KEYWORDS

#include <QApplication>
#include <QLabel>

#include <iostream>
#include <cstring>
#include <libnotify/notify.h>


int main(int argc, char** argv) {
    notify_init("Reminder");
    QApplication app(argc, argv);

    if (argc <= 1) {
        std::cout << "error: not enough arguments; at least one required\n";
        return -1;
    }

    unsigned args_length = argc - 1;
    for (int i = 1; i < argc; ++i) {
        args_length += strlen(argv[i]);
    }
    char labeltxt[args_length];
    int ind = 0;

    for (int i = 1; i < argc; ++i) {
        strcpy(labeltxt + ind, argv[i]);
        ind += strlen(argv[i]);
        labeltxt[ind++] = '\n';
    }

    NotifyNotification* n = notify_notification_new("Reminder",
                                                    const_cast<const char*>(labeltxt),
                                                    0);

    notify_notification_set_timeout(n, 5000);

    QFont f = QGuiApplication::font();
    int fsize = 40;
    f.setPointSize(fsize);

    QLabel label;
    label.setText(QString::fromUtf8(labeltxt));
    label.setAlignment(Qt::AlignCenter);
    label.setFont(f);
    label.setFixedWidth(600);
    label.setFixedHeight(600);
    label.show();

    GError* err = nullptr;
    if (!notify_notification_show(n, &err)) {
        std::cerr << err->message << std::endl;
    }

    return app.exec();
}
c-c++-enable-clang-support t
c-c++-enable-clang-support t

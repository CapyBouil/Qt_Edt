
#include "style.h"

    QString getGlobalStyle() {
    return R"(
        QPushButton {
            background-color: #3498db;
            color: white;
            border: 1px solid #2980b9;
            border-radius: 5px;
            padding: 5px;
        }
        QPushButton:hover {
            background-color: #2980b9;
        }
        QPushButton:pressed {
            background-color: #1c5980;
        }
        QLabel {
            font-size: 14px;
            color: #2c3e50;
        }
        QListWidget {
            border: 1px solid #bdc3c7;
            background-color: #ecf0f1;
        }
        QTableWidget {
            border: 1px solid #bdc3c7;
            gridline-color: #bdc3c7;
        }
    )";
}

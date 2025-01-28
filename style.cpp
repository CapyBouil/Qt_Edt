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
            font-size: 14px;
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
        }
        QListWidget::item {
            padding: 15px; /* Ajouter un padding pour agrandir les éléments */
            border-bottom: 1px solid #bdc3c7; /* Optionnel : ajouter une bordure entre les éléments */
        }
        QListWidget::item:hover {
            background-color: #d5dbdb; /* Changer la couleur de fond au survol */
        }
        QListWidget::item:selected {
            background-color: #3498db; /* Changer la couleur de fond pour l'élément sélectionné */
            color: white;
        }
        QTableWidget {
            border: 1px solid #bdc3c7;
            gridline-color: #bdc3c7;
        }
        QTabBar::tab {
            background-color: #3498db;  /* Fond bleu */
            color: #ffffff;  /* Texte blanc */
            padding: 10px;
            border: 1px solid #e0e0e0;
            border-top-left-radius: 5px;
            border-top-right-radius: 5px;
        }

        QTabBar::tab:selected {
            background-color: #1c5980;  /* Fond bleu clair pour l'onglet sélectionné */
            color: #ffffff;  /* Texte blanc */
        }

        QTabBar::tab:hover {
            background-color: #2980b9;  /* Fond bleu clair au survol */
            color: #ffffff;  /* Texte blanc */
        }

        QSplitter::handle {
            background-color: #3498db;  /* Fond bleu clair */
            border: 1px solid #ffffff;
        }
    )";
}

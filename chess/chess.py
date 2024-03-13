import sys
from pathlib import Path

from PySide6.QtGui import QGuiApplication
from PySide6.QtQml import QQmlApplicationEngine

engine = QQmlApplicationEngine()
qml_file = Path(__file__).resolve().parent / "main.qml"
engine.load(qml_file)
app = QGuiApplication(sys.argv)
if not engine.rootObjects():
    sys.exit(-1)
sys.exit(app.exec())
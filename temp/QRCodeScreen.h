#pragma once

#include "Screen.h"


class QRCodeScreen : public Screen {
 public:
  QRCodeScreen(uint16_t bg = GxEPD_WHITE) : Screen(bg) {}
  void show() override;
  void menu() override;
  static boolean darkMode;
  String getQRString() {return "https://raidel.dev";};
 private:
	void drawQRCode(String content);
    String qrString;
};
display.setFullWindow();
  display.fillScreen(GxEPD_BLACK);
  display.setFont(&FreeMonoBold9pt7b);
  display.setTextColor(GxEPD_WHITE);
  display.setCursor(0, 20);
  display.println("Buzz Interval");

  display.setCursor(0, 50);
  display.println("Current Interval:");
  display.setCursor(0, 70);
  display.println(settings.vibrateOClock);

  display.setCursor(0, 100);
  display.println("Change Interval:");
  display.setCursor(0, 120);
  display.println(interval);


  pinMode(DOWN_BTN_PIN, INPUT);
  pinMode(UP_BTN_PIN, INPUT);
  pinMode(MENU_BTN_PIN, INPUT);
  pinMode(BACK_BTN_PIN, INPUT);

  while (1)
  {
    if (digitalRead(MENU_BTN_PIN) == 1)
    {
      // set the sesttings.vibrateOClock to the interval
      settings.vibrateOClock = interval;
      break;
      display.display(partialRefresh);
    }
    if (digitalRead(BACK_BTN_PIN) == 1)
    {
      showMenu(menuIndex, false);
      break;
    }

    // move up or down from 0 to 5 in increments of 1
    // 0 to 5, 0 = off, 1 = 1 minute, 2 = 5 minutes, 3 = 15 minutes, 4 = 30 minutes, 5 = 1 hour
    // if interval is 0, set to 5, otherwise decrement by 1
    // if interval is 5, set to 0, otherwise increment by 1

    if (digitalRead(DOWN_BTN_PIN) == 1)
    {
      if (interval == 0)
      {
        interval = 5;
      }
      else
      {
        interval--;
      }

      display.display(partialRefresh);
    }

    if (digitalRead(UP_BTN_PIN) == 1)
    {
      if (interval == 5)
      {
        interval = 0;
      }
      else
      {
        interval++;
      }

      display.display(partialRefresh);
    }
  }
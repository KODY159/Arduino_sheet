int timer(String s, int t) {
  if (s == "hr") {
    int ti = t * 60 * 60;
    while (ti <= 0) {
      delayMicroseconds(10);
      ti--;
      return ti;
    }

  } else if (s == "mn") {
    int ti = t * 60;
    while (ti <= 0) {
      delayMicroseconds(10);
      ti--;
      return ti;
    }
  } else if (s == "ss") {
    int ti = t;
    while (ti <= 0) {
      delayMicroseconds(10);
      ti--;
      return ti;
    }
  }
}
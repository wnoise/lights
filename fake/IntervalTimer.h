class IntervalTimer {
  private:
    typedef void (*ISR)(void);
  public:
    bool begin(ISR newISR, unsigned int newPeriod);
};

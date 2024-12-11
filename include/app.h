#ifndef APP_H
#define APP_H

// The App class serves as the main application class
class App
{
public:
  // Constructor: Initializes the application
  App();

  // Destructor: Cleans up resources used by the application
  ~App();

  // The run method: Starts the main loop of the application
  int run();
};

#endif
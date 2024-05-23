#pragma once

/**
  * @brief Set "cls" for LinuxOS and "clear" for WindowsOS
  */
#ifdef _WIN32
#define CLEARSCR "cls"
#endif

#ifdef linux 
#define CLEARSCR "clear"
#endif

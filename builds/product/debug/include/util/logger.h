/**
 ** autor   Alexander K
 ** date    1.10.2012.21.51
 ** BRIEF   project logger for write specific type and log to console and to
 **         log-file
*/

#ifndef LOGGER_G_H
#define LOGGER_G_H
//=============================================================================
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
//=============================================================================
//=============================================================================

namespace Log
{
   class log
   {
   public:
      log(const std::string& filename);
      //friend operator << 
   private:
      print_logname();
      print_time();
      
      std::string m_logname;
      std::string m_filename;
      int m_max_file_size;
      int m_max_string_lenght;
   };
}
#endif // LOGGER_G_H

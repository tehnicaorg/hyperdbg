/*
  Copyright notice
  ================
  
  Copyright (C) 2010
      Lorenzo  Martignoni <martignlo@gmail.com>
      Roberto  Paleari    <roberto.paleari@gmail.com>
      Aristide Fattori    <joystick@security.dico.unimi.it>
  
  This program is free software: you can redistribute it and/or modify it under
  the terms of the GNU General Public License as published by the Free Software
  Foundation, either version 3 of the License, or (at your option) any later
  version.
  
  HyperDbg is distributed in the hope that it will be useful, but WITHOUT ANY
  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
  A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License along with
  this program. If not, see <http://www.gnu.org/licenses/>.
  
*/

#ifndef _PILL_DEBUG_H
#define _PILL_DEBUG_H

#include "comio.h"
#include "config.h"

///////////
//  Log  //
///////////

#include <ntddk.h>

#define WindowsLog(fmt, ...) do { DbgPrint("[vmm] " fmt "\n", __VA_ARGS__); } while(0)
#define NullLog(fmt, ...)    do { } while(0)
#define SerialLog(fmt, ...)						\
  do {									\
    if (ComIsInitialized()) {						\
      ComPrint("[vmm] " fmt "\n", __VA_ARGS__);				\
    }									\
  } while(0)

/* Modify this macro to use a different logging method */
#ifdef DEBUG
#define Log(fmt, ...) SerialLog(fmt, __VA_ARGS__)
#else
#define Log(fmt, ...)
#endif

#endif /* _PILL_DEBUG_H */

#pragma once
//
//    FILE: TOPMIN.h
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.1
//    DATE: 2023-05-18
// PURPOSE: Arduino library to track top n minima.
//     URL: https://github.com/RobTillaart/TOPMIN


#define TOPMIN_LIB_VERSION             (F("0.1.1"))


#include "Arduino.h"


class TOPMIN
{
public:
  TOPMIN(uint8_t size = 5);
  ~TOPMIN();

  uint8_t count();
  uint8_t size();
  void    reset();
  virtual bool add(float value);
  virtual void fill(float value);
  float   getValue(uint8_t index);


protected:
  uint8_t _size;
  uint8_t _count;
  float * _arr;
};


////////////////////////////////////////////////////
//
//  DERIVED
//
class TOPMINext : public TOPMIN
{
public:
  TOPMINext(uint8_t size = 5);
  TOPMINext();

  bool     add(float value, uint32_t tag);
  uint32_t getTag(uint8_t index);
  void     fill(float value, uint32_t tag);

private:
  uint32_t * _tag;
};


//  -- END OF FILE --


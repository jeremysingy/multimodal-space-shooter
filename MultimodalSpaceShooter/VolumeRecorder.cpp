#include "VolumeRecorder.h"
#include <iostream>

VolumeRecorder::VolumeRecorder() : myVolume(0), myLevel(0)
{

}

VolumeRecorder::~VolumeRecorder()
{

}

float VolumeRecorder::getVolume() const
{
    return myVolume;
}

int VolumeRecorder::getLevel()  const
{
    return myLevel;
}

bool VolumeRecorder::OnProcessSamples(const sf::Int16* samples, size_t samplesCount) 
{ 
   myVolume = 0;

   for (std::size_t i = 0; i < samplesCount; ++i) 
   { 
      myVolume += samples[i] * samples[i]; 
      
   } 
   myVolume = sqrt(myVolume / samplesCount); 
   myVolume = myVolume / 10000; 

   std::cout << "Volume :" << myVolume <<std::endl; 

   if(myVolume < 1.0)
       myLevel = 0;
   if(myVolume >= 1.0 && myVolume < 2.0)
       myLevel = 1;
   if(myVolume >= 2.0)
       myLevel = 2;

   return true; 
}
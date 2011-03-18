#include "VolumeRecorder.h"
#include <iostream>

bool VolumeRecorder::OnProcessSamples(const sf::Int16* Samples, size_t SamplesCount) 
{ 
   myVolume = 0;

   for (std::size_t i = 0; i < SamplesCount; ++i) 
   { 
      myVolume += Samples[i] * Samples[i]; 
      
   } 
   myVolume = sqrt(myVolume / SamplesCount); 
   myVolume = myVolume / 10000; 

   std::cout << "\nVolume :" << myVolume <<std::endl; 

   if(myVolume < 1.0)myLevel = 0;
   if(myVolume >= 1.0 && myVolume < 2.0)myLevel = 1;
   if(myVolume >= 2.0)myLevel = 2;

   return true; 
}
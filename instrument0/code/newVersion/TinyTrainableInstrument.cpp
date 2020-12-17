#include "TinyTrainableInstrument.h"
#include <Arduino_KNN.h>  // TODO figure out why we need this here
#include "Instrument0.h"

// returns an object of type TinyTrainableInstrument, the superclass of Instrument0
TinyTrainableInstrument constructInstrument() {
  Instrument0 myInst(true);
  return myInst;
}
cmake_minimum_required(VERSION 3.10)

project(lt_tts VERSION 1.0.0 DESCRIPTION "Text to speech for Lithuanian")

add_library(TextNormalization SHARED native-modules/TextNormalization/TextNormalization.cpp native-modules/TextNormalization/stringWithLetterPosition.cpp)
set_target_properties(TextNormalization PROPERTIES VERSION ${PROJECT_VERSION}
  PUBLIC_HEADER include/TextNormalization)

add_library(UnitSelection SHARED native-modules/UnitSelection/UnitSelection.cpp native-modules/UnitSelection/strtokf.cpp)
set_target_properties(UnitSelection PROPERTIES VERSION ${PROJECT_VERSION}
  PUBLIC_HEADER include/UnitSelection.h)

add_library(Transcription SHARED native-modules/Transcription/ArKirciuoti.cpp  native-modules/Transcription/Kircdb.cpp native-modules/Transcription/strtokf.cpp native-modules/Transcription/Transkr.cpp native-modules/Transcription/fv2id.cpp native-modules/Transcription/Skiemen.cpp native-modules/Transcription/Transcription.cpp)
set_target_properties(Transcription PROPERTIES VERSION ${PROJECT_VERSION}
  PUBLIC_HEADER include/Transcription.h)

add_library(RateChange SHARED native-modules/RateChange/Euristika.cpp  native-modules/RateChange/greitis.cpp  native-modules/RateChange/RateChange.cpp  native-modules/RateChange/VeiksmaiSuFailais.cpp)
set_target_properties(RateChange PROPERTIES VERSION ${PROJECT_VERSION}
  PUBLIC_HEADER include/RateChange.h)

add_library(LithuanianTTS SHARED native-modules/LithuanianTTS/fv2id.cpp native-modules/LithuanianTTS/ilgiai.cpp native-modules/LithuanianTTS/raw2wav.cpp native-modules/LithuanianTTS/getLUSSErrorMessages.cpp native-modules/LithuanianTTS/LithuanianTTS.cpp native-modules/LithuanianTTS/strtokf.cpp)
set_target_properties(LithuanianTTS PROPERTIES VERSION ${PROJECT_VERSION}
  PUBLIC_HEADER include/LithuanianTTS.h)

include(GNUInstallDirs)

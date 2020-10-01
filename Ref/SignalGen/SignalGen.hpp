// ====================================================================== 
// \title  SignalGen.hpp
// \author bocchino
// \brief  hpp file for SequenceFileLoader component implementation class
//
// \copyright
// Copyright (C) 2009-2016 California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
// 
// ====================================================================== 

#ifndef Svc_SignalGen_HPP
#define Svc_SignalGen_HPP

#include <Fw/Types/ByteArray.hpp>
#include <Fw/Types/ConstByteArray.hpp>
#include <Os/File.hpp>
#include <Os/ValidateFile.hpp>
#include <Ref/SignalGen/SignalGenComponentAc.hpp>
#include <Fw/ArrayFile/ArrayTypeArrayAc.hpp>
#include <cmath>

namespace Ref {

  class SignalGen :
    public SignalGenComponentBase
  {

    private:
    
        void schedIn_handler(
            NATIVE_INT_TYPE portNum, /*!< The port number*/
            NATIVE_UINT_TYPE context /*!< The call order*/
        );

        void SignalGen_Settings_cmdHandler(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        U32 Frequency, 
        U32 Amplitude, 
        U32 Phase, 
        Ref::SignalType SigType 
        );

        void SignalGen_Toggle_cmdHandler(
            FwOpcodeType opCode, /*!< The opcode*/
            U32 cmdSeq /*!< The command sequence number*/
        );
        void SignalGen_Skip_cmdHandler(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
        );
        void SignalGen_GenerateArray_cmdHandler(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
        );

    public:
        //! Construct a SignalGen
        SignalGen(
            const char* compName //!< The component name
        );



        //! Initialize a SignalGen
        void init(
            const NATIVE_INT_TYPE queueDepth, //!< The queue depth
            const NATIVE_INT_TYPE instance //!< The instance number
        );
    
        //! Destroy a SignalGen
        ~SignalGen(void);
    
    private:
        bool RUNNING;
        bool SKIP_NEXT;
        U32 sampleFrequency;
        U32 signalFrequency;
        U32 signalAmplitude;
        U32 signalPhase;
        U32 sample;
        SignalType sigType;
  };
};
#endif

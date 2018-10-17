LDBG=0
ALLT=0

MLIST=`grep "%ifdef *" test/test.y | cut -f 2 -d " "`
ALIST=
while [[ "$1" != "" ]]; do
  case $1 in
    -d )
        LDBG=1
        ;;
    -dd )
        LDBG=2
        ;;
    -a )
        ALLT=1
        ;;
    * )
        ALIST="$ALIST $1"
        MLIST=$ALIST
        ;;
  esac
  shift
done

OSYS=""
if [ "$(uname)" == "Darwin" ]; then
  OSYS=OSX
  EXEFILE=test/lemon.osx
elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
  OSYS=LINUX
  EXEFILE=test/lemon.lnx
elif [ "$(expr substr $(uname -s) 1 9)" == "CYGWIN_NT" ]; then
  OSYS=CYGWIN
  EXEFILE=test/lemon.exe
  if [ -n "${VS140COMNTxOOLS+1}" ]; then
    VST=$VS140COMNTOOLS
  elif [ -n "${VS120COMNTOOLS+1}" ]; then
    VST=$VS120COMNTOOLS
  elif [ -n "${VS110COMNTOOLS+1}" ]; then
    VST=$VS110COMNTOOLS
  else
    echo "No compatible Visual Studio version found"
    exit 1
  fi

  SUFX=${VST#*Visual Studio*\\}
  WVSDIR=${VST%"$SUFX"}
  VSDIR=`cygpath -u "$WVSDIR"`
  PATH=$PATH:${VSDIR}VC/bin
  INCLUDE=${WVSDIR}VC\\include
  LIB="${WVSDIR}VC\\lib"
  LIB2="${WVSDIR}..\\Microsoft SDKs\Windows\v7.1A\Lib"
fi

rm -f test/test.c test/test.h test/test.out

PLIST=
FLIST=

function chk {
  STGE=$1
  RECV=$2
  MODE=$3
  MESG=$4
  EXPT=${MODE:0:1}
  case $EXPT in
    S)
      if [ $RECV -ne 0 ]; then
        if [ $ALLT -eq 0 ]; then
          echo $MESG
          exit 1
        fi
        FLIST="$FLIST $MODE"
        return 1
      fi
      ;;
    G)
      if [ $RECV -eq 0 ]; then
        if [ $ALLT -eq 0 ]; then
          echo $MESG
          exit 1
        fi
        FLIST="$FLIST $MODE"
        return 1
      fi
      ;;
    C)
      if [ $RECV -eq 0 ]; then
        if [ $ALLT -eq 0 ]; then
          echo $MESG
          exit 1
        fi
        FLIST="$FLIST $MODE"
        return 1
      fi
      ;;
    R)
      if [ $RECV -eq 0 ]; then
        if [ $ALLT -eq 0 ]; then
          echo $MESG
          exit 1
        fi
        FLIST="$FLIST $MODE"
        return 1
      fi
      ;;
    *)
      echo "Unknown stage $EXPT"
      exit 1
  esac
  if [ $STGE == $EXPT ]; then
    return 1
  fi
  return 0
}

case $OSYS in
   OSX|LINUX)
     clang -g -DLEMONEX_DBG=$LDBG -o $EXEFILE ./lemon.c
     ;;

   CYGWIN)
     cl.exe -nologo -I"$INCLUDE" -DLEMONEX_DBG=$LDBG lemon.c -link -LIBPATH:"$LIB" -LIBPATH:"$LIB2"
     ;;

   *)
     echo 'other OS (or missing cases for above OSs)' 
     ;;
esac

if [ $? -ne 0 ]; then
  echo error compiling lemon
  exit 1
fi

for MODE in $MLIST; do
  ./$EXEFILE T=./lempar.c D=$MODE d=test test/test.y
  chk G $? $MODE "error generating parser in $MODE"
  if [ $? -ne 0 ]; then
    continue
  fi

  case $OSYS in
     OSX|LINUX)
       clang -g -D$MODE -o test/test test/test.c
       ;;

     CYGWIN)
       cl.exe -nologo -I"$INCLUDE" -D$MODE test/test.c -link -LIBPATH:"$LIB" -LIBPATH:"$LIB2"
       ;;

     *)
       echo 'other OS (or missing cases for above OSs)' 
       ;;
  esac
  chk C $? $MODE "error compiling parser in $MODE"
  if [ $? -ne 0 ]; then
    continue
  fi

  ./test/test
  chk R $? $MODE "error running parser in $MODE"

  PLIST="$PLIST $MODE"
  echo DONE:$MODE
done

if [ $ALLT -ne 0 ]; then
  echo "PASSED:[$PLIST]"
  echo "FAILED:[$FLIST]"
fi

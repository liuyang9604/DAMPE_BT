#!  /bin/bash
#=====================================================================
#   File:   thisdmpsw.sh
#   Author: Chi WANG  (chiwang@mail.ustc.edu.cn)    01/10/2013
#---------------------------------------------------------------------
#   Description:
#
#       after installation, source this file in .zshrc(.bashrc), then you can use DampeSoftware
#---------------------------------------------------------------------
#   History:
#                           Last update:  14/12/2013   10:47:33
#=====================================================================

#+  Set DAMPE software developement environment         # for developer
if [ ! $DMPSWWORK ];then
  export DMPSWWORK=$HOME/dmpsw_workdir
  export PATH=$DMPSWWORK/bin:$PATH
  if [ $LD_LIBRARY_PATH ];then
    export LD_LIBRARY_PATH=$DMPSWWORK/lib:$LD_LIBRARY_PATH
  fi
  if [ $DYLD_LIBRARY_PATH ];then        # Mac OS
    export DYLD_LIBRARY_PATH=$DMPSWWORK/lib:$DYLD_LIBRARY_PATH
  fi
fi

#+  Set DAMPE software installation environment         # for future general user installation
#if [ ! $DMPSWSYS ];then
#  PWD=`pwd`
#  export DMPSWSYS=${PWD%"/bin"}      # if use this line, this file must in /prefix/bin
#  export DMPSWDB=$DMPSWSYS/database
#  export PATH=$DMPSWSYS/bin:$PATH
#  export LD_LIBRARY_PATH=$DMPSWSYS/lib:$LD_LIBRARY_PATH
#fi


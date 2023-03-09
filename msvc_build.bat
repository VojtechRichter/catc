@echo off

if not exist .\build mkdir .\build

set build_and_run=1

set common_compiler_flags=-nologo -FC -Zi -MT -std:c17 -WX -wd4142
set common_linker_flags=user32.lib ucrt.lib msvcrt.lib shell32.lib
set target=catc.exe

set source_files=..\src\main.c ..\src\parse_args.c

set target_machine=/MACHINE:X86

if not defined DevEnvDir (
    "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars32.bat"
)

cd .\build

echo [Building]

cl %common_compiler_flags% /Fe: %target% %source_files% /link %target_machine% %common_linker_flags% /NODEFAULTLIB:library

if %build_and_run% == 1 (
    echo [Running]
    .\%target%
)

cd ..
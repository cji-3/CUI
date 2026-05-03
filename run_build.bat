@echo off

mkdir build
cd build
cmake -G "MinGW Makefiles" ..
cmake --build .

if %errorlevel% equ 0 (
    echo.
    echo ������յ{��...
    echo.--------------------
    main_test.exe
    cd ..
) else (
    echo.
    echo �sĶ���ѡA���ˬd�{���X�I
    cd ..
    pause
)
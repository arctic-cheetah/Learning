#A program to calibrate my XP-pen 16TP pro touch screen

is_XP_PEN_present=`xrandr | grep -Ei "DP-2 connected"`;

if [[ -n $is_XP_PEN_present ]]; then
    sudo xinput map-to-output 11 DP-2
    sudo xinput map-to-output 13 DP-2
    sudo xinput map-to-output 14 DP-2
    sudo xinput map-to-output 16 DP-2
    echo "Successfully calibrated XP-pen touch monitor"
else
    echo "XP-pen monitor not detected"
fi
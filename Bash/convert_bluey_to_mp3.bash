arr=(
"Bluey-Keepy-uppy.mp3"
"Bluey-passive-aggressive.mp3"
"Bluey-shadow-lands-short.mp3"
"Bluey-shadow-lands.mp3"
"Grand_theatre_bluey.mp3"
"Nothing_to_lose_bluey.mp3"
"Relaxing-afternoon-bluey.mp3"
"Teasing Background Music Bluey.mp3"
"can-can-bluey.mp3"
"moving_on_bluey.mp3"
"naivety_bluey.mp3"
"not-alone-bluey.mp3"
"Bluey The Album Full Album.mp3"
"Bluey Theme Tune Instrument Parade.mp3"
"MicJaiy  Bluey Theme Song Remix.mp3"
"Sleepytime Background Music Bluey.mp3")

for x in "${arr[@]}"
do
    # convert_to_mp3=$(echo $x | cut -d"." -f 1)
    # convert_to_mp3="${convert_to_mp3}_.mp3"
    # ffmpeg -y -i "$x" -acodec libmp3lame "$convert_to_mp3"
    rm "$x"
done
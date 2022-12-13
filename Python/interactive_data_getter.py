import spotify_data_getter

# print("Enter output file path:")
filename = input("Enter output file path (eg. demofile.txt)")
if not filename:
    filename = "demofile.txt"
playlist_id = input('Enter Spotify playlist ID (eg. 5QZ75WasgTm3nsxC0EdFyl)')
if not playlist_id:
    playlist_id = '5QZ75WasgTm3nsxC0EdFyl'

print("Please wait:")
spotify_data_getter.run(filename, playlist_id)

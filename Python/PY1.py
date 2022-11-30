import spotipy as sp
import csv
import os
import sys
os.environ['SPOTIPY_CLIENT_ID']='67602c876c8d43aeab822b5550633e48'
os.environ['SPOTIPY_CLIENT_SECRET']='cf0c077fb1fc4a768b2d79fd9d1cfecf'
os.environ['SPOTIPY_REDIRECT_URI']='http://localhost:8888/callback'
from spotipy.oauth2 import SpotifyClientCredentials

'''lz_uri = 'spotify:artist:36QJpDe2go2KgaRleHCDTp'

spotify = spotipy.Spotify(client_credentials_manager=SpotifyClientCredentials())
results = spotify.artist_top_tracks(lz_uri)

for track in results['tracks'][:10]:
    print('track    : ' + track['name'])
    print('audio    : ' + track['preview_url'])
    print('cover art: ' + track['album']['images'][0]['url'])
    print()
'''
'''
spotify = spotipy.Spotify(auth_manager=SpotifyClientCredentials())

if len(sys.argv) > 1:
    name = ' '.join(sys.argv[1:])
else:
    name = 'Radiohead'

results = spotify.search(q='artist:' + name, type='artist')
items = results['artists']['items']
if len(items) > 0:
    artist = items[0]
    print(artist['name'], artist['images'][0]['url'])
'''

'''birdy_uri = '5QZ75WasgTm3nsxC0EdFyl'
spotify = spotipy.Spotify(client_credentials_manager=SpotifyClientCredentials())

results = spotify.playlist_tracks(birdy_uri)
albums = results['items']
while results['next']:
    results = spotify.next(results)
    albums.extend(results['items'])

for album in albums:
    print(album['track']['name'])'''

def get_playlist_tracks(sp, playlist_id):
    f = open(r"demofile2.csv", "w")
    # Ref - https://stackoverflow.com/questions/39086287/spotipy-how-to-read-more-than-100-tracks-from-a-playlist?noredirect=1&lq=1
    results = sp.playlist_tracks(playlist_id)
    it = results['items']
    uris = []

    while results['next']:
        results = sp.next(results)
        it.extend(results['items'])

    for album in it:
        f.write(album['track']['name'])
        f.write(', ')
        f.write(album['track']['album']['artists'][0]['name'])
        #f.write(',')
        #a=album['track']["popularity"]
        #a=str(a)
        #f.write(a)
        f.write('\n')
        #f.write('\n')
    f.close()
    f = open("demofile2.csv", "r")
    print(f.read())
#open and read the file after the appending:

spotify = sp.Spotify(client_credentials_manager=SpotifyClientCredentials())
#get_playlist_tracks(spotify, '5QZ75WasgTm3nsxC0EdFyl')
def search(sp):
    #f=open(r"out","w")
    q=input("Enter your search items")
    alb=sp.search(q,type="album")
    art=sp.search(q,type="artist")
    play=sp.search(q,type="playlist")
    tra=sp.search(q,type="track")
    r1=alb["albums"]['items']
    r2=art["artists"]['items']
    r3=play["playlists"]['items']
    r4=tra["tracks"]['items']
    '''while alb["albums"]['next']:
        #alb = sp.next(alb)
        r1.extend(alb["albums"]['items'])
    while art["artist"]['next']:
        #art = sp.next(art)
        r2.extend(art["artist"]['items'])
    while play['next']:
        play = sp.next(play)
        r3.extend(play[1]['items'])
    while tra["tracks"]['next']:
        #tra = sp.next(r1)
        r4.extend(tra["tracks"]['items'])'''

    for i in r4:
        print (i["album"]['artists'][0]['name'],end=" ,")
        print(i["album"]['name'])


            
search(spotify)   
    
    

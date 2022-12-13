import os

import spotipy as sp

os.environ['SPOTIPY_CLIENT_ID'] = '67602c876c8d43aeab822b5550633e48'
os.environ['SPOTIPY_CLIENT_SECRET'] = 'cf0c077fb1fc4a768b2d79fd9d1cfecf'
os.environ['SPOTIPY_REDIRECT_URI'] = 'http://localhost:8888/callback'
from spotipy.oauth2 import SpotifyClientCredentials

# update output filename here
filename = r"demofile2.txt"

def genre(x, sp):
    r = []
    results = sp.artist(x)
    for i in results['genres']:
        r.append(i)
    return r


def get_playlist_tracks(sp, playlist_id):
    f = open(filename, "w")
    # Ref - https://stackoverflow.com/questions/39086287/spotipy-how-to-read-more-than-100-tracks-from-a-playlist?noredirect=1&lq=1
    results = sp.playlist_tracks(playlist_id)
    it = results['items']

    while results['next']:
        results = sp.next(results)
        it.extend(results['items'])

    for album in it:
        f.write(album['track']['name'])
        f.write('; ')
        for i in range(len(album['track']['album']['artists'])):
            f.write(album['track']['album']['artists'][i]['name'])
            f.write(';')
        sad = genre(album['track']['album']['artists'][0]['id'], sp)
        for i in sad:
            f.write(i)
            f.write(';')
        a = album['track']["popularity"]
        a = str(a)
        f.write(a)
        f.write('\n')
        # f.write('\n')
    f.close()
    f = open(filename, "r")
    print(f.read())


# open and read the file after the appending:

spotify = sp.Spotify(client_credentials_manager=SpotifyClientCredentials())
# spotify:playlist:37i9dQZEVXbMDoHDwVN2tF
get_playlist_tracks(spotify, '5QZ75WasgTm3nsxC0EdFyl')


def search(sp):
    # f=open(r"out","w")
    q = input("Enter your search items")
    alb = sp.search(q, type="album")
    art = sp.search(q, type="artist")
    play = sp.search(q, type="playlist")
    tra = sp.search(q, type="track")
    r1 = alb["albums"]['items']
    r2 = art["artists"]['items']
    r3 = play["playlists"]['items']
    r4 = tra["tracks"]['items']
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
        print(i["album"]['artists'][0]['name'], end=" ,")
        print(i["album"]['name'])
# search(spotify)

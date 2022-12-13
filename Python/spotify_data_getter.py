import os

import spotipy as sp

os.environ['SPOTIPY_CLIENT_ID'] = '67602c876c8d43aeab822b5550633e48'
os.environ['SPOTIPY_CLIENT_SECRET'] = 'cf0c077fb1fc4a768b2d79fd9d1cfecf'
os.environ['SPOTIPY_REDIRECT_URI'] = 'http://localhost:8888/callback'
from spotipy.oauth2 import SpotifyClientCredentials


def genre(x, sp):
    r = []
    results = sp.artist(x)
    for i in results['genres']:
        r.append(i)
    return r


def get_playlist_tracks(sp, playlist_id, filename):
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


def run(filename, playlist_id):
    # open and read the file after the appending:
    spotify = sp.Spotify(client_credentials_manager=SpotifyClientCredentials())
    # spotify:playlist:37i9dQZEVXbMDoHDwVN2tF
    get_playlist_tracks(spotify, playlist_id, filename)

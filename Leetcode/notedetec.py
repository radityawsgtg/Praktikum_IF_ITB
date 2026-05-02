import sounddevice as sd
import numpy as np
import math

SAMPLERATE = 44100
BLOCKSIZE = 2048 #y

NOTES = ['C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B']

def hz_to_note(freq):
    if freq < 20: 
        return None
    h = round(12 * math.log2(freq / 440.0)) + 69
    octave = h // 12 - 1
    note = NOTES[h % 12]
    return f"{note}{octave}"

def audio_callback(indata, frames, time, status):
    if status:
        print(status, flush=True)
    
    audio_data = indata[:, 0]

    fft_data = np.fft.rfft(audio_data)
    frequencies = np.fft.rfftfreq(BLOCKSIZE, 1 / SAMPLERATE)

    peak_index = np.argmax(np.abs(fft_data))
    peak_freq = frequencies[peak_index]
    peak_amplitude = np.max(np.abs(fft_data))

    if peak_freq > 60 and peak_amplitude > 10:
        note = hz_to_note(peak_freq)
        print(f"Frekuensi Dominan: {peak_freq:.1f} Hz | Nada: {note}")


try:
    with sd.InputStream(channels=1, callback=audio_callback, blocksize=BLOCKSIZE, samplerate=SAMPLERATE):
        sd.sleep(1000000)
except KeyboardInterrupt:
    print("\nDeteksi dihentikan.")
import numpy as np
import math
import time
import warnings
import matplotlib.pyplot as plt


def dft(x):
    N = len(x)
    f_n = np.exp(np.array([[complex(0, -2*np.pi*k*n/N) for k in range(N)] for n in range(N)]))

    return f_n@x


def idft(s):
    N = len(s)
    f_n = np.exp(np.array([[complex(0, 2*np.pi*k*n/N) for k in range(N)] for n in range(N)]))/N

    return f_n@s


def put_zeros(s):
    epsilon = 10**(-10)
    s[abs(s) < epsilon] = 0
    return s


def fft_rec(x, N, s):
    if N == 1:
        return x[0]
    else:
        X = np.array([complex(0, 0) for i in range(N)])
        half = math.floor(N/2)
        X[0:half] = fft_rec(x, half, 2*s)
        X[half:N] = fft_rec(x[s:], half, 2*s)

        for k in range(half):
            t = X[k]
            X[k] = t + np.exp(complex(0, -2*np.pi*k/N))*X[k+half]
            X[k+math.floor(N/2)] = t - np.exp(complex(0, -2*np.pi*k/N))*X[k+half]

        return X


def fft(x):
    X = fft_rec(x, len(x), 1)
    return X


def first_exercise():
    x = [2, 1, 0, 1, 2, 1, 0, 1]

    start1 = time.clock()
    s_dft = dft(x)
    end1 = time.clock()

    start3 = time.clock()
    x_rev = idft(s_dft)
    end3 = time.clock()

    start4 = time.clock()
    x_rev_lib = np.fft.ifft(s_dft)
    end4 = time.clock()

    start5 = time.clock()
    s_fft = fft(x)
    end5 = time.clock()

    start6 = time.clock()
    s_fft_lib = np.fft.fft(x)
    end6 = time.clock()

    print("\nWektor wejściowy: " + str(x))
    print("\nOtrzymane dft: " + str(put_zeros(s_dft)) + ". \nCzas potrzebny do wykonania: " + str(end1-start1))
    print("\nOtrzymany x z idft: " + str(put_zeros(x_rev)) + ". \nCzas potrzebny na wykonanie: " + str(end3-start3))
    print("\nIdft z funkcji bibliotecznej: " + str(x_rev_lib) + ". \nCzas potrzebny na wykonanie: " + str(end4-start4))
    print("\nWynik fft: " + str(s_fft) + ". \nCzas potrzebny na wykonanie: " + str(end5-start5))
    print("\nWynik fft z f. bibliotecznej: " + str(s_fft_lib) + ". \nCzas potrzebny na wykonanie: " + str(end6-start6))


def second_exercise():
    dt = 1/32
    max_val = 16
    N = max_val/dt
    df = 1/(N*dt)
    timeline = np.linspace(0, max_val, N)
    freqs = np.array([k*df for k in range(math.ceil(-N/2), math.floor(N/2))])
    first_signal = np.array([0 for i in range(len(timeline))])
    second_signal = []

    step = math.floor(N/5)
    for f in range(1, 6):
        first_signal = first_signal + np.array(np.sin(f*timeline))
        second_signal.extend(np.sin(f*timeline[(f-1)*step:step*f]))

    if len(first_signal) > len(second_signal):
        second_signal.extend(np.sin(5*timeline[step*5:]))

    plt.figure()
    plt.subplot(311)
    plt.plot(timeline, first_signal, 'g-', timeline, second_signal, 'r-')
    plt.xlabel("Time [s]")
    plt.ylabel("Values")
    plt.title("Signals in time domain.")

    first_dft = np.fft.fft(first_signal)
    second_fft = np.fft.fft(second_signal)

    plt.subplot(312)
    plt.plot(freqs, np.real(first_dft), 'g-', freqs, np.real(second_fft), 'r-')
    plt.xlabel("Freq [Hz]")
    plt.ylabel("Real(DFT)")
    plt.title("Real part of DFT.")
    plt.axis([-17, 17, -100, 100])

    plt.subplot(313)
    plt.plot(freqs, np.imag(first_dft), 'g-', freqs, np.imag(second_fft), 'r-')
    plt.xlabel("Freq [Hz]")
    plt.ylabel("Img(DFT)")
    plt.title("Imaginary part of DFT.")
    plt.axis([-17, 17, -100, 100])

    plt.show()


warnings.filterwarnings("ignore", category=DeprecationWarning)
first_exercise()
second_exercise()

import matplotlib.pyplot as plt
import numpy as np



def sin_cos():
    x = np.arange(0, 2 * np.pi, 0.1)
    y = np.sin(x)

    x1 = np.arange(0, 2 * np.pi, 0.1)
    y1 = np.cos(x)

    plt.title('hahahaha')
    plt.plot(x, y, x1, y1)
    plt.show()


def sin():
    x = np.arange(0, 2 * np.pi, 0.1)
    y = np.sin(x)

    plt.title('hahahaha')
    plt.plot(x, y)
    plt.show()


def legned():
    plt.plot([10, 20, 30, 40], label = 'asc')
    plt.plot([40, 30, 20, 10], label = 'desc')

    plt.title('legend')
    plt.legend()
    plt.show()


def color():
    plt.plot([10, 20, 30, 40], color='pink', label = 'asc')
    plt.plot([40, 30, 20, 10], 'purple' ,label = 'desc')

    plt.title('legend')
    plt.legend()
    plt.show()


def line():
    plt.plot([10, 20, 30, 40], color='pink', linestyle = '--', label = 'asc')
    plt.plot([40, 30, 20, 10], 'purple' , ls='dashdot',label = 'desc')

    plt.title('legend')
    plt.legend()
    plt.show()


def marker():
    plt.plot([10, 20, 30, 40], 'r.--', label = 'circle')
    plt.plot([40, 30, 20, 10], 'b^-.' ,label = 'triangle')

    plt.title('legend')
    plt.legend()
    plt.show()


if __name__ == '__main__':
    #sin()
    #sin_cos()
    #legned()
    #color()
    #line()
    marker()



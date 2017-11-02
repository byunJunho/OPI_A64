from distutils.core import setup
from distutils.core import Extension
from distutils.command.build_ext import build_ext as _build_ext

import sys

processor_type = "sun8i"

try:
    input = raw_input
except NameError:
    pass


def print_color(text):
    """
    Print text in yellow :)
    :param text: String to be colored
    :return: Colored text
    """

    return '\033[0;33m' + text + '\033[0m'


def print_warning():
    """
    Print confirmation dialog
    :return:
    """
    print (print_color("Warning! ") + "Detected and target processor mismatch. ")


    var = input("Do you want to continue [Y/n]? ")
    if var == 'Y' or var == 'y':
        return
    else:
        print ("Abort.")
        sys.exit(1)


def check_processor():
    """
    Detect processor type
    :return:
    """
    cpuinfo = open("/proc/cpuinfo", 'r')
    for line in cpuinfo:
        if "Hardware" in line:
            processor = line.split(":")[1].rstrip()

            if "sun8i" in processor:
                print ("Detected processor: " + print_color(processor) + " (Probably Allwinner H3)")

            elif "sun50i" in processor:
                print ("Detected processor: " + print_color(processor) + " (Probably Allwinner H5)")

            else:
                print ("Detected processor: " + print_color("unknown"))

            if processor_type not in processor:
                print_warning()

            return

    print ("No processor detected")
    print_warning()


class build_ext(_build_ext):
    def run(self):
        check_processor()
        _build_ext.run(self)


modules = [
    Extension('OPi.gpio.gpio', sources=['OPi/gpio/gpio_lib.c', 'OPi/gpio/gpio.c']),
    Extension('OPi.gpio.port', sources=['OPi/gpio/port/port.c']),
    Extension('OPi.i2c', sources=['OPi/i2c/i2c_lib.c', 'OPi/i2c/i2c.c']),
    Extension('OPi.spi', sources=['OPi/spi/spi_lib.c', 'OPi/spi/spi.c']),
]

setup(
    name='opiH5',
    version='0.1.0',
    author='Jeremie',
    url='https://github.com/Jeremie-C/OPi_H5',
    license='MIT',
    packages=['OPi', 'OPi.gpio'],
    description='Control GPIO, I2C and SPI',
    long_description=open('README.txt').read() + open('CHANGES.txt').read(),
    classifiers=['Development Status :: 3 - Alpha',
                 'Environment :: Console',
                 'Intended Audience :: Developers',
                 'Intended Audience :: Education',
                 'License :: OSI Approved :: MIT License',
                 'Operating System :: POSIX :: Linux',
                 'Programming Language :: Python',
                 'Topic :: Home Automation',
                 'Topic :: Software Development :: Embedded Systems'
    ],
    ext_modules=modules,
    cmdclass={'build_ext': build_ext}
)

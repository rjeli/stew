from distutils.core import setup, Extension

setup(ext_modules=[Extension('stew',
                             sources=['stewmodule.cc'])])

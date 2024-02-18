from setuptools import find_packages
from setuptools import setup

setup(
    name='rft_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('rft_interfaces', 'rft_interfaces.*')),
)

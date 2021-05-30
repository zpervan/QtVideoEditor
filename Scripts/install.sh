#!/usr/bin/env bash

echo "This script installs all needed dependencies to successfully run the QyVideoEditor application on Ubuntu 20.04!"
echo "Run this script with sudo privileges in order to install the libraries!"

if [[ $(whoami) != root ]]; then
  echo -e " -- \e[31mPlease run this script as root or using sudo\e[0m"
  exit
fi

# While installing tzlib, it demands user interaction which stops the installation pipeline. This is a workaround
# to skip the user input section.
DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends tzdata

echo -e " -- \e[33mFetching updates\e[0m"
apt update -qq

echo -e " -- \e[33mInstalling dependencies\e[0m"
apt install -y build-essential \
  clang-11 \
  libfmt-dev \
  qtbase5-dev \
  qtdeclarative5-dev \
  qtmultimedia5-dev \
  qtquickcontrols2-5-dev \
  qml-module-qtquick-controls2 \
  qml-module-qtmultimedia \
  libqt5multimedia5-plugins \
  libqt5svg5-dev \
  libopencv-dev

echo -e " -- \e[33mNew symlink to OpenCV4 library\e"
# There is an issue where the symlink is not correct and creates errors while compiling the OpenCV4 code
rm  /usr/local/include/opencv2
ln -s /usr/include/opencv4/opencv2 /usr/local/include/opencv2

echo -e " -- \e[32mSetup completed!\e[0m"

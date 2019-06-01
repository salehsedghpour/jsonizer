FROM gcc:7

RUN wget https://github.com/Kitware/CMake/releases/download/v3.14.3/cmake-3.14.3-Linux-x86_64.sh \
      -q -O /tmp/cmake-install.sh \
      && chmod u+x /tmp/cmake-install.sh \
      && mkdir /usr/bin/cmake \
      && /tmp/cmake-install.sh --skip-license --prefix=/usr/bin/cmake \
      && rm /tmp/cmake-install.sh
WORKDIR "/opt"

ENV PATH="/usr/bin/cmake/bin:${PATH}"
RUN git clone https://github.com/salehsedghpour/jsonizer.git
WORKDIR "/opt/jsonizer"

RUN cmake .
RUN make

EXPOSE 8080
ENTRYPOINT   /opt/jsonizer/cmake-build-debug/untitled > /opt/ame.log 2>&1

# select base image
FROM ubuntu:19.10

# Dockerfile authors / maintainers
LABEL authors='{"name":"Daniele Bissoli","email":"daniele.bissoli@studenti.unitn.it"}'

# ========================================================== #
WORKDIR /tmp

# set timezone for the server
ENV TZ=Europe/Rome
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

# update application repository list and install required files
RUN apt-get update && apt-get install -y python3 python3-pip python3-dev libglib2.0-dev\
                                         curl freeglut3 freeglut3-dev\
                                         build-essential unzip less nano wget\
                                         python3-tk python3-pydot graphviz\
                                         libgraphviz-dev graphviz-dev pkg-config time\
                                         libgl1-mesa-glx libgl1-mesa-dri mesa-utils\
                                         mesa-opencl-icd mesa-va-drivers mesa-vdpau-drivers \
                                         doxygen ccache
RUN rm -rf /var/lib/apt/lists/*

# install a recent version of cmake
RUN mkdir -p cmake_src && wget -qO- https://github.com/Kitware/CMake/archive/v3.15.5.tar.gz | tar -zxvf - -C cmake_src --strip 1
RUN cd cmake_src && ./bootstrap && make -j`grep -c ^processor /proc/cpuinfo` && make install
RUN rm -r cmake_src

# augument linker search path
#RUN echo "/usr/local/lib" >> /etc/ld.so.conf.d/local-libs.conf && ldconfig

# install further Python dependencies
COPY requirements.txt .

RUN pip3 install --upgrade pip
RUN pip3 install -r requirements.txt && rm requirements.txt

# this alias is just for simplifying the navigation within the container
RUN echo 'alias ll="ls -lh"' >> /etc/bash.bashrc

# ========================================================== #
WORKDIR /home/ntrt

# prepare the container to start the bash shell once launched
ENV TERM=xterm
CMD ["/bin/bash"]
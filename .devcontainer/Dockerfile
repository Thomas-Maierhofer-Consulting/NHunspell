
FROM ubuntu:22.10

## From https://github.hexagon.com/geo-surv/gmat-smartpole-cpu-vscode-env/blob/master/.devcontainer/Dockerfile
# Customize local env with commn-debian.sh
ARG INSTALL_ZSH="true"
ARG UPGRADE_PACKAGES="false"

COPY library-scripts/common-debian.sh /tmp/library-scripts/
RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install --no-install-recommends -y cmake-curses-gui
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && /bin/bash /tmp/library-scripts/common-debian.sh "${INSTALL_ZSH}" "user" "${UID}" "${GID}" "${UPGRADE_PACKAGES}"

# install tools and utilities
RUN apt-get install zsh git file

# customise zsh with oh-my-zsh
RUN sh -c "$(wget -O- https://github.com/deluan/zsh-in-docker/releases/download/v1.1.1/zsh-in-docker.sh)" -- \
    -t bira \
    -p https://github.com/zsh-users/zsh-autosuggestions \
    -a ZSH_AUTOSUGGEST_HIGHLIGHT_STYLE=\"fg=6\" \
    -p git

#install .NET Core SDK
RUN export DEBIAN_FRONTEND=noninteractive && apt-get install dotnet-sdk-7.0 -y

# install the linux and windows compilers
RUN export DEBIAN_FRONTEND=noninteractive && apt-get install build-essential -y
RUN export DEBIAN_FRONTEND=noninteractive && apt-get install gcc-mingw-w64-x86-64 gcc-mingw-w64-i686 g++-mingw-w64-x86-64 g++-mingw-w64-i686 wine64 -y


RUN apt-get autoremove -y && apt-get clean -y && rm -rf /var/lib/apt/lists/*
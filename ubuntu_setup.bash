#This is my quick install for ubuntu
sudo apt update && sudo apt install -y \
java-common gcc clang make cmake build-essential git gitk \
zsh curl wget htop neovim tmux tree unzip zip \
python3 python3-pip python3-venv \
postgresql mysql-server sqlite3 \
texlive-full texstudio \ 
#^this is f**cking massive
python3-numpy python3-pandas python3-matplotlib python3-seaborn python3-scipy python3-sklearn \
jupyter-notebook \
gimp
# 2. Install the GUI/IDE apps
sudo snap install code --classic
sudo snap install android-studio --classic
sudo snap install eclipse --classic
sudo snap install obsidian --classic
sudo snap install spotify discord

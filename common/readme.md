0. 安装 git lfs
```
    sudo apt install git-lfs
    git lfs install
```
1. 下载 common 库
```
    mkdir projects 
    cd projects
    git clone https://github.com/grtstar/common.git
```
2. 验证环境
```
    cd common
    source ./env_arm.sh    // 加载编译环境
    cd messages
    mkdir build 
    cd build
    cmaker
    make
```
若编译成功则环境安装正确

3. 下载其他组件放置同一个父目录下并编译
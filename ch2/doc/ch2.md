# ch2

## 目录

-   [搭建工作环境](#搭建工作环境)
    -   [环境及工具](#环境及工具)
    -   [安装及使用](#安装及使用)

### 搭建工作环境

#### 环境及工具

-   Ubuntu 20.04
-   Bochs 2.6.9
-   nasm 2.14.02
-   gcc 9.4.0

#### 安装及使用

-   安装
    1.  [官网下载bochs](https://bochs.sourceforge.io/getcurrent.html "官网下载bochs")
    2.  &#x20;解压缩

        `tar vxzf bochs bochs-2.6.9.tar.gz `
    3.  依次输入

        `cd bochs-2.3.4 `

        `./configure  --enable-debugger --enable-disasm`&#x20;

        `make`

        `sudo make install`
-   配置文件
    ```matlab
    ###############################################################
    # Configuration file for Bochs
    ###############################################################

    # how much memory the emulated machine will have
    megs: 32

    # filename of ROM images
    romimage: file=/usr/local/share/bochs/BIOS-bochs-latest
    vgaromimage: file=/usr/local/share/bochs/VGABIOS-lgpl-latest

    # what disk images will be used
    floppya: 1_44=a.img, status=inserted

    # choose the boot disk.
    boot: floppy

    # where do we send log messages?
    # log: bochsout.log

    # disable the mouse
    mouse: enabled=0

    # enable key mapping, using US layout as default.
    keyboard: keymap=/usr/local/share/bochs/keymaps/x11-pc-us.map
    ```
-   使用
    1.  汇编

        `nasm boot.asm -o boot.bin`
    2.  生成软盘

        `bximage`

        依次输入fd 1.44 a.img
    3.  将引导扇区写进软盘

        `dd if=boot.bin of=a.img bs=512 count=1 conv=notrunc`
    4.  运行

        `bochs`
-   调试
    -   &#x20;help  随时查看帮助
    -   &#x20;b  ADDR  在ADDR处设置断点
    -   &#x20;info break  查看当前所有断点信息
    -   c  继续执行
    -   s  单步执行，会进入函数体
    -   n  单步执行,跳过函数体
    -   info cpu  查看寄存器信息
    -   r  查看寄存器信息
    -   fp  查看寄存器信息
    -   sreg  查看寄存器信息
    -   creg  查看寄存器信息
    -   print-stack  查看堆栈
    -   x 和 xp   查看内存地址内容
    -   u start end  反汇编一段内存
    -   trace-on  反汇编执行的每一条指令
    -   trace-reg  每执行一条指令就打印CPU信息

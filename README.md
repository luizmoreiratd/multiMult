# multiMult

## Table of contents
* [Introduction](#introduction)
* [Usage](#usage)
* [Getting and Building the Code](#getting-and-building-the-code)
* [License](#license)
* [Release Notes](#release-notes)

## Introduction
A Maya plugin that implements a multi-index multiplication node that takes N inputs and outputs the product of all inputs.

## Usage
```python
# load plugin
cmds.loadPlugin('multiMult', quiet=True)

# create empty group
group = cmds.group(empty=True)

# create multiMult node
mult = cmds.createNode('multiMult')

# connect translates as input
cmds.connectAttr('%s.translateX' % group, '%s.input[0]' % mult)
cmds.connectAttr('%s.translateY' % group, '%s.input[1]' % mult)
cmds.connectAttr('%s.translateZ' % group, '%s.input[2]' % mult)

# connect output to scaleX
cmds.connectAttr('%s.output' % mult, '%s.scaleX' % group)
```

## Getting and Building the Code
You can use CMake to compile the plugin from the command line.

### Clone the repo and create a build directory
```shell
git clone https://github.com/luizmoreiratd/multiMult
mkdir build
cd build
```

### Run a basic build
#### For Windows
```shell
"C:/Program Files (x86)/CMake/bin/cmake.exe" -G "Visual Studio 11 Win64" -DMAYA_VERSION=2015 ..
```

#### For Linux or Mac
```shell
cmake -G "Unix Makefiles" -DMAYA_VERSION=2015 ..
cmake --build .
make install
```

## License
The source code is licensed under the [MIT](./LICENSE) License.

## Release Notes
For release notes and downloads visit the [Release](https://github.com/luizmoreiratd/multiMult/releases/) page.

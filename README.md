# Tool for generating Sublime Text 3 autocompletion from ArmA config classes

## Usage

### Parameters

```
1 : Source file. The file must only contains a cfg_function class.
2 : New file name
```
It is a good and common pratice to split your description.ext's classes into several files so have a file that contains only a cfg_function class won't be a problem

### Output

The executable will generate a .sublime-completions file from your file in the outputs folder

### Options

None

### Exemple

Generate the file from a cfg_function class
```
./bin/autocomple_gen.exe ./test_files/Cfg_Functions.hpp
```

Install the file into sublime Text 3
```
./scripts/install.bat
```

## Authors

* **Lyeed** - [Lyeed](https://github.com/Lyeed)

@echo off
xcopy ".\outputs\*.sublime-completions" "%AppData%\Sublime Text 3\Packages\User\" /I /Y

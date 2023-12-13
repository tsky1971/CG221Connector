@echo off

set EngineVersion=51

set EngineDirectory=D:\UE_Build\UE_%EngineVersion%\Windows
set AutomationToolPath="%EngineDirectory%\Engine\Build\BatchFiles\RunUAT.bat"
set PluginPath="%cd%\CG221Connector\CG221Connector.uplugin"
set OutputPath="%cd%\CG221Connector\CG221Connector_my%EngineVersion%"

title Build Plugin
echo Automation Tool Path: %AutomationToolPath%
echo:

call %AutomationToolPath% BuildPlugin -Plugin=%PluginPath% -Package=%OutputPath% -Rocket -TargetPlatforms=Win64
echo:
pause
exit 0

#set($command = $robot.getProperty("Autonomous Command").getValue())
#set($params = $robot.getProperty("Autonomous command parameters").getValue())

#foreach( $component in $components )
#if ($component.getBase().getType() == "Command"
     && $component.getProperty("Autonomous Selection").getValue())
#if( $component.getProperty("Parameter presets").getValue().isEmpty())
	chooser.AddObject("$component.getName()", new #class($component.getName())());
#else
#foreach( $set in $component.getProperty("Parameter presets").getValue() )
	chooser.AddObject("$component.getName(): $set.getName()", #command_instantiation( $component.getName(), $set.getParameters() ));
#end
#end
#end
#end

#if($command != "None")
	chooser.AddDefault("$command", #command_instantiation( $command, $params));
#end

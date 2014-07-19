inlets = 1;
outlets = 3;
autowatch = 1;

function launch_command(path)
{
	var re = /:(\/.*\/)(.*).app/;
	var res = re.exec(path);
	var base_dir = res[1];
	var app_name = res[2];
	
	var app_fullpath = base_dir + app_name + '.app';
	var launch_cmd = 'open ' + app_fullpath;
	var show_cmd = "printf 'tell application \"" + app_fullpath + "\" \\n if it is running then \\n activate\\n end if \\n end tell' | osascript -"

	outlet(0, launch_cmd);
	outlet(1, show_cmd);
	outlet(2, app_name);
}

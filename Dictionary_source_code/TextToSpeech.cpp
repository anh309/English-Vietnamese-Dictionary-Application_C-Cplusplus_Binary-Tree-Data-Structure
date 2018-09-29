void _Text_To_Speech(char *text){
	char cmdlines [strlen(text)];
	sprintf(cmdlines, "%s \"%s\"", "TTSAPI.vbs", text);
	system(cmdlines);
}
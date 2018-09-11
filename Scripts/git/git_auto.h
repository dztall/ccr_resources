void gitprefix(auto_create)(void) {
	git("clean init");
	git("init");
	git("add -A");
	git("commit -a");
	git("remote add origin https://github.com/mgood7123/global_backup_Mobile_C.git");
	git("push origin master");
	git("clean init");
}

int gitprefix(auto)(int argc, char * argv[]) {
	if (argc < 2) giterrornomessage("%s requires an additional command", argv[0]);
	if(strcmp(argv[1], "create") == 0) return gitprefix(auto_create)();
	else giterrornomessage("%s is not a valid sub command of %s", argv[1], argv[0]);
}

Implement System Calls for File I/O:
1.int Create(char *name)
2.OpenFileId Open(char *name)
3.int Write(char *buffer, int size, OpenFileId id)
4.int Read(char *buffer, int size, OpenFileId id)
5.int Close(OpenFileId id)
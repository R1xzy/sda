// undo.h
#ifndef UNDO_H
#define UNDO_H

#define MAX_UNDO 100

typedef struct {
    char aktivitas[MAX_UNDO][100];
    int top;
} StackUndo;

void createStack(StackUndo* s);
void pushUndo(StackUndo* s, const char* aktivitas);
int popUndo(StackUndo* s, char* aktivitasOut);

#endif

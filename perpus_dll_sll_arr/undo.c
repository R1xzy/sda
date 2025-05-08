// undo.c
#include <stdio.h>
#include <string.h>
#include "undo.h"

void createStack(StackUndo* s) {
    s->top = -1;
}

void pushUndo(StackUndo* s, const char* aktivitas) {
    if (s->top < MAX_UNDO - 1) {
        s->top++;
        strcpy(s->aktivitas[s->top], aktivitas);
    }
}

int popUndo(StackUndo* s, char* aktivitasOut) {
    if (s->top >= 0) {
        strcpy(aktivitasOut, s->aktivitas[s->top]);
        s->top--;
        return 1;
    }
    return 0;
}

int main(int argc, char** argv)
{
    const char* usage =
    "jcc [options] foo.c\n"
    "-c: compile only\n"
    "-dumpLex: dump lex tokens to stdout\n"
    "-dumpParse: dump Abstract Syntax Tree to stdout\n"
    "-lexOnly: lex input file but do not parse or create function calls (no output file)\n"
    "-parseOnly: lex and parse but don't create function calls (no output file)\n";

    printf("prog name=%s\n", argv[0]);

    if (argc==1)
        printf("Usage:\n%s\n",usage);
    else
        printf("compiling... %s\n",argv[1]);
    
    return 0;
}

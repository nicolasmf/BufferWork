typedef struct Buffer
{
    char* data;
    int size;
    int w;
    int r;
    int is_empty;
}Buffer;

Buffer* create_buffer(int n);
void print_buffer(Buffer* buffer);
int write_buffer(Buffer* buffer, char info);
char read_buffer(Buffer* buffer);

void print_w(Buffer *buffer);
void print_r(Buffer *buffer);
char* str_append(char* str, char c);
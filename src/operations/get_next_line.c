#include <stdlib.h>
#include <unistd.h>
#define EOF -1
#ifndef BUFSIZ
#define BUFSIZ 100
#endif

typedef struct s_string {
    char *str;  // 文字列
    size_t len; // 文字列の長さ
    size_t capa; // 確保した領域の大きさ
} t_string;

int ft_putc(t_string *str, char c)
{
    if (str->len + 1 >= str->capa) {
        size_t new_capa = str->capa == 0 ? 16 : str->capa * 2;
        char *new_str = realloc(str->str, new_capa);
        if (!new_str) {
            return -1; // メモリ再確保に失敗した場合
        }
        str->str = new_str;
        str->capa = new_capa;
    }
    str->str[str->len] = c; // 一文字詰め込む
    str->len++;
    return 0;
}

char *get_next_line(int fd) {
    t_string ret = {NULL, 0, 0}; // 文字列構造体の初期化
    static char buf[BUFSIZ]; // バッファ
    static ssize_t bytes_read = 0; // バッファの長さ
    static char *buf_ptr = buf; // バッファのポインタ
    char c;

    while (1) { // 無限ループ
        if(buf_ptr >= buf + bytes_read)
        {
            bytes_read = read(fd, buf, BUFSIZ); // ファイルから読み込む
            buf_ptr = buf;
            if (bytes_read == 0) {
                break; // ファイルの最後ならループから抜ける
            }
        }
        c = *buf_ptr++;
        if (c == EOF) {
            break; // ファイルの最後ならループから抜ける
        }
        if (ft_putc(&ret, c) == -1) {
            free(ret.str); // メモリ再確保に失敗した場合にメモリを解放
            return NULL;
        }
        if (c == '\n') {
            break; // 改行だったらループから抜ける
        }
    }

    if (ret.len > 0) {
        ft_putc(&ret, '\0'); // 最後にNULL文字を詰める
    } else {
        free(ret.str); // 空の行の場合メモリを解放してNULLを返す
        return NULL;
    }
    return ret.str;
}

// #include <stdio.h>
// int main(void) {
//     char *line;
//     printf("Enter lines of text (Ctrl+D to end):\n");
//     while ((line = get_next_line(STDIN_FILENO)) != NULL) {
//         printf("Read line: %s", line);
//         free(line);
//     }
//     return 0;
// }
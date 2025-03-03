### Уточнения по ходу выполнения работы...

Поскольку заголовочные .h файлы находятся не в стандартной директории (/usr/lib/include) и не директории с исходными файлами, для явного указания где их искать был использован флаг -I:

Static:
``` mastard@GENSHIN-PC:~/c_safarov_practice/lectureLibs$ clang main_static.c -L./lib -lpower_for -I ./lib -o main_static.out
mastard@GENSHIN-PC:~/c_safarov_practice/lectureLibs$ ./main_static.out 
2^10 using static library: 1024 
```
Dynamic:
```
mastard@GENSHIN-PC:~/c_safarov_practice/lectureLibs$ clang main_dynamic.c -o main_dynamic.out -L./lib -lpower_divide -I ./lib
```

Чтобы указать путь, где искать .so файлы была модифицированна переменная окружения LD_LIBRARY_PATH (задано новое значение, после чего экспортированно):

```
mastard@GENSHIN-PC:~/c_safarov_practice/lectureLibs$ LD_LIBRARY_PATH=./lib;
mastard@GENSHIN-PC:~/c_safarov_practice/lectureLibs$ export LD_LIBRARY_PATH
mastard@GENSHIN-PC:~/c_safarov_practice/lectureLibs$ ./main_dynamic.out 
2^10 using dynamic library: 1024
```

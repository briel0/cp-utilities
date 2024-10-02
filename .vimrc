filetype indent on
set relativenumber
set smartindent
set smarttab
set incsearch
set expandtab
syntax on
set autoindent expandtab tabstop=4 shiftwidth=4
autocmd BufNewFile *.cpp -r ~/template.cpp

" COMANDOS->
" w|!g++ -g -std=c++2a %
" !./a.out < input.txt
" !gdb a.out

filetype indent on
set relativenumber
set matchpairs=(:),{:},[:],':',":"
set autoindent expandtab tabstop=4 shiftwidth=4
set smarttab
set incsearch
set expandtab
set backspace=indent,eol,start
syntax on
autocmd BufNewFile *.cpp -r ~/template.cpp
autocmd filetype cpp nnoremap <F5> :w <bar> !g++ -std=c++20 % <CR>
autocmd filetype cpp nnoremap <F9> : <bar> !a.exe < input.txt <CR>
set smartindent


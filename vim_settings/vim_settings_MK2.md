# :e $MYVIMRC

---

```vim
set nocompatible
source $VIMRUNTIME/vimrc_example.vim
source $VIMRUNTIME/mswin.vim
behave mswin

set nocompatible

colorscheme torte
set backspace=indent,start
set history=100
set ruler
set showcmd
set ai
set novisualbell
set shiftwidth=4
set tabstop=4
set et
set cindent
set cul
set nu
filetype on
syntax on
set nohls
set sm
set si
set nobackup
set incsearch
set encoding=cp949
set fileencodings=utf-8,cp949
set langmenu=cp949
set clipboard=unnamed

set guifont=Ubuntu_Mono:h15

set diffexpr=MyDiff()
function MyDiff()
    let opt = '-a --binary'
    if &diffopt =~ 'icase' | let opt = opt . '-i' | endif
    if &diffopt =~ 'iwhite' | let opt = opt . '-b' | endif
    :endfunction
```


# :e $VIMRUNTIME\vimrc_example.vim

---

```vim
" An example for a vimrc file.
"
" Maintainer:	Bram Moolenaar <Bram@vim.org>
" Last change:	2019 Dec 17
"
" To use it, copy it to
"	       for Unix:  ~/.vimrc
"	      for Amiga:  s:.vimrc
"	 for MS-Windows:  $VIM\_vimrc
"	      for Haiku:  ~/config/settings/vim/vimrc
"	    for OpenVMS:  sys$login:.vimrc

" When started as "evim", evim.vim will already have done these settings, bail
" out.
if v:progname =~? "evim"
  finish
endif

" Get the defaults that most users want.
source $VIMRUNTIME/defaults.vim

set nocompatible

"allow backspacing over everything in insert mode
set backspace=indent,start
"start =    delete front character
"eol =      end of line. can delete line by using Backspace.
"indent =   deletes indent. find out yourself.
set history=100
set ruler
set showcmd
set incsearch

if has("vms")
  set nobackup		" do not keep a backup file, use versions instead
else
  set backup		" keep a backup file (restore to previous version)
  if has('persistent_undo')
    set undofile	" keep an undo file (undo changes after closing)
  endif
endif

if &t_Co > 2 || has("gui_running")
    " Switch on highlighting the last used search pattern.
    set hlsearch
    if has("gui_gtk2")
        set guifont=Ubuntu\ 14
    elseif has("gui_macvim")
        set guifont=Ubuntu\ Regular:h12
    elseif has("gui_win32")
        set guifont=Ubuntu:h14:cANSI
    endif

endif

" Put these in an autocmd group, so that we can delete them easily.
augroup vimrcEx
  au!

  " For all text files set 'textwidth' to 78 characters.
  autocmd FileType text setlocal textwidth=78
augroup END

" Add optional packages.
"
" The matchit plugin makes the % command work better, but it is not backwards
" compatible.
" The ! means the package won't be loaded right away but when plugins are
" loaded during initialization.
if has('syntax') && has('eval')
  packadd! matchit
endif
```

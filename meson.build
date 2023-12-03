project('xiox', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

if get_option('buildtype').startswith('debug')
  add_project_arguments('-DDEBUG', language : 'c')
endif

source_files = [
  'term.c',
  'drawing.c'
]
sources = []

foreach file : source_files
    full_path = join_paths('src', file)
    sources += files(full_path)
endforeach

executable(
  'xiox',
  'src/xiox.c',
  sources: sources,
  include_directories: include_directories('src'),
)

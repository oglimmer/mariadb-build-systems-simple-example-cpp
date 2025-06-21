project('maria_test', 'cpp',
  default_options: ['cpp_std=c++20']
)

mariadb_dep = dependency('mariadb', method: 'pkg-config', required: true)

executable('maria_test', 'main.cpp',
  dependencies: [mariadb_dep]
)

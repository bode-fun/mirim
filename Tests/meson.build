test_sources = mirim_sources
test_sources += files([
    'main.cpp',
])

catch2 = dependency('catch2-with-main', version: '3.4.0')

executable('mirim-test', test_sources, include_directories: mirim_inc, dependencies: [catch2])

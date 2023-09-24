test_sources = mirim_sources
test_sources += files(
    'main.cpp',
)

catch2_dep = dependency('catch2-with-main', version: '3.4.0')

test_exe = executable('mirim-test', test_sources, include_directories: mirim_inc, dependencies: [catch2_dep])

test('tests', test_exe)

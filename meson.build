# TODO: See References:
# - https://gitlab.gnome.org/GNOME/recipes
# - https://github.com/cisco/openh264
# - https://github.com/andlabs/libui
# - https://github.com/swaywm/sway
# - https://github.com/linuxmint/nemo
# - https://gitlab.gnome.org/GNOME/gnome-photos
project(
    'Mirim',
    'cpp',
    default_options: [
        'cpp_std=c++20', # TODO: Update to c++23
        'warning_level=3',
        # 'werror=true',
        # 'optimization=0',
        # 'prefer_static=false',
        # 'debug=true',
        # 'default_library=shared'
        # 'buildtype=debug',
        # 'b_sanitize=address',
        # 'b_lundef=false' # For address sanizier
        'cpp_args=-fno-omit-frame-pointer'
	],
)

mirim_sources = files([
    'Sources/main.cpp',
    'Sources/Tokenizer/token.cpp',
    'Sources/Tokenizer/tokenizer.cpp',
])

mirim_exe = executable('mirim', mirim_sources)

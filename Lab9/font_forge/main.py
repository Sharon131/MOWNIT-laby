import fontforge

wanted_chars = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
                    't', 'v', 'u', 'w', 'x', 'y', 'z',
                    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
                    'T', 'V', 'U', 'W', 'X', 'Y', 'Z',
                    'zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine',
                    'comma', 'period', 'question', 'exclam', 'semicolon', 'colon', 'space'}

capital_letters = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
                        'T', 'V', 'U', 'W', 'X', 'Y', 'Z'}


def export_char(char_name, path):
    file_name = " "
    if char_name in wanted_chars:
        if char_name in capital_letters:
            filename = path + char_name + "_capital.png"
        else:
            filename = path + char_name + ".png"
        oswald_font[char_name].export(filename)


merriweather_font = fontforge.open("Merriweather-Light.ttf")
lora_font = fontforge.open("Lora-Regular.ttf")
open_sans_font = fontforge.open("OpenSans-Regular.ttf")
oswald_font = fontforge.open("Oswald-Light.ttf")

merriweather_path = "C:\\Users\\pastu\\Documents\\MOWNIT\\Laby\\Lab9\\fonts\\Serif\\Merriweather\\"
lora_path = "C:\\Users\\pastu\\Documents\\MOWNIT\\Laby\\Lab9\\fonts\\Serif\\Lora\\"
open_sans_path = "C:\\Users\\pastu\\Documents\\MOWNIT\\Laby\\Lab9\\fonts\\Sans-serif\\OpenSans\\"
oswald_path = "C:\\Users\\pastu\\Documents\\MOWNIT\\Laby\\Lab9\\fonts\\Sans-serif\\Oswald\\"

for name in merriweather_font:
    export_char(name, merriweather_path)

for name in lora_font:
    export_char(name, lora_path)

for name in open_sans_font:
    export_char(name, open_sans_path)

for name in oswald_font:
    export_char(name, oswald_path)

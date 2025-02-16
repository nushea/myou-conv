This program converts any file that uses any arbitrary number base to base ten to make it compatible with regular compilors :3

The program knows which base to use using the commented text as formatted below

>-#BASE#-<

where the >-# and #-< are just decoration, (this can be changed from config.h)

or to overwrite it you type the number as 

[number][BASE_AFIX] where the digits of the number have to start with a value 0-9 as to avoid confusion with other variables.

the base names are as follows:

[number]b -> binary
[number]t -> ternary
[number]q -> quaternary
[number]s -> senary
[number]o -> octal
[number]i -> decimal (ie if using another base such as dozenal, ignore (or dont convert) this number)
[number]d -> dozenal
[number]x -> hexadecimal
[number]m -> base32
[number]h -> sexagesimal

[number]_[base] -> the number followed by _ and then the base that it should convert to (where the base is described in decimal)
eg use: 4C_13 == 64 (4*13 + 12), 403_9 == 327 (4*81 + 0*9 + 3)


For this initial version the only usage is to convert the file as below

myou_conv [INPUT_FILE_NAME] [OUTPUT_FILE_NAME]

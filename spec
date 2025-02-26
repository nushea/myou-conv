This program converts any file that uses any arbitrary number base to base ten to make it compatible with regular compilors :3

The program knows which base to use using the commented text as formatted below

>-#BASE

where the >-# is just a decorator, (this can be changed)

or to overwrite it you type the number as 

the program removes the 1st character of the decorator as to not try to convert an already converted value if the program is to be ran again by accident but perserves the rest as to not disrupt readability

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

example of usage:

int function(){
	//>-#16This is the base hex
	int a = 6F;
	int b = 10010b;
	for(int i = 0; i < 100; i+= 1){
		a *= 10.8;
		a += 10%10.2;
		b /= 10.28;
	}
	//>-#2
	while(a)
		printf("%i", a%10);
		a/=10;
}

#include "NeoC/Exception.h"
#include "NeoC/String.h"
#include "NeoC/SGR.h"
#include "NeoC/CC.h"

#include <stdio.h>

void main() $NeoC {
	String_t *neoC = String.New("NeoC");
	String_t *isA = String.New(" is a ");
	String_t *neo = String.New("Neo ");
	String_t *CPEL = String.New("C Programming Environment Library");
	String_t *exc = String.New(" !");

	String_t *msg = String.NewFormat(
		"%c%c%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
		CC.HT, CC.HT, SGR.SET.BOLD, SGR.TEXT.LIGHT_YELLOW,
		String.Unpack(neoC), SGR.RESET.BOLD, SGR.TEXT.YELLOW,
		String.Unpack(isA), SGR.SET.BOLD, SGR.SET.BLINK,
		SGR.TEXT.LIGHT_RED, String.Unpack(neo),SGR.RESET.BOLD,
		SGR.RESET.BLINK, SGR.SET.UNDERLINED, SGR.TEXT.GREEN,
		String.Unpack(CPEL), SGR.RESET.UNDERLINED, SGR.SET.BOLD,
		SGR.TEXT.LIGHT_CYAN, String.Unpack(exc), SGR.RESET.BOLD,
		SGR.TEXT.DEFAULT
	);

	printf("%s%c", String.Unpack(msg), CC.LF); // Console.WriteLine(msg);
	printf("%c%c", CC.HT, CC.HT);

	String_t *text = String.NewFormat(
		"%s%s%s%s%s", String.Unpack(neoC), String.Unpack(isA),
		String.Unpack(neo), String.Unpack(CPEL), String.Unpack(exc)
	);

	for (int32_t i = 0; i < String.GetLength(text); i++) { // foreach () {
		printf("%c", (String.GetCharAt(text, i) == 'm')? '^' : '.');
	}

	printf("%c%c%c", CC.LF, CC.HT, CC.HT);

	try {
		int32_t fm = String.FirstIndexOf(text, 'i');
		int32_t lm = String.LastIndexOf(text, 'i');

		for (int32_t i = 0; i < String.GetLength(text); i++)
			printf("%c", (i == fm || i == lm)? '~' : ' ');

		printf("%c", CC.LF);
	} catch (String.RuntimeException) {
		printf("[Error] Target Not Found.\n");
	} end
} NeoC$

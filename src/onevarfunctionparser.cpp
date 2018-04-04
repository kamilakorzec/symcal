#include "lib/onevarfunctionparser.h"

OneVarFunction OneVarFunctionParser::fromSuffixNotation(string input)
{
    // Wrzucaj wszystko jak leci
    // Tokeny rozdziela spacja

    OneVarFunction ovf(input, "");
    return ovf;
}

OneVarFunction OneVarFunctionParser::fromStandardNotation(string input)
{

    // Póki zostały symbole do przeczytania wykonuj:
    // Przeczytaj symbol.
    // Symbole są między sobą rozdzielone operatorami - np. 12+3 -> (12, +, 3)
    // Jeśli symbol jest liczbą dodaj go do kolejki wyjście.
    // Jeśli symbol jest funkcją włóż go na stos.
    // Jeśli symbol jest znakiem oddzielającym argumenty funkcji (np. przecinek):
    // Dopóki najwyższy element stosu nie jest lewym nawiasem, zdejmij element ze stosu i dodaj go do kolejki wyjście. Jeśli lewy nawias nie został napotkany oznacza to, że znaki oddzielające zostały postawione w złym miejscu lub nawiasy są źle umieszczone.
    // Jeśli symbol jest operatorem, o1, wtedy:
    // 1) dopóki na górze stosu znajduje się operator, o2 taki, że:
    // o1 jest lewostronnie łączny i jego kolejność wykonywania jest mniejsza lub równa kolejności wyk. o2,
    // lub
    // o1 jest prawostronnie łączny i jego kolejność wykonywania jest mniejsza od o2,
    // zdejmij o2 ze stosu i dołóż go do kolejki wyjściowej i wykonaj jeszcze raz 1)
    // 2) włóż o1 na stos operatorów.
    // Jeżeli symbol jest lewym nawiasem to włóż go na stos.
    // Jeżeli symbol jest prawym nawiasem to zdejmuj operatory ze stosu i dokładaj je do kolejki wyjście,
    // dopóki symbol na górze stosu nie jest lewym nawiasem, kiedy dojdziesz do tego miejsca zdejmij lewy nawias ze stosu bez dokładania go do kolejki wyjście. Teraz, jeśli najwyższy element na stosie jest funkcją, także dołóż go do kolejki wyjście.
    // Jeśli stos zostanie opróżniony i nie napotkasz lewego nawiasu, oznacza to, że nawiasy zostały źle umieszczone.
    // Jeśli nie ma więcej symboli do przeczytania, zdejmuj wszystkie symbole ze stosu (jeśli jakieś są) i dodawaj je do kolejki wyjścia. (Powinny to być wyłącznie operatory, jeśli natrafisz na jakiś nawias oznacza to, że nawiasy zostały źle umieszczone.)


    // Source:
    // https://pl.wikipedia.org/wiki/Odwrotna_notacja_polska#Algorytm_konwersji_z_notacji_infiksowej_do_ONP

    for(int i = 0; i < input.length(); i++) {
        if(input[i] != ' ') {
            if(operators.isOperator(input[i])) {

            }
            else { //character

            }
        }
    }

    OneVarFunction ovf("", input);

    return ovf;
}

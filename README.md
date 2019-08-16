## Gentod cipher

Method in which each letter in the plaintext is replaced by a symbol some fixed number of positions behind the alphabet and vice versa based on [Gboard](https://play.google.com/store/apps/details?id=com.google.android.inputmethod.latin) (the Google Keyboard).

The technique encrypts pairs of letters _(bigrams or digrams)_, instead of single letters as in the simple [substitution cipher](https://en.wikipedia.org/wiki/Substitution_cipher) and rather more complex [Vigenère cipher](https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher) systems then in use. The Gentod is thus significantly harder to break since the [frequency analysis](https://en.wikipedia.org/wiki/Frequency_analysis) used for simple substitution ciphers does not work with it. The frequency analysis of bigrams is possible, but considerably more difficult. With 600 possible bigrams rather than the 26 possible monograms (single symbols, usually letters in this context), a considerably larger cipher text is required in order to be useful.

## Description

The Gentod cipher uses a 4 by 4 table containing a alphabet and symbol. Memorization of the Gboard and 4 simple rules was all that was required to create the 4 by 4 table and use the cipher.

<img src="https://user-images.githubusercontent.com/25837540/63173603-6c723080-c06a-11e9-92a6-c6a4c2c94a09.jpg" alt="" data-canonical-src="https://user-images.githubusercontent.com/25837540/63173603-6c723080-c06a-11e9-92a6-c6a4c2c94a09.jpg" width="350" />
<img src="https://user-images.githubusercontent.com/25837540/63173601-6bd99a00-c06a-11e9-97b7-91001651a7bc.jpg" alt="" data-canonical-src="https://user-images.githubusercontent.com/25837540/63173601-6bd99a00-c06a-11e9-97b7-91001651a7bc.jpg" width="350" />

## History and usage

At that time, there was someone who made a typo because he forgot to change the keyboard type from symbol to alphabet mode.

<img src="https://user-images.githubusercontent.com/25837540/63173799-d1c62180-c06a-11e9-87f2-3059d1a2ecea.png" alt="" data-canonical-src="https://user-images.githubusercontent.com/25837540/63173799-d1c62180-c06a-11e9-87f2-3059d1a2ecea.png" width="400" />
<img src="https://user-images.githubusercontent.com/25837540/63173797-d1c62180-c06a-11e9-82f7-e4d4c65155d6.png" alt="" data-canonical-src="https://user-images.githubusercontent.com/25837540/63173797-d1c62180-c06a-11e9-82f7-e4d4c65155d6.png" width="400" />
<img src="https://user-images.githubusercontent.com/25837540/63173796-d12d8b00-c06a-11e9-9cff-afdadbee799a.png" alt="" data-canonical-src="https://user-images.githubusercontent.com/25837540/63173796-d12d8b00-c06a-11e9-9cff-afdadbee799a.png" width="400" />


Then, we use this as our encrypted communication.

<img src="https://user-images.githubusercontent.com/25837540/63173600-6bd99a00-c06a-11e9-802e-b0e077202d1e.jpg" alt="" data-canonical-src="https://user-images.githubusercontent.com/25837540/63173600-6bd99a00-c06a-11e9-802e-b0e077202d1e.jpg" width="400" />
<img src="https://user-images.githubusercontent.com/25837540/63173599-6b410380-c06a-11e9-84e7-3a630910b328.jpg" alt="" data-canonical-src="https://user-images.githubusercontent.com/25837540/63173599-6b410380-c06a-11e9-84e7-3a630910b328.jpg" width="400" />

## Example

```
$ make test
$ ./test/test
```

When encrypting, a person looks up each letter of the message in the "plaintext" line and writes down the corresponding letter in the "cipher" line.
```
Plaintext: hello, world!
Gentod cipher: -3//9, 294/$n
```

The encryption can also be represented using [polybius square](https://en.wikipedia.org/wiki/Polybius_square) by first transforming the letters into symbols, according to the scheme, a → @, b → ;, ..., z → \*.

## Cryptanalysis

Like most classical ciphers, the Gentod cipher can be easily cracked if there is enough table. When only the ciphertext is known, brute force cryptanalysis of the cipher involves searching through the key space for matches between the frequency of occurrence of digrams (pairs of letters) and the known frequency of occurrence of digrams in the assumed language of the original message.

Cryptanalysis of Gentod is similar to that of [four-square](https://en.wikipedia.org/wiki/Four-square_cipher) and [two-square](https://en.wikipedia.org/wiki/Two-square_cipher) ciphers, though the relative simplicity of the Gentod system makes identifying candidate plaintext strings easier. Identifying nearby digraphs in the ciphertext and matching the pattern to a list of known plaintext words containing the pattern is an easy way to generate possible plaintext strings.

A different approach to tackling a Gentod cipher is the [shotgun hill climbing](https://en.wikipedia.org/wiki/Random-restart_hill_climbing) method. This starts with a a-z of letters. Then minor changes are introduced (i.e. switching letters, rows, or reflecting the entire square) to see if the candidate plaintext is more like standard plaintext than before the change (perhaps by comparing the digrams to a known frequency chart). If the new square is deemed to be an improvement, then it is adopted and then further mutated to find an even better candidate. Eventually, the plaintext or something very close is found to achieve a maximal score by whatever grading method is chosen. This is obviously beyond the range of typical human patience, but computers can adopt this algorithm to crack Gentod ciphers with a relatively small amount of text.

Another aspect of Gentod that separates it from four-square and two-square ciphers is the fact that it will never contain a double-letter digram, e.g. EE. If there are no double letter digrams in the ciphertext and the length of the message is long enough to make this statistically significant, it is very likely that the method of encryption is Gentod.
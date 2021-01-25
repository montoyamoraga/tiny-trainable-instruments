# Markdown guide

Markdown is a lightweight markup language with simple, intuitive syntax. Aside from a few key differences, it is largely the same as plaintext. This markdown guide is itself written using markdown!

This guide is heavily based off of the [GitHub Markdown Guide](https://guides.github.com/features/mastering-markdown/).

## Headers
To create a header, place a `#` before the header text. You can include from one `#` to six `######`, which progressively makes the text smaller. For example the header to this section is written as `## Headers`, and the header to this guide is `# Markdown Guide`!

## Text

```
You can italicize text by surrounding it with *asterisks* or with _underscores_! Bolded text is the same, but with **double asterisks** or __double underscores__. You can combine the two, _**like this**_! Also, you can strikethrough text using ~~double tildes~~.
```

You can italicize text by surrounding it with *asterisks* or with _underscores_! Bolded text is the same, but with **double asterisks** or __double underscores__. You can combine the two, ***like this***! Also, you can strikethrough text using ~~double tildes~~.

## Linking

```
To link to a website, surround the clickable text with square brackets, and the link with parentheses, [like this](https://github.com/montoyamoraga/tiny-trainable-instruments)!
```

To link to a website, surround the clickable text with square brackets, and the link with parentheses, [like this](https://github.com/montoyamoraga/tiny-trainable-instruments)!

## Images

```
Inserting images has a very similar syntax to linking, but with a ! preceding the open square bracket: ![Example image](https://github.com/montoyamoraga/tiny-trainable-instruments/blob/main/docs/images/MIT_Media_Lab_Logo.png "MIT Media Lab Logo")
```

Inserting images has a very similar syntax to linking, but with a ! preceding the open square bracket: ![Example image](https://github.com/montoyamoraga/tiny-trainable-instruments/blob/main/docs/images/arduino_placement.png "Arduino on breadboard")

## Quotes

```
> To quote someone, place a > before the quote. - Maxwell Wang
```

> To quote someone, place a > before the quote. - Maxwell Wang

## Lists
```
* You can add a bullet points by putting an asterisk and a space before each item.
  * You can indent points by putting a two-space indent before the asterisk.
- Dashes work too, if you prefer.

Numbered lists are preceded by:
1. A number
2. A period
3. A space
```

* You can add a bullet points by putting an asterisk and a space before each item.
  * You can indent points by putting a two-space indent before the asterisk.
- Dashes work too, if you prefer.

Numbered lists are preceded by:
1. A number
2. A period
3. A space

## Code

    You can insert inline code like `print("Hello World!")` by surrounding it with backticks.

    Surround block code with triple backticks:

    ```
    print("Hello World!")
    ```

    or by indenting it:

        print("Hello World!")

    And you can get syntax highlighting by specifying the language!

    ```python
    print("Hello World!")
    ```

You can insert inline code like `print("Hello World!")` by surrounding it with backticks.

Surround block code with triple backticks:

```
print("Hello World!")
```

or by indenting it:

    print("Hello World!")

And you can get syntax highlighting by specifying the language!

```python
print("Hello World!")
```
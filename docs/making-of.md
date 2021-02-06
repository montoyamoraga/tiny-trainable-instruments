# Making of

In this section of the documentation, we explain the main tools we are using for this project.

## Jupyter

Jupyter is a free, open-source browser application that allows users to easily read and write code in a clean, accessible environment. Code is segmented into cells, which users can execute individually by clicking into and selecting the triangle "play" button at the top. Subsequent code executes based on operations done in previous cells. Basically, Jupyter notebooks allow programmers to create clean, step-by-step interactive walkthroughs through their code.

For more details, please read the official quick start guide at [https://jupyter-notebook-beginner-guide.readthedocs.io/en/latest/index.html](https://jupyter-notebook-beginner-guide.readthedocs.io/en/latest/index.html).

## Markdown

The documentation of this project is written using Markdown, including this document!

Markdown is a lightweight markup language with simple, intuitive syntax. Aside from a few key differences, it is largely the same as plaintext.

This guide is heavily based off of the [GitHub Markdown Guide](https://guides.github.com/features/mastering-markdown/).

### Headers

To create a header, use a `#` before the header text. You can include from one `#` to six `######`, which progressively makes the text smaller. For example the header to this section is written as `## Headers`, and the header to this guide is `# Markdown`!

### Text

You can italicize text by surrounding it with *asterisks*, or you can make it bold with, or do both with three asterisks ***like this***!

### Links

To link to a website, surround the clickable text with square brackets, and the link with parentheses, [like this](https://github.com/montoyamoraga/tiny-trainable-instruments)!

### Images

Inserting images has a very similar syntax to linking, but with a ! preceding the open square bracket: ![Example image](https://github.com/montoyamoraga/tiny-trainable-instruments/blob/main/docs/images/arduino_placement.png "Arduino on breadboard")

### Quotes

> To quote someone, place a > before the quote. - Maxwell Wang

### Lists

* You can add a bullet points by putting an asterisk and a space before each item.
  * You can indent points by putting a two-space indent before the asterisk.
- Dashes work too, if you prefer.

Numbered lists are preceded by:
1. A number
2. A period
3. A space

### Code

You can insert inline code like `print("Hello World!")` by surrounding it with backticks, and you can also surround a block code with triple backticks:

```
print("Hello World!")
```
You can get syntax highlighting by specifying the language!

```python
print("Hello World!")
```

# Contributing

If you find an error or have a comment, please start a discussion by submitting an issue on our repositories!

* https://github.com/montoyamoraga/tiny-trainable-instruments/issues
* https://github.com/montoyamoraga/TinyTrainable/issues

## Tools

## clang-format

Tool for automation of formatting to source code. More information here: https://clang.llvm.org/docs/ClangFormat.html

### Doxygen

Tool for generating documentation from the source code, for more information please visit https://www.doxygen.nl/.

### GitHub Actions

Every time we push code to the TinyTrainable repositories, a GitHub action creates a virtual machine, and runs a script to generate the Doxygen documentation and push it to the gh-pages branch.

### Jupyter

Jupyter is a free, open-source browser application that allows users to easily read and write code in a clean, accessible environment. Code is segmented into cells, which users can execute individually by clicking into and selecting the triangle "play" button at the top. Subsequent code executes based on operations done in previous cells. Basically, Jupyter notebooks allow programmers to create clean, step-by-step interactive walkthroughs through their code.

For more details, please read the official quick start guide at [https://jupyter-notebook-beginner-guide.readthedocs.io/en/latest/index.html](https://jupyter-notebook-beginner-guide.readthedocs.io/en/latest/index.html).

### Markdown

The documentation of this project is written using Markdown, including this document!

Markdown is a lightweight markup language with simple, intuitive syntax. Aside from a few key differences, it is largely the same as plaintext.

This guide is heavily based off of the [GitHub Markdown Guide](https://guides.github.com/features/mastering-markdown/).

## GitHub instructions

### To contribute to this repository:

1. Create a free GitHub account
2. Fork the repository
3. Clone your new repository to your computer

```bash
git clone https://github.com/your_username/tiny-trainable-instruments.git
```

Optionally, you can also clone the submodules of this repository, with the command 


```bash
git submodule update --init --recursive
```

4. Change directory (cd) into the project folder

```bash
cd tiny-trainable-instruments
```

5. Make some changes

6. Stage and make a commit to your repository on your computer

```bash
git add .
```

```bash
git commit -m "your comment"
```

7. Push your commit to your personal fork on GitHub

```bash
git push
```

8. Open your repository online

9. Open a pull request and wait for comments or approval

### For subsequent pull requests:

If your fork is behind [origin](https://github.com/montoyamoraga/tiny-trainable-instruments.git):

1. Open a pull request, but reverse the order (merge main into your fork)

2. Approve the merge to update your fork

3. Pull your repository to your computer

```bash
git pull
```

4. Continue from step 4 above

## Contributing documentation

For more information about how to contribute documentation to an open source artistic project, we recommend looking at the documentation by the p5.js project, available at https://github.com/processing/p5.js/blob/main/contributor_docs/contributing_documentation.md

## Adding submodules

If you think there are more repositories we should include as submodules for archival purposes, use the following command, replacing GITPATH with the location of the repository you want to include, and FOLDERPATH with the destination.


```bash
git submodule add GITPATH FOLDERPATH 
```

## Helper scripts

The helper scripts are located on the assets/ folder. To run them, cd to assets/ and then use the following commands

### Compiling code

This script uses arduino-cli for checking the compilation of all examples of TinyTrainable.

```bash
sh compile-code.sh
```

### Delete metadata

This script uses exiftool to delete the metadata of all pictures in docs/

```bash
sh delete-metadata.sh
```

### Format code

This script uses clang-format to organize all the code in TinyTrainable

```bash
sh format-code.sh
```

### Markdown to PDF

This script uses pandoc to convert the documentation from Markdown to PDF format.

```bash
sh markdown-to-pdf.sh
```

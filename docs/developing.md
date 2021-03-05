# Developing

## Cloning repository

There are 2 options to clone this repository:


Using first `git clone` for cloning the repository, and then `git submodule` to download the contents of the submodules

```bash
git clone https://github.com/montoyamoraga/tiny-trainable-instruments.git
git submodule update --init --recursive
```

The other option is to perform both actions with `git clone` and the `--recursive` flag

```bash
git clone ---recursive https://github.com/montoyamoraga/tiny-trainable-instruments.git
```

## Submodules

The Arduino library TinyTrainable lives in its own repository, and also as a submodule on this repository.

Command for downloading the contents of the submodules

```bash
git submodule update --init --recursive
```

## Adding submodules

cd to TinyTrainable and:

```bash
git submodule add GIT_PATH libraries/FOLDERNAME 
```

## Formatting

```bash
sh format.sh
```

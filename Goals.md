# Project goals

## To run on as many platforms as possible

Quon can target almost any programming language and platform, and my goal is to make it so that no matter what computer, OS, and platform that you use, quon will work there.

## Completely seamless integration

No FFI or definitions required, 100% seamless interoperation with the target language.  Call any native functions you want, without any extra code.

And you can directly call any quon function from the target language.

## Neat output

Target languages fall into two rough categories:

### "Normal" languages.  

All the usual language features from other programming languages, like functions and types.  The compiler output will be as neat and readable as possible.  So e.g. the C output should be similar to what a person would write.

### Underpowered langauges.  

Targets like Assembler, BASH/CSH etc.  The output will be unreadable compiler barf.  I still try to make it comprehensible, but it will look machine generated.

## Stability

In general, don't waste the previous work people have done on the compiler or programming language.  Don't break backwards compatibility, or provide an upgrade path if I do.

## Excellent user feedback

The compiler will try to be as informative and helpful as possible.  There will be lots of error and consistency checks, and the messages will all

    * make sense
    * be clear
    * be helpful

## Support tooling and program analysis

The project will provide as much help as possible to support editors, static analysers, alternate front ends etc.  

# General principles

## Keep the compiler as small as possible

Use preprocessors, external tools and etc to keep the compiler small.  A small compiler is easy to maintain, test and port.  My guess is that a lot of programming languages have failed because they were too complicated for anyone to pick up and maintain by themselves.  Keeping a small, neat core will ensure that people can drop in and easily fix bugs or add their own improvements.

## Personal experimentation should be encouraged

This project has a very personal feel for me, and I would like other people to have the same experience.  This isn't a project owned by some other group of people, it is your project.

It should be easy for anyone to open it in an editor, make some experimental changes, and immediately see their new feature working in front of them.

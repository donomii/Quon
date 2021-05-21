## Sun 3 Mar, 2019

I just spent a frustrating 4 hour debugging session tracking down the fact that I didn't really understand how '() works in Scheme.  It is slightly frightening to realise that I have been programming Scheme on and off for 20 years without actually knowing how it works under the hood.

But I suppose that always has to be true.  Even if I understand the programming language completely, I don't really understand how the CPU works, or the physics that drive it, or etc...  I just do the best I can and hope it works most of the time.

In this case, I didn't understand that '() was actually a null pointer, as in C, because that is what goes in the cdr field to indicate that the list has finished.  I also didn't realise that the null pointer has a type of "list" in Scheme.  Having to write that for C made it clear.  I also could not have figured it out without the advanced debugging tools that we have today.  The people who designed this without any support were significantly better programmers than me.

In general I have been trying to copy the functionality of Scheme without actually writing a Scheme interpreter.  The reason being that I really want to be able to call native functions without ANY kind of FFI at all.  My previous project, Throff, floundered when I realised that no matter how good I made it, I would have to spend vast amounts of time writing and debugging boilerplate declarations to connect native functions to the interpreter.  Even connecting a simple graphics library requires connecting 20 or more functions, and larger, more complicated libraries could take 100s.

So I have a strict requirement that I can call native functions directly from my code, and that native functions can call my code directly.  Absolutely no barriers.  That means I have to use native types, native calling conventions, and no lambdas, closures, coroutines, continuations or any of the other stuff that would actually make my job quick and easy.  I'm really beginning to appreciate the simple and effective design of Scheme, but it really doesn't work well without lambdas, and I don't have an easy or quick way to implement those just now.

Most of my time so far has been implementing the most basic of Scheme functions.  Car, cdr, list?, empty? etc.  Today I have just finished adding basic assoc lists, because I really need some kind of key-value data structure, and most languages (that I care about right now) don't provide one out of the box.  Assoc lists are nice, and even better, they stress my implementations of srfi1 functions, catching a lot of bugs.

So I have now reached the point where I am ready to build my AST, and from there outputting code is quite quick and easy.

### Notes on the motivation for this project, and the downfall of Perl

Perl is diminishing, causing many people to rejoice.  This is an odd reason for merriment, because something existing shouldn't bother anyone, something vanishing shouldn't please anyone, and yet here we are.

But why is it fading?  The people who worked on the Perl6 project seemed to believe the most common criticism of Perl - that the syntax was horrible, and the features were confusing.  That might be true, but it didn't bother fans for 20 years, and I don't think that people suddenly changed their minds on the issue.

My suspicion is that Perl is less popular, because it hasn't adapted to modern computing, and so people literally cannot use it.  I think that if Perl worked better on windows, and ran in the browser and on Android etc, that it would be much more popular today.  But there are projects to run python and scheme and many more in the browser, and they are not popular, so clearly there are other factors here too.

Regardless, I have found it hard to actually install and use Perl in recent years.  Perl is currenlty broken on my MacOS development machine, for reasons I have not yet bothered to investigate.  None the less, it is frustrating to be cut off from all my useful scripts and tools, and I find myself wishing that Perl was easier to fix.  And I think this is a large problem.  Perl is a large, complicated, sprawling install with many complicated rules to accomodate many different
environments, some of which do not exist anymore.  But their ghost lingers on in the code.

Patching Perl is nearly impossible for me.  It would take weeks or months for me to figure out the most basic of changes, and then I would have to convince the maintainer team that my new idea was worthwhile, and so on.  The interpreter base that made Perl such a success in earlier years is now a massive drag.  It can't be ported into the browser, or into Java for Android, or other environments where I actually want it.  

There are projects like Perlito to help run your Perl code in new environments, but they don't move Perl itself, so your programs are heavily restricted in functionality and basically have to be written anew.  I certainly hope that perl-the-language can separate itself from perl-the-interpreter, but I don't care enough to actually join the project.

This is the motivation for my current project.  I want a programming language that can change itself to move from platform to platform as I need it, picking its way across the the programming language swamp like a flamingo or whichever bird with long legs lives in swamps and walks around lots.  Help me out here, I'm not an ornathologist.

I really have no idea if this project will result in anything useful to myself or other people, but I am annoyed enough at the current state of affairs that I am putting the work in to try and make something better.  Here's hoping for the best.

## Sun 17th March, 2019

Sunday seems to be a good day for reflection.  Funny how that works.

In the last two weeks I manage to get the project self hosting.  It's a major milestone, and I thought I would be much happier about achieving it.  But instead I ended up frustrated when I discovered that I still couldn't write full programs.  It was self hosting, but that didn't mean it could compile anything else except itself.  It needed library loading abilities, and it took a surprisingly long time to add them.  I think some of the decisions I made while implementing library loading will cause problems in the future.  Still, it's better to have it than not have it, since now I can actually compile a complete program.

The compiled programs work well.  The self-compiled compiler runs so fast that it finishes before I can lift my finger off the key, and the little demo programs I am writing finish equally quickly.  I don't feel the need to do speed tests, because the code runs at native speed, and the lisp code runs much slower, so if you care about speed you write using native functions and avoid the lisp part as much as possible.

I didn't realise that I would miss map() and fold() as much as I do.  Because I don't have them, I have to write a new recursive function for every place where I would normally use map().  This turns out to be a lot of places, and really shows up that I have too much boilerplate in my function definitions.  On the up side, it is easy for me to take lisp and scheme functions and quickly adapt them to work here.  I should be able to reproduce a large part of srfi/1 in a short amount of time.

And naturally, none of this would be a problem if I had closures, but that is not possible in general, and solutions like lambda lifting make the output code look awful, so I'm trapped for the moment.  I'm still thinking about the best way to get them in, but I have no ideas for now.  I want to add "tagging" to variables, so I might be able to hide a context in there.

PS And of course I declared victory too soon, library loading is still not quite working.  It's a curiously difficult problem, mainly because I didn't design it from the start, so now I have to work around the current design.

## Mon 18th March, 2019

Library loading now working at a basic level, although it doesn't handle the same library being loaded twice.  I'm definitely regretting not designing this in from the start.  I think the solution still would hve looked similar, but been much less stressful.

I spent some time thinking about tagging variables, and I'm pretty sure it's a good idea.  It will certainly solve many of the problems I currently have with the compiler, and make my code smaller, neater and more comprehensible.  The downsides appear to be possible security holes and confusion to programmers that aren't aware of the feature.  Also memory leaks and potential collisions when multiple programmers think that they are the only ones writing to the tag.

Let's try some examples to see how it might work:

    (set greeting (tag "Said by Bob" (boxString "Hello World")))

    (display greeting)
    >Hello World

    (display (gettag greeting))
    >Said by Bob

However we can attach anything as a tag, so making it an assoc list is a natural thing to do:

    (set greeting (atag "author" "Bob" (boxString "Hello World")))

    (display greeting)
    >Hello World

    (display (agettag "author" greeting))
    >Bob

Tagging will use purely functional data structures, so the old tag will not be altered in place, (tag ) will copy the data structure, adding a new tag in the process.

The driving need for tagging is to be able to add information to the parse tree, such as line numbers for error messages.  At the moment, we cannot print line numbers for error messages, which makes the compiler almost unusable.

Addendum:  I reversed the "then" and "else" clauses in an if statement and spent 3 hours debugging it.  I desperately need better error messages and debugging tools.


## Tuesday 26th March

I implemented tagging, and it worked better than expected.  I have built three error handling mechanisms on top of it, and I look forwards to working with it more.  I wish I had attempted it earler, it would have made my code so much shorter and more importantly, nice to read.

Tagging still isn't fully implemented, but even in its current form, it's effective.  Tags are very obviously objects (but I don't have objects, so they are just structures) - structures with a "default" element.  So you use variables normally, and they work nomally.  But when you call the special "getTag" function on them, you get a different value.  Let's look at an example.

	[printf "%s" [unBoxString function_name]]
	>add

No surprises here.

	[printf "%s defined at line %d\n" [unBoxString function_name] [getTag "line" function_name]]
	>382

```function_name``` holds the name of the function.  But it is also tagged with other information like the line number and file name.  This allows me to print error messages with a location, while still keeping the parser code reasonably simple.

Could I do all of this with objects?  Of course.  But there are several reasons not to.  First of all, I would have to implement objects, and I would have to implement them without the help of error messages.  I have worked like this before, and it was an utterly miserable experience that I never want to repeat.  I think good error messages are more important than almost any other part of the programming language.

Addionally, objects don't really do what I want.  They can be forced to work, but you normally can't dynamically add and remove properties of an object, as you can with tags, and also people reasonably complain that by doing the obvious (adding a line property to the root class), they don't want to have a "line" property on every single object in the program, since many objects won't have a "line number".  Again, you could work around it by adding a "tag" property to the top of the class hierarchy, which holds a dictionary object, so every object now has a flexible tag system, but you've just done the same thing I did with stuctures, but it requries an object system with tens of thousands of lines of code.

The other reason to avoid objects is that they tend to kill any chance of applying functional programming principles.  There have been attempts at immutable objects, but almost all OO design theory assumes that objects are mutable.  If you want immutable objects, you may as well use closures or monads or whatever.  Objects are univertsally regarded as ways to manage state(via mutation), so even if I managed to get a nicely working immutable object system, it would be regarded as an own goal by most programmers.

The main drawback of tags at the moment is that I can only tag data structures by wrapping them in a "box" structure.  I have plans to tag unboxed structures by recording their pointers in a separate table, but that is far in the future.

The final point is style.  I dislike always having to type "variable.value()" to access the default value of an object.  It is such a clumsy choice to force the programmer to type so much to get the default value.  I want to access the default value as quickly and simply as possible.  And if I want something more complicated, then I should start typing more.

And some thoughts for the future: debugging could become even easier if I record, in the tags, every time a variable's value is set (or where it is created, in functional style).  Then when I get a crash because a variable has the wrong value, I can just check the tags to see where the wrong value was set.  Because that is what I am really looking for when I print a trace, so why bother with the trace when I can get the correct answer immediately?

Addendum:  I could get the same by just modifying the set function to print a line to the log every time I set a variable, which is probably better overall.  No need to write a complicated solution when the simple one works just fine.

## Thursday, 24th August

The big features are all in, and they seem to work.  Tags are fantastic, and now all that remains is putting error messages at the right point.

Program tracing works, although it is less helpful than I hoped.  Stack traces are NOT working, mainly because it is too difficult to detect all the points where a function returns, and put the correct stack trace code there(to remove the function from the trace after it returns).

Quon now targets C, Perl, NodeJs and Java, and I am constantly surprised that this works at all.  Naturally, the programs can't do much, but this project will be very handy for writing algorithm libraries that are wanted on every platform.

The multiple targets have already proved their value.  I managed to improve the code to the point where the current version of the compiler could not read its own code, and my last backup/bootstrap file was from a week ago.  Rolling back would have lost a lot of work.  Luckily, while the C version was't working, the Perl version still ran fine, and I was able to compile a working C version.  Every quon compiler (C, Perl, NodeJS and Java) is able to generate source code for any of the other languages, making it wonderfully robust.

Error checking and reporting is now the top priority - it was almost impossible to write a quon program, because any syntax error would result in the compiler simply printing an empty file.  Now, there are some error messages, covering the most common errors I make (function definitions and if statements).  It would be fascinating to do some data collecting to discover which errors are the most common.  We know which errors are the most common in running code, especially
security-related errors, but I have never heard of a study of errors during the initial creation phase.

The next enhancements after errors seem to be:

* macros
* better type handling, and better types
* first-class functions, or a good way to fake them
* networking
* subprocesses and system functions
* some kind of gui?

## Friday, 21st March, 2021

Quon now has multiple C backends, each one with a new feature.

It also appears to be quite robust.  Apparently I was in a very odd frame of mind while I was writing the ansi C emitter, because I wrote this:

    int andBool(int a, int b) { return a == b;}

That has been in there right from the beginning, and somehow it still worked.  I'm amazed.

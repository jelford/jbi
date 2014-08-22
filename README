# JBI - Just Build It

JBI is a long-running build tool for Java projects. 

The aim is to be able to build a maven-ised project faster. It's still in early
development but the project will be considered a success when it's able to build
a group of interdependent reactors with third party dependencies in less time
than a vanilla maven build.

## Status

This project is _not_ ready for prime time. You're welcome to give it a spin,
but expect very basic functionality to be missing or buggy.

## Usage

`JBI` uses an incremental compile model that avoids some of the work we normally
do when we build a large code base.

### What JBI is not

* `JBI` is not a new compiler. Under the hood, `javac` is invoked directly
* `JBI` is not going to speed up a clean build. At the end of the day, you
are still going to have to compile all your `java` files.
* `JBI` is not going to ask you to through away your existing build confiuration
or spend lots of time configuring it. The aim is to be 100% maven compatible.

### What JBI is

* A long-running process that watches your project and re-builds binaries 
on-demand.

`JBI` attempts to bring the "bottom-up" approach to build from [tup](gittup.org) 
to the Java world. 

# ESTIMATE INTRODUCTION

This is a simple estimation tool designed to help one compute a project cost
within a specified timeframe.

To enjoy most of ESTIMATE and see it's capabilities, I implore you to use it for
huge projects which involves lots of professionals. Though it works as weell as
it was designed, for small projects.

## Description
When using ESTIMATE, we assume that you know the following before:

	1. The number of each professional you would want for the project.
	2. The project timeline. Though this can be adjusted as you continue to
	add and remove professionals into your project.

The software provides the user with various optimal classes:

	1. OPTIMUM - describes the highest level of the optimal classes.
	In this class, the SENIOR level professionals are the highest.
	It is only advised to be used where the number of professionals are less than
	FIVE or equal to five.

	2. SUB-OPTIMAL - describes the mid-level of the optimal classes.
	Herein, the MID-LEVEL professionals are the highest in sum.
	It is also advised for projects where the number of professionals are
	less than or equal to FIVE.

	3. BASIC - describes the junior level of the optimal classes.
	When chosen, it implies that the JUNIOR professionals will be the
	majority in that specific class within the project.
	Also advised for projects where professionals needed are less than or
	equal to FIVE.

	4. EQUILLIBRIUM - describes the state when all the other three previous
	classes balances out.
	It is the ADVISED class for any project, with any number of
	professionals involved.

To start up the project, you will have to build your own database by putting in
entries. The database can have every professional you think you might need for
the project. This stands in place for an actual/persistant database which shall
be designed later as the project progresses.

From the database, you can add unto you project any professional you would want
to involve witjin the project. These profesionals can be removed at any time
before and even after the computations.

When doing cost entries, you can use an average of cost estimate for every
professiobal.

NOTE: every professional level(SENIOR, MID-LEVEL, JUNIOR) must be involved. To
mean that for every profession selected, there must be at least ONE of the
levels.

## Language and implementation

C Language is wholly used within the project to demonstrate the power and
ability of PROCEDURAL programming, a programming paradigmn I hold so dearly at
heart.

## Coding Style
Betty Coding Style.

Check compliance by running:

	betty main.c computations/*.c init_prof/*.c ratios/*.c 

If you don't have Betty installed in your PC, install it by:

#### 1. Clone the Betty repository

	git clone https://github.com/holbertonschool/Betty.git

#### 2. Change into the Betty repository

	cd Betty

#### 3. Install Betty using the included installer script:

	sudo ./install.sh

After installation you can go back to project repository and run the command as
earlier stated.

## Features

* Creating a non-persistant database.
* Creating a project
* Computing project cost; both monthly and within the specified timframe.
* Computing the total number of professionals needed for the project.
* Adjusting timeframes and professionals involved in the project.
* Compute cost per profession involved in the project.
	- With this you can see where most of the money goes to in your project.

## Getting Started

These instructions will help you get a copy of the project up and running on your local machine.

###  Prerequisites
* Linux-based/Linux-like operating system(e.g., Ubuntu, CentOS)
* GCC (GNU Compiler Collection) installed

### Installation

#### 1. Clone the repository:

	git clone https://[your-PAT @]github.com/your-username/estimate.git

#### 2. Navigate to the project directory:

	cd estimate

#### 3. Compile the source code:

	gcc -Wall -Werror -Wextra -pedantic -std=gnu89 main.c computations/*.c
									     init_prof/*.c
									     ratios/*.c
									     -o
									     estimate

#### 4. Run estimate:

	./estimate

### Usage

Use to compute project estimates.

#### Example usage

* `CREATE/UPDATE DATABASE - allows you to create a database.
* `CREATE/UPDATE PROJECT - allows you to create a project.

For more information on features, please refer to the source code and comments.

#### Database Entries Examples

Assuming your project will only need software engineers, you can populate the
database with the following subfields:
* Web Developer
* Mobile App Developer
* Artificial Intelligence(AI) Developer
* Machine Learning Developer
* Blockchain Developer
* Quality Assurance(QA) and Testing Engineer
* Back-End Developer
* Front-End Developer
* UI/UX Developer
* Cloud Computing Specialist
* DevOps Engineer
* Embedded System Developer
* Database Administrator
* Game Developer
* Security Specialist

## Acknowledgements

* This project is solely done by https://github.com/ochiengsulwe

# ESTIMATE INTRODUCTION

This is a simple estimation tool designed to help one compute a project cost
within a specified timeframe.

To enjoy most of ESTIMATE and see it's capabilities, I implore you to use it for
huge projects which involves lots of professionals. Though it works as well too
with small projects.

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
## Text editor

I love vim. All you see is work of vim.

## Coding Style
Betty Coding Style.

Check compliance by running:

	betty main.c computations/*.c init_prof/*.c ratios/*.c memory/*.c

If you don't have Betty installed in your PC, install it by:

#### 1. Clone the Betty repository

	git clone https://github.com/holbertonschool/Betty.git

#### 2. Change into the Betty repository

	cd Betty

#### 3. Install Betty using the included installer script:

	sudo ./install.sh

After installation you can go back to project repository and run the command as
earlier stated.

## Memory
To check for any faul allocation (out of your curiousity) you can run valgrind
(if you have it installed) as follows:

	valgrind ./estimate

If you don't have valgrind in your machine, please follow the following steps to
install it.
#### For Ubuntu/Debian
##### 1. Open a terminal.
##### 2. Update the package list to make sure you have the latest information about available packages:

	sudo apt update
##### 3. Install Valgrind using the package manager:
	sudo apt install valgrind
##### 4. Verify the installation by checking the Valgrind version:
	valgrind --version
#### For CentOS/RHEL:
##### 1. Open a terminal.
##### 2. nstall the EPEL repository (Extra Packages for Enterprise Linux) if it's not already installed. Valgrind is available in EPEL.
	sudo yum install epel-release
##### 3. Install Valgrind using the package manager:
	sudo yum install valgrind
##### 4. Verify the installation by checking the Valgrind version:
	valgrind --version

Valgrind should now be installed on your system.

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

	gcc -Wall -Werror -Wextra -pedantic -std=gnu89 main.c computations/*.c init_prof/*.c memory/*.c ratios/*.c - o estimate

##### 3(a) Alternative compilation

Run the below script if the initial one throws at you error:

	gcc: error: -E or -x required when input is from standard input

Run this:

	gcc -Wall -Werror -Wextra -pedantic -std=gnu89 main.c \computations/compute.c computations/equillibrium_compute.c computations/node_cost.c computations/opt.c \init_prof/database.c init_prof/init_project.c init_prof/node_functions.c init_prof/user_input.c \memory/free_mem.c \ratios/equilibrium.c ratios/optimum.c ratios/utils.c -o estimate


#### 4. Run estimate:

	./estimate

### Usage

Use to compute project estimated cost, to help an organisation  know before-hand
how much it will cost them to complete a project at hand.

It will allow the user to put in timelines for the project, something they can
adjust as the project goes along, to help in costa and/or time management.

#### Example usage

* `CREATE/UPDATE DATABASE` - allows you to create a database.
* `CREATE/UPDATE PROJECT` - allows you to create a project.

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

NOTICE that the last letter 's' is ommitted  at the very end of each entry, intentionally. When
creating a database, copy paste as it is.
## Acknowledgements

* This project is solely done by https://github.com/ochiengsulwe and https://github.com/sulweochieng

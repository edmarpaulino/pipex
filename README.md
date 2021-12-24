<h1 align=center>
	<b>pipex</b>
</h1>

<h4 align=center>
	This project is the discovery in detail and by programming of a UNIX
mechanism that you already know.
</h4>

<p align=center>
	In this repo you will find all the codes developed during the <i>pipex</i> project, both <b>mandatory</b>'s part and <b>bonus</b>.
</p>

---

<div align=center>
<h2>
	Final score
</h2>
<img src=https://github.com/edmarpaulino/42projects_pics/blob/master/score_125.png alt=edpaulin's 42Project Score/>
<h4>Completed + Bonus</h4>
<img src=https://github.com/edmarpaulino/42projects_pics/blob/master/pipexm.png alt=edpaulin's 42Project Badge/>
</div>

---

<h3 align=center>
Mandatory
</h3>
In the Pipex project we should simulate the same behavior as the pipe on unix systems with output redirection.<br>

• Pipex program should be executed in this way:
```bash
$> ./pipex file1 cmd1 cmd2 file2
```
Just in case: file1 and file2 are file names, cmd1 and cmd2 are shell commands with
their parameters.
The execution of the pipex program should do the same as the next shell command:
```bash
$> < file1 cmd1 | cmd2 > file2
```
<br>
Examples

```bash
$> ./pipex infile "ls -l" "wc -l" outfile
```
should be the same as 
```bash
$> < infile ls -l | wc -l > outfile
```
<br>

```bash
$> ./pipex infile "grep a1" "wc -w" outfile
```
should be the same as
```bash
$> < infile grep a1 | wc -w > outfile
```

<p align=center>

</p>

<h3 align=center>
Bonus
</h3>

• Handle multiple pipes:

```bash
$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```
Must be equivalent to:
```bash
$> < file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
```
<br>
• Support « and » when the first parameter is "here_doc"

```bash
$> ./pipex here_doc LIMITER cmd cmd1 file
```
Must be equivalent to:
```bash
$> cmd << LIMITER | cmd1 >> file
```

---
<h2>
Usage
</h2>

### Requirements

This project requires *cc* compiler.

### Instructions

Clone this repository in your local computer:

```sh
git clone https://github.com/edmarpaulino/pipex.git
```

In your local repository, run `make`

```sh
make 
```

> `make` suports 6 flags: 
> - `make all` or simply `make` compiles the project mandatory's part
> - `make bonus` compiles the bonus part
> - `make clean` deletes the `.o` files generated during compilation
> - `make fclean` deletes the `.o` and the `libft.a` executable file
> - `make re` executes `fclean` and `all` in sequence
> - `make rebonus` executes `fclean` and `bonus` in sequence

To run the program see **Mandatory and bonus examples** section above.

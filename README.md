# pipex (42Porto - 42Cursus)  

### Showcase
![](./extras/showcase.png)

### Description
A simple program that replicates the UNIX pipe functionality - introduction to Inter Process Communication (IPC).  

### Installing and running the project

1- Clone this repository
	
	git clone https://github.com/Kuninoto/42_pipex
2- Compile and clean the generated object files that you won't need anymore
	
	make && make clean
3- Run `pipex`

	./pipex <infile> <cmd1> <cmd2> <outfile>

#### Makefile available targets  
`make` or `make all` - Makes `pipex`  
`make clean` - Deletes all the resulting object files  
`make fclean` - Deletes `pipex` and all the resulting object files  
`make re` - `fclean` + `all`  

## Useful links
[The fork() function in C](https://www.youtube.com/watch?v=cex9XrZCU14&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY)  
[man dup, dup2](https://www.man7.org/linux/man-pages/man2/dup.2.html)  
[C program that demonstrates fork and pipe GeekForGeeks](https://www.geeksforgeeks.org/c-program-demonstrate-fork-and-pipe/)  
[Communicating between processes (using pipes) in C](https://www.youtube.com/watch?v=Mqb2dVRe0uo)  

## Disclaimer
> At [42School](https://en.wikipedia.org/wiki/42_(school)), almost every project must be written in accordance to the "Norm", the schools' coding standard. As a result, the implementation of certain parts may appear strange and for sure had room for improvement.

---
Made by Nuno Carvalho (Kuninoto) | nnuno-ca@student.42porto.com  
<div id="badge"> <a href="https://www.linkedin.com/in/nuno-carvalho-218822247"/> <img src="https://img.shields.io/badge/LinkedIn-blue?style=for-the-badge&logo=linkedin&logoColor=white" alt="LinkedIn Badge"/>&nbsp;

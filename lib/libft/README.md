# libft

This is an improved version of my libft, which includes ft_printf and get_next_line (bonus only).
ft_printf and get_next_line can be updated automatically from their own git repo.

<h2>Automations </h2>
The update.sh file is able to:

* clone git additional functions (like ft_printf) from their own adaptive git repo.
* copy them to the srcs/ (for .c files) or includes/ (for .h files) directories.

<h2>In case of errors </h2>
You can run the "Make update" command to update the repo, if the problem persists, re-clone the libft or create a new issue on github.

<h2>Compiling </h2>
To compile, you need to run the "make" command, it should create a libft.a file on bin/

Now to use it, you need to add the path of libft.a file to add it to the project

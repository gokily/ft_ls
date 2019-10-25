# ft_ls

This project asks you to recode the directory listing command `ls`. It is the first project of the Unix system branch at 42. It's main objectif is to make student understand the filing system in unix and discover the sub-system of functions of operating system’s API, the associated data structures, as
well as the management of memory allocation and the associated data.

### Instructions
- You must recode the system’s command ls.
- Its behavior must be identical to the original ls command with the following variations:
	- Amongst the numerous options available, we are asking you to create the following: -l, -R, -a, -r and -t.
	- We strongly recommend that you account for the implications of the option -R from the very beginning of your code...
	- You do not have to deal with the multiple column format for the exit when the option -l isn’t in the arguments.
	- You are not required to deal with ACL and extended attributes.
	- The overall display, depending on each option, must stay as identical as possible to the system command. We will be cordial when grading either the padding or the pagination, but no information can be missing.

### Bonus
I added as bonuses to this project:
- Management of ACL and extended attributes.
- Management of the columns without the option -l (options -1 and -C).
- Management of views in colors (options -G and -M).
- Time optimization on big ls.
- Management of piping. Ex: ls | cat.
- Addition of option: -u.
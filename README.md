course-selections
=================

Basic algorithm to match students with their courses.

### Basic Algorithm
- go through every course
- for each course 
	- go through the entire list of voters
	- put every voter, who voted for the course in a list
	- if there are more voters than open spots, remove voters randomly from the list
	- match everyone remaining in the list with the course and mark them as matched
- repeat for second, third, ... choice

This Algorithm only works for a basic situration. An example is a project week at a school:
> Students have to choose one project they want to participate in. The projects all have a size limit, which is why there needs to be a voting system. Usually students then get to pick their first, second and third choice.
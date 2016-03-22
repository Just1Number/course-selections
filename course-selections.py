from random import randint
import sys, getopt
# simple examples for testing:
# votelist=[
#     ["a", "a", "a", "a", "a", "a", "b", "a", "a", "a", "a", "b", "a", "a", "a", "a", "b", "b", "b", "b", "b", "b", "b", "b", "a", "a", "a", "a", "c", "c", "c", "c", "a", "a", "a", "a", "a", "a", "b", "b", "b", "b", "a", "a", "a", "a", "c", "c", "c"],
#     ["b", "b", "b", "b", "b", "b", "c", "b", "b", "b", "b", "c", "b", "b", "b", "b", "c", "c", "c", "c", "c", "c", "c", "c", "b", "b", "b", "b", "a", "a", "a", "a", "b", "b", "b", "b", "b", "b", "c", "c", "c", "c", "b", "b", "b", "b", "a", "a", "a"]
#     ]
# coiceslist=[["a",16],["b",16],["c",16]]
def main(argv):
	helpmsg="course-selections -i <sourcefile> -f <first-voting-column> -l <last-voting-column> -o <outputcolumn>"
	try:
        opts, args = getopt.getopt(argv,"hi:f:l:o:",["ifile="]) #argv is the list of arguments, "hi:o:" means there are the options -h, -i <...>, -o <...>, last parameter discribes long options (--ifile)
   	except getopt.GetoptError:
        print(helpmsg)
        sys.exit(2)
	for opt, arg in opts:
	  	if opt == "-h":
	  		print(helpmsg)
	  		sys.exit()
	  	elif opt in ("-i","--ifile"):
	  		sourcefilepath = arg
	  	elif opt in "-o":
	  		outputColumn = arg
	  	elif opt == "-f":
	  		firstVotingColumn = arg
	  	elif opt == "-l":
	  		lastVotingColumn = arg
	## wait for python libreoffice api...

def courseMatchingAlgo(list_of_votelists, list_of_courses_and_max_members):
    """ courseMatchingAlgo discription
    Arguments:
    list_of_votelists: [[string]] A list of lists of the votes 
    	(list_of_votelists[0] is the list of the first votes list_of_votelists[1] of the second votes etc)
    list_of_courses_and_max_members: [[string, int]] A list of lists with the lenght of 2. 
    	Left element is the name of the Choice and the right is the max size.
    """
    matchlist = [""] * len(list_of_votelists[0])
    list_of_votelists.insert(0, list(range(0, len(matchlist)))) # inserts an id help list

    for voteRound in range(1, len(list_of_votelists)):

        for choice in range(0, len(list_of_courses_and_max_members)):
            
            courseVoters = []

            for voter in range(0, len(list_of_votelists[voteRound])):
                if list_of_votelists[voteRound][voter] == list_of_courses_and_max_members[choice][0]:
                    courseVoters.append(list_of_votelists[0][voter])

            while len(courseVoters) > list_of_courses_and_max_members[choice][1]:
                courseVoters.pop(randint(0, len(courseVoters)-1))

            list_of_courses_and_max_members[choice][1] -= len(courseVoters)

            for voter in range(0, len(courseVoters)):
                matchlist[courseVoters[voter]] = list_of_courses_and_max_members[choice][0]
                
                index = list_of_votelists[0].index(courseVoters[voter])
                for listnum in range(0, (len(list_of_votelists))):
                    list_of_votelists[listnum].pop(index)

    return matchlist

if __name__ == "__main__":
   main(sys.argv[1:])
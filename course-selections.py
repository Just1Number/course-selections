from random import randint
import sys, getopt
# simple examples for testing:
# votelist=[
#     ["a", "a", "a", "a", "a", "a", "b", "a", "a", "a", "a", "b", "a", "a", "a", "a", "b", "b", "b", "b", "b", "b", "b", "b", "a", "a", "a", "a", "c", "c", "c", "c", "a", "a", "a", "a", "a", "a", "b", "b", "b", "b", "a", "a", "a", "a", "c", "c", "c"],
#     ["b", "b", "b", "b", "b", "b", "c", "b", "b", "b", "b", "c", "b", "b", "b", "b", "c", "c", "c", "c", "c", "c", "c", "c", "b", "b", "b", "b", "a", "a", "a", "a", "b", "b", "b", "b", "b", "b", "c", "c", "c", "c", "b", "b", "b", "b", "a", "a", "a"]
#     ]
# coiceslist=[["a",16],["b",16],["c",16]]
def main(argv):
	helpmsg="course-selections -i <sourcefile> -f <first-voting-column> -l <last-voting-column -o <outputfile>"
	try:
        opts, args = getopt.getopt(argv,"hi:f:l:o:",["ifile=","ofile="]) #argv is the list of arguments, "hi:o:" means there are the options -h, -i <...>, -o <...>, last parameter discribes long options (--ifile)
   	except getopt.GetoptError:
        print(helpmsg)
        sys.exit(2)
	for opt, arg in opts:
	  	if opt == "-h":
	  		print(helpmsg)
	  		sys.exit()
	  	elif opt in ("-i","--ifile"):
	  		sourcefilepath = arg
	  	elif opt in ("-o","--ofile"):
	  		outputfilepath = arg
	  	elif opt == "-f":
	  		firstVotingColumn = arg
	  	elif opt == "-l":
	  		lastVotingColumn = arg


def courseMatchingAlgo(listOfVotelists, listOfCoursesAndMaxMembers):
    """ courseMatchingAlgo discription
    Arguments:
    listOfVotelists: [[string]] A list of lists of the votes (listOfVotelists[0] is the list of the first votes listOfVotelists[1] of the second votes etc)
    listOfVotelists: [[string, int]] A list of lists with the lenght of 2. Left element is the name of the Choice and the right is the max size.
    """
    matchlist = [""] * len(listOfVotelists[0])
    listOfVotelists.insert(0, list(range(0, len(matchlist))))

    for voteRound in range(1, len(listOfVotelists)):

        for choice in range(0, len(listOfCoursesAndMaxMembers)):
            
            courseVoters = []

            for voter in range(0, len(listOfVotelists[voteRound])):
                if listOfVotelists[voteRound][voter] == listOfCoursesAndMaxMembers[choice][0]:
                    courseVoters.append(listOfVotelists[0][voter])

            while len(courseVoters) > listOfCoursesAndMaxMembers[choice][1]:
                courseVoters.pop(randint(0, len(courseVoters)-1))

            listOfCoursesAndMaxMembers[choice][1] -= len(courseVoters)

            for voter in range(0, len(courseVoters)):
                matchlist[courseVoters[voter]] = listOfCoursesAndMaxMembers[choice][0]
                
                index = listOfVotelists[0].index(courseVoters[voter])
                for listnum in range(0, (len(listOfVotelists))):
                    listOfVotelists[listnum].pop(index)

    return matchlist

if __name__ == "__main__":
   main(sys.argv[1:])
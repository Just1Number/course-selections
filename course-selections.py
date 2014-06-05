from random import randint

# votelist=[
#     ["a", "a", "a", "a", "a", "a", "b", "a", "a", "a", "a", "b", "a", "a", "a", "a", "b", "b", "b", "b", "b", "b", "b", "b", "a", "a", "a", "a", "c", "c", "c", "c", "a", "a", "a", "a", "a", "a", "b", "b", "b", "b", "a", "a", "a", "a", "c", "c", "c"],
#     ["b", "b", "b", "b", "b", "b", "c", "b", "b", "b", "b", "c", "b", "b", "b", "b", "c", "c", "c", "c", "c", "c", "c", "c", "b", "b", "b", "b", "a", "a", "a", "a", "b", "b", "b", "b", "b", "b", "c", "c", "c", "c", "b", "b", "b", "b", "a", "a", "a"]
#     ]
# coiceslist=[["a",16],["b",16],["c",16]]

def votingAlgo(listOfVotelists, listOfChoicesAndMaxMembers):
    """ votingAlgo discription
    Arguments:
    listOfVotelists: [[string]] A list of lists of the votes (listOfVotelists[0] is the list of the first votes listOfVotelists[1] of the second votes etc)
    listOfVotelists: [[string, int]] A list of lists with the lenght of 2. Left element is the name of the Choice and the right is the max size.
    """
    result = [""] * len(listOfVotelists[0])
    listOfVotelists.insert(0, list(range(0, len(result))))
    for voteRound in range(1, len(listOfVotelists)):

        for choice in range(0, len(listOfChoicesAndMaxMembers)):
            
            votersForChoice = []

            for voter in range(0, len(listOfVotelists[voteRound])):
                if listOfVotelists[voteRound][voter] == listOfChoicesAndMaxMembers[choice][0]:
                    votersForChoice.append(listOfVotelists[0][voter])

            while len(votersForChoice) > listOfChoicesAndMaxMembers[choice][1]:
                votersForChoice.pop(randint(0, len(votersForChoice)-1))

            listOfChoicesAndMaxMembers[choice][1] -= len(votersForChoice)

            for voter in range(0, len(votersForChoice)):
                result[votersForChoice[voter]] = listOfChoicesAndMaxMembers[choice][0]
                index = listOfVotelists[0].index(votersForChoice[voter])
                for listnum in range(0, (len(listOfVotelists))):
                    listOfVotelists[listnum].pop(index)

    return result


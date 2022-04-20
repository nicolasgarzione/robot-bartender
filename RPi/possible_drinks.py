import csv

def DrinkList():
    file = open("drinklist.csv")
    csvreader = csv.reader(file)
    header = next(csvreader)

    #list of all the liquids
    liquors = ['Vodka', 'Light Rum', 'Tequila', 'Whiskey', 'Gin']
    liqueurs = ['Triple Sec', 'Peach Schnapps', 'Coconut Rum', 'Blue Curacao']
    mixers = ['Coke', '7-Up/Sprite',' Sweet & Sour Mix', 'Orange Juice', \
              'Pineapple Juice', 'Grapefruit Juice', 'Lime Juice', 'Grenadine',\
              'Ginger Beer', 'Club Soda', 'Tonic Water']

    #input the position of all the drinks by using the lists above
    liquid_pos1 = liquors[0]
    liquid_pos2 = liquors[1]
    liquid_pos3 = liquors[2]
    liquid_pos4 = liqueurs[0]
    liquid_pos5 = liqueurs[2]
    liquid_pos6 = mixers[0]
    liquid_pos7 = mixers[1]
    liquid_pos8 = mixers[2]
    liquid_pos9 = mixers[3]
    liquid_pos10 = mixers[4]
    liquid_pos11 = mixers[5]
    liquid_pos12 = mixers[6]
    liquid_positions = [liquid_pos1, liquid_pos2, liquid_pos3, liquid_pos4,\
                        liquid_pos5, liquid_pos6, liquid_pos7, liquid_pos8,\
                        liquid_pos9, liquid_pos10, liquid_pos11, liquid_pos12]

    #finding the possible drinks
    drinks = []
    liquids = []
    possible_drinks = []
    for row in csvreader:
        row = list(filter(None, row))
        drinks.append(row)
    liquids = drinks[0]
    drinks.remove(drinks[0])
    #print(liquids)

    for idx, drink_array in enumerate(drinks):
        possible = True
        for i, value in enumerate(drink_array):
            if value != '0':
                #print(value, i)
                if i != 0:
                    liquid_present = False
                    for j, liquid in enumerate(liquid_positions):
                        if liquid == liquids[i - 1]:
                            liquid_present = True
                    if liquid_present == False:
                        possible = False
                        break
                            
        if possible == True:
            possible_drinks.append(drink_array)
    file.close()
    return possible_drinks, liquids, liquid_positions





def cupArray(current_order, possible_drinks, liquids, liquid_positions, all_cups):
    
    possible = False

    for idx, value in enumerate(possible_drinks):

        if current_order == value[0] :
            possible = True
            possible_drink_array = value
            break

    timed_liquids = []
    if possible == True:
        
        cup = [0] * 13
        
        for idx, value in enumerate(possible_drink_array):
            if value != '0' and idx != 0:
                timed_liquids.append([liquids[idx-1], value])

        for idx, liquid in enumerate(liquid_positions):
            for __, timed_liquid_array in enumerate(timed_liquids):
                if timed_liquid_array[0] == liquid:
                    cup[idx+1] = int(timed_liquid_array[1])
        all_cups.append(cup)
    else:
        return all_cups
    
    return all_cups
        
if __name__ == "__main__":
    
    possible_drinks, liquids, liquid_positions = DrinkList()        
    all_cups = []
    current_order = 'Rum and Coke'
    all_cups = cupArray(current_order, possible_drinks, liquids, liquid_positions, all_cups)

    current_order = 'Whiskey Coke'
    all_cups = cupArray(current_order, possible_drinks, liquids, liquid_positions, all_cups)
    print(all_cups)

    

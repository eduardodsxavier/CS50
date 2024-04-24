from cs50 import SQL
import csv

# create a list of dicts for the students
prophecy = []

# open the students.csv file and save in the memory
with open('students.csv') as students:
    csvStudents = csv.DictReader(students)
    for row in csvStudents:
        prophecy.append(row)

# open the database file
db = SQL('sqlite:///prophecy.db')

# create two lists for every house and house head
houses = []
houseHead = []

# save the houses and heads names if they are not already saved
for row in prophecy:
    if row['house'] not in houses:
        houses.append(row['house'])
        houseHead.append(row['head'])

# put every house and head in the houses table
for index in range(len(houses)):
    db.execute('INSERT INTO houses(house, head) VALUES(?, ?);', houses[index], houseHead[index])

# pass for every student in the list
for row in prophecy:
    # put their name in the students table
    db.execute('INSERT INTO students(student_name) VALUES(?)', row['student_name'])

    # create a id for the student house
    houseId = 0

    # see what's the id of the student house and save in the 'houseId' variable
    for index in range(len(houses)):
        if  row['house'] == houses[index]:
            houseId = index + 1

    # put the student id and the house id in the student_house table
    db.execute('INSERT INTO student_house(student_id, house_id) VALUES(?, ?)', row['id'], houseId)

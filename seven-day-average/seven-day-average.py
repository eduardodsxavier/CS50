import csv
import requests


def main():
    # Read NYTimes Covid Database
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)

    # Construct 14 day lists of new cases for each states
    new_cases = calculate(reader)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ")
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


# TODO: Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader):
    new_cases = {}
    previous_cases = {}
    for row in reader:
        if row["state"] not in new_cases:
            new_cases[row["state"]] = []
            previous_cases[row["state"]] = row["cases"]
        else:
            tmp = int(row["cases"]) - int(previous_cases[row["state"]])
            new_cases[row["state"]].append(tmp)
            if len(new_cases[row["state"]]) > 14:
                new_cases[row["state"]].pop(0)
            previous_cases[row["state"]] = row["cases"]

    return new_cases


# TODO: Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
    for state in states:
        firstWeek = 0
        secondWeek = 0
        difference = 0
        for cases in new_cases[state][0:6]:
            firstWeek += cases
        for cases in new_cases[state][7:13]:
            secondWeek += cases

        firstWeek = firstWeek / 7
        secondWeek = secondWeek / 7

        try:
            difference = secondWeek - firstWeek
            difference = difference / secondWeek

        except ZeroDivisionError:
            print("invalid operation")
            break

        if int(difference) > 0:
            print(f"{state} had a 7-day average of {int(secondWeek)} and a increase of {int(difference)}%.")
        else:
            print(f"{state} had a 7-day average of {int(secondWeek)} and a decrease of {int(abs(difference))}%.")


main()

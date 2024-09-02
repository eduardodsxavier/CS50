#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(pair originalPair[], int arraySize);
void merge_sort(pair originalPair[], pair leftPart[], pair rightPart[], int arraySize);
void lock_pairs(void);
bool cycle(int cycleStart, int cycleEnd);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs(pairs, pair_count);
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name,candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[i].winner = i;
                pairs[i].loser = j;
                pair_count++;
            }
            else if (preferences[j][i] > preferences[i][j])
            {
                pairs[i].winner = j;
                pairs[i].loser = i;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(pair originalPair[], int arraySize)
{
    // TODO
    if (arraySize < 2)
    {
        return;
    }
    int midIndex = arraySize/2;

    pair leftPart[midIndex];
    pair rightPart[arraySize - midIndex];

    for (int i = 0; i < midIndex; i++)
    {
        leftPart[i] = originalPair[i];
    }
    for (int i = midIndex; i < arraySize; i++)
    {
        rightPart[i - midIndex] = originalPair[i];
    }

    sort_pairs(leftPart, midIndex);
    sort_pairs(rightPart, arraySize - midIndex);

    merge_sort(originalPair, leftPart, rightPart, arraySize);
    return;
}

void merge_sort(pair originalPair[], pair leftPart[], pair rightPart[], int arraySize)
{
    int midIndex = arraySize/2;
    int i = 0, j = 0, k = 0;
    int leftPartSize = midIndex;
    int rightPartSize = arraySize - midIndex;

    while (i < leftPartSize && j < rightPartSize)
    {
        if (preferences[leftPart[i].winner][leftPart[i].loser] >= preferences[rightPart[j].winner][rightPart[j].loser])
        {
            originalPair[k] = leftPart[i];
            i++;
        }
        else
        {
            originalPair[k] = rightPart[j];
            j++;
        }
        k++;
    }

    while (i < leftPartSize)
    {
        originalPair[k] = leftPart[i];
        i++;
        k++;
    }
    while (j < rightPartSize)
    {
        originalPair[k] = rightPart[j];
        j++;
        k++;
    }
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    for (int i = 0; i < pair_count; i++)
    {
        if (!cycle(pairs[i].winner, pairs[i].loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}

bool cycle(int cycleStart, int cycleEnd)
{
    if (cycleStart == cycleEnd)
    {
        return true;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[cycleEnd][i] && cycle(i, cycleStart))
        {
            return true;
        }
    }
    return false;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        int lock_count = 0;
        for (int j = 0; j < candidate_count; j++)
        {
            if (!locked[j][i])
            {
                lock_count++;
                if (lock_count == candidate_count)
                {
                    printf("%s \n",candidates[i]);
                }
            }
        }
    }
    return;
}
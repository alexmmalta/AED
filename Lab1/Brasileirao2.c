#include <stdio.h>
#include <string.h>

#define MAX_TEAMS 100
#define MAX_NAME_LEN 101

typedef struct {
    char name[MAX_NAME_LEN];
    int points;
    int wins;
    int draws;
    int losses;
    int goal_diff;
    int goals_for;
    int goals_against;
} Team;

Team teams[MAX_TEAMS];
int team_count = 0;

int find_team_index(char *name) {
    for (int i = 0; i < team_count; i++) {
        if (strcmp(teams[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void update_team_stats(char *home, int home_goals, int away_goals, char *away) {
    int home_index = find_team_index(home);
    int away_index = find_team_index(away);

    if (home_goals > away_goals) {
        teams[home_index].points += 3;
        teams[home_index].wins++;
        teams[away_index].losses++;
    } else if (home_goals < away_goals) {
        teams[away_index].points += 3;
        teams[away_index].wins++;
        teams[home_index].losses++;
    } else {
        teams[home_index].points++;
        teams[away_index].points++;
        teams[home_index].draws++;
        teams[away_index].draws++;
    }

    teams[home_index].goals_for += home_goals;
    teams[home_index].goals_against += away_goals;
    teams[home_index].goal_diff += (home_goals - away_goals);

    teams[away_index].goals_for += away_goals;
    teams[away_index].goals_against += home_goals;
    teams[away_index].goal_diff += (away_goals - home_goals);
}

int main() {
    int n;
    scanf("%d", &n);
    team_count = n;

    for (int i = 0; i < n; i++) {
        scanf("%s", teams[i].name);
        teams[i].points = 0;
        teams[i].wins = 0;
        teams[i].draws = 0;
        teams[i].losses = 0;
        teams[i].goal_diff = 0;
        teams[i].goals_for = 0;
        teams[i].goals_against = 0;
    }

    char home[MAX_NAME_LEN], away[MAX_NAME_LEN];
    int home_goals, away_goals;
    for (int i = 0; i < n * (n - 1); i++) {
        scanf("%s %d x %d %s", home, &home_goals, &away_goals, away);
        update_team_stats(home, home_goals, away_goals, away);
    }

    // Sorting and output logic goes here

    return 0;
}
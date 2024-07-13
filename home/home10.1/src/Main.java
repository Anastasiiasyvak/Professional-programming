import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

class Team {
    String name;
    int goalsScored = 0;
    int goalsConceded = 0;
    int yellowCards = 0;
    int redCards = 0;
    double totalTopHeight = 0.0;
    double points = 0.0;

    Team(String name) {
        this.name = name;
    }

    void addMatchResult(int scored, int conceded, int yellow, int red, double topHeight) {
        goalsScored += scored;
        goalsConceded += conceded;
        yellowCards += yellow;
        redCards += red;
        totalTopHeight += topHeight;

        if (scored > conceded) {
            points += 3.14;
        } else if (scored == conceded) {
            points += 2.71828;
        } else {
            points -= 0.5;
        }
    }

    double goalDifference() {
        return goalsScored - goalsConceded;
    }
}

class Match {
    Team team1;
    Team team2;
    int goals1, goals2;
    int yellow1, yellow2;
    int red1, red2;
    double topHeight1, topHeight2;

    Match(Team t1, Team t2) {
        team1 = t1;
        team2 = t2;
    }

    void playMatch() {
        Scanner scanner = new Scanner(System.in);
        System.out.printf("Enter results for match between %s and %s:\n", team1.name, team2.name);

        System.out.printf("Goals scored by %s: ", team1.name);
        goals1 = scanner.nextInt();
        System.out.printf("Yellow cards shown to %s: ", team1.name);
        yellow1 = scanner.nextInt();
        System.out.printf("Red cards shown to %s: ", team1.name);
        red1 = scanner.nextInt();
        System.out.printf("Top height reached by %s: ", team1.name);
        topHeight1 = scanner.nextDouble();

        System.out.printf("Goals scored by %s: ", team2.name);
        goals2 = scanner.nextInt();
        System.out.printf("Yellow cards shown to %s: ", team2.name);
        yellow2 = scanner.nextInt();
        System.out.printf("Red cards shown to %s: ", team2.name);
        red2 = scanner.nextInt();
        System.out.printf("Top height reached by %s: ", team2.name);
        topHeight2 = scanner.nextDouble();

        team1.addMatchResult(goals1, goals2, yellow1, red1, topHeight1);
        team2.addMatchResult(goals2, goals1, yellow2, red2, topHeight2);
    }
}

class Tournament {
    List<Team> teams = new ArrayList<>();
    List<Match> matches = new ArrayList<>();

    void addTeam(String name) {
        teams.add(new Team(name));
    }

    void playTournament() {
        for (int i = 0; i < teams.size(); i++) {
            for (int j = i + 1; j < teams.size(); j++) {
                matches.add(new Match(teams.get(i), teams.get(j)));
            }
        }

        for (Match match : matches) {
            match.playMatch();
        }

        rankTeams();
    }

    void rankTeams() {
        for (Team team : teams) {
            if (team.name.equalsIgnoreCase("Russia") || team.name.equals("404")) {
                team.points = -1;
            }
        }

        teams.sort(Comparator.comparingDouble((Team t) -> t.points)
                .thenComparingDouble((Team t) -> t.totalTopHeight)
                .thenComparingDouble((Team t) -> t.goalDifference())
                .thenComparingInt(t -> t.goalsScored)
                .thenComparingInt(t -> t.redCards)
                .thenComparingInt(t -> t.yellowCards)
                .reversed());

        printResults();
    }

    void printResults() {
        System.out.println("Final standings:");
        for (Team team : teams) {
            System.out.printf("%s - Points: %.2f, Goals Scored: %d, Goals Conceded: %d, Yellow Cards: %d, Red Cards: %d, Total Top Height: %.2f\n",
                    team.name, team.points, team.goalsScored, team.goalsConceded, team.yellowCards, team.redCards, team.totalTopHeight);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Tournament tournament = new Tournament();
        Scanner scanner = new Scanner(System.in);
        List<String> teamNames = new ArrayList<>(4);

        System.out.println("Enter the names of 4 teams:");
        for (int i = 0; i < 4; i++) {
            teamNames.add(scanner.nextLine());
            tournament.addTeam(teamNames.get(i));
        }

        tournament.playTournament();
    }
}

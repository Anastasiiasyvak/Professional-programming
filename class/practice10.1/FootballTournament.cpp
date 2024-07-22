#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ranges>
#include <print>

class Team {
public:
    std::string name;
    int goals_scored = 0;
    int goals_conceded = 0;
    int yellow_cards = 0;
    int red_cards = 0;
    double total_top_height = 0.0;
    double points = 0.0;

    Team(const std::string& name) : name(name) {}

    void addMatchResult(int scored, int conceded, int yellow, int red, double top_height) {
        goals_scored += scored;
        goals_conceded += conceded;
        yellow_cards += yellow;
        red_cards += red;
        total_top_height += top_height;

        if (scored > conceded) {
            points += 3.14;
        } else if (scored == conceded) {
            points += 2.71828;
        } else {
            points += -0.5;
        }
    }

    double goalDifference() const {
        return goals_scored - goals_conceded;
    }
};

class Match {
public:
    Team& team1;
    Team& team2;
    int goals1, goals2;
    int yellow1, yellow2;
    int red1, red2;
    double top_height1, top_height2;

    Match(Team& t1, Team& t2) : team1(t1), team2(t2) {}

    void playMatch() {
        std::println("Enter results for match between {} and {}:", team1.name, team2.name);
        std::println("Goals scored by {}: ", team1.name); std::cin >> goals1;
        std::println("Yellow cards shown to {}: ", team1.name); std::cin >> yellow1;
        std::println("Red cards shown to {}: ", team1.name); std::cin >> red1;
        std::println("Top height reached by {}: ", team1.name); std::cin >> top_height1;

        std::println("Goals scored by {}: ", team2.name); std::cin >> goals2;
        std::println("Yellow cards shown to {}: ", team2.name); std::cin >> yellow2;
        std::println("Red cards shown to {}: ", team2.name); std::cin >> red2;
        std::println("Top height reached by {}: ", team2.name); std::cin >> top_height2;

        team1.addMatchResult(goals1, goals2, yellow1, red1, top_height1);
        team2.addMatchResult(goals2, goals1, yellow2, red2, top_height2);
    }
};

class Tournament {
public:
    std::vector<Team> teams;
    std::vector<Match> matches;

    void addTeam(const std::string& name) {
        teams.emplace_back(name);
    }

    void playTournament() {
        for (auto i = 0; i < teams.size(); ++i) {
            for (auto j = i + 1; j < teams.size(); ++j) {
                matches.emplace_back(teams[i], teams[j]);
            }
        }

        for (auto& match : matches) {
            match.playMatch();
        }

        rankTeams();
    }

    void rankTeams() {
        auto criteria = [](const Team& a, const Team& b) {
            if (a.points != b.points) return a.points > b.points;
            if (a.total_top_height != b.total_top_height) return a.total_top_height > b.total_top_height;
            if (a.goalDifference() != b.goalDifference()) return a.goalDifference() > b.goalDifference();
            if (a.goals_scored != b.goals_scored) return a.goals_scored > b.goals_scored;
            if (a.red_cards != b.red_cards) return a.red_cards < b.red_cards;
            if (a.yellow_cards != b.yellow_cards) return a.yellow_cards < b.yellow_cards;
            return rand() % 2 == 0;
        };

        std::ranges::sort(teams, criteria);

        printResults();
    }

    void printResults() {
        std::println("Final standings:");
        for (const auto& team : teams) {
            std::println("{} - Points: {}, Goals Scored: {}, Goals Conceded: {}, Yellow Cards: {}, Red Cards: {}, Total Top Height: {}",
                         team.name, team.points, team.goals_scored, team.goals_conceded, team.yellow_cards, team.red_cards, team.total_top_height);
        }
    }
};

int main() {
    Tournament tournament;
    std::vector<std::string> teamNames(4);
    std::println("Enter the names of 4 teams:");
    for (auto& name : teamNames) {
        std::cin >> name;
        tournament.addTeam(name);
    }

    tournament.playTournament();
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ranges>
#include <cstdlib>  // Для функції rand()

class Team {
public:
    std::string name;
    int goals_scored = 0;
    int goals_conceded = 0;
    int yellow_cards = 0;
    int red_cards = 0;
    double total_top_height = 0.0;
    double points = 0.0;

    Team(const std::string& name) : name(name) {}

    void addMatchResult(int scored, int conceded, int yellow, int red, double top_height) {
        goals_scored += scored;
        goals_conceded += conceded;
        yellow_cards += yellow;
        red_cards += red;
        total_top_height += top_height;

        if (scored > conceded) {
            points += 3.14;
        } else if (scored == conceded) {
            points += 2.71828;
        } else {
            points += -0.5;
        }
    }

    double goalDifference() const {
        return goals_scored - goals_conceded;
    }
};

class Match {
public:
    Team& team1;
    Team& team2;
    int goals1, goals2;
    int yellow1, yellow2;
    int red1, red2;
    double top_height1, top_height2;

    Match(Team& t1, Team& t2) : team1(t1), team2(t2) {}

    void playMatch() {
        std::println("Enter results for match between {} and {}:", team1.name, team2.name);
        std::println("Goals scored by {}: ", team1.name); std::cin >> goals1;
        std::println("Yellow cards shown to {}: ", team1.name); std::cin >> yellow1;
        std::println("Red cards shown to {}: ", team1.name); std::cin >> red1;
        std::println("Top height reached by {}: ", team1.name); std::cin >> top_height1;

        std::println("Goals scored by {}: ", team2.name); std::cin >> goals2;
        std::println("Yellow cards shown to {}: ", team2.name); std::cin >> yellow2;
        std::println("Red cards shown to {}: ", team2.name); std::cin >> red2;
        std::println("Top height reached by {}: ", team2.name); std::cin >> top_height2;

        team1.addMatchResult(goals1, goals2, yellow1, red1, top_height1);
        team2.addMatchResult(goals2, goals1, yellow2, red2, top_height2);
    }
};

class Tournament {
public:
    std::vector<Team> teams;
    std::vector<Match> matches;

    void addTeam(const std::string& name) {
        teams.emplace_back(name);
    }

    void playTournament() {
        for (auto i = 0; i < teams.size(); ++i) {
            for (auto j = i + 1; j < teams.size(); ++j) {
                matches.emplace_back(teams[i], teams[j]);
            }
        }

        for (auto& match : matches) {
            match.playMatch();
        }

        rankTeams();
    }

    void rankTeams() {
        auto criteria = [](const Team& a, const Team& b) {
            if (a.points != b.points) return a.points > b.points;
            if (a.total_top_height != b.total_top_height) return a.total_top_height > b.total_top_height;
            if (a.goalDifference() != b.goalDifference()) return a.goalDifference() > b.goalDifference();
            if (a.goals_scored != b.goals_scored) return a.goals_scored > b.goals_scored;
            if (a.red_cards != b.red_cards) return a.red_cards < b.red_cards;
            if (a.yellow_cards != b.yellow_cards) return a.yellow_cards < b.yellow_cards;
            return rand() % 2 == 0;
        };

        std::ranges::sort(teams, criteria);

        printResults();
    }

    void printResults() {
        std::println("Final standings:");
        for (const auto& team : teams) {
            std::println("{} - Points: {}, Goals Scored: {}, Goals Conceded: {}, Yellow Cards: {}, Red Cards: {}, Total Top Height: {}",
                         team.name, team.points, team.goals_scored, team.goals_conceded, team.yellow_cards, team.red_cards, team.total_top_height);
        }
    }
};

int main() {
    Tournament tournament;
    std::vector<std::string> teamNames(4);
    std::println("Enter the names of 4 teams:");
    for (auto& name : teamNames) {
        std::cin >> name;
        tournament.addTeam(name);
    }

    tournament.playTournament();
    return 0;
}


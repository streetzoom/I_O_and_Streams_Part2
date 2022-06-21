#include <iostream>
#include <iomanip>
#include <fstream>

void display_line() {
    std::cout << std::setw(30) << std::setfill('=') << "" << std::endl;
    std::cout << std::setfill(' ');
}

void display_title() {
    std::cout << std::setw(15) << std::left << "Student"
              << std::setw(15) << std::right << "Score" << std::endl;
   display_line();
}

void display_body(const std::string &student_name, int score) {
    std::cout << std::setw(15) << std::left << student_name
              << std::setw(15) << std::right << score << std::endl;
}

void display_avg(double avg_score) {
    display_line();
    std::cout << std::setw(15) << std::left << "Average score"
              << std::setw(15) << std::right << avg_score << std::endl;
}

int calc_correct_answer(const std::string &correct_answer, const std::string &student_answer) {
    int score{0};
    for (size_t i {0}; i < correct_answer.size(); ++i) {
        if (correct_answer.at(i) == student_answer.at(i)) {
            ++score;
        }
    }
    return score;
}

int main() {
    std::ifstream in_file;
    std::string student_name{};
    std::string correct_answer{};
    std::string student_answer{};
    double avg_score {0.0};
    int sum {0};
    int total_student {0};

    in_file.open("../responses.txt");
    if (!in_file) {
        std::cerr << "Can not open the file" << std::endl;
        std::exit(1);
    }
    in_file >> correct_answer;
    display_title();

    while (in_file >> student_name >> student_answer) {
        int score = calc_correct_answer(correct_answer, student_answer);
        sum += score;
        display_body(student_name, score);
        ++total_student;
    }

    if (total_student != 0) {
        avg_score = static_cast<double>(sum)/total_student;
    }

    display_avg(avg_score);
    in_file.close();

    return 0;
}



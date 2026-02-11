#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>

// Surname_K.B 1001 3 Maths 5 Physics 4 CompScience 5
// BSurname_C.B 1002 2 Maths 3 Physics 2
// JSurname_C.B 1003 4 Maths 4 Physics 5 Chemistry 3 CompScience 4
// ASurname_C.B 1004 2 Maths 5 CompScience 5
// CSurname_C.B 1005 3 Physics 5 Chemistry 5 CompScience 6

struct Mark {
	std::string subject_;
	size_t mark_;

};

struct StudentData {
	std::string name_;
	size_t number_;
	std::vector<Mark> mark_;

};

void outputSortedZachetka(const std::map<size_t, StudentData>& students) {
	if (students.empty()) {
		std::cout << "No students." << std::endl;
		return;
	}
	for (const auto& pair : students) {
		std::cout << pair.first << " - " << pair.second.name_ << "\n";
	}
}

double average(StudentData& student) {
		double sum = 0;
		for ( auto mark : student.mark_){
			sum += mark.mark_;
		}
		double average = 0; 
		if (!student.mark_.empty()) {
			return average = sum / student.mark_.size();
		}
	}

double averageForAll(std::map<size_t, StudentData> students) {
	for (auto element : students) {
		double sum = 0;
		for (auto mark : element.second.mark_) {
			sum += mark.mark_;
		}
		double average = 0;
		if (!element.second.mark_.empty()) {
			return average = sum / element.second.mark_.size();
		}
	}
}


bool compareStudentsByName(std::pair<size_t, StudentData> a, std::pair<size_t, StudentData> b) {
	if (a.second.name_ != b.second.name_) {
		return a.second.name_ < b.second.name_;
	}
	return average(a.second) > average(b.second);
}

void alphabetOrder(std::map<size_t , StudentData> students) {
	std::vector<std::pair<size_t, StudentData>> studentList;

	for (auto element : students) {
		studentList.push_back(element);
	}

	std::sort(studentList.begin(), studentList.end(), compareStudentsByName);

	for (int i = 0; i < studentList.size(); ++i) {
		std::cout << i + 1 << ", " << studentList[i].second.name_ << ", " << studentList[i].first << ", " << average(studentList[i].second) << std::endl;
	}
}

bool compareByAverageDesc(std::pair<double, StudentData> a, std::pair<double, StudentData> b) {
	return a.first > b.first;
}

void ouptputStudentsInRange(std::map<size_t , StudentData> students) {
	int a, b;
	std::cout << "Enter the start of the range: ";
	std::cin >> a;
	std::cout << "Enter the end of the range: ";
	std::cin >> b;
	if (a < 0 || b < 0) {
		std::cout << "Enter realistic range" << std::endl;
		exit(0);
	}
	else {
		if (a > b) {
			std::cout << "Start must be < than end" << std::endl;
			exit(0);
		}

		std::vector<std::pair<double, StudentData>> studentsInRange;

		bool anyFound = false;

		for (auto& element : students) {
			StudentData& student = element.second;
			double avg = average(student);

			if (avg >= a && avg <= b) {
				studentsInRange.push_back({ avg, student });
			}
		}

		if (studentsInRange.empty()) {
			std::cout << "No students in range" << a << " - " << b << std::endl;
			return;
		}

		std::sort(studentsInRange.begin(), studentsInRange.end(), compareByAverageDesc);
		for (auto element : studentsInRange) {
			std::cout << element.second.name_ << " " << element.second.number_ << " " << average(element.second) << std::endl;
		}
	}
}

void studentsWhoPassedTheSubject(std::map<size_t, StudentData> students) {
	std::string subject;
	std::cout << "Enter the subject: ";
	std::cin >> subject;
	bool found = false;
	for (auto element : students) {
		for (auto mark : element.second.mark_) {
			if (mark.subject_ == subject) {
				std::cout << element.second.name_ << std::endl;
				found = true;
				break;
			}
		}
	}
	if (!found){
		std::cout << "No students who passed this subject" << std::endl;
	}
}


void AllSubjects(std::map<size_t, StudentData> students) {
	std::vector<std::string> subjects;

	for (auto& element : students) {
		StudentData& student = element.second;
		for (auto& mark : student.mark_) {
			subjects.push_back(mark.subject_);
		}
	}

	std::sort(subjects.begin(), subjects.end());

	if (subjects.empty()) {
		std::cout << "No data";
		return;
	}

	std::string currentSubject = subjects[0];
	int studentCount = 1;

	for (size_t i = 1; i < subjects.size(); i++) {
		if (subjects[i] == currentSubject) {
			studentCount++;
		}
		else {
			std::cout << currentSubject << ": " << studentCount << " students" << std::endl;
			currentSubject = subjects[i];
			studentCount = 1;
		}
	}
	std::cout << currentSubject << ": " << studentCount << " students " << std::endl;
}

void averageForEachSubject(std::map<size_t, StudentData> students) {
	std::map<std::string, std::pair<int, int>> subjectData;

	for (auto& element : students) {
		for (auto& mark : element.second.mark_) {
			subjectData[mark.subject_].first += mark.mark_;
			subjectData[mark.subject_].second++; 
		}
	}

	std::vector<std::pair<double, std::string>> result;

	for (auto item : subjectData) {
		double average = (double)item.second.first / item.second.second;
		result.push_back({ average, item.first });
	}

	for (int i = 0; i < result.size(); i++) {
		for (int j = i + 1; j < result.size(); j++) {
			if (result[i].first < result[j].first) {
				std::swap(result[i], result[j]);
			}
		}
	}

	for (auto item : result) {
		std::cout << item.second << ": " << item.first << std::endl;
	}
}

void maxScoreStudents(std::map<size_t, StudentData> students) {
	int maxSum = 0;
	for (auto& s : students) {
		int sum = 0;
		for (auto& m : s.second.mark_) {
			sum += m.mark_;
		}
		if (sum > maxSum) maxSum = sum;
	}

	std::cout << "Max score : " << maxSum << std::endl;

	for (auto& s : students) {
		int sum = 0;
		for (auto& m : s.second.mark_) {
			sum += m.mark_;
		}
		if (sum == maxSum) {
			std::cout <<"Student: " << s.second.name_ << std::endl;
		}
	}
}

void studentsWithBadGrades(std::map<size_t, StudentData> students) {
	std::cout << "Students with bad grades:";
	for (auto& s : students) {
		for (auto& m : s.second.mark_) {
			if (m.mark_ <= 3) {
				std::cout << s.second.name_ << " ";
				break;
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	std::string filename , line;
	std::cout << "Enter file's name: ";
	std::cin >> filename;
	std::map<size_t, StudentData > students;
	std::ifstream in(filename);
	if (!(in.is_open())) {
		std::cout << "File can't be opened" << std::endl;
		exit(0);
	}
	else {
		if (in.peek() == EOF) {
			std::cout << "File is empty" << std::endl;
			exit(0);
		}
		else {
			while (std::getline(in, line)) {
				std::istringstream fin(line);
				StudentData student;
				size_t markCount;
				if (!(fin >> student.name_ >> student.number_ >> markCount)) {
					std::cout << "Can't read information about student from that line: " << line << std::endl;
					continue;
				}
				for (size_t i = 0; i < markCount; ++i) {
					Mark mark;
					if (!(fin >> mark.subject_ >> mark.mark_)) {
						std::cout << "Can't read marks for " << student.name_ << std::endl;
						break;
					}
					student.mark_.push_back(mark);
				}
				students[student.number_] = student;
			}
		}
	}
	in.close();
}

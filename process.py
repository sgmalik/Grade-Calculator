import sys


# Funciton to handle the backend logic for saving data and then doing calculations
def handle(file_path):
    with open(file_path, "r") as file:
        path_choice = file.readline().strip()

        if path_choice == "gpaCalculator":
            type = "GPA"
            # Saving gpa data to a list
            gpa_data = []
            for line in file:
                info = line.strip().split(',')
                course = info[0]
                credits = int(info[1])
                grade = int(info[2])
                gpa_data.append((course, credits, grade))
            return [gpa_data, type]

        # Logic for final grade, not yet working
        elif path_choice == "finalGrade":
            type = "GRADE"
            lines = file.readlines()

            course_name = ""
            courses = []
            categories = []
            assignments = []

            for line in lines:
                line = line.strip()

                # If the line is empty, go to next course
                if not line:
                    courses.append([course_name, categories])
                    course_name = ""
                    categories = []
                    assignments = []
                    continue

                if not course_name:
                    course_name = line
                    continue

                category_info = line.split(',')
                category_name = category_info[0]
                category_weight = float(category_info[1])
                assignments = [(category_info[i], int(category_info[i + 1])) for i in
                               range(2, len(category_info) - 1, 2)]

                categories.append([category_name, category_weight, assignments])
            return [courses, type]


# Function to calculate a GPA once given a list of formatted data
def calculate_gpa(class_grades):
    total_credits = 0
    sum = 0.0

    # Calculating GPA with unpacked tuples from the input list
    for name, credits, grade in class_grades:
        if 100 >= grade >= 93:
            sum += (4.0 * credits)
        elif 93 > grade >= 90:
            sum += (3.67 * credits)
        elif 90 > grade >= 87:
            sum += (3.33 * credits)
        elif 87 > grade >= 83:
            sum += (3.0 * credits)
        elif 83 > grade >= 80:
            sum += (2.67 * credits)
        elif 80 > grade >= 77:
            sum += (2.33 * credits)
        elif 77 > grade >= 73:
            sum += (2.0 * credits)
        elif 73 > grade >= 70:
            sum += (1.67 * credits)
        elif 70 > grade >= 67:
            sum += (1.33 * credits)
        elif 67 > grade >= 63:
            sum += (1.0 * credits)
        elif 63 > grade >= 60:
            sum += (0.67 * credits)
        elif 60 > grade:
            # Grade is less than 60, no points added to sum but credits counted towards total
            pass
        total_credits += credits

    return sum / total_credits


def calculate_final_grade(courses):
    averages = []
    numCourses = len(courses)
    for i in range(0, numCourses):
        totalWeightedAverage = 0.0
        numCategories = len(courses[i][1])
        for j in range(0, numCategories):
            catWeight = courses[i][1][j][1]
            weightedAverage = 0.0
            totalPoints = 0.0
            numAssignments = len(courses[i][1][j][2])
            for k in range(0, numAssignments):
                totalPoints = totalPoints + courses[i][1][j][2][k][1]
            weightedAverage = (totalPoints / numAssignments) * catWeight
            totalWeightedAverage = totalWeightedAverage + weightedAverage
        averages.append(totalWeightedAverage)
    return averages

if __name__ == "__main__":
    # Making sure all command line arguments are passed
    if len(sys.argv) < 2:
        print("Usage: python3 process.py <file_path>")
        sys.exit(1)

    # Getting the file name, and then outputting the resulting GPA
    file_name = sys.argv[1]
    test = handle(file_name)
    if (test[1] == "GPA"):
        print(calculate_gpa(test[0]))
    elif (test[1] == "GRADE"):
        print(calculate_final_grade(test[0]))
    

